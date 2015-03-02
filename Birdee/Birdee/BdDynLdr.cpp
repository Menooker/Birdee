#include "BdDynLdr.h"
extern "C"{
#include "..\..\include\DBG.h"
//#include "..\..\include\DVM.h"
#include "..\..\DVM\DVM_pri.h"
#include "../../include/MEM.h"
}

#include "Loader.h"
#include <hash_set>
#ifdef BD_ON_GCC
#include <ext/hash_map>
using namespace std;
using namespace __gnu_cxx;
namespace std
{
using namespace __gnu_cxx;
}
namespace __gnu_cxx
{
    template<> struct hash<const string>
    {
        size_t operator()(const string& s) const
        { return hash<const char*>()( s.c_str() ); } //__stl_hash_string
    };
    template<> struct hash<std::string>
    {
        size_t operator()(const std::string& s) const
        { return hash<const char*>()( s.c_str() ); }
    };
}
#else
#include <hash_map>
#endif



#include <string>
#include <stdio.h>
#include <io.h>
#include <string.h>

std::hash_map<std::string,DVM_ExecutableList> LoadedLibs;
std::hash_map<std::string,ExecutableEntry*> LoadedMods;
std::hash_map<std::string,ExecutableEntry*> LoadedReqMods;

//std::hash_map<std::string,std::string> BuiltinModules;
//FILENAME_MAX

ExecutableEntry* LdGetLoadedRequiredModule(char* name)
{
	if(!name)
		name="";
	if(LoadedReqMods.find(name)!=LoadedReqMods.end())
	{
		return LoadedReqMods[name];
	}
	return 0;
}

ExecutableEntry* LdPushRequiredModule(char* name,ExecutableEntry* ee)
{
	if(!name)
		name="";
	ExecutableEntry* ret=LdGetLoadedRequiredModule(name);
	if(ret)
		return ret;
	LoadedReqMods[name]=ee;
	return 0;
}

ExecutableEntry* LdGetLoadedModule(char* name)
{
	if(!name)
		name="";
	if(LoadedMods.find(name)!=LoadedMods.end())
	{
		return LoadedMods[name];
	}
	return 0;
}

ExecutableEntry* LdPushModule(char* name,ExecutableEntry* ee)
{
	if(!name)
		name="";
	ExecutableEntry* ret=LdGetLoadedModule(name);
	if(ret)
		return ret;
	LoadedMods[name]=ee;
	return 0;
}

void my_make_search_path_impl(char *package_name, char *buf)
{
    int suffix_len;
    int package_len;
    int i;

	if(package_name==0)
	{
		buf[0]=0;
		return ;
	}
    suffix_len = strlen(DIKSAM_IMPLEMENTATION_SUFFIX);
    package_len = strlen(package_name);

    DBG_assert(package_len <= FILENAME_MAX - (2 + suffix_len),
               ("package name is too long(%s)", package_name));

    for (i = 0; package_name[i] != '\0'; i++) {
        if (package_name[i] == '.') {
            buf[i] = FILE_SEPARATOR;
        } else {
            buf[i] = package_name[i];
        }
    }
    buf[i] = '\0';
    strcat(buf, BIRDEE_LIB_SUFFIX);
}

SearchFileStatus LdSearchLibFile(char *search_path, char *search_file,char *found_path)
{
    int sp_idx;
    int dp_idx;
    char dir_path[FILENAME_MAX];
    char *home;
    int search_file_len;
    FILE *fp_tmp;

    search_file_len = strlen(search_file);

    for (sp_idx = 0, dp_idx = 0; ; sp_idx++) {
        if (search_path[sp_idx] == FILE_PATH_SEPARATOR
            || search_path[sp_idx] == '\0') {

            if (dp_idx + 1 + search_file_len >= FILENAME_MAX-1) {
                return SEARCH_FILE_PATH_TOO_LONG;
            }

            if (dp_idx > 0 && dir_path[dp_idx-1] != FILE_SEPARATOR && dir_path[dp_idx-1] != '\\') {
                dir_path[dp_idx] = FILE_SEPARATOR;
                dp_idx++;
            }
            strcpy(&dir_path[dp_idx], search_file);
			if( (_access(dir_path , 4 )) != -1 )
			{
                strcpy(found_path, dir_path);
                return SEARCH_FILE_SUCCESS;
            }
            dp_idx = 0;
            if (search_path[sp_idx] == '\0')
                return SEARCH_FILE_NOT_FOUND;
        } else {
            if (dp_idx == 0 && search_path[sp_idx] == '~'
                && (home = getenv("HOME")) != NULL) {
                strcpy(&dir_path[dp_idx], home);
                dp_idx += strlen(home);
            } else {
                if (dp_idx >= FILENAME_MAX-1) {
                    return SEARCH_FILE_PATH_TOO_LONG;
                }
                dir_path[dp_idx] = search_path[sp_idx];
                dp_idx++;
            }
        }
    }

    DBG_assert(0, ("bad flow."));
}

BdStatus LdGetDynamicLibPath(char *package_name, char *found_path,char *search_file)
{
    SearchFileStatus status;
    char *search_path;
	my_make_search_path_impl(package_name, search_file);

    search_path = getenv("BDL_LOAD_SEARCH_PATH");
    if (search_path != NULL)
	{
		status = LdSearchLibFile(search_path, search_file, found_path);
		if (status == SEARCH_FILE_SUCCESS) {
			return BdSuccess;
		}
	}
	status = LdSearchLibFile(".", search_file, found_path);
	if (status == SEARCH_FILE_SUCCESS) {
		return BdSuccess;
	}
    return BdFileNotFound;
}




extern "C" ExecutableEntry * add_executable_to_dvm(DVM_VirtualMachine *dvm, DVM_Executable *executable,DVM_Boolean is_top_level);
extern "C" void initialize_constant(DVM_VirtualMachine *dvm, ExecutableEntry *ee);


/*
void ExFreeDynamicLibraries()
{
	std::hash_map<std::string,DVM_ExecutableList*>::iterator it;
	for(it=LoadedLibs.begin();it!=LoadedLibs.end();it++)
	{
		DVM_dispose_executable_list(it->second);
	}
}*/

DVM_ExecutableItem* LdLoadDynamicLibrary(DVM_VirtualMachine *dvm,char* path,char* libname)
{
    DVM_ExecutableItem *pos,*lastitm;
    ExecutableEntry *ee;
	DVM_ExecutableList list={0};
    //dvm->executable_list = list;
	BdStatus status=LdLoadCode(path,&list);
	if(status)
	{
		printf("ERROR Loading Code %d\n",status);
		_BreakPoint()
		return 0;
	}
	LoadedLibs[libname]=list;
    lastitm = dvm->executable_list->list;
	if(lastitm)
	{
		for(;;)
		{
			if(lastitm->next)
				lastitm = lastitm->next;
			else
				break;
		}
	}
    for (pos = list.list; pos; pos = pos->next) {
		pos->executable->isDyn=DVM_TRUE;
		pos->executable->class_count=0; //fix-me : may lead to memory leak

		if(lastitm)
			lastitm->next=pos;
		else
			dvm->executable_list->list=pos;
		lastitm=pos;

		if(pos->executable->package_name !=NULL)
		{
			ee = add_executable_to_dvm(dvm, pos->executable,DVM_FALSE);
			initialize_constant(dvm, ee);
			if(ee->executable->is_required)
				LdPushRequiredModule(ee->executable->package_name,ee);
			else
				LdPushModule(ee->executable->package_name,ee);
		}
    }
	lastitm->next=0;
	return list.list;
}


DVM_ExecutableItem* LdLoadPackage(DVM_VirtualMachine *dvm,char* libname,char* packagename)
{
	if(LoadedLibs.find(libname)!=LoadedLibs.end())
	{
		return LoadedLibs[libname].list;
	}
	char found_path[FILENAME_MAX],search_file[FILENAME_MAX];
	if(LdGetDynamicLibPath(libname,found_path,search_file)==BdSuccess)
	{
		DVM_ExecutableItem* pos=LdLoadDynamicLibrary(dvm,found_path,libname);
		for (; pos; pos = pos->next) {
			if(!strcmp(pos->executable->package_name,packagename))
			{
				return pos;
			}
		}
		//Load success but the package not found
		return 0;
	}
	return 0;
}

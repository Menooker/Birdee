#ifndef _H_HASH_MAP_COMP
#define _H_HASH_MAP_COMP
#include "BirdeeDef.h"
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

#endif
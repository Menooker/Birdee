#ifndef _H_HASH_MAP_COMP
#define _H_HASH_MAP_COMP
#include "BirdeeDef.h"
#ifdef BD_ON_GCC
#include <ext/hash_map>
#include <string>
using namespace std;
using namespace __gnu_cxx;
namespace std
{
using namespace __gnu_cxx;
}
namespace __gnu_cxx
{
    inline size_t MyHash(const wchar_t *str,size_t len)
    {
        size_t ahash = 0;
        for(int i=0;i<len; i++,str++)
        {
            size_t ch=*str;
            ahash = ahash * 131 + ch;
        }
        return ahash;
    }

    template<> struct hash<const long long int>
    {
        size_t operator()(const long long int& s) const
        {  return (s>>4)%0xffffffff; } //__stl_hash_string
    };
    template<> struct hash<long long int>
    {
        size_t operator()(const long long int& s) const
        {  return (s>>4)%0xffffffff; } //__stl_hash_string
    };


    template<> struct hash<const std::wstring>
    {
        size_t operator()(const wstring& s) const
        {  return MyHash( s.c_str(),wcslen(s.c_str()) ); } //__stl_hash_string
    };
    template<> struct hash<std::wstring>
    {
        size_t operator()(const std::wstring& s) const
        { return MyHash( s.c_str(),wcslen(s.c_str()) ); }
    };

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

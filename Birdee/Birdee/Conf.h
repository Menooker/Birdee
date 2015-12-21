#ifndef _H_BIRDEE_CONFIG
#define _H_BIRDEE_CONFIG

//#define BD_ON_LINUX
//#define BD_ON_GCC
//#define BD_ON_WINDOWS
#ifdef BD_ON_WINDOWS
    #define PAGE_SIZE (4096) // 4K
#else
    #ifdef __cplusplus
    extern "C" int PAGE_SIZE;
    #else
    extern int PAGE_SIZE;
    #endif

#endif

#define BD_ON_X86
//#define BD_ON_VC
#define BD_USE_STL_HASH_MAP


//#define BD_MULTITHREAD

#define BD_MAX_SHARED_STATIC_PER_MODULE 512
#define BD_MAX_SHARED_MODULES 4096
#define BD_MAX_SHARED_STATIC_ID (BD_MAX_SHARED_STATIC_PER_MODULE*BD_MAX_SHARED_MODULES)
#define BD_MAX_SHARED_KEY_TRIES 2000

#endif

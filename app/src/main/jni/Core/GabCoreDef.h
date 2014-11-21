#ifndef GAB_CORE_DEF_H
#define GAB_CORE_DEF_H

#if defined GAB_CORE_EXPORTS
#if defined _WIN32
#define GAB_CORE_EXPORT              __declspec( dllexport )
#else
#define GAB_CORE_EXPORT
#endif
#else
#if defined _WIN32
#define GAB_CORE_EXPORT              __declspec( dllimport )
#else
#define GAB_CORE_EXPORT
#endif
#endif

#endif
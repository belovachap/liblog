#pragma once

#if defined(LIBLOG_STATIC)         // Using static.
#  define LIBLOG_SYMEXPORT
#elif defined(LIBLOG_STATIC_BUILD) // Building static.
#  define LIBLOG_SYMEXPORT
#elif defined(LIBLOG_SHARED)       // Using shared.
#  ifdef _WIN32
#    define LIBLOG_SYMEXPORT __declspec(dllimport)
#  else
#    define LIBLOG_SYMEXPORT
#  endif
#elif defined(LIBLOG_SHARED_BUILD) // Building shared.
#  ifdef _WIN32
#    define LIBLOG_SYMEXPORT __declspec(dllexport)
#  else
#    define LIBLOG_SYMEXPORT
#  endif
#else
// If none of the above macros are defined, then we assume we are being used
// by some third-party build system that cannot/doesn't signal the library
// type. Note that this fallback works for both static and shared but in case
// of shared will be sub-optimal compared to having dllimport.
//
#  define LIBLOG_SYMEXPORT         // Using static or shared.
#endif

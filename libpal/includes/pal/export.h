#pragma once

#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__) || defined( __MWERKS__)
#  if defined( LIBPAL_LIBRARY_STATIC )
#    define LIBPAL_EXPORT
#  elif defined( LIBPAL_LIBRARY )
#    define LIBPAL_EXPORT   __declspec(dllexport)
#  else
#    define LIBPAL_EXPORT   __declspec(dllimport)
#endif
#else
#define LIBPAL_EXPORT 
#endif 
#pragma once

#if defined(WIN32) || defined(_WIN32)
#	ifndef VDGL_PLATFORM_WINDOWS
#		define VDGL_PLATFORM_WINDOWS
#	endif
#endif

#if defined(VDGL_PLATFORM_WINDOWS) && defined(UNICODE)
#	define VDGL_USE_WCHAR
#endif

#if defined(VDGL_USE_WCHAR)
#	define VDGLString(string) L##string
using VDGLChar = wchar_t;
#else
#	define VDGLString(string) string
using VDGLChar = char;
#endif

#if defined(_MSC_VER)
#	define FORCE_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#	define FORCE_INLINE inline __attribute__((always_inline))
#else
#	define FORCE_INLINE inline
#endif

#define VDGL_FN(returnType, call, name, parameters, arguments) using PFN##name = returnType (call*) parameters;\
inline PFN##name _vdgl_##name = nullptr;\
FORCE_INLINE returnType call name parameters { return _vdgl_##name arguments; }

#define VDGL_LOAD_FN(name) _vdgl_##name = (PFN##name)GetFunctionPointer(#name)
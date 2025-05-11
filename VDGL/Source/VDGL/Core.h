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

#define VDGL_FN(returnType, call, name, ...) using PFN##name = returnType (call) (__VA_ARGS__);\
inline PFN##name name = nullptr

#define VDGL_LOAD_FN(name) name = (PFN##name)GetFunctionPointer(#name)
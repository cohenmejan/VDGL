#pragma once

#define VDGL_FN(returnType, call, name, ...) using PFN##name = returnType (call) (__VA_ARGS__);\
inline PFN##name name = nullptr

#define VDGL_LOAD_FN(name) name = (PFN##name)GetFunctionPointer(#name)
#pragma once

#include "Core.h"
#include "GLDefinitions.h"

#if defined(VDGL_PLATFORM_WINDOWS)
#	include "WGLDefinitions.h"
#endif

class VDGL final {
public:

	//////
	////// VDGL::Status
	//////

		// Holds success or error status info for functions
		struct Status {
			const bool success = false;
			const char* message = nullptr;

			constexpr Status(const bool success, const char* message);

			constexpr operator bool() const;
			constexpr operator const char* () const;
		};

		//////
		////// VDGL
		//////

			// Initializes the OpenGL function pointers
			// Must be called before any OpenGL functions are used
			// Application must link to opengl32.lib
			static Status Initialize();

			// Frees the OpenGL resources
			static Status Close();

		private:
			// Acquires the function pointer with the given name from the OpenGL library
			static void* GetFunctionPointer(const char* name);

			// Gets all available function pointers from the OpenGL library module
			static void LoadGLFunctions();

			// Gets all available platform-specific GL function pointers
			// Windows: WGL
			static void LoadPlatformFunctions();

			// Loads all available functions
			static inline void LoadFunctions();

			// Unloads all GL function pointers
			static void UnloadGLFunctions();

			// Unloads all platform-specific GL function pointers
			static void UnloadPlatformFunctions();

			// Unloads all function pointers
			static inline void UnloadFunctions();
};

//////
////// VDGL::Status
//////

constexpr VDGL::Status::Status(const bool success, const char* message) :
	success(success),
	message(message) {}

constexpr VDGL::Status::operator bool() const {
	return success;
}

constexpr VDGL::Status::operator const char* () const {
	return message;
}

//////
////// VDGL
//////

inline void VDGL::LoadFunctions() {
	LoadGLFunctions();
	LoadPlatformFunctions();
}

inline void VDGL::UnloadFunctions() {
	UnloadGLFunctions();
	UnloadPlatformFunctions();
}
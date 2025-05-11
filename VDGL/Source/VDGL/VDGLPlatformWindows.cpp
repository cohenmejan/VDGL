#include "Core.h"
#ifdef VDGL_PLATFORM_WINDOWS

#include "VDGL.h"
#include "WGLDefinitions.h"

static HMODULE sGLLib = nullptr;
static HWND sWindowHandle = nullptr;
static HDC sHDC = nullptr;
static HGLRC sHRC = nullptr;
static HINSTANCE sInstance = nullptr;
static const VDGLChar* sWindowClassName = VDGLString("VDGLInitWindowClass");

VDGL::Status VDGL::Initialize() {

	// OpenGL library

	if(sGLLib) {
		Close();
	}

	if(!sGLLib) {
		sGLLib = LoadLibrary(VDGLString("opengl32.dll"));

		if(!sGLLib) {
			return Status(false, "Failed to load GL library");
		}
	}

	// Window class

	sInstance = GetModuleHandle(nullptr);

	WNDCLASS windowClass = {};
	windowClass.lpfnWndProc = DefWindowProc;
	windowClass.hInstance = sInstance;
	windowClass.lpszClassName = sWindowClassName;

	if(RegisterClass(&windowClass) == 0) {
		return Status(false, "Failed to register VDGLInitWindowClass");
	}

	// Window

	sWindowHandle = CreateWindowEx(
		0,
		sWindowClassName,
		VDGLString("VDGLInitWindow"),
		WS_OVERLAPPED,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		nullptr,
		nullptr,
		sInstance,
		nullptr
	);

	if(!sWindowHandle) {
		UnregisterClass(sWindowClassName, sInstance);
		Close();

		return Status(false, "Failed to create VDGLInitWindow");
	}

	// Device context

	sHDC = GetDC(sWindowHandle);

	if(!sHDC) {
		DestroyWindow(sWindowHandle);
		UnregisterClass(sWindowClassName, sInstance);
		Close();

		return Status(false, "Failed to get device context");
	}

	// Pixel format

	PIXELFORMATDESCRIPTOR pfd = {};

	if(!SetPixelFormat(sHDC, ChoosePixelFormat(sHDC, &pfd), &pfd)) {
		ReleaseDC(sWindowHandle, sHDC);
		DestroyWindow(sWindowHandle);
		UnregisterClass(sWindowClassName, sInstance);
		Close();

		return Status(false, "Failed to set pixel format");
	}

	// Context

	sHRC = wglCreateContext(sHDC);

	if(!wglMakeCurrent(sHDC, sHRC)) {
		wglDeleteContext(sHRC);
		ReleaseDC(sWindowHandle, sHDC);
		DestroyWindow(sWindowHandle);
		UnregisterClass(sWindowClassName, sInstance);
		Close();

		return Status(false, "Failed to set temporary context");
	}

	// Load

	LoadFunctions();

	// Delete temporary window

	wglMakeCurrent(nullptr, nullptr);
	wglDeleteContext(sHRC);
	ReleaseDC(sWindowHandle, sHDC);
	DestroyWindow(sWindowHandle);
	UnregisterClass(sWindowClassName, sInstance);

	return Status(true, "GL initialized");
}

VDGL::Status VDGL::Close() {
	UnloadFunctions();

	if(sGLLib) {
		FreeLibrary(sGLLib);
	}

	sGLLib = nullptr;
	sWindowHandle = nullptr;
	sHDC = nullptr;
	sHRC = nullptr;
	sInstance = nullptr;

	return Status(true, "GL closed");
}

void* VDGL::GetFunctionPointer(const char* name) {
	if(!sGLLib) return nullptr;

	void* result = (void*)wglGetProcAddress(name);

	if(!result || (result == (void*)1) || (result == (void*)2) || (result == (void*)3) || (result == (void*)-1)) {
		result = (void*)GetProcAddress(sGLLib, name);
	}

	return result;
}

void VDGL::LoadPlatformFunctions() {
	VDGL_LOAD_FN(wglCreateContextAttribsARB);
	VDGL_LOAD_FN(wglChoosePixelFormatARB);
	VDGL_LOAD_FN(wglSwapIntervalEXT);
}

void VDGL::UnloadPlatformFunctions() {
	wglCreateContextAttribsARB = nullptr;
	wglChoosePixelFormatARB = nullptr;
	wglSwapIntervalEXT = nullptr;
}

#endif // VDGL_PLATFORM_WINDOWS
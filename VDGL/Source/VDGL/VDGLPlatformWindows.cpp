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

	PIXELFORMATDESCRIPTOR pixelFormat = {};
	if(!SetPixelFormat(sHDC, ChoosePixelFormat(sHDC, &pixelFormat), &pixelFormat)) {
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
	VDGL_LOAD_FN(wglCreateBufferRegionARB);
	VDGL_LOAD_FN(wglDeleteBufferRegionARB);
	VDGL_LOAD_FN(wglSaveBufferRegionARB);
	VDGL_LOAD_FN(wglRestoreBufferRegionARB);
	VDGL_LOAD_FN(wglCreateContextAttribsARB);
	VDGL_LOAD_FN(wglGetExtensionsStringARB);
	VDGL_LOAD_FN(wglMakeContextCurrentARB);
	VDGL_LOAD_FN(wglGetCurrentReadDCARB);
	VDGL_LOAD_FN(wglCreatePbufferARB);
	VDGL_LOAD_FN(wglGetPbufferDCARB);
	VDGL_LOAD_FN(wglReleasePbufferDCARB);
	VDGL_LOAD_FN(wglDestroyPbufferARB);
	VDGL_LOAD_FN(wglQueryPbufferARB);
	VDGL_LOAD_FN(wglGetPixelFormatAttribivARB);
	VDGL_LOAD_FN(wglGetPixelFormatAttribfvARB);
	VDGL_LOAD_FN(wglChoosePixelFormatARB);
	VDGL_LOAD_FN(wglBindTexImageARB);
	VDGL_LOAD_FN(wglReleaseTexImageARB);
	VDGL_LOAD_FN(wglSetPbufferAttribARB);
	VDGL_LOAD_FN(wglSetStereoEmitterState3DL);
	VDGL_LOAD_FN(wglGetGPUIDsAMD);
	VDGL_LOAD_FN(wglGetGPUInfoAMD);
	VDGL_LOAD_FN(wglGetContextGPUIDAMD);
	VDGL_LOAD_FN(wglCreateAssociatedContextAMD);
	VDGL_LOAD_FN(wglCreateAssociatedContextAttribsAMD);
	VDGL_LOAD_FN(wglDeleteAssociatedContextAMD);
	VDGL_LOAD_FN(wglMakeAssociatedContextCurrentAMD);
	VDGL_LOAD_FN(wglGetCurrentAssociatedContextAMD);
	VDGL_LOAD_FN(wglBlitContextFramebufferAMD);
	VDGL_LOAD_FN(wglCreateDisplayColorTableEXT);
	VDGL_LOAD_FN(wglLoadDisplayColorTableEXT);
	VDGL_LOAD_FN(wglBindDisplayColorTableEXT);
	VDGL_LOAD_FN(wglDestroyDisplayColorTableEXT);
	VDGL_LOAD_FN(wglGetExtensionsStringEXT);
	VDGL_LOAD_FN(wglMakeContextCurrentEXT);
	VDGL_LOAD_FN(wglGetCurrentReadDCEXT);
	VDGL_LOAD_FN(wglCreatePbufferEXT);
	VDGL_LOAD_FN(wglGetPbufferDCEXT);
	VDGL_LOAD_FN(wglReleasePbufferDCEXT);
	VDGL_LOAD_FN(wglDestroyPbufferEXT);
	VDGL_LOAD_FN(wglQueryPbufferEXT);
	VDGL_LOAD_FN(wglGetPixelFormatAttribivEXT);
	VDGL_LOAD_FN(wglGetPixelFormatAttribfvEXT);
	VDGL_LOAD_FN(wglChoosePixelFormatEXT);
	VDGL_LOAD_FN(wglSwapIntervalEXT);
	VDGL_LOAD_FN(wglGetSwapIntervalEXT);
	VDGL_LOAD_FN(wglGetDigitalVideoParametersI3D);
	VDGL_LOAD_FN(wglSetDigitalVideoParametersI3D);
	VDGL_LOAD_FN(wglGetGammaTableParametersI3D);
	VDGL_LOAD_FN(wglSetGammaTableParametersI3D);
	VDGL_LOAD_FN(wglGetGammaTableI3D);
	VDGL_LOAD_FN(wglSetGammaTableI3D);
	VDGL_LOAD_FN(wglEnableGenlockI3D);
	VDGL_LOAD_FN(wglDisableGenlockI3D);
	VDGL_LOAD_FN(wglIsEnabledGenlockI3D);
	VDGL_LOAD_FN(wglGenlockSourceI3D);
	VDGL_LOAD_FN(wglGetGenlockSourceI3D);
	VDGL_LOAD_FN(wglGenlockSourceEdgeI3D);
	VDGL_LOAD_FN(wglGetGenlockSourceEdgeI3D);
	VDGL_LOAD_FN(wglGenlockSampleRateI3D);
	VDGL_LOAD_FN(wglGetGenlockSampleRateI3D);
	VDGL_LOAD_FN(wglGenlockSourceDelayI3D);
	VDGL_LOAD_FN(wglGetGenlockSourceDelayI3D);
	VDGL_LOAD_FN(wglQueryGenlockMaxSourceDelayI3D);
	VDGL_LOAD_FN(wglCreateImageBufferI3D);
	VDGL_LOAD_FN(wglDestroyImageBufferI3D);
	VDGL_LOAD_FN(wglAssociateImageBufferEventsI3D);
	VDGL_LOAD_FN(wglReleaseImageBufferEventsI3D);
	VDGL_LOAD_FN(wglEnableFrameLockI3D);
	VDGL_LOAD_FN(wglDisableFrameLockI3D);
	VDGL_LOAD_FN(wglIsEnabledFrameLockI3D);
	VDGL_LOAD_FN(wglQueryFrameLockMasterI3D);
	VDGL_LOAD_FN(wglGetFrameUsageI3D);
	VDGL_LOAD_FN(wglBeginFrameTrackingI3D);
	VDGL_LOAD_FN(wglEndFrameTrackingI3D);
	VDGL_LOAD_FN(wglQueryFrameTrackingI3D);
	VDGL_LOAD_FN(wglDXSetResourceShareHandleNV);
	VDGL_LOAD_FN(wglDXOpenDeviceNV);
	VDGL_LOAD_FN(wglDXCloseDeviceNV);
	VDGL_LOAD_FN(wglDXRegisterObjectNV);
	VDGL_LOAD_FN(wglDXUnregisterObjectNV);
	VDGL_LOAD_FN(wglDXObjectAccessNV);
	VDGL_LOAD_FN(wglDXLockObjectsNV);
	VDGL_LOAD_FN(wglDXUnlockObjectsNV);
	VDGL_LOAD_FN(wglCopyImageSubDataNV);
	VDGL_LOAD_FN(wglDelayBeforeSwapNV);
	VDGL_LOAD_FN(wglEnumGpusNV);
	VDGL_LOAD_FN(wglEnumGpuDevicesNV);
	VDGL_LOAD_FN(wglCreateAffinityDCNV);
	VDGL_LOAD_FN(wglEnumGpusFromAffinityDCNV);
	VDGL_LOAD_FN(wglDeleteDCNV);
	VDGL_LOAD_FN(wglEnumerateVideoDevicesNV);
	VDGL_LOAD_FN(wglBindVideoDeviceNV);
	VDGL_LOAD_FN(wglQueryCurrentContextNV);
	VDGL_LOAD_FN(wglJoinSwapGroupNV);
	VDGL_LOAD_FN(wglBindSwapBarrierNV);
	VDGL_LOAD_FN(wglQuerySwapGroupNV);
	VDGL_LOAD_FN(wglQueryMaxSwapGroupsNV);
	VDGL_LOAD_FN(wglQueryFrameCountNV);
	VDGL_LOAD_FN(wglResetFrameCountNV);
	VDGL_LOAD_FN(wglAllocateMemoryNV);
	VDGL_LOAD_FN(wglFreeMemoryNV);
	VDGL_LOAD_FN(wglBindVideoCaptureDeviceNV);
	VDGL_LOAD_FN(wglEnumerateVideoCaptureDevicesNV);
	VDGL_LOAD_FN(wglLockVideoCaptureDeviceNV);
	VDGL_LOAD_FN(wglQueryVideoCaptureDeviceNV);
	VDGL_LOAD_FN(wglReleaseVideoCaptureDeviceNV);
	VDGL_LOAD_FN(wglGetVideoDeviceNV);
	VDGL_LOAD_FN(wglReleaseVideoDeviceNV);
	VDGL_LOAD_FN(wglBindVideoImageNV);
	VDGL_LOAD_FN(wglReleaseVideoImageNV);
	VDGL_LOAD_FN(wglSendPbufferToVideoNV);
	VDGL_LOAD_FN(wglGetVideoInfoNV);
	VDGL_LOAD_FN(wglGetSyncValuesOML);
	VDGL_LOAD_FN(wglGetMscRateOML);
	VDGL_LOAD_FN(wglSwapBuffersMscOML);
	VDGL_LOAD_FN(wglSwapLayerBuffersMscOML);
	VDGL_LOAD_FN(wglWaitForMscOML);
	VDGL_LOAD_FN(wglWaitForSbcOML);
}

void VDGL::UnloadPlatformFunctions() {
	_vdgl_wglCreateBufferRegionARB = nullptr;
	_vdgl_wglDeleteBufferRegionARB = nullptr;
	_vdgl_wglSaveBufferRegionARB = nullptr;
	_vdgl_wglRestoreBufferRegionARB = nullptr;
	_vdgl_wglCreateContextAttribsARB = nullptr;
	_vdgl_wglGetExtensionsStringARB = nullptr;
	_vdgl_wglMakeContextCurrentARB = nullptr;
	_vdgl_wglGetCurrentReadDCARB = nullptr;
	_vdgl_wglCreatePbufferARB = nullptr;
	_vdgl_wglGetPbufferDCARB = nullptr;
	_vdgl_wglReleasePbufferDCARB = nullptr;
	_vdgl_wglDestroyPbufferARB = nullptr;
	_vdgl_wglQueryPbufferARB = nullptr;
	_vdgl_wglGetPixelFormatAttribivARB = nullptr;
	_vdgl_wglGetPixelFormatAttribfvARB = nullptr;
	_vdgl_wglChoosePixelFormatARB = nullptr;
	_vdgl_wglBindTexImageARB = nullptr;
	_vdgl_wglReleaseTexImageARB = nullptr;
	_vdgl_wglSetPbufferAttribARB = nullptr;
	_vdgl_wglSetStereoEmitterState3DL = nullptr;
	_vdgl_wglGetGPUIDsAMD = nullptr;
	_vdgl_wglGetGPUInfoAMD = nullptr;
	_vdgl_wglGetContextGPUIDAMD = nullptr;
	_vdgl_wglCreateAssociatedContextAMD = nullptr;
	_vdgl_wglCreateAssociatedContextAttribsAMD = nullptr;
	_vdgl_wglDeleteAssociatedContextAMD = nullptr;
	_vdgl_wglMakeAssociatedContextCurrentAMD = nullptr;
	_vdgl_wglGetCurrentAssociatedContextAMD = nullptr;
	_vdgl_wglBlitContextFramebufferAMD = nullptr;
	_vdgl_wglCreateDisplayColorTableEXT = nullptr;
	_vdgl_wglLoadDisplayColorTableEXT = nullptr;
	_vdgl_wglBindDisplayColorTableEXT = nullptr;
	_vdgl_wglDestroyDisplayColorTableEXT = nullptr;
	_vdgl_wglGetExtensionsStringEXT = nullptr;
	_vdgl_wglMakeContextCurrentEXT = nullptr;
	_vdgl_wglGetCurrentReadDCEXT = nullptr;
	_vdgl_wglCreatePbufferEXT = nullptr;
	_vdgl_wglGetPbufferDCEXT = nullptr;
	_vdgl_wglReleasePbufferDCEXT = nullptr;
	_vdgl_wglDestroyPbufferEXT = nullptr;
	_vdgl_wglQueryPbufferEXT = nullptr;
	_vdgl_wglGetPixelFormatAttribivEXT = nullptr;
	_vdgl_wglGetPixelFormatAttribfvEXT = nullptr;
	_vdgl_wglChoosePixelFormatEXT = nullptr;
	_vdgl_wglSwapIntervalEXT = nullptr;
	_vdgl_wglGetSwapIntervalEXT = nullptr;
	_vdgl_wglGetDigitalVideoParametersI3D = nullptr;
	_vdgl_wglSetDigitalVideoParametersI3D = nullptr;
	_vdgl_wglGetGammaTableParametersI3D = nullptr;
	_vdgl_wglSetGammaTableParametersI3D = nullptr;
	_vdgl_wglGetGammaTableI3D = nullptr;
	_vdgl_wglSetGammaTableI3D = nullptr;
	_vdgl_wglEnableGenlockI3D = nullptr;
	_vdgl_wglDisableGenlockI3D = nullptr;
	_vdgl_wglIsEnabledGenlockI3D = nullptr;
	_vdgl_wglGenlockSourceI3D = nullptr;
	_vdgl_wglGetGenlockSourceI3D = nullptr;
	_vdgl_wglGenlockSourceEdgeI3D = nullptr;
	_vdgl_wglGetGenlockSourceEdgeI3D = nullptr;
	_vdgl_wglGenlockSampleRateI3D = nullptr;
	_vdgl_wglGetGenlockSampleRateI3D = nullptr;
	_vdgl_wglGenlockSourceDelayI3D = nullptr;
	_vdgl_wglGetGenlockSourceDelayI3D = nullptr;
	_vdgl_wglQueryGenlockMaxSourceDelayI3D = nullptr;
	_vdgl_wglCreateImageBufferI3D = nullptr;
	_vdgl_wglDestroyImageBufferI3D = nullptr;
	_vdgl_wglAssociateImageBufferEventsI3D = nullptr;
	_vdgl_wglReleaseImageBufferEventsI3D = nullptr;
	_vdgl_wglEnableFrameLockI3D = nullptr;
	_vdgl_wglDisableFrameLockI3D = nullptr;
	_vdgl_wglIsEnabledFrameLockI3D = nullptr;
	_vdgl_wglQueryFrameLockMasterI3D = nullptr;
	_vdgl_wglGetFrameUsageI3D = nullptr;
	_vdgl_wglBeginFrameTrackingI3D = nullptr;
	_vdgl_wglEndFrameTrackingI3D = nullptr;
	_vdgl_wglQueryFrameTrackingI3D = nullptr;
	_vdgl_wglDXSetResourceShareHandleNV = nullptr;
	_vdgl_wglDXOpenDeviceNV = nullptr;
	_vdgl_wglDXCloseDeviceNV = nullptr;
	_vdgl_wglDXRegisterObjectNV = nullptr;
	_vdgl_wglDXUnregisterObjectNV = nullptr;
	_vdgl_wglDXObjectAccessNV = nullptr;
	_vdgl_wglDXLockObjectsNV = nullptr;
	_vdgl_wglDXUnlockObjectsNV = nullptr;
	_vdgl_wglCopyImageSubDataNV = nullptr;
	_vdgl_wglDelayBeforeSwapNV = nullptr;
	_vdgl_wglEnumGpusNV = nullptr;
	_vdgl_wglEnumGpuDevicesNV = nullptr;
	_vdgl_wglCreateAffinityDCNV = nullptr;
	_vdgl_wglEnumGpusFromAffinityDCNV = nullptr;
	_vdgl_wglDeleteDCNV = nullptr;
	_vdgl_wglEnumerateVideoDevicesNV = nullptr;
	_vdgl_wglBindVideoDeviceNV = nullptr;
	_vdgl_wglQueryCurrentContextNV = nullptr;
	_vdgl_wglJoinSwapGroupNV = nullptr;
	_vdgl_wglBindSwapBarrierNV = nullptr;
	_vdgl_wglQuerySwapGroupNV = nullptr;
	_vdgl_wglQueryMaxSwapGroupsNV = nullptr;
	_vdgl_wglQueryFrameCountNV = nullptr;
	_vdgl_wglResetFrameCountNV = nullptr;
	_vdgl_wglAllocateMemoryNV = nullptr;
	_vdgl_wglFreeMemoryNV = nullptr;
	_vdgl_wglBindVideoCaptureDeviceNV = nullptr;
	_vdgl_wglEnumerateVideoCaptureDevicesNV = nullptr;
	_vdgl_wglLockVideoCaptureDeviceNV = nullptr;
	_vdgl_wglQueryVideoCaptureDeviceNV = nullptr;
	_vdgl_wglReleaseVideoCaptureDeviceNV = nullptr;
	_vdgl_wglGetVideoDeviceNV = nullptr;
	_vdgl_wglReleaseVideoDeviceNV = nullptr;
	_vdgl_wglBindVideoImageNV = nullptr;
	_vdgl_wglReleaseVideoImageNV = nullptr;
	_vdgl_wglSendPbufferToVideoNV = nullptr;
	_vdgl_wglGetVideoInfoNV = nullptr;
	_vdgl_wglGetSyncValuesOML = nullptr;
	_vdgl_wglGetMscRateOML = nullptr;
	_vdgl_wglSwapBuffersMscOML = nullptr;
	_vdgl_wglSwapLayerBuffersMscOML = nullptr;
	_vdgl_wglWaitForMscOML = nullptr;
	_vdgl_wglWaitForSbcOML = nullptr;
}

#endif // VDGL_PLATFORM_WINDOWS
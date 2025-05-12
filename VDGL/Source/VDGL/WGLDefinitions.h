#pragma once

#include "Core.h"
#ifdef VDGL_PLATFORM_WINDOWS

#include "GLDefinitions.h"

#define VDGL_WGL_FN(returnType, name, parameters, arguments) VDGL_FN(returnType, WINAPI, name, parameters, arguments)

//////
////// WGL
//////

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>
#endif

#define WGL_WGLEXT_VERSION 20250203
#define WGL_FRONT_COLOR_BUFFER_BIT_ARB 0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB 0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB 0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB 0x00000008
#define WGL_CONTEXT_RELEASE_BEHAVIOR_ARB 0x2097
#define WGL_CONTEXT_RELEASE_BEHAVIOR_NONE_ARB 0
#define WGL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB 0x2098
#define WGL_CONTEXT_DEBUG_BIT_ARB 0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB 0x00000002
#define WGL_CONTEXT_MAJOR_VERSION_ARB 0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB 0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB 0x2093
#define WGL_CONTEXT_FLAGS_ARB 0x2094
#define ERROR_INVALID_VERSION_ARB 0x2095
#define WGL_CONTEXT_OPENGL_NO_ERROR_ARB 0x31B3
#define WGL_CONTEXT_PROFILE_MASK_ARB 0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB 0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002
#define ERROR_INVALID_PROFILE_ARB 0x2096
#define WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB 0x00000004
#define WGL_LOSE_CONTEXT_ON_RESET_ARB 0x8252
#define WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB 0x8256
#define WGL_NO_RESET_NOTIFICATION_ARB 0x8261
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB 0x20A9
#define ERROR_INVALID_PIXEL_TYPE_ARB 0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB 0x2054
#define WGL_SAMPLE_BUFFERS_ARB 0x2041
#define WGL_SAMPLES_ARB 0x2042
#define WGL_DRAW_TO_PBUFFER_ARB 0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB 0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB 0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB 0x2030
#define WGL_PBUFFER_LARGEST_ARB 0x2033
#define WGL_PBUFFER_WIDTH_ARB 0x2034
#define WGL_PBUFFER_HEIGHT_ARB 0x2035
#define WGL_PBUFFER_LOST_ARB 0x2036
#define WGL_NUMBER_PIXEL_FORMATS_ARB 0x2000
#define WGL_DRAW_TO_WINDOW_ARB 0x2001
#define WGL_DRAW_TO_BITMAP_ARB 0x2002
#define WGL_ACCELERATION_ARB 0x2003
#define WGL_NEED_PALETTE_ARB 0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB 0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB 0x2006
#define WGL_SWAP_METHOD_ARB 0x2007
#define WGL_NUMBER_OVERLAYS_ARB 0x2008
#define WGL_NUMBER_UNDERLAYS_ARB 0x2009
#define WGL_TRANSPARENT_ARB 0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB 0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB 0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB 0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB 0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB 0x203B
#define WGL_SHARE_DEPTH_ARB 0x200C
#define WGL_SHARE_STENCIL_ARB 0x200D
#define WGL_SHARE_ACCUM_ARB 0x200E
#define WGL_SUPPORT_GDI_ARB 0x200F
#define WGL_SUPPORT_OPENGL_ARB 0x2010
#define WGL_DOUBLE_BUFFER_ARB 0x2011
#define WGL_STEREO_ARB 0x2012
#define WGL_PIXEL_TYPE_ARB 0x2013
#define WGL_COLOR_BITS_ARB 0x2014
#define WGL_RED_BITS_ARB 0x2015
#define WGL_RED_SHIFT_ARB 0x2016
#define WGL_GREEN_BITS_ARB 0x2017
#define WGL_GREEN_SHIFT_ARB 0x2018
#define WGL_BLUE_BITS_ARB 0x2019
#define WGL_BLUE_SHIFT_ARB 0x201A
#define WGL_ALPHA_BITS_ARB 0x201B
#define WGL_ALPHA_SHIFT_ARB 0x201C
#define WGL_ACCUM_BITS_ARB 0x201D
#define WGL_ACCUM_RED_BITS_ARB 0x201E
#define WGL_ACCUM_GREEN_BITS_ARB 0x201F
#define WGL_ACCUM_BLUE_BITS_ARB 0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB 0x2021
#define WGL_DEPTH_BITS_ARB 0x2022
#define WGL_STENCIL_BITS_ARB 0x2023
#define WGL_AUX_BUFFERS_ARB 0x2024
#define WGL_NO_ACCELERATION_ARB 0x2025
#define WGL_GENERIC_ACCELERATION_ARB 0x2026
#define WGL_FULL_ACCELERATION_ARB 0x2027
#define WGL_SWAP_EXCHANGE_ARB 0x2028
#define WGL_SWAP_COPY_ARB 0x2029
#define WGL_SWAP_UNDEFINED_ARB 0x202A
#define WGL_TYPE_RGBA_ARB 0x202B
#define WGL_TYPE_COLORINDEX_ARB 0x202C
#define WGL_TYPE_RGBA_FLOAT_ARB 0x21A0
#define WGL_BIND_TO_TEXTURE_RGB_ARB 0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB 0x2071
#define WGL_TEXTURE_FORMAT_ARB 0x2072
#define WGL_TEXTURE_TARGET_ARB 0x2073
#define WGL_MIPMAP_TEXTURE_ARB 0x2074
#define WGL_TEXTURE_RGB_ARB 0x2075
#define WGL_TEXTURE_RGBA_ARB 0x2076
#define WGL_NO_TEXTURE_ARB 0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB 0x2078
#define WGL_TEXTURE_1D_ARB 0x2079
#define WGL_TEXTURE_2D_ARB 0x207A
#define WGL_MIPMAP_LEVEL_ARB 0x207B
#define WGL_CUBE_MAP_FACE_ARB 0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB 0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB 0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB 0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB 0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB 0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB 0x2082
#define WGL_FRONT_LEFT_ARB 0x2083
#define WGL_FRONT_RIGHT_ARB 0x2084
#define WGL_BACK_LEFT_ARB 0x2085
#define WGL_BACK_RIGHT_ARB 0x2086
#define WGL_AUX0_ARB 0x2087
#define WGL_AUX1_ARB 0x2088
#define WGL_AUX2_ARB 0x2089
#define WGL_AUX3_ARB 0x208A
#define WGL_AUX4_ARB 0x208B
#define WGL_AUX5_ARB 0x208C
#define WGL_AUX6_ARB 0x208D
#define WGL_AUX7_ARB 0x208E
#define WGL_AUX8_ARB 0x208F
#define WGL_AUX9_ARB 0x2090
#define WGL_CONTEXT_RESET_ISOLATION_BIT_ARB 0x00000008
#define WGL_SAMPLE_BUFFERS_3DFX 0x2060
#define WGL_SAMPLES_3DFX 0x2061
#define WGL_STEREO_EMITTER_ENABLE_3DL 0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL 0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL 0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL 0x2058
#define WGL_GPU_VENDOR_AMD 0x1F00
#define WGL_GPU_RENDERER_STRING_AMD 0x1F01
#define WGL_GPU_OPENGL_VERSION_STRING_AMD 0x1F02
#define WGL_GPU_FASTEST_TARGET_GPUS_AMD 0x21A2
#define WGL_GPU_RAM_AMD 0x21A3
#define WGL_GPU_CLOCK_AMD 0x21A4
#define WGL_GPU_NUM_PIPES_AMD 0x21A5
#define WGL_GPU_NUM_SIMD_AMD 0x21A6
#define WGL_GPU_NUM_RB_AMD 0x21A7
#define WGL_GPU_NUM_SPI_AMD 0x21A8
#define WGL_TYPE_RGBA_FLOAT_ATI 0x21A0
#define WGL_TEXTURE_RECTANGLE_ATI 0x21A5
#define WGL_COLORSPACE_EXT 0x309D
#define WGL_COLORSPACE_SRGB_EXT 0x3089
#define WGL_COLORSPACE_LINEAR_EXT 0x308A
#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT 0x00000004
#define WGL_CONTEXT_ES_PROFILE_BIT_EXT 0x00000004
#define WGL_DEPTH_FLOAT_EXT 0x2040
#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT 0x20A9
#define ERROR_INVALID_PIXEL_TYPE_EXT 0x2043
#define WGL_SAMPLE_BUFFERS_EXT 0x2041
#define WGL_SAMPLES_EXT 0x2042
#define WGL_DRAW_TO_PBUFFER_EXT 0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT 0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT 0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT 0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT 0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT 0x2032
#define WGL_PBUFFER_LARGEST_EXT 0x2033
#define WGL_PBUFFER_WIDTH_EXT 0x2034
#define WGL_PBUFFER_HEIGHT_EXT 0x2035
#define WGL_NUMBER_PIXEL_FORMATS_EXT 0x2000
#define WGL_DRAW_TO_WINDOW_EXT 0x2001
#define WGL_DRAW_TO_BITMAP_EXT 0x2002
#define WGL_ACCELERATION_EXT 0x2003
#define WGL_NEED_PALETTE_EXT 0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT 0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT 0x2006
#define WGL_SWAP_METHOD_EXT 0x2007
#define WGL_NUMBER_OVERLAYS_EXT 0x2008
#define WGL_NUMBER_UNDERLAYS_EXT 0x2009
#define WGL_TRANSPARENT_EXT 0x200A
#define WGL_TRANSPARENT_VALUE_EXT 0x200B
#define WGL_SHARE_DEPTH_EXT 0x200C
#define WGL_SHARE_STENCIL_EXT 0x200D
#define WGL_SHARE_ACCUM_EXT 0x200E
#define WGL_SUPPORT_GDI_EXT 0x200F
#define WGL_SUPPORT_OPENGL_EXT 0x2010
#define WGL_DOUBLE_BUFFER_EXT 0x2011
#define WGL_STEREO_EXT 0x2012
#define WGL_PIXEL_TYPE_EXT 0x2013
#define WGL_COLOR_BITS_EXT 0x2014
#define WGL_RED_BITS_EXT 0x2015
#define WGL_RED_SHIFT_EXT 0x2016
#define WGL_GREEN_BITS_EXT 0x2017
#define WGL_GREEN_SHIFT_EXT 0x2018
#define WGL_BLUE_BITS_EXT 0x2019
#define WGL_BLUE_SHIFT_EXT 0x201A
#define WGL_ALPHA_BITS_EXT 0x201B
#define WGL_ALPHA_SHIFT_EXT 0x201C
#define WGL_ACCUM_BITS_EXT 0x201D
#define WGL_ACCUM_RED_BITS_EXT 0x201E
#define WGL_ACCUM_GREEN_BITS_EXT 0x201F
#define WGL_ACCUM_BLUE_BITS_EXT 0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT 0x2021
#define WGL_DEPTH_BITS_EXT 0x2022
#define WGL_STENCIL_BITS_EXT 0x2023
#define WGL_AUX_BUFFERS_EXT 0x2024
#define WGL_NO_ACCELERATION_EXT 0x2025
#define WGL_GENERIC_ACCELERATION_EXT 0x2026
#define WGL_FULL_ACCELERATION_EXT 0x2027
#define WGL_SWAP_EXCHANGE_EXT 0x2028
#define WGL_SWAP_COPY_EXT 0x2029
#define WGL_SWAP_UNDEFINED_EXT 0x202A
#define WGL_TYPE_RGBA_EXT 0x202B
#define WGL_TYPE_COLORINDEX_EXT 0x202C
#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT 0x20A8
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D 0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D 0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D 0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D 0x2053
#define WGL_GAMMA_TABLE_SIZE_I3D 0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D 0x204F
#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D 0x2044
#define WGL_GENLOCK_SOURCE_EXTERNAL_SYNC_I3D 0x2045
#define WGL_GENLOCK_SOURCE_EXTERNAL_FIELD_I3D 0x2046
#define WGL_GENLOCK_SOURCE_EXTERNAL_TTL_I3D 0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D 0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D 0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D 0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D 0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D 0x204C
#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D 0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D 0x00000002
#define WGL_ACCESS_READ_ONLY_NV 0x00000000
#define WGL_ACCESS_READ_WRITE_NV 0x00000001
#define WGL_ACCESS_WRITE_DISCARD_NV 0x00000002
#define WGL_FLOAT_COMPONENTS_NV 0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV 0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV 0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV 0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV 0x20B4
#define WGL_TEXTURE_FLOAT_R_NV 0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV 0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV 0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV 0x20B8
#define ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV 0x20D0
#define ERROR_MISSING_AFFINITY_MASK_NV 0x20D1
#define WGL_CONTEXT_MULTIGPU_ATTRIB_NV 0x20AA
#define WGL_CONTEXT_MULTIGPU_ATTRIB_SINGLE_NV 0x20AB
#define WGL_CONTEXT_MULTIGPU_ATTRIB_AFR_NV 0x20AC
#define WGL_CONTEXT_MULTIGPU_ATTRIB_MULTICAST_NV 0x20AD
#define WGL_CONTEXT_MULTIGPU_ATTRIB_MULTI_DISPLAY_MULTICAST_NV 0x20AE
#define WGL_COVERAGE_SAMPLES_NV 0x2042
#define WGL_COLOR_SAMPLES_NV 0x20B9
#define WGL_NUM_VIDEO_SLOTS_NV 0x20F0
#define WGL_BIND_TO_TEXTURE_DEPTH_NV 0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV 0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV 0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV 0x20A6
#define WGL_DEPTH_COMPONENT_NV 0x20A7
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV 0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV 0x20A1
#define WGL_TEXTURE_RECTANGLE_NV 0x20A2
#define WGL_UNIQUE_ID_NV 0x20CE
#define WGL_NUM_VIDEO_CAPTURE_SLOTS_NV 0x20CF
#define WGL_BIND_TO_VIDEO_RGB_NV 0x20C0
#define WGL_BIND_TO_VIDEO_RGBA_NV 0x20C1
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV 0x20C2
#define WGL_VIDEO_OUT_COLOR_NV 0x20C3
#define WGL_VIDEO_OUT_ALPHA_NV 0x20C4
#define WGL_VIDEO_OUT_DEPTH_NV 0x20C5
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV 0x20C6
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV 0x20C7
#define WGL_VIDEO_OUT_FRAME 0x20C8
#define WGL_VIDEO_OUT_FIELD_1 0x20C9
#define WGL_VIDEO_OUT_FIELD_2 0x20CA
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2 0x20CB
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1 0x20CC

DECLARE_HANDLE(HPBUFFERARB);
DECLARE_HANDLE(HPBUFFEREXT);
DECLARE_HANDLE(HGPUNV);
DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
DECLARE_HANDLE(HPVIDEODEV);

struct _GPU_DEVICE {
    DWORD  cb;
    CHAR   DeviceName[32];
    CHAR   DeviceString[128];
    DWORD  Flags;
    RECT   rcVirtualScreen;
};
typedef struct _GPU_DEVICE* PGPU_DEVICE;

VDGL_WGL_FN(HANDLE, wglCreateBufferRegionARB, (HDC hDC, int iLayerPlane, UINT uType), (hDC, iLayerPlane, uType));
VDGL_WGL_FN(VOID, wglDeleteBufferRegionARB, (HANDLE hRegion), (hRegion));
VDGL_WGL_FN(BOOL, wglSaveBufferRegionARB, (HANDLE hRegion, int x, int y, int width, int height), (hRegion, x, y, width, height));
VDGL_WGL_FN(BOOL, wglRestoreBufferRegionARB, (HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc), (hRegion, x, y, width, height, xSrc, ySrc));
VDGL_WGL_FN(HGLRC, wglCreateContextAttribsARB, (HDC hDC, HGLRC hShareContext, const int* attribList), (hDC, hShareContext, attribList));
VDGL_WGL_FN(const char*, wglGetExtensionsStringARB, (HDC hdc), (hdc));
VDGL_WGL_FN(BOOL, wglMakeContextCurrentARB, (HDC hDrawDC, HDC hReadDC, HGLRC hglrc), (hDrawDC, hReadDC, hglrc));
VDGL_WGL_FN(HDC, wglGetCurrentReadDCARB, (void), ());
VDGL_WGL_FN(HPBUFFERARB, wglCreatePbufferARB, (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList), (hDC, iPixelFormat, iWidth, iHeight, piAttribList));
VDGL_WGL_FN(HDC, wglGetPbufferDCARB, (HPBUFFERARB hPbuffer), (hPbuffer));
VDGL_WGL_FN(int, wglReleasePbufferDCARB, (HPBUFFERARB hPbuffer, HDC hDC), (hPbuffer, hDC));
VDGL_WGL_FN(BOOL, wglDestroyPbufferARB, (HPBUFFERARB hPbuffer), (hPbuffer));
VDGL_WGL_FN(BOOL, wglQueryPbufferARB, (HPBUFFERARB hPbuffer, int iAttribute, int* piValue), (hPbuffer, iAttribute, piValue));
VDGL_WGL_FN(BOOL, wglGetPixelFormatAttribivARB, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, int* piValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues));
VDGL_WGL_FN(BOOL, wglGetPixelFormatAttribfvARB, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int* piAttributes, FLOAT* pfValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues));
VDGL_WGL_FN(BOOL, wglChoosePixelFormatARB, (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats), (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats));
VDGL_WGL_FN(BOOL, wglBindTexImageARB, (HPBUFFERARB hPbuffer, int iBuffer), (hPbuffer, iBuffer));
VDGL_WGL_FN(BOOL, wglReleaseTexImageARB, (HPBUFFERARB hPbuffer, int iBuffer), (hPbuffer, iBuffer));
VDGL_WGL_FN(BOOL, wglSetPbufferAttribARB, (HPBUFFERARB hPbuffer, const int* piAttribList), (hPbuffer, piAttribList));
VDGL_WGL_FN(BOOL, wglSetStereoEmitterState3DL, (HDC hDC, UINT uState), (hDC, uState));
VDGL_WGL_FN(UINT, wglGetGPUIDsAMD, (UINT maxCount, UINT* ids), (maxCount, ids));
VDGL_WGL_FN(INT, wglGetGPUInfoAMD, (UINT id, INT property, GLenum dataType, UINT size, void* data), (id, property, dataType, size, data));
VDGL_WGL_FN(UINT, wglGetContextGPUIDAMD, (HGLRC hglrc), (hglrc));
VDGL_WGL_FN(HGLRC, wglCreateAssociatedContextAMD, (UINT id), (id));
VDGL_WGL_FN(HGLRC, wglCreateAssociatedContextAttribsAMD, (UINT id, HGLRC hShareContext, const int* attribList), (id, hShareContext,attribList));
VDGL_WGL_FN(BOOL, wglDeleteAssociatedContextAMD, (HGLRC hglrc), (hglrc));
VDGL_WGL_FN(BOOL, wglMakeAssociatedContextCurrentAMD, (HGLRC hglrc), (hglrc));
VDGL_WGL_FN(HGLRC, wglGetCurrentAssociatedContextAMD, (void), ());
VDGL_WGL_FN(VOID, wglBlitContextFramebufferAMD, (HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter), (dstCtx, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter));
VDGL_WGL_FN(GLboolean, wglCreateDisplayColorTableEXT, (GLushort id), (id));
VDGL_WGL_FN(GLboolean, wglLoadDisplayColorTableEXT, (const GLushort* table, GLuint length), (table, length));
VDGL_WGL_FN(GLboolean, wglBindDisplayColorTableEXT, (GLushort id), (id));
VDGL_WGL_FN(VOID, wglDestroyDisplayColorTableEXT, (GLushort id), (id));
VDGL_WGL_FN(const char*, wglGetExtensionsStringEXT, (void), ());
VDGL_WGL_FN(BOOL, wglMakeContextCurrentEXT, (HDC hDrawDC, HDC hReadDC, HGLRC hglrc), (hDrawDC, hReadDC, hglrc));
VDGL_WGL_FN(HDC, wglGetCurrentReadDCEXT, (void), ());
VDGL_WGL_FN(HPBUFFEREXT, wglCreatePbufferEXT, (HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int* piAttribList), (hDC, iPixelFormat, iWidth, iHeight, piAttribList));
VDGL_WGL_FN(HDC, wglGetPbufferDCEXT, (HPBUFFEREXT hPbuffer), (hPbuffer));
VDGL_WGL_FN(int, wglReleasePbufferDCEXT, (HPBUFFEREXT hPbuffer, HDC hDC), (hPbuffer, hDC));
VDGL_WGL_FN(BOOL, wglDestroyPbufferEXT, (HPBUFFEREXT hPbuffer), (hPbuffer));
VDGL_WGL_FN(BOOL, wglQueryPbufferEXT, (HPBUFFEREXT hPbuffer, int iAttribute, int* piValue), (hPbuffer, iAttribute, piValue));
VDGL_WGL_FN(BOOL, wglGetPixelFormatAttribivEXT, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, int* piValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, piValues));
VDGL_WGL_FN(BOOL, wglGetPixelFormatAttribfvEXT, (HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int* piAttributes, FLOAT* pfValues), (hdc, iPixelFormat, iLayerPlane, nAttributes, piAttributes, pfValues));
VDGL_WGL_FN(BOOL, wglChoosePixelFormatEXT, (HDC hdc, const int* piAttribIList, const FLOAT* pfAttribFList, UINT nMaxFormats, int* piFormats, UINT* nNumFormats), (hdc, piAttribIList, pfAttribFList, nMaxFormats, piFormats, nNumFormats));
VDGL_WGL_FN(BOOL, wglSwapIntervalEXT, (int interval), (interval));
VDGL_WGL_FN(int, wglGetSwapIntervalEXT, (void), ());
VDGL_WGL_FN(BOOL, wglGetDigitalVideoParametersI3D, (HDC hDC, int iAttribute, int* piValue), (hDC, iAttribute, piValue));
VDGL_WGL_FN(BOOL, wglSetDigitalVideoParametersI3D, (HDC hDC, int iAttribute, const int* piValue), (hDC, iAttribute, piValue));
VDGL_WGL_FN(BOOL, wglGetGammaTableParametersI3D, (HDC hDC, int iAttribute, int* piValue), (hDC, iAttribute, piValue));
VDGL_WGL_FN(BOOL, wglSetGammaTableParametersI3D, (HDC hDC, int iAttribute, const int* piValue), (hDC, iAttribute, piValue));
VDGL_WGL_FN(BOOL, wglGetGammaTableI3D, (HDC hDC, int iEntries, USHORT* puRed, USHORT* puGreen, USHORT* puBlue), (hDC, iEntries, puRed, puGreen, puBlue));
VDGL_WGL_FN(BOOL, wglSetGammaTableI3D, (HDC hDC, int iEntries, const USHORT* puRed, const USHORT* puGreen, const USHORT* puBlue), (hDC, iEntries, puRed, puGreen, puBlue));
VDGL_WGL_FN(BOOL, wglEnableGenlockI3D, (HDC hDC), (hDC));
VDGL_WGL_FN(BOOL, wglDisableGenlockI3D, (HDC hDC), (hDC));
VDGL_WGL_FN(BOOL, wglIsEnabledGenlockI3D, (HDC hDC, BOOL* pFlag), (hDC, pFlag));
VDGL_WGL_FN(BOOL, wglGenlockSourceI3D, (HDC hDC, UINT uSource), (hDC, uSource));
VDGL_WGL_FN(BOOL, wglGetGenlockSourceI3D, (HDC hDC, UINT* uSource), (hDC, uSource));
VDGL_WGL_FN(BOOL, wglGenlockSourceEdgeI3D, (HDC hDC, UINT uEdge), (hDC, uEdge));
VDGL_WGL_FN(BOOL, wglGetGenlockSourceEdgeI3D, (HDC hDC, UINT* uEdge), (hDC, uEdge));
VDGL_WGL_FN(BOOL, wglGenlockSampleRateI3D, (HDC hDC, UINT uRate), (hDC, uRate));
VDGL_WGL_FN(BOOL, wglGetGenlockSampleRateI3D, (HDC hDC, UINT* uRate), (hDC, uRate));
VDGL_WGL_FN(BOOL, wglGenlockSourceDelayI3D, (HDC hDC, UINT uDelay), (hDC, uDelay));
VDGL_WGL_FN(BOOL, wglGetGenlockSourceDelayI3D, (HDC hDC, UINT* uDelay), (hDC, uDelay));
VDGL_WGL_FN(BOOL, wglQueryGenlockMaxSourceDelayI3D, (HDC hDC, UINT* uMaxLineDelay, UINT* uMaxPixelDelay), (hDC, uMaxLineDelay, uMaxPixelDelay));
VDGL_WGL_FN(LPVOID, wglCreateImageBufferI3D, (HDC hDC, DWORD dwSize, UINT uFlags), (hDC, dwSize, uFlags));
VDGL_WGL_FN(BOOL, wglDestroyImageBufferI3D, (HDC hDC, LPVOID pAddress), (hDC, pAddress));
VDGL_WGL_FN(BOOL, wglAssociateImageBufferEventsI3D, (HDC hDC, const HANDLE* pEvent, const LPVOID* pAddress, const DWORD* pSize, UINT count), (hDC, pEvent, pAddress, pSize, count));
VDGL_WGL_FN(BOOL, wglReleaseImageBufferEventsI3D, (HDC hDC, const LPVOID* pAddress, UINT count), (hDC, pAddress, count));
VDGL_WGL_FN(BOOL, wglEnableFrameLockI3D, (void), ());
VDGL_WGL_FN(BOOL, wglDisableFrameLockI3D, (void), ());
VDGL_WGL_FN(BOOL, wglIsEnabledFrameLockI3D, (BOOL* pFlag), (pFlag));
VDGL_WGL_FN(BOOL, wglQueryFrameLockMasterI3D, (BOOL* pFlag), (pFlag));
VDGL_WGL_FN(BOOL, wglGetFrameUsageI3D, (float* pUsage), (pUsage));
VDGL_WGL_FN(BOOL, wglBeginFrameTrackingI3D, (void), ());
VDGL_WGL_FN(BOOL, wglEndFrameTrackingI3D, (void), ());
VDGL_WGL_FN(BOOL, wglQueryFrameTrackingI3D, (DWORD* pFrameCount, DWORD* pMissedFrames, float* pLastMissedUsage), (pFrameCount, pMissedFrames, pLastMissedUsage));
VDGL_WGL_FN(BOOL, wglDXSetResourceShareHandleNV, (void* dxObject, HANDLE shareHandle), (dxObject, shareHandle));
VDGL_WGL_FN(HANDLE, wglDXOpenDeviceNV, (void* dxDevice), (dxDevice));
VDGL_WGL_FN(BOOL, wglDXCloseDeviceNV, (HANDLE hDevice), (hDevice));
VDGL_WGL_FN(HANDLE, wglDXRegisterObjectNV, (HANDLE hDevice, void* dxObject, GLuint name, GLenum type, GLenum access), (hDevice, dxObject, name, type, access));
VDGL_WGL_FN(BOOL, wglDXUnregisterObjectNV, (HANDLE hDevice, HANDLE hObject), (hDevice, hObject));
VDGL_WGL_FN(BOOL, wglDXObjectAccessNV, (HANDLE hObject, GLenum access), (hObject, access));
VDGL_WGL_FN(BOOL, wglDXLockObjectsNV, (HANDLE hDevice, GLint count, HANDLE* hObjects), (hDevice, count, hObjects));
VDGL_WGL_FN(BOOL, wglDXUnlockObjectsNV, (HANDLE hDevice, GLint count, HANDLE* hObjects), (hDevice, count, hObjects));
VDGL_WGL_FN(BOOL, wglCopyImageSubDataNV, (HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth), (hSrcRC, srcName, srcTarget, srcLevel, srcX, srcY, srcZ, hDstRC, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, width, height, depth));
VDGL_WGL_FN(BOOL, wglDelayBeforeSwapNV, (HDC hDC, GLfloat seconds), (hDC, seconds));
VDGL_WGL_FN(BOOL, wglEnumGpusNV, (UINT iGpuIndex, HGPUNV* phGpu), (iGpuIndex, phGpu));
VDGL_WGL_FN(BOOL, wglEnumGpuDevicesNV, (HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice), (hGpu, iDeviceIndex, lpGpuDevice));
VDGL_WGL_FN(HDC, wglCreateAffinityDCNV, (const HGPUNV* phGpuList), (phGpuList));
VDGL_WGL_FN(BOOL, wglEnumGpusFromAffinityDCNV, (HDC hAffinityDC, UINT iGpuIndex, HGPUNV* hGpu), (hAffinityDC, iGpuIndex, hGpu));
VDGL_WGL_FN(BOOL, wglDeleteDCNV, (HDC hdc), (hdc));
VDGL_WGL_FN(int, wglEnumerateVideoDevicesNV, (HDC hDc, HVIDEOOUTPUTDEVICENV* phDeviceList), (hDc, phDeviceList));
VDGL_WGL_FN(BOOL, wglBindVideoDeviceNV, (HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int* piAttribList), (hDc, uVideoSlot, hVideoDevice, piAttribList));
VDGL_WGL_FN(BOOL, wglQueryCurrentContextNV, (int iAttribute, int* piValue), (iAttribute, piValue));
VDGL_WGL_FN(BOOL, wglJoinSwapGroupNV, (HDC hDC, GLuint group), (hDC, group));
VDGL_WGL_FN(BOOL, wglBindSwapBarrierNV, (GLuint group, GLuint barrier), (group, barrier));
VDGL_WGL_FN(BOOL, wglQuerySwapGroupNV, (HDC hDC, GLuint* group, GLuint* barrier), (hDC, group, barrier));
VDGL_WGL_FN(BOOL, wglQueryMaxSwapGroupsNV, (HDC hDC, GLuint* maxGroups, GLuint* maxBarriers), (hDC, maxGroups, maxBarriers));
VDGL_WGL_FN(BOOL, wglQueryFrameCountNV, (HDC hDC, GLuint* count), (hDC, count));
VDGL_WGL_FN(BOOL, wglResetFrameCountNV, (HDC hDC), (hDC));
VDGL_WGL_FN(void*, wglAllocateMemoryNV, (GLsizei size, GLfloat readfreq, GLfloat writefreq, GLfloat priority), (size, readfreq, writefreq, priority));
VDGL_WGL_FN(void, wglFreeMemoryNV, (void* pointer), (pointer));
VDGL_WGL_FN(BOOL, wglBindVideoCaptureDeviceNV, (UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice), (uVideoSlot, hDevice));
VDGL_WGL_FN(UINT, wglEnumerateVideoCaptureDevicesNV, (HDC hDc, HVIDEOINPUTDEVICENV* phDeviceList), (hDc, phDeviceList));
VDGL_WGL_FN(BOOL, wglLockVideoCaptureDeviceNV, (HDC hDc, HVIDEOINPUTDEVICENV hDevice), (hDc, hDevice));
VDGL_WGL_FN(BOOL, wglQueryVideoCaptureDeviceNV, (HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int* piValue), (hDc, hDevice, iAttribute, piValue));
VDGL_WGL_FN(BOOL, wglReleaseVideoCaptureDeviceNV, (HDC hDc, HVIDEOINPUTDEVICENV hDevice), (hDc, hDevice));
VDGL_WGL_FN(BOOL, wglGetVideoDeviceNV, (HDC hDC, int numDevices, HPVIDEODEV* hVideoDevice), (hDC, numDevices, hVideoDevice));
VDGL_WGL_FN(BOOL, wglReleaseVideoDeviceNV, (HPVIDEODEV hVideoDevice), (hVideoDevice));
VDGL_WGL_FN(BOOL, wglBindVideoImageNV, (HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer), (hVideoDevice, hPbuffer, iVideoBuffer));
VDGL_WGL_FN(BOOL, wglReleaseVideoImageNV, (HPBUFFERARB hPbuffer, int iVideoBuffer), (hPbuffer, iVideoBuffer));
VDGL_WGL_FN(BOOL, wglSendPbufferToVideoNV, (HPBUFFERARB hPbuffer, int iBufferType, unsigned long* pulCounterPbuffer, BOOL bBlock), (hPbuffer, iBufferType, pulCounterPbuffer, bBlock));
VDGL_WGL_FN(BOOL, wglGetVideoInfoNV, (HPVIDEODEV hpVideoDevice, unsigned long* pulCounterOutputPbuffer, unsigned long* pulCounterOutputVideo), (hpVideoDevice, pulCounterOutputPbuffer, pulCounterOutputVideo));
VDGL_WGL_FN(BOOL, wglGetSyncValuesOML, (HDC hdc, INT64* ust, INT64* msc, INT64* sbc), (hdc, ust, msc, sbc));
VDGL_WGL_FN(BOOL, wglGetMscRateOML, (HDC hdc, INT32* numerator, INT32* denominator), (hdc, numerator, denominator));
VDGL_WGL_FN(INT64, wglSwapBuffersMscOML, (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder), (hdc, target_msc, divisor, remainder));
VDGL_WGL_FN(INT64, wglSwapLayerBuffersMscOML, (HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder), (hdc, fuPlanes, target_msc, divisor, remainder));
VDGL_WGL_FN(BOOL, wglWaitForMscOML, (HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64* ust, INT64* msc, INT64* sbc), (hdc, target_msc, divisor, remainder, ust, msc, sbc));
VDGL_WGL_FN(BOOL, wglWaitForSbcOML, (HDC hdc, INT64 target_sbc, INT64* ust, INT64* msc, INT64* sbc), (hdc, target_sbc, ust, msc, sbc));

#endif // VDGL_PLATFORM_WINDOWS
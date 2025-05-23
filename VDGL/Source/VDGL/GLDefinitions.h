#pragma once

#include "Core.h"
#define VDGL_GL_FN(returnType, name, parameters, arguments) VDGL_FN(returnType, , name, parameters, arguments)

//////
////// CoreARB
//////

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

//////
////// KHR
//////

#ifndef __khrplatform_h_
#define __khrplatform_h_

/*
** Copyright (c) 2008-2018 The Khronos Group Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and/or associated documentation files (the
** "Materials"), to deal in the Materials without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Materials, and to
** permit persons to whom the Materials are furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Materials.
**
** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
*/

/* Khronos platform-specific types and definitions.
 *
 * The master copy of khrplatform.h is maintained in the Khronos EGL
 * Registry repository at https://github.com/KhronosGroup/EGL-Registry
 * The last semantic modification to khrplatform.h was at commit ID:
 *      67a3e0864c2d75ea5287b9f3d2eb74a745936692
 *
 * Adopters may modify this file to suit their platform. Adopters are
 * encouraged to submit platform specific modifications to the Khronos
 * group so that they can be included in future versions of this file.
 * Please submit changes by filing pull requests or issues on
 * the EGL Registry repository linked above.
 *
 *
 * See the Implementer's Guidelines for information about where this file
 * should be located on your system and for more details of its use:
 *    http://www.khronos.org/registry/implementers_guide.pdf
 *
 * This file should be included as
 *        #include <KHR/khrplatform.h>
 * by Khronos client API header files that use its types and defines.
 *
 * The types in khrplatform.h should only be used to define API-specific types.
 *
 * Types defined in khrplatform.h:
 *    khronos_int8_t              signed   8  bit
 *    khronos_uint8_t             unsigned 8  bit
 *    khronos_int16_t             signed   16 bit
 *    khronos_uint16_t            unsigned 16 bit
 *    khronos_int32_t             signed   32 bit
 *    khronos_uint32_t            unsigned 32 bit
 *    khronos_int64_t             signed   64 bit
 *    khronos_uint64_t            unsigned 64 bit
 *    khronos_intptr_t            signed   same number of bits as a pointer
 *    khronos_uintptr_t           unsigned same number of bits as a pointer
 *    khronos_ssize_t             signed   size
 *    khronos_usize_t             unsigned size
 *    khronos_float_t             signed   32 bit floating point
 *    khronos_time_ns_t           unsigned 64 bit time in nanoseconds
 *    khronos_utime_nanoseconds_t unsigned time interval or absolute time in
 *                                         nanoseconds
 *    khronos_stime_nanoseconds_t signed time interval in nanoseconds
 *    khronos_boolean_enum_t      enumerated boolean type. This should
 *      only be used as a base type when a client API's boolean type is
 *      an enum. Client APIs which use an integer or other type for
 *      booleans cannot use this as the base type for their boolean.
 *
 * Tokens defined in khrplatform.h:
 *
 *    KHRONOS_FALSE, KHRONOS_TRUE Enumerated boolean false/true values.
 *
 *    KHRONOS_SUPPORT_INT64 is 1 if 64 bit integers are supported; otherwise 0.
 *    KHRONOS_SUPPORT_FLOAT is 1 if floats are supported; otherwise 0.
 *
 * Calling convention macros defined in this file:
 *    KHRONOS_APICALL
 *    KHRONOS_APIENTRY
 *    KHRONOS_APIATTRIBUTES
 *
 * These may be used in function prototypes as:
 *
 *      KHRONOS_APICALL void KHRONOS_APIENTRY funcname(
 *                                  int arg1,
 *                                  int arg2) KHRONOS_APIATTRIBUTES;
 */

#if defined(__SCITECH_SNAP__) && !defined(KHRONOS_STATIC)
#   define KHRONOS_STATIC 1
#endif

 /*-------------------------------------------------------------------------
  * Definition of KHRONOS_APICALL
  *-------------------------------------------------------------------------
  * This precedes the return type of the function in the function prototype.
  */
#if defined(KHRONOS_STATIC)
  /* If the preprocessor constant KHRONOS_STATIC is defined, make the
   * header compatible with static linking. */
#   define KHRONOS_APICALL
#elif defined(_WIN32)
#   define KHRONOS_APICALL __declspec(dllimport)
#elif defined (__SYMBIAN32__)
#   define KHRONOS_APICALL IMPORT_C
#elif defined(__ANDROID__)
#   define KHRONOS_APICALL __attribute__((visibility("default")))
#else
#   define KHRONOS_APICALL
#endif

  /*-------------------------------------------------------------------------
   * Definition of KHRONOS_APIENTRY
   *-------------------------------------------------------------------------
   * This follows the return type of the function  and precedes the function
   * name in the function prototype.
   */
#if defined(_WIN32) && !defined(_WIN32_WCE) && !defined(__SCITECH_SNAP__)
   /* Win32 but not WinCE */
#   define KHRONOS_APIENTRY __stdcall
#else
#   define KHRONOS_APIENTRY
#endif

   /*-------------------------------------------------------------------------
	* Definition of KHRONOS_APIATTRIBUTES
	*-------------------------------------------------------------------------
	* This follows the closing parenthesis of the function prototype arguments.
	*/
#if defined (__ARMCC_2__)
#define KHRONOS_APIATTRIBUTES __softfp
#else
#define KHRONOS_APIATTRIBUTES
#endif

	/*-------------------------------------------------------------------------
	 * basic type definitions
	 *-----------------------------------------------------------------------*/
#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || defined(__GNUC__) || defined(__SCO__) || defined(__USLC__)


	 /*
	  * Using <stdint.h>
	  */
#include <stdint.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1
/*
 * To support platform where unsigned long cannot be used interchangeably with
 * inptr_t (e.g. CHERI-extended ISAs), we can use the stdint.h intptr_t.
 * Ideally, we could just use (u)intptr_t everywhere, but this could result in
 * ABI breakage if khronos_uintptr_t is changed from unsigned long to
 * unsigned long long or similar (this results in different C++ name mangling).
 * To avoid changes for existing platforms, we restrict usage of intptr_t to
 * platforms where the size of a pointer is larger than the size of long.
 */
#if defined(__SIZEOF_LONG__) && defined(__SIZEOF_POINTER__)
#if __SIZEOF_POINTER__ > __SIZEOF_LONG__
#define KHRONOS_USE_INTPTR_T
#endif
#endif

#elif defined(__VMS ) || defined(__sgi)

	 /*
	  * Using <inttypes.h>
	  */
#include <inttypes.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(_WIN32) && !defined(__SCITECH_SNAP__)

	 /*
	  * Win32
	  */
typedef __int32                 khronos_int32_t;
typedef unsigned __int32        khronos_uint32_t;
typedef __int64                 khronos_int64_t;
typedef unsigned __int64        khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif defined(__sun__) || defined(__digital__)

	 /*
	  * Sun or Digital
	  */
typedef int                     khronos_int32_t;
typedef unsigned int            khronos_uint32_t;
#if defined(__arch64__) || defined(_LP64)
typedef long int                khronos_int64_t;
typedef unsigned long int       khronos_uint64_t;
#else
typedef long long int           khronos_int64_t;
typedef unsigned long long int  khronos_uint64_t;
#endif /* __arch64__ */
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#elif 0

	 /*
	  * Hypothetical platform with no float or int64 support
	  */
typedef int                     khronos_int32_t;
typedef unsigned int            khronos_uint32_t;
#define KHRONOS_SUPPORT_INT64   0
#define KHRONOS_SUPPORT_FLOAT   0

#else

	 /*
	  * Generic fallback
	  */
#include <stdint.h>
typedef int32_t                 khronos_int32_t;
typedef uint32_t                khronos_uint32_t;
typedef int64_t                 khronos_int64_t;
typedef uint64_t                khronos_uint64_t;
#define KHRONOS_SUPPORT_INT64   1
#define KHRONOS_SUPPORT_FLOAT   1

#endif


/*
 * Types that are (so far) the same on all platforms
 */
typedef signed   char          khronos_int8_t;
typedef unsigned char          khronos_uint8_t;
typedef signed   short int     khronos_int16_t;
typedef unsigned short int     khronos_uint16_t;

/*
 * Types that differ between LLP64 and LP64 architectures - in LLP64,
 * pointers are 64 bits, but 'long' is still 32 bits. Win64 appears
 * to be the only LLP64 architecture in current use.
 */
#ifdef KHRONOS_USE_INTPTR_T
typedef intptr_t               khronos_intptr_t;
typedef uintptr_t              khronos_uintptr_t;
#elif defined(_WIN64)
typedef signed   long long int khronos_intptr_t;
typedef unsigned long long int khronos_uintptr_t;
#else
typedef signed   long  int     khronos_intptr_t;
typedef unsigned long  int     khronos_uintptr_t;
#endif

#if defined(_WIN64)
typedef signed   long long int khronos_ssize_t;
typedef unsigned long long int khronos_usize_t;
#else
typedef signed   long  int     khronos_ssize_t;
typedef unsigned long  int     khronos_usize_t;
#endif

#if KHRONOS_SUPPORT_FLOAT
/*
 * Float type
 */
typedef          float         khronos_float_t;
#endif

#if KHRONOS_SUPPORT_INT64
/* Time types
 *
 * These types can be used to represent a time interval in nanoseconds or
 * an absolute Unadjusted System Time.  Unadjusted System Time is the number
 * of nanoseconds since some arbitrary system event (e.g. since the last
 * time the system booted).  The Unadjusted System Time is an unsigned
 * 64 bit value that wraps back to 0 every 584 years.  Time intervals
 * may be either signed or unsigned.
 */
typedef khronos_uint64_t       khronos_utime_nanoseconds_t;
typedef khronos_int64_t        khronos_stime_nanoseconds_t;
#endif

/*
 * Dummy value used to pad enum types to 32 bits.
 */
#ifndef KHRONOS_MAX_ENUM
#define KHRONOS_MAX_ENUM 0x7FFFFFFF
#endif

 /*
  * Enumerated boolean type
  *
  * Values other than zero should be considered to be true.  Therefore
  * comparisons should not be made against KHRONOS_TRUE.
  */
typedef enum {
	KHRONOS_FALSE = 0,
	KHRONOS_TRUE = 1,
	KHRONOS_BOOLEAN_ENUM_FORCE_SIZE = KHRONOS_MAX_ENUM
} khronos_boolean_enum_t;

#endif /* __khrplatform_h_ */

//////
////// 1.0
//////

typedef void GLvoid;
typedef unsigned int GLenum;
typedef khronos_float_t GLfloat;
typedef int GLint;
typedef int GLsizei;
typedef unsigned int GLbitfield;
typedef double GLdouble;
typedef unsigned int GLuint;
typedef unsigned char GLboolean;
typedef khronos_uint8_t GLubyte;

#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_ZERO 0
#define GL_ONE 1
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_NONE 0
#define GL_FRONT_LEFT 0x0400
#define GL_FRONT_RIGHT 0x0401
#define GL_BACK_LEFT 0x0402
#define GL_BACK_RIGHT 0x0403
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_LEFT 0x0406
#define GL_RIGHT 0x0407
#define GL_FRONT_AND_BACK 0x0408
#define GL_NO_ERROR 0
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_OUT_OF_MEMORY 0x0505
#define GL_CW 0x0900
#define GL_CCW 0x0901
#define GL_POINT_SIZE 0x0B11
#define GL_POINT_SIZE_RANGE 0x0B12
#define GL_POINT_SIZE_GRANULARITY 0x0B13
#define GL_LINE_SMOOTH 0x0B20
#define GL_LINE_WIDTH 0x0B21
#define GL_LINE_WIDTH_RANGE 0x0B22
#define GL_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_POLYGON_MODE 0x0B40
#define GL_POLYGON_SMOOTH 0x0B41
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_VIEWPORT 0x0BA2
#define GL_DITHER 0x0BD0
#define GL_BLEND_DST 0x0BE0
#define GL_BLEND_SRC 0x0BE1
#define GL_BLEND 0x0BE2
#define GL_LOGIC_OP_MODE 0x0BF0
#define GL_DRAW_BUFFER 0x0C01
#define GL_READ_BUFFER 0x0C02
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_DOUBLEBUFFER 0x0C32
#define GL_STEREO 0x0C33
#define GL_LINE_SMOOTH_HINT 0x0C52
#define GL_POLYGON_SMOOTH_HINT 0x0C53
#define GL_UNPACK_SWAP_BYTES 0x0CF0
#define GL_UNPACK_LSB_FIRST 0x0CF1
#define GL_UNPACK_ROW_LENGTH 0x0CF2
#define GL_UNPACK_SKIP_ROWS 0x0CF3
#define GL_UNPACK_SKIP_PIXELS 0x0CF4
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_SWAP_BYTES 0x0D00
#define GL_PACK_LSB_FIRST 0x0D01
#define GL_PACK_ROW_LENGTH 0x0D02
#define GL_PACK_SKIP_ROWS 0x0D03
#define GL_PACK_SKIP_PIXELS 0x0D04
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_TEXTURE_1D 0x0DE0
#define GL_TEXTURE_2D 0x0DE1
#define GL_TEXTURE_WIDTH 0x1000
#define GL_TEXTURE_HEIGHT 0x1001
#define GL_TEXTURE_BORDER_COLOR 0x1004
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_STACK_OVERFLOW 0x0503
#define GL_STACK_UNDERFLOW 0x0504
#define GL_CLEAR 0x1500
#define GL_AND 0x1501
#define GL_AND_REVERSE 0x1502
#define GL_COPY 0x1503
#define GL_AND_INVERTED 0x1504
#define GL_NOOP 0x1505
#define GL_XOR 0x1506
#define GL_OR 0x1507
#define GL_NOR 0x1508
#define GL_EQUIV 0x1509
#define GL_INVERT 0x150A
#define GL_OR_REVERSE 0x150B
#define GL_COPY_INVERTED 0x150C
#define GL_OR_INVERTED 0x150D
#define GL_NAND 0x150E
#define GL_SET 0x150F
#define GL_TEXTURE 0x1702
#define GL_COLOR 0x1800
#define GL_DEPTH 0x1801
#define GL_STENCIL 0x1802
#define GL_STENCIL_INDEX 0x1901
#define GL_DEPTH_COMPONENT 0x1902
#define GL_RED 0x1903
#define GL_GREEN 0x1904
#define GL_BLUE 0x1905
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_POINT 0x1B00
#define GL_LINE 0x1B01
#define GL_FILL 0x1B02
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_REPEAT 0x2901

VDGL_GL_FN(void, glCullFace, (GLenum mode), (mode));
VDGL_GL_FN(void, glFrontFace, (GLenum mode), (mode));
VDGL_GL_FN(void, glHint, (GLenum target, GLenum mode), (target, mode));
VDGL_GL_FN(void, glLineWidth, (GLfloat width), (width));
VDGL_GL_FN(void, glPointSize, (GLfloat size), (size));
VDGL_GL_FN(void, glPolygonMode, (GLenum face, GLenum mode), (face, mode));
VDGL_GL_FN(void, glScissor, (GLint x, GLint y, GLsizei width, GLsizei height), (x, y, width, height));
VDGL_GL_FN(void, glTexParameterf, (GLenum target, GLenum pname, GLfloat param), (target, pname, param));
VDGL_GL_FN(void, glTexParameterfv, (GLenum target, GLenum pname, const GLfloat* params), (target, pname, params));
VDGL_GL_FN(void, glTexParameteri, (GLenum target, GLenum pname, GLint param), (target, pname, param));
VDGL_GL_FN(void, glTexParameteriv, (GLenum target, GLenum pname, const GLint* params), (target, pname, params));
VDGL_GL_FN(void, glTexImage1D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void* pixels), (target, level, internalformat, width, border, format, type, pixels));
VDGL_GL_FN(void, glTexImage2D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void* pixels), (target, level, internalformat, width, height, border, format, type, pixels));
VDGL_GL_FN(void, glDrawBuffer, (GLenum buf), (buf));
VDGL_GL_FN(void, glClear, (GLbitfield mask), (mask));
VDGL_GL_FN(void, glClearColor, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha), (red, green, blue, alpha));
VDGL_GL_FN(void, glClearStencil, (GLint s), (s));
VDGL_GL_FN(void, glClearDepth, (GLdouble depth), (depth));
VDGL_GL_FN(void, glStencilMask, (GLuint mask), (mask));
VDGL_GL_FN(void, glColorMask, (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha), (red, green, blue, alpha));
VDGL_GL_FN(void, glDepthMask, (GLboolean flag), (flag));
VDGL_GL_FN(void, glDisable, (GLenum cap), (cap));
VDGL_GL_FN(void, glEnable, (GLenum cap), (cap));
VDGL_GL_FN(void, glFinish, (void), ());
VDGL_GL_FN(void, glFlush, (void), ());
VDGL_GL_FN(void, glBlendFunc, (GLenum sfactor, GLenum dfactor), (sfactor, dfactor));
VDGL_GL_FN(void, glLogicOp, (GLenum opcode), (opcode));
VDGL_GL_FN(void, glStencilFunc, (GLenum func, GLint ref, GLuint mask), (func, ref, mask));
VDGL_GL_FN(void, glStencilOp, (GLenum fail, GLenum zfail, GLenum zpass), (fail, zfail, zpass));
VDGL_GL_FN(void, glDepthFunc, (GLenum func), (func));
VDGL_GL_FN(void, glPixelStoref, (GLenum pname, GLfloat param), (pname, param));
VDGL_GL_FN(void, glPixelStorei, (GLenum pname, GLint param), (pname, param));
VDGL_GL_FN(void, glReadBuffer, (GLenum src), (src));
VDGL_GL_FN(void, glReadPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void* pixels), (x, y, width, height, format, type, pixels));
VDGL_GL_FN(void, glGetBooleanv, (GLenum pname, GLboolean* data), (pname, data));
VDGL_GL_FN(void, glGetDoublev, (GLenum pname, GLdouble* data), (pname, data));
VDGL_GL_FN(GLenum, glGetError, (void), ());
VDGL_GL_FN(void, glGetFloatv, (GLenum pname, GLfloat* data), (pname, data));
VDGL_GL_FN(void, glGetIntegerv, (GLenum pname, GLint* data), (pname, data));
VDGL_GL_FN(const GLubyte*, glGetString, (GLenum name), (name));
VDGL_GL_FN(void, glGetTexImage, (GLenum target, GLint level, GLenum format, GLenum type, void* pixels), (target, level, format, type, pixels));
VDGL_GL_FN(void, glGetTexParameterfv, (GLenum target, GLenum pname, GLfloat* params), (target, pname, params));
VDGL_GL_FN(void, glGetTexParameteriv, (GLenum target, GLenum pname, GLint* params), (target, pname, params));
VDGL_GL_FN(void, glGetTexLevelParameterfv, (GLenum target, GLint level, GLenum pname, GLfloat* params), (target, level, pname, params));
VDGL_GL_FN(void, glGetTexLevelParameteriv, (GLenum target, GLint level, GLenum pname, GLint* params), (target, level, pname, params));
VDGL_GL_FN(GLboolean, glIsEnabled, (GLenum cap), (cap));
VDGL_GL_FN(void, glDepthRange, (GLdouble n, GLdouble f), (n, f));
VDGL_GL_FN(void, glViewport, (GLint x, GLint y, GLsizei width, GLsizei height), (x, y, width, height));

//////
////// 1.1
//////

typedef khronos_float_t GLclampf;
typedef double GLclampd;

#define GL_COLOR_LOGIC_OP 0x0BF2
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_POINT 0x2A01
#define GL_POLYGON_OFFSET_LINE 0x2A02
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_TEXTURE_BINDING_1D 0x8068
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_TEXTURE_INTERNAL_FORMAT 0x1003
#define GL_TEXTURE_RED_SIZE 0x805C
#define GL_TEXTURE_GREEN_SIZE 0x805D
#define GL_TEXTURE_BLUE_SIZE 0x805E
#define GL_TEXTURE_ALPHA_SIZE 0x805F
#define GL_DOUBLE 0x140A
#define GL_PROXY_TEXTURE_1D 0x8063
#define GL_PROXY_TEXTURE_2D 0x8064
#define GL_R3_G3_B2 0x2A10
#define GL_RGB4 0x804F
#define GL_RGB5 0x8050
#define GL_RGB8 0x8051
#define GL_RGB10 0x8052
#define GL_RGB12 0x8053
#define GL_RGB16 0x8054
#define GL_RGBA2 0x8055
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_RGBA8 0x8058
#define GL_RGB10_A2 0x8059
#define GL_RGBA12 0x805A
#define GL_RGBA16 0x805B
#define GL_VERTEX_ARRAY 0x8074

VDGL_GL_FN(void, glDrawArrays, (GLenum mode, GLint first, GLsizei count), (mode, first, count));
VDGL_GL_FN(void, glDrawElements, (GLenum mode, GLsizei count, GLenum type, const void* indices), (mode, count, type, indices));
VDGL_GL_FN(void, glGetPointerv, (GLenum pname, void** params), (pname, params));
VDGL_GL_FN(void, glPolygonOffset, (GLfloat factor, GLfloat units), (factor, units));
VDGL_GL_FN(void, glCopyTexImage1D, (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border), (target, level, internalformat, x, y, width, border));
VDGL_GL_FN(void, glCopyTexImage2D, (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border), (target, level, internalformat, x, y, width, height, border));
VDGL_GL_FN(void, glCopyTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width), (target, level, xoffset, x, y, width));
VDGL_GL_FN(void, glCopyTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height), (target, level, xoffset, yoffset, x, y, width, height));
VDGL_GL_FN(void, glTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels), (target, level, xoffset, width, format, type, pixels));
VDGL_GL_FN(void, glTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels), (target, level, xoffset, yoffset, width, height, format, type, pixels));
VDGL_GL_FN(void, glBindTexture, (GLenum target, GLuint texture), (target, texture));
VDGL_GL_FN(void, glDeleteTextures, (GLsizei n, const GLuint* textures), (n, textures));
VDGL_GL_FN(void, glGenTextures, (GLsizei n, GLuint* textures), (n, textures));
VDGL_GL_FN(GLboolean, glIsTexture, (GLuint texture), (texture));

//////
////// 1.2
//////

#define GL_UNSIGNED_BYTE_3_3_2 0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_INT_8_8_8_8 0x8035
#define GL_UNSIGNED_INT_10_10_10_2 0x8036
#define GL_TEXTURE_BINDING_3D 0x806A
#define GL_PACK_SKIP_IMAGES 0x806B
#define GL_PACK_IMAGE_HEIGHT 0x806C
#define GL_UNPACK_SKIP_IMAGES 0x806D
#define GL_UNPACK_IMAGE_HEIGHT 0x806E
#define GL_TEXTURE_3D 0x806F
#define GL_PROXY_TEXTURE_3D 0x8070
#define GL_TEXTURE_DEPTH 0x8071
#define GL_TEXTURE_WRAP_R 0x8072
#define GL_MAX_3D_TEXTURE_SIZE 0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define GL_BGR 0x80E0
#define GL_BGRA 0x80E1
#define GL_MAX_ELEMENTS_VERTICES 0x80E8
#define GL_MAX_ELEMENTS_INDICES 0x80E9
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_TEXTURE_MIN_LOD 0x813A
#define GL_TEXTURE_MAX_LOD 0x813B
#define GL_TEXTURE_BASE_LEVEL 0x813C
#define GL_TEXTURE_MAX_LEVEL 0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E

VDGL_GL_FN(void, glDrawRangeElements, (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices), (mode, start, end, count, type, indices));
VDGL_GL_FN(void, glTexImage3D, (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void* pixels), (target, level, internalformat, width, height, depth, border, format, type, pixels));
VDGL_GL_FN(void, glTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels), (target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels));
VDGL_GL_FN(void, glCopyTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height), (target, level, xoffset, yoffset, zoffset, x, y, width, height));

//////
////// 1.3
//////

#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_MULTISAMPLE 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_ALPHA_TO_ONE 0x809F
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP 0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_COMPRESSED_RGB 0x84ED
#define GL_COMPRESSED_RGBA 0x84EE
#define GL_TEXTURE_COMPRESSION_HINT 0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define GL_TEXTURE_COMPRESSED 0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_CLAMP_TO_BORDER 0x812D

VDGL_GL_FN(void, glActiveTexture, (GLenum texture), (texture));
VDGL_GL_FN(void, glSampleCoverage, (GLfloat value, GLboolean invert), (value, invert));
VDGL_GL_FN(void, glCompressedTexImage3D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void* data), (target, level, internalformat, width, height, depth, border, imageSize, data));
VDGL_GL_FN(void, glCompressedTexImage2D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void* data), (target, level, internalformat, width, height, border, imageSize, data));
VDGL_GL_FN(void, glCompressedTexImage1D, (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void* data), (target, level, internalformat, width, border, imageSize, data));
VDGL_GL_FN(void, glCompressedTexSubImage3D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data), (target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data));
VDGL_GL_FN(void, glCompressedTexSubImage2D, (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data), (target, level, xoffset, yoffset, width, height, format, imageSize, data));
VDGL_GL_FN(void, glCompressedTexSubImage1D, (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data), (target, level, xoffset, width, format, imageSize, data));
VDGL_GL_FN(void, glGetCompressedTexImage, (GLenum target, GLint level, void* img), (target, level, img));

//////
////// 1.4
//////

#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE 0x8128
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_DEPTH_COMPONENT24 0x81A6
#define GL_DEPTH_COMPONENT32 0x81A7
#define GL_MIRRORED_REPEAT 0x8370
#define GL_MAX_TEXTURE_LOD_BIAS 0x84FD
#define GL_TEXTURE_LOD_BIAS 0x8501
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_TEXTURE_DEPTH_SIZE 0x884A
#define GL_TEXTURE_COMPARE_MODE 0x884C
#define GL_TEXTURE_COMPARE_FUNC 0x884D
#define GL_BLEND_COLOR 0x8005
#define GL_BLEND_EQUATION 0x8009
#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_FUNC_ADD 0x8006
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_FUNC_SUBTRACT 0x800A
#define GL_MIN 0x8007
#define GL_MAX 0x8008

VDGL_GL_FN(void, glBlendFuncSeparate, (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha), (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha));
VDGL_GL_FN(void, glMultiDrawArrays, (GLenum mode, const GLint* first, const GLsizei* count, GLsizei drawcount), (mode, first, count, drawcount));
VDGL_GL_FN(void, glMultiDrawElements, (GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount), (mode, count, type, indices, drawcount));
VDGL_GL_FN(void, glPointParameterf, (GLenum pname, GLfloat param), (pname, param));
VDGL_GL_FN(void, glPointParameterfv, (GLenum pname, const GLfloat* params), (pname, params));
VDGL_GL_FN(void, glPointParameteri, (GLenum pname, GLint param), (pname, param));
VDGL_GL_FN(void, glPointParameteriv, (GLenum pname, const GLint* params), (pname, params));
VDGL_GL_FN(void, glBlendColor, (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha), (red, green, blue, alpha));
VDGL_GL_FN(void, glBlendEquation, (GLenum mode), (mode));

//////
////// 1.5
//////

typedef khronos_ssize_t GLsizeiptr;
typedef khronos_intptr_t GLintptr;

#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_QUERY_COUNTER_BITS 0x8864
#define GL_CURRENT_QUERY 0x8865
#define GL_QUERY_RESULT 0x8866
#define GL_QUERY_RESULT_AVAILABLE 0x8867
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_READ_ONLY 0x88B8
#define GL_WRITE_ONLY 0x88B9
#define GL_READ_WRITE 0x88BA
#define GL_BUFFER_ACCESS 0x88BB
#define GL_BUFFER_MAPPED 0x88BC
#define GL_BUFFER_MAP_POINTER 0x88BD
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA
#define GL_SAMPLES_PASSED 0x8914
#define GL_SRC1_ALPHA 0x8589

VDGL_GL_FN(void, glGenQueries, (GLsizei n, GLuint* ids), (n, ids));
VDGL_GL_FN(void, glDeleteQueries, (GLsizei n, const GLuint* ids), (n, ids));
VDGL_GL_FN(GLboolean, glIsQuery, (GLuint id), (id));
VDGL_GL_FN(void, glBeginQuery, (GLenum target, GLuint id), (target, id));
VDGL_GL_FN(void, glEndQuery, (GLenum target), (target));
VDGL_GL_FN(void, glGetQueryiv, (GLenum target, GLenum pname, GLint* params), (target, pname, params));
VDGL_GL_FN(void, glGetQueryObjectiv, (GLuint id, GLenum pname, GLint* params), (id, pname, params));
VDGL_GL_FN(void, glGetQueryObjectuiv, (GLuint id, GLenum pname, GLuint* params), (id, pname, params));
VDGL_GL_FN(void, glBindBuffer, (GLenum target, GLuint buffer), (target, buffer));
VDGL_GL_FN(void, glDeleteBuffers, (GLsizei n, const GLuint* buffers), (n, buffers));
VDGL_GL_FN(void, glGenBuffers, (GLsizei n, GLuint* buffers), (n, buffers));
VDGL_GL_FN(GLboolean, glIsBuffer, (GLuint buffer), (buffer));
VDGL_GL_FN(void, glBufferData, (GLenum target, GLsizeiptr size, const void* data, GLenum usage), (target, size, data, usage));
VDGL_GL_FN(void, glBufferSubData, (GLenum target, GLintptr offset, GLsizeiptr size, const void* data), (target, offset, size, data));
VDGL_GL_FN(void, glGetBufferSubData, (GLenum target, GLintptr offset, GLsizeiptr size, void* data), (target, offset, size, data));
VDGL_GL_FN(void*, glMapBuffer, (GLenum target, GLenum access), (target, access));
VDGL_GL_FN(GLboolean, glUnmapBuffer, (GLenum target), (target));
VDGL_GL_FN(void, glGetBufferParameteriv, (GLenum target, GLenum pname, GLint* params), (target, pname, params));
VDGL_GL_FN(void, glGetBufferPointerv, (GLenum target, GLenum pname, void** params), (target, pname, params));

//////
////// 2.0
//////

typedef char GLchar;
typedef khronos_int16_t GLshort;
typedef khronos_int8_t GLbyte;
typedef khronos_uint16_t GLushort;

#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_MAX_DRAW_BUFFERS 0x8824
#define GL_DRAW_BUFFER0 0x8825
#define GL_DRAW_BUFFER1 0x8826
#define GL_DRAW_BUFFER2 0x8827
#define GL_DRAW_BUFFER3 0x8828
#define GL_DRAW_BUFFER4 0x8829
#define GL_DRAW_BUFFER5 0x882A
#define GL_DRAW_BUFFER6 0x882B
#define GL_DRAW_BUFFER7 0x882C
#define GL_DRAW_BUFFER8 0x882D
#define GL_DRAW_BUFFER9 0x882E
#define GL_DRAW_BUFFER10 0x882F
#define GL_DRAW_BUFFER11 0x8830
#define GL_DRAW_BUFFER12 0x8831
#define GL_DRAW_BUFFER13 0x8832
#define GL_DRAW_BUFFER14 0x8833
#define GL_DRAW_BUFFER15 0x8834
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define GL_MAX_VARYING_FLOATS 0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_1D 0x8B5D
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_3D 0x8B5F
#define GL_SAMPLER_CUBE 0x8B60
#define GL_SAMPLER_1D_SHADOW 0x8B61
#define GL_SAMPLER_2D_SHADOW 0x8B62
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define GL_LOWER_LEFT 0x8CA1
#define GL_UPPER_LEFT 0x8CA2
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5

VDGL_GL_FN(void, glBlendEquationSeparate, (GLenum modeRGB, GLenum modeAlpha), (modeRGB, modeAlpha));
VDGL_GL_FN(void, glDrawBuffers, (GLsizei n, const GLenum* bufs), (n, bufs));
VDGL_GL_FN(void, glStencilOpSeparate, (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass), (face, sfail, dpfail, dppass));
VDGL_GL_FN(void, glStencilFuncSeparate, (GLenum face, GLenum func, GLint ref, GLuint mask), (face, func, ref, mask));
VDGL_GL_FN(void, glStencilMaskSeparate, (GLenum face, GLuint mask), (face, mask));
VDGL_GL_FN(void, glAttachShader, (GLuint program, GLuint shader), (program, shader));
VDGL_GL_FN(void, glBindAttribLocation, (GLuint program, GLuint index, const GLchar* name), (program, index, name));
VDGL_GL_FN(void, glCompileShader, (GLuint shader), (shader));
VDGL_GL_FN(GLuint, glCreateProgram, (void), ());
VDGL_GL_FN(GLuint, glCreateShader, (GLenum type), (type));
VDGL_GL_FN(void, glDeleteProgram, (GLuint program), (program));
VDGL_GL_FN(void, glDeleteShader, (GLuint shader), (shader));
VDGL_GL_FN(void, glDetachShader, (GLuint program, GLuint shader), (program, shader));
VDGL_GL_FN(void, glDisableVertexAttribArray, (GLuint index), (index));
VDGL_GL_FN(void, glEnableVertexAttribArray, (GLuint index), (index));
VDGL_GL_FN(void, glGetActiveAttrib, (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name), (program, index, bufSize, length, size, type, name));
VDGL_GL_FN(void, glGetActiveUniform, (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLint* size, GLenum* type, GLchar* name), (program, index, bufSize, length, size, type, name));
VDGL_GL_FN(void, glGetAttachedShaders, (GLuint program, GLsizei maxCount, GLsizei* count, GLuint* shaders), (program, maxCount, count, shaders));
VDGL_GL_FN(GLint, glGetAttribLocation, (GLuint program, const GLchar* name), (program, name));
VDGL_GL_FN(void, glGetProgramiv, (GLuint program, GLenum pname, GLint* params), (program, pname, params));
VDGL_GL_FN(void, glGetProgramInfoLog, (GLuint program, GLsizei bufSize, GLsizei* length, GLchar* infoLog), (program, bufSize, length, infoLog));
VDGL_GL_FN(void, glGetShaderiv, (GLuint shader, GLenum pname, GLint* params), (shader, pname, params));
VDGL_GL_FN(void, glGetShaderInfoLog, (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* infoLog), (shader, bufSize, length, infoLog));
VDGL_GL_FN(void, glGetShaderSource, (GLuint shader, GLsizei bufSize, GLsizei* length, GLchar* source), (shader, bufSize, length, source));
VDGL_GL_FN(GLint, glGetUniformLocation, (GLuint program, const GLchar* name), (program, name));
VDGL_GL_FN(void, glGetUniformfv, (GLuint program, GLint location, GLfloat* params), (program, location, params));
VDGL_GL_FN(void, glGetUniformiv, (GLuint program, GLint location, GLint* params), (program, location, params));
VDGL_GL_FN(void, glGetVertexAttribdv, (GLuint index, GLenum pname, GLdouble* params), (index, pname, params));
VDGL_GL_FN(void, glGetVertexAttribfv, (GLuint index, GLenum pname, GLfloat* params), (index, pname, params));
VDGL_GL_FN(void, glGetVertexAttribiv, (GLuint index, GLenum pname, GLint* params), (index, pname, params));
VDGL_GL_FN(void, glGetVertexAttribPointerv, (GLuint index, GLenum pname, void** pointer), (index, pname, pointer));
VDGL_GL_FN(GLboolean, glIsProgram, (GLuint program), (program));
VDGL_GL_FN(GLboolean, glIsShader, (GLuint shader), (shader));
VDGL_GL_FN(void, glLinkProgram, (GLuint program), (program));
VDGL_GL_FN(void, glShaderSource, (GLuint shader, GLsizei count, const GLchar* const* string, const GLint* length), (shader, count, string, length));
VDGL_GL_FN(void, glUseProgram, (GLuint program), (program));
VDGL_GL_FN(void, glUniform1f, (GLint location, GLfloat v0), (location, v0));
VDGL_GL_FN(void, glUniform2f, (GLint location, GLfloat v0, GLfloat v1), (location, v0, v1));
VDGL_GL_FN(void, glUniform3f, (GLint location, GLfloat v0, GLfloat v1, GLfloat v2), (location, v0, v1, v2));
VDGL_GL_FN(void, glUniform4f, (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3), (location, v0, v1, v2, v3));
VDGL_GL_FN(void, glUniform1i, (GLint location, GLint v0), (location, v0));
VDGL_GL_FN(void, glUniform2i, (GLint location, GLint v0, GLint v1), (location, v0, v1));
VDGL_GL_FN(void, glUniform3i, (GLint location, GLint v0, GLint v1, GLint v2), (location, v0, v1, v2));
VDGL_GL_FN(void, glUniform4i, (GLint location, GLint v0, GLint v1, GLint v2, GLint v3), (location, v0, v1, v2, v3));
VDGL_GL_FN(void, glUniform1fv, (GLint location, GLsizei count, const GLfloat* value), (location, count, value));
VDGL_GL_FN(void, glUniform2fv, (GLint location, GLsizei count, const GLfloat* value), (location, count, value));
VDGL_GL_FN(void, glUniform3fv, (GLint location, GLsizei count, const GLfloat* value), (location, count, value));
VDGL_GL_FN(void, glUniform4fv, (GLint location, GLsizei count, const GLfloat* value), (location, count, value));
VDGL_GL_FN(void, glUniform1iv, (GLint location, GLsizei count, const GLint* value), (location, count, value));
VDGL_GL_FN(void, glUniform2iv, (GLint location, GLsizei count, const GLint* value), (location, count, value));
VDGL_GL_FN(void, glUniform3iv, (GLint location, GLsizei count, const GLint* value), (location, count, value));
VDGL_GL_FN(void, glUniform4iv, (GLint location, GLsizei count, const GLint* value), (location, count, value));
VDGL_GL_FN(void, glUniformMatrix2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (location, count, transpose, value));
VDGL_GL_FN(void, glValidateProgram, (GLuint program), (program));
VDGL_GL_FN(void, glVertexAttrib1d, (GLuint index, GLdouble x), (index, x));
VDGL_GL_FN(void, glVertexAttrib1dv, (GLuint index, const GLdouble* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib1f, (GLuint index, GLfloat x), (index, x));
VDGL_GL_FN(void, glVertexAttrib1fv, (GLuint index, const GLfloat* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib1s, (GLuint index, GLshort x), (index, x));
VDGL_GL_FN(void, glVertexAttrib1sv, (GLuint index, const GLshort* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib2d, (GLuint index, GLdouble x, GLdouble y), (index, x, y));
VDGL_GL_FN(void, glVertexAttrib2dv, (GLuint index, const GLdouble* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib2f, (GLuint index, GLfloat x, GLfloat y), (index, x, y));
VDGL_GL_FN(void, glVertexAttrib2fv, (GLuint index, const GLfloat* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib2s, (GLuint index, GLshort x, GLshort y), (index, x, y));
VDGL_GL_FN(void, glVertexAttrib2sv, (GLuint index, const GLshort* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib3d, (GLuint index, GLdouble x, GLdouble y, GLdouble z), (index, x, y, z));
VDGL_GL_FN(void, glVertexAttrib3dv, (GLuint index, const GLdouble* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib3f, (GLuint index, GLfloat x, GLfloat y, GLfloat z), (index, x, y, z));
VDGL_GL_FN(void, glVertexAttrib3fv, (GLuint index, const GLfloat* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib3s, (GLuint index, GLshort x, GLshort y, GLshort z), (index, x, y, z));
VDGL_GL_FN(void, glVertexAttrib3sv, (GLuint index, const GLshort* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4Nbv, (GLuint index, const GLbyte* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4Niv, (GLuint index, const GLint* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4Nsv, (GLuint index, const GLshort* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4Nub, (GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w), (index, x, y, z, w));
VDGL_GL_FN(void, glVertexAttrib4Nubv, (GLuint index, const GLubyte* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4Nuiv, (GLuint index, const GLuint* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4Nusv, (GLuint index, const GLushort* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4bv, (GLuint index, const GLbyte* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4d, (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w), (index, x, y, z, w));
VDGL_GL_FN(void, glVertexAttrib4dv, (GLuint index, const GLdouble* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4f, (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w), (index, x, y, z, w));
VDGL_GL_FN(void, glVertexAttrib4fv, (GLuint index, const GLfloat* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4iv, (GLuint index, const GLint* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4s, (GLuint index, GLshort x, GLshort y, GLshort z, GLshort w), (index, x, y, z, w));
VDGL_GL_FN(void, glVertexAttrib4sv, (GLuint index, const GLshort* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4ubv, (GLuint index, const GLubyte* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4uiv, (GLuint index, const GLuint* v), (index, v));
VDGL_GL_FN(void, glVertexAttrib4usv, (GLuint index, const GLushort* v), (index, v));
VDGL_GL_FN(void, glVertexAttribPointer, (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer), (index, size, type, normalized, stride, pointer));

//////
////// 2.1
//////

#define GL_PIXEL_PACK_BUFFER 0x88EB
#define GL_PIXEL_UNPACK_BUFFER 0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define GL_FLOAT_MAT2x3 0x8B65
#define GL_FLOAT_MAT2x4 0x8B66
#define GL_FLOAT_MAT3x2 0x8B67
#define GL_FLOAT_MAT3x4 0x8B68
#define GL_FLOAT_MAT4x2 0x8B69
#define GL_FLOAT_MAT4x3 0x8B6A
#define GL_SRGB 0x8C40
#define GL_SRGB8 0x8C41
#define GL_SRGB_ALPHA 0x8C42
#define GL_SRGB8_ALPHA8 0x8C43
#define GL_COMPRESSED_SRGB 0x8C48
#define GL_COMPRESSED_SRGB_ALPHA 0x8C49

VDGL_GL_FN(void, glUniformMatrix2x3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix3x2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix2x4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix4x2fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix3x4fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix4x3fv, (GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (location, count, transpose, value));

//////
////// 3.0
//////

using GLhalf = khronos_uint16_t;

#define GL_COMPARE_REF_TO_TEXTURE 0x884E
#define GL_CLIP_DISTANCE0 0x3000
#define GL_CLIP_DISTANCE1 0x3001
#define GL_CLIP_DISTANCE2 0x3002
#define GL_CLIP_DISTANCE3 0x3003
#define GL_CLIP_DISTANCE4 0x3004
#define GL_CLIP_DISTANCE5 0x3005
#define GL_CLIP_DISTANCE6 0x3006
#define GL_CLIP_DISTANCE7 0x3007
#define GL_MAX_CLIP_DISTANCES 0x0D32
#define GL_MAJOR_VERSION 0x821B
#define GL_MINOR_VERSION 0x821C
#define GL_NUM_EXTENSIONS 0x821D
#define GL_CONTEXT_FLAGS 0x821E
#define GL_COMPRESSED_RED 0x8225
#define GL_COMPRESSED_RG 0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define GL_RGBA32F 0x8814
#define GL_RGB32F 0x8815
#define GL_RGBA16F 0x881A
#define GL_RGB16F 0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define GL_CLAMP_READ_COLOR 0x891C
#define GL_FIXED_ONLY 0x891D
#define GL_MAX_VARYING_COMPONENTS 0x8B4B
#define GL_TEXTURE_1D_ARRAY 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define GL_TEXTURE_2D_ARRAY 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define GL_R11F_G11F_B10F 0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define GL_RGB9_E5 0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define GL_TEXTURE_SHARED_SIZE 0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define GL_PRIMITIVES_GENERATED 0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define GL_RASTERIZER_DISCARD 0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define GL_INTERLEAVED_ATTRIBS 0x8C8C
#define GL_SEPARATE_ATTRIBS 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define GL_RGBA32UI 0x8D70
#define GL_RGB32UI 0x8D71
#define GL_RGBA16UI 0x8D76
#define GL_RGB16UI 0x8D77
#define GL_RGBA8UI 0x8D7C
#define GL_RGB8UI 0x8D7D
#define GL_RGBA32I 0x8D82
#define GL_RGB32I 0x8D83
#define GL_RGBA16I 0x8D88
#define GL_RGB16I 0x8D89
#define GL_RGBA8I 0x8D8E
#define GL_RGB8I 0x8D8F
#define GL_RED_INTEGER 0x8D94
#define GL_GREEN_INTEGER 0x8D95
#define GL_BLUE_INTEGER 0x8D96
#define GL_RGB_INTEGER 0x8D98
#define GL_RGBA_INTEGER 0x8D99
#define GL_BGR_INTEGER 0x8D9A
#define GL_BGRA_INTEGER 0x8D9B
#define GL_SAMPLER_1D_ARRAY 0x8DC0
#define GL_SAMPLER_2D_ARRAY 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define GL_SAMPLER_CUBE_SHADOW 0x8DC5
#define GL_UNSIGNED_INT_VEC2 0x8DC6
#define GL_UNSIGNED_INT_VEC3 0x8DC7
#define GL_UNSIGNED_INT_VEC4 0x8DC8
#define GL_INT_SAMPLER_1D 0x8DC9
#define GL_INT_SAMPLER_2D 0x8DCA
#define GL_INT_SAMPLER_3D 0x8DCB
#define GL_INT_SAMPLER_CUBE 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY 0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY 0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define GL_QUERY_WAIT 0x8E13
#define GL_QUERY_NO_WAIT 0x8E14
#define GL_QUERY_BY_REGION_WAIT 0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT 0x8E16
#define GL_BUFFER_ACCESS_FLAGS 0x911F
#define GL_BUFFER_MAP_LENGTH 0x9120
#define GL_BUFFER_MAP_OFFSET 0x9121
#define GL_DEPTH_COMPONENT32F 0x8CAC
#define GL_DEPTH32F_STENCIL8 0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define GL_FRAMEBUFFER_DEFAULT 0x8218
#define GL_FRAMEBUFFER_UNDEFINED 0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT 0x821A
#define GL_MAX_RENDERBUFFER_SIZE 0x84E8
#define GL_DEPTH_STENCIL 0x84F9
#define GL_UNSIGNED_INT_24_8 0x84FA
#define GL_DEPTH24_STENCIL8 0x88F0
#define GL_TEXTURE_STENCIL_SIZE 0x88F1
#define GL_TEXTURE_RED_TYPE 0x8C10
#define GL_TEXTURE_GREEN_TYPE 0x8C11
#define GL_TEXTURE_BLUE_TYPE 0x8C12
#define GL_TEXTURE_ALPHA_TYPE 0x8C13
#define GL_TEXTURE_DEPTH_TYPE 0x8C16
#define GL_UNSIGNED_NORMALIZED 0x8C17
#define GL_FRAMEBUFFER_BINDING 0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define GL_RENDERBUFFER_BINDING 0x8CA7
#define GL_READ_FRAMEBUFFER 0x8CA8
#define GL_DRAW_FRAMEBUFFER 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING 0x8CAA
#define GL_RENDERBUFFER_SAMPLES 0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define GL_FRAMEBUFFER_COMPLETE 0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS 0x8CDF
#define GL_COLOR_ATTACHMENT0 0x8CE0
#define GL_COLOR_ATTACHMENT1 0x8CE1
#define GL_COLOR_ATTACHMENT2 0x8CE2
#define GL_COLOR_ATTACHMENT3 0x8CE3
#define GL_COLOR_ATTACHMENT4 0x8CE4
#define GL_COLOR_ATTACHMENT5 0x8CE5
#define GL_COLOR_ATTACHMENT6 0x8CE6
#define GL_COLOR_ATTACHMENT7 0x8CE7
#define GL_COLOR_ATTACHMENT8 0x8CE8
#define GL_COLOR_ATTACHMENT9 0x8CE9
#define GL_COLOR_ATTACHMENT10 0x8CEA
#define GL_COLOR_ATTACHMENT11 0x8CEB
#define GL_COLOR_ATTACHMENT12 0x8CEC
#define GL_COLOR_ATTACHMENT13 0x8CED
#define GL_COLOR_ATTACHMENT14 0x8CEE
#define GL_COLOR_ATTACHMENT15 0x8CEF
#define GL_COLOR_ATTACHMENT16 0x8CF0
#define GL_COLOR_ATTACHMENT17 0x8CF1
#define GL_COLOR_ATTACHMENT18 0x8CF2
#define GL_COLOR_ATTACHMENT19 0x8CF3
#define GL_COLOR_ATTACHMENT20 0x8CF4
#define GL_COLOR_ATTACHMENT21 0x8CF5
#define GL_COLOR_ATTACHMENT22 0x8CF6
#define GL_COLOR_ATTACHMENT23 0x8CF7
#define GL_COLOR_ATTACHMENT24 0x8CF8
#define GL_COLOR_ATTACHMENT25 0x8CF9
#define GL_COLOR_ATTACHMENT26 0x8CFA
#define GL_COLOR_ATTACHMENT27 0x8CFB
#define GL_COLOR_ATTACHMENT28 0x8CFC
#define GL_COLOR_ATTACHMENT29 0x8CFD
#define GL_COLOR_ATTACHMENT30 0x8CFE
#define GL_COLOR_ATTACHMENT31 0x8CFF
#define GL_DEPTH_ATTACHMENT 0x8D00
#define GL_STENCIL_ATTACHMENT 0x8D20
#define GL_FRAMEBUFFER 0x8D40
#define GL_RENDERBUFFER 0x8D41
#define GL_RENDERBUFFER_WIDTH 0x8D42
#define GL_RENDERBUFFER_HEIGHT 0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define GL_STENCIL_INDEX1 0x8D46
#define GL_STENCIL_INDEX4 0x8D47
#define GL_STENCIL_INDEX8 0x8D48
#define GL_STENCIL_INDEX16 0x8D49
#define GL_RENDERBUFFER_RED_SIZE 0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE 0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE 0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define GL_MAX_SAMPLES 0x8D57
#define GL_FRAMEBUFFER_SRGB 0x8DB9
#define GL_HALF_FLOAT 0x140B
#define GL_MAP_READ_BIT 0x0001
#define GL_MAP_WRITE_BIT 0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT 0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT 0x0020
#define GL_COMPRESSED_RED_RGTC1 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define GL_COMPRESSED_RG_RGTC2 0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE
#define GL_RG 0x8227
#define GL_RG_INTEGER 0x8228
#define GL_R8 0x8229
#define GL_R16 0x822A
#define GL_RG8 0x822B
#define GL_RG16 0x822C
#define GL_R16F 0x822D
#define GL_R32F 0x822E
#define GL_RG16F 0x822F
#define GL_RG32F 0x8230
#define GL_R8I 0x8231
#define GL_R8UI 0x8232
#define GL_R16I 0x8233
#define GL_R16UI 0x8234
#define GL_R32I 0x8235
#define GL_R32UI 0x8236
#define GL_RG8I 0x8237
#define GL_RG8UI 0x8238
#define GL_RG16I 0x8239
#define GL_RG16UI 0x823A
#define GL_RG32I 0x823B
#define GL_RG32UI 0x823C
#define GL_VERTEX_ARRAY_BINDING 0x85B5

VDGL_GL_FN(void, glColorMaski, (GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a), (index, r, g, b, a));
VDGL_GL_FN(void, glGetBooleani_v, (GLenum target, GLuint index, GLboolean* data), (target, index, data));
VDGL_GL_FN(void, glGetIntegeri_v, (GLenum target, GLuint index, GLint* data), (target, index, data));
VDGL_GL_FN(void, glEnablei, (GLenum target, GLuint index), (target, index));
VDGL_GL_FN(void, glDisablei, (GLenum target, GLuint index), (target, index));
VDGL_GL_FN(GLboolean, glIsEnabledi, (GLenum target, GLuint index), (target, index));
VDGL_GL_FN(void, glBeginTransformFeedback, (GLenum primitiveMode), (primitiveMode));
VDGL_GL_FN(void, glEndTransformFeedback, (void), ());
VDGL_GL_FN(void, glBindBufferRange, (GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size), (target, index, buffer, offset, size));
VDGL_GL_FN(void, glBindBufferBase, (GLenum target, GLuint index, GLuint buffer), (target, index, buffer));
VDGL_GL_FN(void, glTransformFeedbackVaryings, (GLuint program, GLsizei count, const GLchar* const* varyings, GLenum bufferMode), (program, count, varyings, bufferMode));
VDGL_GL_FN(void, glGetTransformFeedbackVarying, (GLuint program, GLuint index, GLsizei bufSize, GLsizei* length, GLsizei* size, GLenum* type, GLchar* name), (program, index, bufSize, length, size, type, name));
VDGL_GL_FN(void, glClampColor, (GLenum target, GLenum clamp), (target, clamp));
VDGL_GL_FN(void, glBeginConditionalRender, (GLuint id, GLenum mode), (id, mode));
VDGL_GL_FN(void, glEndConditionalRender, (void), ());
VDGL_GL_FN(void, glVertexAttribIPointer, (GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer), (index, size, type, stride, pointer));
VDGL_GL_FN(void, glGetVertexAttribIiv, (GLuint index, GLenum pname, GLint* params), (index, pname, params));
VDGL_GL_FN(void, glGetVertexAttribIuiv, (GLuint index, GLenum pname, GLuint* params), (index, pname, params));
VDGL_GL_FN(void, glVertexAttribI1i, (GLuint index, GLint x), (index, x));
VDGL_GL_FN(void, glVertexAttribI2i, (GLuint index, GLint x, GLint y), (index, x, y));
VDGL_GL_FN(void, glVertexAttribI3i, (GLuint index, GLint x, GLint y, GLint z), (index, x, y, z));
VDGL_GL_FN(void, glVertexAttribI4i, (GLuint index, GLint x, GLint y, GLint z, GLint w), (index, x, y, z, w));
VDGL_GL_FN(void, glVertexAttribI1ui, (GLuint index, GLuint x), (index, x));
VDGL_GL_FN(void, glVertexAttribI2ui, (GLuint index, GLuint x, GLuint y), (index, x, y));
VDGL_GL_FN(void, glVertexAttribI3ui, (GLuint index, GLuint x, GLuint y, GLuint z), (index, x, y, z));
VDGL_GL_FN(void, glVertexAttribI4ui, (GLuint index, GLuint x, GLuint y, GLuint z, GLuint w), (index, x, y, z, w));
VDGL_GL_FN(void, glVertexAttribI1iv, (GLuint index, const GLint* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI2iv, (GLuint index, const GLint* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI3iv, (GLuint index, const GLint* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI4iv, (GLuint index, const GLint* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI1uiv, (GLuint index, const GLuint* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI2uiv, (GLuint index, const GLuint* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI3uiv, (GLuint index, const GLuint* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI4uiv, (GLuint index, const GLuint* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI4bv, (GLuint index, const GLbyte* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI4sv, (GLuint index, const GLshort* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI4ubv, (GLuint index, const GLubyte* v), (index, v));
VDGL_GL_FN(void, glVertexAttribI4usv, (GLuint index, const GLushort* v), (index, v));
VDGL_GL_FN(void, glGetUniformuiv, (GLuint program, GLint location, GLuint* params), (program, location, params));
VDGL_GL_FN(void, glBindFragDataLocation, (GLuint program, GLuint color, const GLchar* name), (program, color, name));
VDGL_GL_FN(GLint, glGetFragDataLocation, (GLuint program, const GLchar* name), (program, name));
VDGL_GL_FN(void, glUniform1ui, (GLint location, GLuint v0), (location, v0));
VDGL_GL_FN(void, glUniform2ui, (GLint location, GLuint v0, GLuint v1), (location, v0, v1));
VDGL_GL_FN(void, glUniform3ui, (GLint location, GLuint v0, GLuint v1, GLuint v2), (location, v0, v1, v2));
VDGL_GL_FN(void, glUniform4ui, (GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3), (location, v0, v1, v2, v3));
VDGL_GL_FN(void, glUniform1uiv, (GLint location, GLsizei count, const GLuint* value), (location, count, value));
VDGL_GL_FN(void, glUniform2uiv, (GLint location, GLsizei count, const GLuint* value), (location, count, value));
VDGL_GL_FN(void, glUniform3uiv, (GLint location, GLsizei count, const GLuint* value), (location, count, value));
VDGL_GL_FN(void, glUniform4uiv, (GLint location, GLsizei count, const GLuint* value), (location, count, value));
VDGL_GL_FN(void, glTexParameterIiv, (GLenum target, GLenum pname, const GLint* params), (target, pname, params));
VDGL_GL_FN(void, glTexParameterIuiv, (GLenum target, GLenum pname, const GLuint* params), (target, pname, params));
VDGL_GL_FN(void, glGetTexParameterIiv, (GLenum target, GLenum pname, GLint* params), (target, pname, params));
VDGL_GL_FN(void, glGetTexParameterIuiv, (GLenum target, GLenum pname, GLuint* params), (target, pname, params));
VDGL_GL_FN(void, glClearBufferiv, (GLenum buffer, GLint drawbuffer, const GLint* value), (buffer, drawbuffer, value));
VDGL_GL_FN(void, glClearBufferuiv, (GLenum buffer, GLint drawbuffer, const GLuint* value), (buffer, drawbuffer, value));
VDGL_GL_FN(void, glClearBufferfv, (GLenum buffer, GLint drawbuffer, const GLfloat* value), (buffer, drawbuffer, value));
VDGL_GL_FN(void, glClearBufferfi, (GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil), (buffer, drawbuffer, depth, stencil));
VDGL_GL_FN(const GLubyte*, glGetStringi, (GLenum name, GLuint index), (name, index));
VDGL_GL_FN(GLboolean, glIsRenderbuffer, (GLuint renderbuffer), (renderbuffer));
VDGL_GL_FN(void, glBindRenderbuffer, (GLenum target, GLuint renderbuffer), (target, renderbuffer));
VDGL_GL_FN(void, glDeleteRenderbuffers, (GLsizei n, const GLuint* renderbuffers), (n, renderbuffers));
VDGL_GL_FN(void, glGenRenderbuffers, (GLsizei n, GLuint* renderbuffers), (n, renderbuffers));
VDGL_GL_FN(void, glRenderbufferStorage, (GLenum target, GLenum internalformat, GLsizei width, GLsizei height), (target, internalformat, width, height));
VDGL_GL_FN(void, glGetRenderbufferParameteriv, (GLenum target, GLenum pname, GLint* params), (target, pname, params));
VDGL_GL_FN(GLboolean, glIsFramebuffer, (GLuint framebuffer), (framebuffer));
VDGL_GL_FN(void, glBindFramebuffer, (GLenum target, GLuint framebuffer), (target, framebuffer));
VDGL_GL_FN(void, glDeleteFramebuffers, (GLsizei n, const GLuint* framebuffers), (n, framebuffers));
VDGL_GL_FN(void, glGenFramebuffers, (GLsizei n, GLuint* framebuffers), (n, framebuffers));
VDGL_GL_FN(GLenum, glCheckFramebufferStatus, (GLenum target), (target));
VDGL_GL_FN(void, glFramebufferTexture1D, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level), (target, attachment, textarget, texture, level));
VDGL_GL_FN(void, glFramebufferTexture2D, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level), (target, attachment, textarget, texture, level));
VDGL_GL_FN(void, glFramebufferTexture3D, (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset), (target, attachment, textarget, texture, level, zoffset));
VDGL_GL_FN(void, glFramebufferRenderbuffer, (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer), (target, attachment, renderbuffertarget, renderbuffer));
VDGL_GL_FN(void, glGetFramebufferAttachmentParameteriv, (GLenum target, GLenum attachment, GLenum pname, GLint* params), (target, attachment, pname, params));
VDGL_GL_FN(void, glGenerateMipmap, (GLenum target), (target));
VDGL_GL_FN(void, glBlitFramebuffer, (GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter), (srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter));
VDGL_GL_FN(void, glRenderbufferStorageMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height), (target, samples, internalformat, width, height));
VDGL_GL_FN(void, glFramebufferTextureLayer, (GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer), (target, attachment, texture, level, layer));
VDGL_GL_FN(void*, glMapBufferRange, (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access), (target, offset, length, access));
VDGL_GL_FN(void, glFlushMappedBufferRange, (GLenum target, GLintptr offset, GLsizeiptr length), (target, offset, length));
VDGL_GL_FN(void, glBindVertexArray, (GLuint array), (array));
VDGL_GL_FN(void, glDeleteVertexArrays, (GLsizei n, const GLuint* arrays), (n, arrays));
VDGL_GL_FN(void, glGenVertexArrays, (GLsizei n, GLuint* arrays), (n, arrays));
VDGL_GL_FN(GLboolean, glIsVertexArray, (GLuint array), (array));

//////
////// 3.1
//////

#define GL_SAMPLER_2D_RECT 0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW 0x8B64
#define GL_SAMPLER_BUFFER 0x8DC2
#define GL_INT_SAMPLER_2D_RECT 0x8DCD
#define GL_INT_SAMPLER_BUFFER 0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define GL_TEXTURE_BUFFER 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define GL_TEXTURE_BINDING_BUFFER 0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define GL_TEXTURE_RECTANGLE 0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE 0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE 0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define GL_R8_SNORM 0x8F94
#define GL_RG8_SNORM 0x8F95
#define GL_RGB8_SNORM 0x8F96
#define GL_RGBA8_SNORM 0x8F97
#define GL_R16_SNORM 0x8F98
#define GL_RG16_SNORM 0x8F99
#define GL_RGB16_SNORM 0x8F9A
#define GL_RGBA16_SNORM 0x8F9B
#define GL_SIGNED_NORMALIZED 0x8F9C
#define GL_PRIMITIVE_RESTART 0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX 0x8F9E
#define GL_COPY_READ_BUFFER 0x8F36
#define GL_COPY_WRITE_BUFFER 0x8F37
#define GL_UNIFORM_BUFFER 0x8A11
#define GL_UNIFORM_BUFFER_BINDING 0x8A28
#define GL_UNIFORM_BUFFER_START 0x8A29
#define GL_UNIFORM_BUFFER_SIZE 0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define GL_UNIFORM_TYPE 0x8A37
#define GL_UNIFORM_SIZE 0x8A38
#define GL_UNIFORM_NAME_LENGTH 0x8A39
#define GL_UNIFORM_BLOCK_INDEX 0x8A3A
#define GL_UNIFORM_OFFSET 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE 0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE 0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define GL_UNIFORM_BLOCK_BINDING 0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define GL_INVALID_INDEX 0xFFFFFFFFu

VDGL_GL_FN(void, glDrawArraysInstanced, (GLenum mode, GLint first, GLsizei count, GLsizei instancecount), (mode, first, count, instancecount));
VDGL_GL_FN(void, glDrawElementsInstanced, (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount), (mode, count, type, indices, instancecount));
VDGL_GL_FN(void, glTexBuffer, (GLenum target, GLenum internalformat, GLuint buffer), (target, internalformat, buffer));
VDGL_GL_FN(void, glPrimitiveRestartIndex, (GLuint index), (index));
VDGL_GL_FN(void, glCopyBufferSubData, (GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size), (readTarget, writeTarget, readOffset, writeOffset, size));
VDGL_GL_FN(void, glGetUniformIndices, (GLuint program, GLsizei uniformCount, const GLchar* const* uniformNames, GLuint* uniformIndices), (program, uniformCount, uniformNames, uniformIndices));
VDGL_GL_FN(void, glGetActiveUniformsiv, (GLuint program, GLsizei uniformCount, const GLuint* uniformIndices, GLenum pname, GLint* params), (program, uniformCount, uniformIndices, pname, params));
VDGL_GL_FN(void, glGetActiveUniformName, (GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformName), (program, uniformIndex, bufSize, length, uniformName));
VDGL_GL_FN(GLuint, glGetUniformBlockIndex, (GLuint program, const GLchar* uniformBlockName), (program, uniformBlockName));
VDGL_GL_FN(void, glGetActiveUniformBlockiv, (GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint* params), (program, uniformBlockIndex, pname, params));
VDGL_GL_FN(void, glGetActiveUniformBlockName, (GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei* length, GLchar* uniformBlockName), (program, uniformBlockIndex, bufSize, length, uniformBlockName));
VDGL_GL_FN(void, glUniformBlockBinding, (GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding), (program, uniformBlockIndex, uniformBlockBinding));

//////
////// 3.2
//////

typedef struct __GLsync* GLsync;
typedef khronos_uint64_t GLuint64;
typedef khronos_int64_t GLint64;

#define GL_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define GL_LINES_ADJACENCY 0x000A
#define GL_LINE_STRIP_ADJACENCY 0x000B
#define GL_TRIANGLES_ADJACENCY 0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY 0x000D
#define GL_PROGRAM_POINT_SIZE 0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define GL_GEOMETRY_SHADER 0x8DD9
#define GL_GEOMETRY_VERTICES_OUT 0x8916
#define GL_GEOMETRY_INPUT_TYPE 0x8917
#define GL_GEOMETRY_OUTPUT_TYPE 0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define GL_CONTEXT_PROFILE_MASK 0x9126
#define GL_DEPTH_CLAMP 0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define GL_FIRST_VERTEX_CONVENTION 0x8E4D
#define GL_LAST_VERTEX_CONVENTION 0x8E4E
#define GL_PROVOKING_VERTEX 0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS 0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define GL_OBJECT_TYPE 0x9112
#define GL_SYNC_CONDITION 0x9113
#define GL_SYNC_STATUS 0x9114
#define GL_SYNC_FLAGS 0x9115
#define GL_SYNC_FENCE 0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define GL_UNSIGNALED 0x9118
#define GL_SIGNALED 0x9119
#define GL_ALREADY_SIGNALED 0x911A
#define GL_TIMEOUT_EXPIRED 0x911B
#define GL_CONDITION_SATISFIED 0x911C
#define GL_WAIT_FAILED 0x911D
#define GL_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define GL_SAMPLE_POSITION 0x8E50
#define GL_SAMPLE_MASK 0x8E51
#define GL_SAMPLE_MASK_VALUE 0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS 0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE 0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define GL_TEXTURE_SAMPLES 0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define GL_SAMPLER_2D_MULTISAMPLE 0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define GL_MAX_INTEGER_SAMPLES 0x9110

VDGL_GL_FN(void, glDrawElementsBaseVertex, (GLenum mode, GLsizei count, GLenum type, const void* indices, GLint basevertex), (mode, count, type, indices, basevertex));
VDGL_GL_FN(void, glDrawRangeElementsBaseVertex, (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void* indices, GLint basevertex), (mode, start, end, count, type, indices, basevertex));
VDGL_GL_FN(void, glDrawElementsInstancedBaseVertex, (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex), (mode, count, type, indices, instancecount, basevertex));
VDGL_GL_FN(void, glMultiDrawElementsBaseVertex, (GLenum mode, const GLsizei* count, GLenum type, const void* const* indices, GLsizei drawcount, const GLint* basevertex), (mode, count, type, indices, drawcount, basevertex));
VDGL_GL_FN(void, glProvokingVertex, (GLenum mode), (mode));
VDGL_GL_FN(GLsync, glFenceSync, (GLenum condition, GLbitfield flags), (condition, flags));
VDGL_GL_FN(GLboolean, glIsSync, (GLsync sync), (sync));
VDGL_GL_FN(void, glDeleteSync, (GLsync sync), (sync));
VDGL_GL_FN(GLenum, glClientWaitSync, (GLsync sync, GLbitfield flags, GLuint64 timeout), (sync, flags, timeout));
VDGL_GL_FN(void, glWaitSync, (GLsync sync, GLbitfield flags, GLuint64 timeout), (sync, flags, timeout));
VDGL_GL_FN(void, glGetInteger64v, (GLenum pname, GLint64* data), (pname, data));
VDGL_GL_FN(void, glGetSynciv, (GLsync sync, GLenum pname, GLsizei count, GLsizei* length, GLint* values), (sync, pname, count, length, values));
VDGL_GL_FN(void, glGetInteger64i_v, (GLenum target, GLuint index, GLint64* data), (target, index, data));
VDGL_GL_FN(void, glGetBufferParameteri64v, (GLenum target, GLenum pname, GLint64* params), (target, pname, params));
VDGL_GL_FN(void, glFramebufferTexture, (GLenum target, GLenum attachment, GLuint texture, GLint level), (target, attachment, texture, level));
VDGL_GL_FN(void, glTexImage2DMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations), (target, samples, internalformat, width, height, fixedsamplelocations));
VDGL_GL_FN(void, glTexImage3DMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations), (target, samples, internalformat, width, height, depth, fixedsamplelocations));
VDGL_GL_FN(void, glGetMultisamplefv, (GLenum pname, GLuint index, GLfloat* val), (pname, index, val));
VDGL_GL_FN(void, glSampleMaski, (GLuint maskNumber, GLbitfield mask), (maskNumber, mask));

//////
////// 3.3
//////

#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define GL_SRC1_COLOR 0x88F9
#define GL_ONE_MINUS_SRC1_COLOR 0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA 0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
#define GL_ANY_SAMPLES_PASSED 0x8C2F
#define GL_SAMPLER_BINDING 0x8919
#define GL_RGB10_A2UI 0x906F
#define GL_TEXTURE_SWIZZLE_R 0x8E42
#define GL_TEXTURE_SWIZZLE_G 0x8E43
#define GL_TEXTURE_SWIZZLE_B 0x8E44
#define GL_TEXTURE_SWIZZLE_A 0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA 0x8E46
#define GL_TIME_ELAPSED 0x88BF
#define GL_TIMESTAMP 0x8E28
#define GL_INT_2_10_10_10_REV 0x8D9F

VDGL_GL_FN(void, glBindFragDataLocationIndexed, (GLuint program, GLuint colorNumber, GLuint index, const GLchar* name), (program, colorNumber, index, name));
VDGL_GL_FN(GLint, glGetFragDataIndex, (GLuint program, const GLchar* name), (program, name));
VDGL_GL_FN(void, glGenSamplers, (GLsizei count, GLuint* samplers), (count, samplers));
VDGL_GL_FN(void, glDeleteSamplers, (GLsizei count, const GLuint* samplers), (count, samplers));
VDGL_GL_FN(GLboolean, glIsSampler, (GLuint sampler), (sampler));
VDGL_GL_FN(void, glBindSampler, (GLuint unit, GLuint sampler), (unit, sampler));
VDGL_GL_FN(void, glSamplerParameteri, (GLuint sampler, GLenum pname, GLint param), (sampler, pname, param));
VDGL_GL_FN(void, glSamplerParameteriv, (GLuint sampler, GLenum pname, const GLint* param), (sampler, pname, param));
VDGL_GL_FN(void, glSamplerParameterf, (GLuint sampler, GLenum pname, GLfloat param), (sampler, pname, param));
VDGL_GL_FN(void, glSamplerParameterfv, (GLuint sampler, GLenum pname, const GLfloat* param), (sampler, pname, param));
VDGL_GL_FN(void, glSamplerParameterIiv, (GLuint sampler, GLenum pname, const GLint* param), (sampler, pname, param));
VDGL_GL_FN(void, glSamplerParameterIuiv, (GLuint sampler, GLenum pname, const GLuint* param), (sampler, pname, param));
VDGL_GL_FN(void, glGetSamplerParameteriv, (GLuint sampler, GLenum pname, GLint* params), (sampler, pname, params));
VDGL_GL_FN(void, glGetSamplerParameterIiv, (GLuint sampler, GLenum pname, GLint* params), (sampler, pname, params));
VDGL_GL_FN(void, glGetSamplerParameterfv, (GLuint sampler, GLenum pname, GLfloat* params), (sampler, pname, params));
VDGL_GL_FN(void, glGetSamplerParameterIuiv, (GLuint sampler, GLenum pname, GLuint* params), (sampler, pname, params));
VDGL_GL_FN(void, glQueryCounter, (GLuint id, GLenum target), (id, target));
VDGL_GL_FN(void, glGetQueryObjecti64v, (GLuint id, GLenum pname, GLint64* params), (id, pname, params));
VDGL_GL_FN(void, glGetQueryObjectui64v, (GLuint id, GLenum pname, GLuint64* params), (id, pname, params));
VDGL_GL_FN(void, glVertexAttribDivisor, (GLuint index, GLuint divisor), (index, divisor));
VDGL_GL_FN(void, glVertexAttribP1ui, (GLuint index, GLenum type, GLboolean normalized, GLuint value), (index, type, normalized, value));
VDGL_GL_FN(void, glVertexAttribP1uiv, (GLuint index, GLenum type, GLboolean normalized, const GLuint* value), (index, type, normalized, value));
VDGL_GL_FN(void, glVertexAttribP2ui, (GLuint index, GLenum type, GLboolean normalized, GLuint value), (index, type, normalized, value));
VDGL_GL_FN(void, glVertexAttribP2uiv, (GLuint index, GLenum type, GLboolean normalized, const GLuint* value), (index, type, normalized, value));
VDGL_GL_FN(void, glVertexAttribP3ui, (GLuint index, GLenum type, GLboolean normalized, GLuint value), (index, type, normalized, value));
VDGL_GL_FN(void, glVertexAttribP3uiv, (GLuint index, GLenum type, GLboolean normalized, const GLuint* value), (index, type, normalized, value));
VDGL_GL_FN(void, glVertexAttribP4ui, (GLuint index, GLenum type, GLboolean normalized, GLuint value), (index, type, normalized, value));
VDGL_GL_FN(void, glVertexAttribP4uiv, (GLuint index, GLenum type, GLboolean normalized, const GLuint* value), (index, type, normalized, value));

//////
////// 4.0
//////

#define GL_SAMPLE_SHADING 0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE 0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET 0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY 0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY 0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW 0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY 0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY 0x900F
#define GL_DRAW_INDIRECT_BUFFER 0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING 0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS 0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS 0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET 0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET 0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS 0x8E5D
#define GL_MAX_VERTEX_STREAMS 0x8E71
#define GL_DOUBLE_VEC2 0x8FFC
#define GL_DOUBLE_VEC3 0x8FFD
#define GL_DOUBLE_VEC4 0x8FFE
#define GL_DOUBLE_MAT2 0x8F46
#define GL_DOUBLE_MAT3 0x8F47
#define GL_DOUBLE_MAT4 0x8F48
#define GL_DOUBLE_MAT2x3 0x8F49
#define GL_DOUBLE_MAT2x4 0x8F4A
#define GL_DOUBLE_MAT3x2 0x8F4B
#define GL_DOUBLE_MAT3x4 0x8F4C
#define GL_DOUBLE_MAT4x2 0x8F4D
#define GL_DOUBLE_MAT4x3 0x8F4E
#define GL_ACTIVE_SUBROUTINES 0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS 0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS 0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH 0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH 0x8E49
#define GL_MAX_SUBROUTINES 0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS 0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES 0x8E4A
#define GL_COMPATIBLE_SUBROUTINES 0x8E4B
#define GL_PATCHES 0x000E
#define GL_PATCH_VERTICES 0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL 0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL 0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES 0x8E75
#define GL_TESS_GEN_MODE 0x8E76
#define GL_TESS_GEN_SPACING 0x8E77
#define GL_TESS_GEN_VERTEX_ORDER 0x8E78
#define GL_TESS_GEN_POINT_MODE 0x8E79
#define GL_ISOLINES 0x8E7A
#define GL_FRACTIONAL_ODD 0x8E7B
#define GL_FRACTIONAL_EVEN 0x8E7C
#define GL_MAX_PATCH_VERTICES 0x8E7D
#define GL_MAX_TESS_GEN_LEVEL 0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS 0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS 0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS 0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS 0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS 0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS 0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS 0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS 0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS 0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS 0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS 0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER 0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER 0x84F1
#define GL_TESS_EVALUATION_SHADER 0x8E87
#define GL_TESS_CONTROL_SHADER 0x8E88
#define GL_TRANSFORM_FEEDBACK 0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED 0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING 0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS 0x8E70

VDGL_GL_FN(void, glMinSampleShading, (GLfloat value), (value));
VDGL_GL_FN(void, glBlendEquationi, (GLuint buf, GLenum mode), (buf, mode));
VDGL_GL_FN(void, glBlendEquationSeparatei, (GLuint buf, GLenum modeRGB, GLenum modeAlpha), (buf, modeRGB, modeAlpha));
VDGL_GL_FN(void, glBlendFunci, (GLuint buf, GLenum src, GLenum dst), (buf, src, dst));
VDGL_GL_FN(void, glBlendFuncSeparatei, (GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha), (buf, srcRGB, dstRGB, srcAlpha, dstAlpha));
VDGL_GL_FN(void, glDrawArraysIndirect, (GLenum mode, const void* indirect), (mode, indirect));
VDGL_GL_FN(void, glDrawElementsIndirect, (GLenum mode, GLenum type, const void* indirect), (mode, type, indirect));
VDGL_GL_FN(void, glUniform1d, (GLint location, GLdouble x), (location, x));
VDGL_GL_FN(void, glUniform2d, (GLint location, GLdouble x, GLdouble y), (location, x, y));
VDGL_GL_FN(void, glUniform3d, (GLint location, GLdouble x, GLdouble y, GLdouble z), (location, x, y, z));
VDGL_GL_FN(void, glUniform4d, (GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w), (location, x, y, z, w));
VDGL_GL_FN(void, glUniform1dv, (GLint location, GLsizei count, const GLdouble* value), (location, count, value));
VDGL_GL_FN(void, glUniform2dv, (GLint location, GLsizei count, const GLdouble* value), (location, count, value));
VDGL_GL_FN(void, glUniform3dv, (GLint location, GLsizei count, const GLdouble* value), (location, count, value));
VDGL_GL_FN(void, glUniform4dv, (GLint location, GLsizei count, const GLdouble* value), (location, count, value));
VDGL_GL_FN(void, glUniformMatrix2dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix3dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix4dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix2x3dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix2x4dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix3x2dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix3x4dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix4x2dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (location, count, transpose, value));
VDGL_GL_FN(void, glUniformMatrix4x3dv, (GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (location, count, transpose, value));
VDGL_GL_FN(void, glGetUniformdv, (GLuint program, GLint location, GLdouble* params), (program, location, params));
VDGL_GL_FN(GLint, glGetSubroutineUniformLocation, (GLuint program, GLenum shadertype, const GLchar* name), (program, shadertype, name));
VDGL_GL_FN(GLuint, glGetSubroutineIndex, (GLuint program, GLenum shadertype, const GLchar* name), (program, shadertype, name));
VDGL_GL_FN(void, glGetActiveSubroutineUniformiv, (GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint* values), (program, shadertype, index, pname, values));
VDGL_GL_FN(void, glGetActiveSubroutineUniformName, (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name), (program, shadertype, index, bufSize, length, name));
VDGL_GL_FN(void, glGetActiveSubroutineName, (GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name), (program, shadertype, index, bufSize, length, name));
VDGL_GL_FN(void, glUniformSubroutinesuiv, (GLenum shadertype, GLsizei count, const GLuint* indices), (shadertype, count, indices));
VDGL_GL_FN(void, glGetUniformSubroutineuiv, (GLenum shadertype, GLint location, GLuint* params), (shadertype, location, params));
VDGL_GL_FN(void, glGetProgramStageiv, (GLuint program, GLenum shadertype, GLenum pname, GLint* values), (program, shadertype, pname, values));
VDGL_GL_FN(void, glPatchParameteri, (GLenum pname, GLint value), (pname, value));
VDGL_GL_FN(void, glPatchParameterfv, (GLenum pname, const GLfloat* values), (pname, values));
VDGL_GL_FN(void, glBindTransformFeedback, (GLenum target, GLuint id), (target, id));
VDGL_GL_FN(void, glDeleteTransformFeedbacks, (GLsizei n, const GLuint* ids), (n, ids));
VDGL_GL_FN(void, glGenTransformFeedbacks, (GLsizei n, GLuint* ids), (n, ids));
VDGL_GL_FN(GLboolean, glIsTransformFeedback, (GLuint id), (id));
VDGL_GL_FN(void, glPauseTransformFeedback, (void), ());
VDGL_GL_FN(void, glResumeTransformFeedback, (void), ());
VDGL_GL_FN(void, glDrawTransformFeedback, (GLenum mode, GLuint id), (mode, id));
VDGL_GL_FN(void, glDrawTransformFeedbackStream, (GLenum mode, GLuint id, GLuint stream), (mode, id, stream));
VDGL_GL_FN(void, glBeginQueryIndexed, (GLenum target, GLuint index, GLuint id), (target, index, id));
VDGL_GL_FN(void, glEndQueryIndexed, (GLenum target, GLuint index), (target, index));
VDGL_GL_FN(void, glGetQueryIndexediv, (GLenum target, GLuint index, GLenum pname, GLint* params), (target, index, pname, params));

//////
////// 4.1
//////

#define GL_FIXED 0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define GL_LOW_FLOAT 0x8DF0
#define GL_MEDIUM_FLOAT 0x8DF1
#define GL_HIGH_FLOAT 0x8DF2
#define GL_LOW_INT 0x8DF3
#define GL_MEDIUM_INT 0x8DF4
#define GL_HIGH_INT 0x8DF5
#define GL_SHADER_COMPILER 0x8DFA
#define GL_SHADER_BINARY_FORMATS 0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define GL_MAX_VARYING_VECTORS 0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define GL_RGB565 0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define GL_PROGRAM_BINARY_LENGTH 0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define GL_PROGRAM_BINARY_FORMATS 0x87FF
#define GL_VERTEX_SHADER_BIT 0x00000001
#define GL_FRAGMENT_SHADER_BIT 0x00000002
#define GL_GEOMETRY_SHADER_BIT 0x00000004
#define GL_TESS_CONTROL_SHADER_BIT 0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT 0x00000010
#define GL_ALL_SHADER_BITS 0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE 0x8258
#define GL_ACTIVE_PROGRAM 0x8259
#define GL_PROGRAM_PIPELINE_BINDING 0x825A
#define GL_MAX_VIEWPORTS 0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS 0x825C
#define GL_VIEWPORT_BOUNDS_RANGE 0x825D
#define GL_LAYER_PROVOKING_VERTEX 0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX 0x825F
#define GL_UNDEFINED_VERTEX 0x8260

VDGL_GL_FN(void, glReleaseShaderCompiler, (void), ());
VDGL_GL_FN(void, glShaderBinary, (GLsizei count, const GLuint* shaders, GLenum binaryFormat, const void* binary, GLsizei length), (count, shaders, binaryFormat, binary, length));
VDGL_GL_FN(void, glGetShaderPrecisionFormat, (GLenum shadertype, GLenum precisiontype, GLint* range, GLint* precision), (shadertype, precisiontype, range, precision));
VDGL_GL_FN(void, glDepthRangef, (GLfloat n, GLfloat f), (n, f));
VDGL_GL_FN(void, glClearDepthf, (GLfloat d), (d));
VDGL_GL_FN(void, glGetProgramBinary, (GLuint program, GLsizei bufSize, GLsizei* length, GLenum* binaryFormat, void* binary), (program, bufSize, length, binaryFormat, binary));
VDGL_GL_FN(void, glProgramBinary, (GLuint program, GLenum binaryFormat, const void* binary, GLsizei length), (program, binaryFormat, binary, length));
VDGL_GL_FN(void, glProgramParameteri, (GLuint program, GLenum pname, GLint value), (program, pname, value));
VDGL_GL_FN(void, glUseProgramStages, (GLuint pipeline, GLbitfield stages, GLuint program), (pipeline, stages, program));
VDGL_GL_FN(void, glActiveShaderProgram, (GLuint pipeline, GLuint program), (pipeline, program));
VDGL_GL_FN(GLuint, glCreateShaderProgramv, (GLenum type, GLsizei count, const GLchar* const* strings), (type, count, strings));
VDGL_GL_FN(void, glBindProgramPipeline, (GLuint pipeline), (pipeline));
VDGL_GL_FN(void, glDeleteProgramPipelines, (GLsizei n, const GLuint* pipelines), (n, pipelines));
VDGL_GL_FN(void, glGenProgramPipelines, (GLsizei n, GLuint* pipelines), (n, pipelines));
VDGL_GL_FN(GLboolean, glIsProgramPipeline, (GLuint pipeline), (pipeline));
VDGL_GL_FN(void, glGetProgramPipelineiv, (GLuint pipeline, GLenum pname, GLint* params), (pipeline, pname, params));
VDGL_GL_FN(void, glProgramUniform1i, (GLuint program, GLint location, GLint v0), (program, location, v0));
VDGL_GL_FN(void, glProgramUniform1iv, (GLuint program, GLint location, GLsizei count, const GLint* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform1f, (GLuint program, GLint location, GLfloat v0), (program, location, v0));
VDGL_GL_FN(void, glProgramUniform1fv, (GLuint program, GLint location, GLsizei count, const GLfloat* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform1d, (GLuint program, GLint location, GLdouble v0), (program, location, v0));
VDGL_GL_FN(void, glProgramUniform1dv, (GLuint program, GLint location, GLsizei count, const GLdouble* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform1ui, (GLuint program, GLint location, GLuint v0), (program, location, v0));
VDGL_GL_FN(void, glProgramUniform1uiv, (GLuint program, GLint location, GLsizei count, const GLuint* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform2i, (GLuint program, GLint location, GLint v0, GLint v1), (program, location, v0, v1));
VDGL_GL_FN(void, glProgramUniform2iv, (GLuint program, GLint location, GLsizei count, const GLint* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform2f, (GLuint program, GLint location, GLfloat v0, GLfloat v1), (program, location, v0, v1));
VDGL_GL_FN(void, glProgramUniform2fv, (GLuint program, GLint location, GLsizei count, const GLfloat* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform2d, (GLuint program, GLint location, GLdouble v0, GLdouble v1), (program, location, v0, v1));
VDGL_GL_FN(void, glProgramUniform2dv, (GLuint program, GLint location, GLsizei count, const GLdouble* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform2ui, (GLuint program, GLint location, GLuint v0, GLuint v1), (program, location, v0, v1));
VDGL_GL_FN(void, glProgramUniform2uiv, (GLuint program, GLint location, GLsizei count, const GLuint* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform3i, (GLuint program, GLint location, GLint v0, GLint v1, GLint v2), (program, location, v0, v1, v2));
VDGL_GL_FN(void, glProgramUniform3iv, (GLuint program, GLint location, GLsizei count, const GLint* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform3f, (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2), (program, location, v0, v1, v2));
VDGL_GL_FN(void, glProgramUniform3fv, (GLuint program, GLint location, GLsizei count, const GLfloat* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform3d, (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2), (program, location, v0, v1, v2));
VDGL_GL_FN(void, glProgramUniform3dv, (GLuint program, GLint location, GLsizei count, const GLdouble* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform3ui, (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2), (program, location, v0, v1, v2));
VDGL_GL_FN(void, glProgramUniform3uiv, (GLuint program, GLint location, GLsizei count, const GLuint* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform4i, (GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3), (program, location, v0, v1, v2, v3));
VDGL_GL_FN(void, glProgramUniform4iv, (GLuint program, GLint location, GLsizei count, const GLint* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform4f, (GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3), (program, location, v0, v1, v2, v3));
VDGL_GL_FN(void, glProgramUniform4fv, (GLuint program, GLint location, GLsizei count, const GLfloat* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform4d, (GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3), (program, location, v0, v1, v2, v3));
VDGL_GL_FN(void, glProgramUniform4dv, (GLuint program, GLint location, GLsizei count, const GLdouble* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniform4ui, (GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3), (program, location, v0, v1, v2, v3));
VDGL_GL_FN(void, glProgramUniform4uiv, (GLuint program, GLint location, GLsizei count, const GLuint* value), (program, location, count, value));
VDGL_GL_FN(void, glProgramUniformMatrix2fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix3fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix4fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix2dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix3dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix4dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix2x3fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix3x2fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix2x4fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix4x2fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix3x4fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix4x3fv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix2x3dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix3x2dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix2x4dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix4x2dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix3x4dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glProgramUniformMatrix4x3dv, (GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble* value), (program, location, count, transpose, value));
VDGL_GL_FN(void, glValidateProgramPipeline, (GLuint pipeline), (pipeline));
VDGL_GL_FN(void, glGetProgramPipelineInfoLog, (GLuint pipeline, GLsizei bufSize, GLsizei* length, GLchar* infoLog), (pipeline, bufSize, length, infoLog));
VDGL_GL_FN(void, glVertexAttribL1d, (GLuint index, GLdouble x), (index, x));
VDGL_GL_FN(void, glVertexAttribL2d, (GLuint index, GLdouble x, GLdouble y), (index, x, y));
VDGL_GL_FN(void, glVertexAttribL3d, (GLuint index, GLdouble x, GLdouble y, GLdouble z), (index, x, y, z));
VDGL_GL_FN(void, glVertexAttribL4d, (GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w), (index, x, y, z, w));
VDGL_GL_FN(void, glVertexAttribL1dv, (GLuint index, const GLdouble* v), (index, v));
VDGL_GL_FN(void, glVertexAttribL2dv, (GLuint index, const GLdouble* v), (index, v));
VDGL_GL_FN(void, glVertexAttribL3dv, (GLuint index, const GLdouble* v), (index, v));
VDGL_GL_FN(void, glVertexAttribL4dv, (GLuint index, const GLdouble* v), (index, v));
VDGL_GL_FN(void, glVertexAttribLPointer, (GLuint index, GLint size, GLenum type, GLsizei stride, const void* pointer), (index, size, type, stride, pointer));
VDGL_GL_FN(void, glGetVertexAttribLdv, (GLuint index, GLenum pname, GLdouble* params), (index, pname, params));
VDGL_GL_FN(void, glViewportArrayv, (GLuint first, GLsizei count, const GLfloat* v), (first, count, v));
VDGL_GL_FN(void, glViewportIndexedf, (GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h), (index, x, y, w, h));
VDGL_GL_FN(void, glViewportIndexedfv, (GLuint index, const GLfloat* v), (index, v));
VDGL_GL_FN(void, glScissorArrayv, (GLuint first, GLsizei count, const GLint* v), (first, count, v));
VDGL_GL_FN(void, glScissorIndexed, (GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height), (index, left, bottom, width, height));
VDGL_GL_FN(void, glScissorIndexedv, (GLuint index, const GLint* v), (index, v));
VDGL_GL_FN(void, glDepthRangeArrayv, (GLuint first, GLsizei count, const GLdouble* v), (first, count, v));
VDGL_GL_FN(void, glDepthRangeIndexed, (GLuint index, GLdouble n, GLdouble f), (index, n, f));
VDGL_GL_FN(void, glGetFloati_v, (GLenum target, GLuint index, GLfloat* data), (target, index, data));
VDGL_GL_FN(void, glGetDoublei_v, (GLenum target, GLuint index, GLdouble* data), (target, index, data));

//////
////// 4.2
//////

#define GL_COPY_READ_BUFFER_BINDING 0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING 0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
#define GL_TRANSFORM_FEEDBACK_PAUSED 0x8E23
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH 0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT 0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH 0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE 0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH 0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT 0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH 0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE 0x912E
#define GL_NUM_SAMPLE_COUNTS 0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT 0x90BC
#define GL_ATOMIC_COUNTER_BUFFER 0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START 0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE 0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE 0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS 0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES 0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER 0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER 0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER 0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER 0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER 0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS 0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS 0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS 0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS 0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS 0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS 0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS 0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS 0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS 0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS 0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS 0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS 0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE 0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS 0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS 0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX 0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER 0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT 0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT 0x00000002
#define GL_UNIFORM_BARRIER_BIT 0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT 0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT 0x00000020
#define GL_COMMAND_BARRIER_BIT 0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT 0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT 0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT 0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT 0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT 0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT 0x00001000
#define GL_ALL_BARRIER_BITS 0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS 0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS 0x8F39
#define GL_IMAGE_BINDING_NAME 0x8F3A
#define GL_IMAGE_BINDING_LEVEL 0x8F3B
#define GL_IMAGE_BINDING_LAYERED 0x8F3C
#define GL_IMAGE_BINDING_LAYER 0x8F3D
#define GL_IMAGE_BINDING_ACCESS 0x8F3E
#define GL_IMAGE_1D 0x904C
#define GL_IMAGE_2D 0x904D
#define GL_IMAGE_3D 0x904E
#define GL_IMAGE_2D_RECT 0x904F
#define GL_IMAGE_CUBE 0x9050
#define GL_IMAGE_BUFFER 0x9051
#define GL_IMAGE_1D_ARRAY 0x9052
#define GL_IMAGE_2D_ARRAY 0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY 0x9054
#define GL_IMAGE_2D_MULTISAMPLE 0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY 0x9056
#define GL_INT_IMAGE_1D 0x9057
#define GL_INT_IMAGE_2D 0x9058
#define GL_INT_IMAGE_3D 0x9059
#define GL_INT_IMAGE_2D_RECT 0x905A
#define GL_INT_IMAGE_CUBE 0x905B
#define GL_INT_IMAGE_BUFFER 0x905C
#define GL_INT_IMAGE_1D_ARRAY 0x905D
#define GL_INT_IMAGE_2D_ARRAY 0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY 0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE 0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x9061
#define GL_UNSIGNED_INT_IMAGE_1D 0x9062
#define GL_UNSIGNED_INT_IMAGE_2D 0x9063
#define GL_UNSIGNED_INT_IMAGE_3D 0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT 0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE 0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER 0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY 0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY 0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY 0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE 0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY 0x906C
#define GL_MAX_IMAGE_SAMPLES 0x906D
#define GL_IMAGE_BINDING_FORMAT 0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE 0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE 0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS 0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS 0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS 0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS 0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS 0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS 0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS 0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM 0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM 0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT 0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT 0x8E8F
#define GL_TEXTURE_IMMUTABLE_FORMAT 0x912F

VDGL_GL_FN(void, glDrawArraysInstancedBaseInstance, (GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance), (mode, first, count, instancecount, baseinstance));
VDGL_GL_FN(void, glDrawElementsInstancedBaseInstance, (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLuint baseinstance), (mode, count, type, indices, instancecount, baseinstance));
VDGL_GL_FN(void, glDrawElementsInstancedBaseVertexBaseInstance, (GLenum mode, GLsizei count, GLenum type, const void* indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance), (mode, count, type, indices, instancecount, basevertex, baseinstance));
VDGL_GL_FN(void, glGetInternalformativ, (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint* params), (target, internalformat, pname, count, params));
VDGL_GL_FN(void, glGetActiveAtomicCounterBufferiv, (GLuint program, GLuint bufferIndex, GLenum pname, GLint* params), (program, bufferIndex, pname, params));
VDGL_GL_FN(void, glBindImageTexture, (GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format), (unit, texture, level, layered, layer, access, format));
VDGL_GL_FN(void, glMemoryBarrier, (GLbitfield barriers), (barriers));
VDGL_GL_FN(void, glTexStorage1D, (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width), (target, levels, internalformat, width));
VDGL_GL_FN(void, glTexStorage2D, (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height), (target, levels, internalformat, width, height));
VDGL_GL_FN(void, glTexStorage3D, (GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth), (target, levels, internalformat, width, height, depth));
VDGL_GL_FN(void, glDrawTransformFeedbackInstanced, (GLenum mode, GLuint id, GLsizei instancecount), (mode, id, instancecount));
VDGL_GL_FN(void, glDrawTransformFeedbackStreamInstanced, (GLenum mode, GLuint id, GLuint stream, GLsizei instancecount), (mode, id, stream, instancecount));

//////
////// 4.3
//////

typedef void (APIENTRY* GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

#define GL_NUM_SHADING_LANGUAGE_VERSIONS 0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG 0x874E
#define GL_COMPRESSED_RGB8_ETC2 0x9274
#define GL_COMPRESSED_SRGB8_ETC2 0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define GL_COMPRESSED_R11_EAC 0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC 0x9271
#define GL_COMPRESSED_RG11_EAC 0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC 0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define GL_MAX_ELEMENT_INDEX 0x8D6B
#define GL_COMPUTE_SHADER 0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS 0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS 0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS 0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE 0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS 0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS 0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS 0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS 0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS 0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT 0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE 0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE 0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER 0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER 0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER 0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING 0x90EF
#define GL_COMPUTE_SHADER_BIT 0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define GL_DEBUG_CALLBACK_FUNCTION 0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM 0x8245
#define GL_DEBUG_SOURCE_API 0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY 0x8249
#define GL_DEBUG_SOURCE_APPLICATION 0x824A
#define GL_DEBUG_SOURCE_OTHER 0x824B
#define GL_DEBUG_TYPE_ERROR 0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#define GL_DEBUG_TYPE_PORTABILITY 0x824F
#define GL_DEBUG_TYPE_PERFORMANCE 0x8250
#define GL_DEBUG_TYPE_OTHER 0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define GL_DEBUG_LOGGED_MESSAGES 0x9145
#define GL_DEBUG_SEVERITY_HIGH 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM 0x9147
#define GL_DEBUG_SEVERITY_LOW 0x9148
#define GL_DEBUG_TYPE_MARKER 0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP 0x8269
#define GL_DEBUG_TYPE_POP_GROUP 0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH 0x826D
#define GL_BUFFER 0x82E0
#define GL_SHADER 0x82E1
#define GL_PROGRAM 0x82E2
#define GL_QUERY 0x82E3
#define GL_PROGRAM_PIPELINE 0x82E4
#define GL_SAMPLER 0x82E6
#define GL_MAX_LABEL_LENGTH 0x82E8
#define GL_DEBUG_OUTPUT 0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT 0x00000002
#define GL_MAX_UNIFORM_LOCATIONS 0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH 0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT 0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS 0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES 0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS 0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH 0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT 0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS 0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES 0x9318
#define GL_INTERNALFORMAT_SUPPORTED 0x826F
#define GL_INTERNALFORMAT_PREFERRED 0x8270
#define GL_INTERNALFORMAT_RED_SIZE 0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE 0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE 0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE 0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE 0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE 0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE 0x8277
#define GL_INTERNALFORMAT_RED_TYPE 0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE 0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE 0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE 0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE 0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE 0x827D
#define GL_MAX_WIDTH 0x827E
#define GL_MAX_HEIGHT 0x827F
#define GL_MAX_DEPTH 0x8280
#define GL_MAX_LAYERS 0x8281
#define GL_MAX_COMBINED_DIMENSIONS 0x8282
#define GL_COLOR_COMPONENTS 0x8283
#define GL_DEPTH_COMPONENTS 0x8284
#define GL_STENCIL_COMPONENTS 0x8285
#define GL_COLOR_RENDERABLE 0x8286
#define GL_DEPTH_RENDERABLE 0x8287
#define GL_STENCIL_RENDERABLE 0x8288
#define GL_FRAMEBUFFER_RENDERABLE 0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED 0x828A
#define GL_FRAMEBUFFER_BLEND 0x828B
#define GL_READ_PIXELS 0x828C
#define GL_READ_PIXELS_FORMAT 0x828D
#define GL_READ_PIXELS_TYPE 0x828E
#define GL_TEXTURE_IMAGE_FORMAT 0x828F
#define GL_TEXTURE_IMAGE_TYPE 0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT 0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE 0x8292
#define GL_MIPMAP 0x8293
#define GL_MANUAL_GENERATE_MIPMAP 0x8294
#define GL_AUTO_GENERATE_MIPMAP 0x8295
#define GL_COLOR_ENCODING 0x8296
#define GL_SRGB_READ 0x8297
#define GL_SRGB_WRITE 0x8298
#define GL_FILTER 0x829A
#define GL_VERTEX_TEXTURE 0x829B
#define GL_TESS_CONTROL_TEXTURE 0x829C
#define GL_TESS_EVALUATION_TEXTURE 0x829D
#define GL_GEOMETRY_TEXTURE 0x829E
#define GL_FRAGMENT_TEXTURE 0x829F
#define GL_COMPUTE_TEXTURE 0x82A0
#define GL_TEXTURE_SHADOW 0x82A1
#define GL_TEXTURE_GATHER 0x82A2
#define GL_TEXTURE_GATHER_SHADOW 0x82A3
#define GL_SHADER_IMAGE_LOAD 0x82A4
#define GL_SHADER_IMAGE_STORE 0x82A5
#define GL_SHADER_IMAGE_ATOMIC 0x82A6
#define GL_IMAGE_TEXEL_SIZE 0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS 0x82A8
#define GL_IMAGE_PIXEL_FORMAT 0x82A9
#define GL_IMAGE_PIXEL_TYPE 0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST 0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE 0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE 0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH 0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT 0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE 0x82B3
#define GL_CLEAR_BUFFER 0x82B4
#define GL_TEXTURE_VIEW 0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS 0x82B6
#define GL_FULL_SUPPORT 0x82B7
#define GL_CAVEAT_SUPPORT 0x82B8
#define GL_IMAGE_CLASS_4_X_32 0x82B9
#define GL_IMAGE_CLASS_2_X_32 0x82BA
#define GL_IMAGE_CLASS_1_X_32 0x82BB
#define GL_IMAGE_CLASS_4_X_16 0x82BC
#define GL_IMAGE_CLASS_2_X_16 0x82BD
#define GL_IMAGE_CLASS_1_X_16 0x82BE
#define GL_IMAGE_CLASS_4_X_8 0x82BF
#define GL_IMAGE_CLASS_2_X_8 0x82C0
#define GL_IMAGE_CLASS_1_X_8 0x82C1
#define GL_IMAGE_CLASS_11_11_10 0x82C2
#define GL_IMAGE_CLASS_10_10_10_2 0x82C3
#define GL_VIEW_CLASS_128_BITS 0x82C4
#define GL_VIEW_CLASS_96_BITS 0x82C5
#define GL_VIEW_CLASS_64_BITS 0x82C6
#define GL_VIEW_CLASS_48_BITS 0x82C7
#define GL_VIEW_CLASS_32_BITS 0x82C8
#define GL_VIEW_CLASS_24_BITS 0x82C9
#define GL_VIEW_CLASS_16_BITS 0x82CA
#define GL_VIEW_CLASS_8_BITS 0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB 0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA 0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA 0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA 0x82CF
#define GL_VIEW_CLASS_RGTC1_RED 0x82D0
#define GL_VIEW_CLASS_RGTC2_RG 0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM 0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT 0x82D3
#define GL_UNIFORM 0x92E1
#define GL_UNIFORM_BLOCK 0x92E2
#define GL_PROGRAM_INPUT 0x92E3
#define GL_PROGRAM_OUTPUT 0x92E4
#define GL_BUFFER_VARIABLE 0x92E5
#define GL_SHADER_STORAGE_BLOCK 0x92E6
#define GL_VERTEX_SUBROUTINE 0x92E8
#define GL_TESS_CONTROL_SUBROUTINE 0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE 0x92EA
#define GL_GEOMETRY_SUBROUTINE 0x92EB
#define GL_FRAGMENT_SUBROUTINE 0x92EC
#define GL_COMPUTE_SUBROUTINE 0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM 0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM 0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM 0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM 0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM 0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM 0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING 0x92F4
#define GL_ACTIVE_RESOURCES 0x92F5
#define GL_MAX_NAME_LENGTH 0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES 0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES 0x92F8
#define GL_NAME_LENGTH 0x92F9
#define GL_TYPE 0x92FA
#define GL_ARRAY_SIZE 0x92FB
#define GL_OFFSET 0x92FC
#define GL_BLOCK_INDEX 0x92FD
#define GL_ARRAY_STRIDE 0x92FE
#define GL_MATRIX_STRIDE 0x92FF
#define GL_IS_ROW_MAJOR 0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX 0x9301
#define GL_BUFFER_BINDING 0x9302
#define GL_BUFFER_DATA_SIZE 0x9303
#define GL_NUM_ACTIVE_VARIABLES 0x9304
#define GL_ACTIVE_VARIABLES 0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER 0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER 0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER 0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER 0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER 0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER 0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE 0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE 0x930D
#define GL_LOCATION 0x930E
#define GL_LOCATION_INDEX 0x930F
#define GL_IS_PER_PATCH 0x92E7
#define GL_SHADER_STORAGE_BUFFER 0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING 0x90D3
#define GL_SHADER_STORAGE_BUFFER_START 0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE 0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS 0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS 0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS 0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS 0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS 0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS 0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS 0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS 0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE 0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT 0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT 0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES 0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE 0x90EA
#define GL_TEXTURE_BUFFER_OFFSET 0x919D
#define GL_TEXTURE_BUFFER_SIZE 0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT 0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL 0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS 0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER 0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS 0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#define GL_VERTEX_ATTRIB_BINDING 0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D5
#define GL_VERTEX_BINDING_DIVISOR 0x82D6
#define GL_VERTEX_BINDING_OFFSET 0x82D7
#define GL_VERTEX_BINDING_STRIDE 0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET 0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS 0x82DA
#define GL_VERTEX_BINDING_BUFFER 0x8F4F

VDGL_GL_FN(void, glClearBufferData, (GLenum target, GLenum internalformat, GLenum format, GLenum type, const void* data), (target, internalformat, format, type, data));
VDGL_GL_FN(void, glClearBufferSubData, (GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data), (target, internalformat, offset, size, format, type, data));
VDGL_GL_FN(void, glDispatchCompute, (GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z), (num_groups_x, num_groups_y, num_groups_z));
VDGL_GL_FN(void, glDispatchComputeIndirect, (GLintptr indirect), (indirect));
VDGL_GL_FN(void, glCopyImageSubData, (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth), (srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth));
VDGL_GL_FN(void, glFramebufferParameteri, (GLenum target, GLenum pname, GLint param), (target, pname, param));
VDGL_GL_FN(void, glGetFramebufferParameteriv, (GLenum target, GLenum pname, GLint* params), (target, pname, params));
VDGL_GL_FN(void, glGetInternalformati64v, (GLenum target, GLenum internalformat, GLenum pname, GLsizei count, GLint64* params), (target, internalformat, pname, count, params));
VDGL_GL_FN(void, glInvalidateTexSubImage, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth), (texture, level, xoffset, yoffset, zoffset, width, height, depth));
VDGL_GL_FN(void, glInvalidateTexImage, (GLuint texture, GLint level), (texture, level));
VDGL_GL_FN(void, glInvalidateBufferSubData, (GLuint buffer, GLintptr offset, GLsizeiptr length), (buffer, offset, length));
VDGL_GL_FN(void, glInvalidateBufferData, (GLuint buffer), (buffer));
VDGL_GL_FN(void, glInvalidateFramebuffer, (GLenum target, GLsizei numAttachments, const GLenum* attachments), (target, numAttachments, attachments));
VDGL_GL_FN(void, glInvalidateSubFramebuffer, (GLenum target, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height), (target, numAttachments, attachments, x, y, width, height));
VDGL_GL_FN(void, glMultiDrawArraysIndirect, (GLenum mode, const void* indirect, GLsizei drawcount, GLsizei stride), (mode, indirect, drawcount, stride));
VDGL_GL_FN(void, glMultiDrawElementsIndirect, (GLenum mode, GLenum type, const void* indirect, GLsizei drawcount, GLsizei stride), (mode, type, indirect, drawcount, stride));
VDGL_GL_FN(void, glGetProgramInterfaceiv, (GLuint program, GLenum programInterface, GLenum pname, GLint* params), (program, programInterface, pname, params));
VDGL_GL_FN(GLuint, glGetProgramResourceIndex, (GLuint program, GLenum programInterface, const GLchar* name), (program, programInterface, name));
VDGL_GL_FN(void, glGetProgramResourceName, (GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei* length, GLchar* name), (program, programInterface, index, bufSize, length, name));
VDGL_GL_FN(void, glGetProgramResourceiv, (GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum* props, GLsizei count, GLsizei* length, GLint* params), (program, programInterface, index, propCount, props, count, length, params));
VDGL_GL_FN(GLint, glGetProgramResourceLocation, (GLuint program, GLenum programInterface, const GLchar* name), (program, programInterface, name));
VDGL_GL_FN(GLint, glGetProgramResourceLocationIndex, (GLuint program, GLenum programInterface, const GLchar* name), (program, programInterface, name));
VDGL_GL_FN(void, glShaderStorageBlockBinding, (GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding), (program, storageBlockIndex, storageBlockBinding));
VDGL_GL_FN(void, glTexBufferRange, (GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size), (target, internalformat, buffer, offset, size));
VDGL_GL_FN(void, glTexStorage2DMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations), (target, samples, internalformat, width, height, fixedsamplelocations));
VDGL_GL_FN(void, glTexStorage3DMultisample, (GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations), (target, samples, internalformat, width, height, depth, fixedsamplelocations));
VDGL_GL_FN(void, glTextureView, (GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers), (texture, target, origtexture, internalformat, minlevel, numlevels, minlayer, numlayers));
VDGL_GL_FN(void, glBindVertexBuffer, (GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride), (bindingindex, buffer, offset, stride));
VDGL_GL_FN(void, glVertexAttribFormat, (GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset), (attribindex, size, type, normalized, relativeoffset));
VDGL_GL_FN(void, glVertexAttribIFormat, (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset), (attribindex, size, type, relativeoffset));
VDGL_GL_FN(void, glVertexAttribLFormat, (GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset), (attribindex, size, type, relativeoffset));
VDGL_GL_FN(void, glVertexAttribBinding, (GLuint attribindex, GLuint bindingindex), (attribindex, bindingindex));
VDGL_GL_FN(void, glVertexBindingDivisor, (GLuint bindingindex, GLuint divisor), (bindingindex, divisor));
VDGL_GL_FN(void, glDebugMessageControl, (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint* ids, GLboolean enabled), (source, type, severity, count, ids, enabled));
VDGL_GL_FN(void, glDebugMessageInsert, (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* buf), (source, type, id, severity, length, buf));
VDGL_GL_FN(void, glDebugMessageCallback, (GLDEBUGPROC callback, const void* userParam), (callback, userParam));
VDGL_GL_FN(GLuint, glGetDebugMessageLog, (GLuint count, GLsizei bufSize, GLenum* sources, GLenum* types, GLuint* ids, GLenum* severities, GLsizei* lengths, GLchar* messageLog), (count, bufSize, sources, types, ids, severities, lengths, messageLog));
VDGL_GL_FN(void, glPushDebugGroup, (GLenum source, GLuint id, GLsizei length, const GLchar* message), (source, id, length, message));
VDGL_GL_FN(void, glPopDebugGroup, (void), ());
VDGL_GL_FN(void, glObjectLabel, (GLenum identifier, GLuint name, GLsizei length, const GLchar* label), (identifier, name, length, label));
VDGL_GL_FN(void, glGetObjectLabel, (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei* length, GLchar* label), (identifier, name, bufSize, length, label));
VDGL_GL_FN(void, glObjectPtrLabel, (const void* ptr, GLsizei length, const GLchar* label), (ptr, length, label));
VDGL_GL_FN(void, glGetObjectPtrLabel, (const void* ptr, GLsizei bufSize, GLsizei* length, GLchar* label), (ptr, bufSize, length, label));


//////
////// 4.4
//////

#define GL_MAX_VERTEX_ATTRIB_STRIDE 0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED 0x8221
#define GL_TEXTURE_BUFFER_BINDING 0x8C2A
#define GL_MAP_PERSISTENT_BIT 0x0040
#define GL_MAP_COHERENT_BIT 0x0080
#define GL_DYNAMIC_STORAGE_BIT 0x0100
#define GL_CLIENT_STORAGE_BIT 0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT 0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE 0x821F
#define GL_BUFFER_STORAGE_FLAGS 0x8220
#define GL_CLEAR_TEXTURE 0x9365
#define GL_LOCATION_COMPONENT 0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX 0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE 0x934C
#define GL_QUERY_BUFFER 0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT 0x00008000
#define GL_QUERY_BUFFER_BINDING 0x9193
#define GL_QUERY_RESULT_NO_WAIT 0x9194
#define GL_MIRROR_CLAMP_TO_EDGE 0x8743

VDGL_GL_FN(void, glBufferStorage, (GLenum target, GLsizeiptr size, const void* data, GLbitfield flags), (target, size, data, flags));
VDGL_GL_FN(void, glClearTexImage, (GLuint texture, GLint level, GLenum format, GLenum type, const void* data), (texture, level, format, type, data));
VDGL_GL_FN(void, glClearTexSubImage, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* data), (texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, data));
VDGL_GL_FN(void, glBindBuffersBase, (GLenum target, GLuint first, GLsizei count, const GLuint* buffers), (target, first, count, buffers));
VDGL_GL_FN(void, glBindBuffersRange, (GLenum target, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizeiptr* sizes), (target, first, count, buffers, offsets, sizes));
VDGL_GL_FN(void, glBindTextures, (GLuint first, GLsizei count, const GLuint* textures), (first, count, textures));
VDGL_GL_FN(void, glBindSamplers, (GLuint first, GLsizei count, const GLuint* samplers), (first, count, samplers));
VDGL_GL_FN(void, glBindImageTextures, (GLuint first, GLsizei count, const GLuint* textures), (first, count, textures));
VDGL_GL_FN(void, glBindVertexBuffers, (GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides), (first, count, buffers, offsets, strides));

//////
////// 4.5
//////

#define GL_CONTEXT_LOST 0x0507
#define GL_NEGATIVE_ONE_TO_ONE 0x935E
#define GL_ZERO_TO_ONE 0x935F
#define GL_CLIP_ORIGIN 0x935C
#define GL_CLIP_DEPTH_MODE 0x935D
#define GL_QUERY_WAIT_INVERTED 0x8E17
#define GL_QUERY_NO_WAIT_INVERTED 0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED 0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED 0x8E1A
#define GL_MAX_CULL_DISTANCES 0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES 0x82FA
#define GL_TEXTURE_TARGET 0x1006
#define GL_QUERY_TARGET 0x82EA
#define GL_GUILTY_CONTEXT_RESET 0x8253
#define GL_INNOCENT_CONTEXT_RESET 0x8254
#define GL_UNKNOWN_CONTEXT_RESET 0x8255
#define GL_RESET_NOTIFICATION_STRATEGY 0x8256
#define GL_LOSE_CONTEXT_ON_RESET 0x8252
#define GL_NO_RESET_NOTIFICATION 0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT 0x00000004
#define GL_CONTEXT_RELEASE_BEHAVIOR 0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH 0x82FC

VDGL_GL_FN(void, glClipControl, (GLenum origin, GLenum depth), (origin, depth));
VDGL_GL_FN(void, glCreateTransformFeedbacks, (GLsizei n, GLuint* ids), (n, ids));
VDGL_GL_FN(void, glTransformFeedbackBufferBase, (GLuint xfb, GLuint index, GLuint buffer), (xfb, index, buffer));
VDGL_GL_FN(void, glTransformFeedbackBufferRange, (GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size), (xfb, index, buffer, offset, size));
VDGL_GL_FN(void, glGetTransformFeedbackiv, (GLuint xfb, GLenum pname, GLint* param), (xfb, pname, param));
VDGL_GL_FN(void, glGetTransformFeedbacki_v, (GLuint xfb, GLenum pname, GLuint index, GLint* param), (xfb, pname, index, param));
VDGL_GL_FN(void, glGetTransformFeedbacki64_v, (GLuint xfb, GLenum pname, GLuint index, GLint64* param), (xfb, pname, index, param));
VDGL_GL_FN(void, glCreateBuffers, (GLsizei n, GLuint* buffers), (n, buffers));
VDGL_GL_FN(void, glNamedBufferStorage, (GLuint buffer, GLsizeiptr size, const void* data, GLbitfield flags), (buffer, size, data, flags));
VDGL_GL_FN(void, glNamedBufferData, (GLuint buffer, GLsizeiptr size, const void* data, GLenum usage), (buffer, size, data, usage));
VDGL_GL_FN(void, glNamedBufferSubData, (GLuint buffer, GLintptr offset, GLsizeiptr size, const void* data), (buffer, offset, size, data));
VDGL_GL_FN(void, glCopyNamedBufferSubData, (GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size), (readBuffer, writeBuffer, readOffset, writeOffset, size));
VDGL_GL_FN(void, glClearNamedBufferData, (GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void* data), (buffer, internalformat, format, type, data));
VDGL_GL_FN(void, glClearNamedBufferSubData, (GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void* data), (buffer, internalformat, offset, size, format, type, data));
VDGL_GL_FN(void*, glMapNamedBuffer, (GLuint buffer, GLenum access), (buffer, access));
VDGL_GL_FN(void*, glMapNamedBufferRange, (GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access), (buffer, offset, length, access));
VDGL_GL_FN(GLboolean, glUnmapNamedBuffer, (GLuint buffer), (buffer));
VDGL_GL_FN(void, glFlushMappedNamedBufferRange, (GLuint buffer, GLintptr offset, GLsizeiptr length), (buffer, offset, length));
VDGL_GL_FN(void, glGetNamedBufferParameteriv, (GLuint buffer, GLenum pname, GLint* params), (buffer, pname, params));
VDGL_GL_FN(void, glGetNamedBufferParameteri64v, (GLuint buffer, GLenum pname, GLint64* params), (buffer, pname, params));
VDGL_GL_FN(void, glGetNamedBufferPointerv, (GLuint buffer, GLenum pname, void** params), (buffer, pname, params));
VDGL_GL_FN(void, glGetNamedBufferSubData, (GLuint buffer, GLintptr offset, GLsizeiptr size, void* data), (buffer, offset, size, data));
VDGL_GL_FN(void, glCreateFramebuffers, (GLsizei n, GLuint* framebuffers), (n, framebuffers));
VDGL_GL_FN(void, glNamedFramebufferRenderbuffer, (GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer), (framebuffer, attachment, renderbuffertarget, renderbuffer));
VDGL_GL_FN(void, glNamedFramebufferParameteri, (GLuint framebuffer, GLenum pname, GLint param), (framebuffer, pname, param));
VDGL_GL_FN(void, glNamedFramebufferTexture, (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level), (framebuffer, attachment, texture, level));
VDGL_GL_FN(void, glNamedFramebufferTextureLayer, (GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer), (framebuffer, attachment, texture, level, layer));
VDGL_GL_FN(void, glNamedFramebufferDrawBuffer, (GLuint framebuffer, GLenum buf), (framebuffer, buf));
VDGL_GL_FN(void, glNamedFramebufferDrawBuffers, (GLuint framebuffer, GLsizei n, const GLenum* bufs), (framebuffer, n, bufs));
VDGL_GL_FN(void, glNamedFramebufferReadBuffer, (GLuint framebuffer, GLenum src), (framebuffer, src));
VDGL_GL_FN(void, glInvalidateNamedFramebufferData, (GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments), (framebuffer, numAttachments, attachments));
VDGL_GL_FN(void, glInvalidateNamedFramebufferSubData, (GLuint framebuffer, GLsizei numAttachments, const GLenum* attachments, GLint x, GLint y, GLsizei width, GLsizei height), (framebuffer, numAttachments, attachments, x, y, width, height));
VDGL_GL_FN(void, glClearNamedFramebufferiv, (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint* value), (framebuffer, buffer, drawbuffer, value));
VDGL_GL_FN(void, glClearNamedFramebufferuiv, (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint* value), (framebuffer, buffer, drawbuffer, value));
VDGL_GL_FN(void, glClearNamedFramebufferfv, (GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat* value), (framebuffer, buffer, drawbuffer, value));
VDGL_GL_FN(void, glClearNamedFramebufferfi, (GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil), (framebuffer, buffer, drawbuffer, depth, stencil));
VDGL_GL_FN(void, glBlitNamedFramebuffer, (GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter), (readFramebuffer, drawFramebuffer, srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter));
VDGL_GL_FN(GLenum, glCheckNamedFramebufferStatus, (GLuint framebuffer, GLenum target), (framebuffer, target));
VDGL_GL_FN(void, glGetNamedFramebufferParameteriv, (GLuint framebuffer, GLenum pname, GLint* param), (framebuffer, pname, param));
VDGL_GL_FN(void, glGetNamedFramebufferAttachmentParameteriv, (GLuint framebuffer, GLenum attachment, GLenum pname, GLint* params), (framebuffer, attachment, pname, params));
VDGL_GL_FN(void, glCreateRenderbuffers, (GLsizei n, GLuint* renderbuffers), (n, renderbuffers));
VDGL_GL_FN(void, glNamedRenderbufferStorage, (GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height), (renderbuffer, internalformat, width, height));
VDGL_GL_FN(void, glNamedRenderbufferStorageMultisample, (GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height), (renderbuffer, samples, internalformat, width, height));
VDGL_GL_FN(void, glGetNamedRenderbufferParameteriv, (GLuint renderbuffer, GLenum pname, GLint* params), (renderbuffer, pname, params));
VDGL_GL_FN(void, glCreateTextures, (GLenum target, GLsizei n, GLuint* textures), (target, n, textures));
VDGL_GL_FN(void, glTextureBuffer, (GLuint texture, GLenum internalformat, GLuint buffer), (texture, internalformat, buffer));
VDGL_GL_FN(void, glTextureBufferRange, (GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size), (texture, internalformat, buffer, offset, size));
VDGL_GL_FN(void, glTextureStorage1D, (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width), (texture, levels, internalformat, width));
VDGL_GL_FN(void, glTextureStorage2D, (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height), (texture, levels, internalformat, width, height));
VDGL_GL_FN(void, glTextureStorage3D, (GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth), (texture, levels, internalformat, width, height, depth));
VDGL_GL_FN(void, glTextureStorage2DMultisample, (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations), (texture, samples, internalformat, width, height, fixedsamplelocations));
VDGL_GL_FN(void, glTextureStorage3DMultisample, (GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations), (texture, samples, internalformat, width, height, depth, fixedsamplelocations));
VDGL_GL_FN(void, glTextureSubImage1D, (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void* pixels), (texture, level, xoffset, width, format, type, pixels));
VDGL_GL_FN(void, glTextureSubImage2D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void* pixels), (texture, level, xoffset, yoffset, width, height, format, type, pixels));
VDGL_GL_FN(void, glTextureSubImage3D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void* pixels), (texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels));
VDGL_GL_FN(void, glCompressedTextureSubImage1D, (GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void* data), (texture, level, xoffset, width, format, imageSize, data));
VDGL_GL_FN(void, glCompressedTextureSubImage2D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void* data), (texture, level, xoffset, yoffset, width, height, format, imageSize, data));
VDGL_GL_FN(void, glCompressedTextureSubImage3D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void* data), (texture, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data));
VDGL_GL_FN(void, glCopyTextureSubImage1D, (GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width), (texture, level, xoffset, x, y, width));
VDGL_GL_FN(void, glCopyTextureSubImage2D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height), (texture, level, xoffset, yoffset, x, y, width, height));
VDGL_GL_FN(void, glCopyTextureSubImage3D, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height), (texture, level, xoffset, yoffset, zoffset, x, y, width, height));
VDGL_GL_FN(void, glTextureParameterf, (GLuint texture, GLenum pname, GLfloat param), (texture, pname, param));
VDGL_GL_FN(void, glTextureParameterfv, (GLuint texture, GLenum pname, const GLfloat* param), (texture, pname, param));
VDGL_GL_FN(void, glTextureParameteri, (GLuint texture, GLenum pname, GLint param), (texture, pname, param));
VDGL_GL_FN(void, glTextureParameterIiv, (GLuint texture, GLenum pname, const GLint* params), (texture, pname, params));
VDGL_GL_FN(void, glTextureParameterIuiv, (GLuint texture, GLenum pname, const GLuint* params), (texture, pname, params));
VDGL_GL_FN(void, glTextureParameteriv, (GLuint texture, GLenum pname, const GLint* param), (texture, pname, param));
VDGL_GL_FN(void, glGenerateTextureMipmap, (GLuint texture), (texture));
VDGL_GL_FN(void, glBindTextureUnit, (GLuint unit, GLuint texture), (unit, texture));
VDGL_GL_FN(void, glGetTextureImage, (GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels), (texture, level, format, type, bufSize, pixels));
VDGL_GL_FN(void, glGetCompressedTextureImage, (GLuint texture, GLint level, GLsizei bufSize, void* pixels), (texture, level, bufSize, pixels));
VDGL_GL_FN(void, glGetTextureLevelParameterfv, (GLuint texture, GLint level, GLenum pname, GLfloat* params), (texture, level, pname, params));
VDGL_GL_FN(void, glGetTextureLevelParameteriv, (GLuint texture, GLint level, GLenum pname, GLint* params), (texture, level, pname, params));
VDGL_GL_FN(void, glGetTextureParameterfv, (GLuint texture, GLenum pname, GLfloat* params), (texture, pname, params));
VDGL_GL_FN(void, glGetTextureParameterIiv, (GLuint texture, GLenum pname, GLint* params), (texture, pname, params));
VDGL_GL_FN(void, glGetTextureParameterIuiv, (GLuint texture, GLenum pname, GLuint* params), (texture, pname, params));
VDGL_GL_FN(void, glGetTextureParameteriv, (GLuint texture, GLenum pname, GLint* params), (texture, pname, params));
VDGL_GL_FN(void, glCreateVertexArrays, (GLsizei n, GLuint* arrays), (n, arrays));
VDGL_GL_FN(void, glDisableVertexArrayAttrib, (GLuint vaobj, GLuint index), (vaobj, index));
VDGL_GL_FN(void, glEnableVertexArrayAttrib, (GLuint vaobj, GLuint index), (vaobj, index));
VDGL_GL_FN(void, glVertexArrayElementBuffer, (GLuint vaobj, GLuint buffer), (vaobj, buffer));
VDGL_GL_FN(void, glVertexArrayVertexBuffer, (GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride), (vaobj, bindingindex, buffer, offset, stride));
VDGL_GL_FN(void, glVertexArrayVertexBuffers, (GLuint vaobj, GLuint first, GLsizei count, const GLuint* buffers, const GLintptr* offsets, const GLsizei* strides), (vaobj, first, count, buffers, offsets, strides));
VDGL_GL_FN(void, glVertexArrayAttribBinding, (GLuint vaobj, GLuint attribindex, GLuint bindingindex), (vaobj, attribindex, bindingindex));
VDGL_GL_FN(void, glVertexArrayAttribFormat, (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset), (vaobj, attribindex, size, type, normalized, relativeoffset));
VDGL_GL_FN(void, glVertexArrayAttribIFormat, (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset), (vaobj, attribindex, size, type, relativeoffset));
VDGL_GL_FN(void, glVertexArrayAttribLFormat, (GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset), (vaobj, attribindex, size, type, relativeoffset));
VDGL_GL_FN(void, glVertexArrayBindingDivisor, (GLuint vaobj, GLuint bindingindex, GLuint divisor), (vaobj, bindingindex, divisor));
VDGL_GL_FN(void, glGetVertexArrayiv, (GLuint vaobj, GLenum pname, GLint* param), (vaobj, pname, param));
VDGL_GL_FN(void, glGetVertexArrayIndexediv, (GLuint vaobj, GLuint index, GLenum pname, GLint* param), (vaobj, index, pname, param));
VDGL_GL_FN(void, glGetVertexArrayIndexed64iv, (GLuint vaobj, GLuint index, GLenum pname, GLint64* param), (vaobj, index, pname, param));
VDGL_GL_FN(void, glCreateSamplers, (GLsizei n, GLuint* samplers), (n, samplers));
VDGL_GL_FN(void, glCreateProgramPipelines, (GLsizei n, GLuint* pipelines), (n, pipelines));
VDGL_GL_FN(void, glCreateQueries, (GLenum target, GLsizei n, GLuint* ids), (target, n, ids));
VDGL_GL_FN(void, glGetQueryBufferObjecti64v, (GLuint id, GLuint buffer, GLenum pname, GLintptr offset), (id, buffer, pname, offset));
VDGL_GL_FN(void, glGetQueryBufferObjectiv, (GLuint id, GLuint buffer, GLenum pname, GLintptr offset), (id, buffer, pname, offset));
VDGL_GL_FN(void, glGetQueryBufferObjectui64v, (GLuint id, GLuint buffer, GLenum pname, GLintptr offset), (id, buffer, pname, offset));
VDGL_GL_FN(void, glGetQueryBufferObjectuiv, (GLuint id, GLuint buffer, GLenum pname, GLintptr offset), (id, buffer, pname, offset));
VDGL_GL_FN(void, glMemoryBarrierByRegion, (GLbitfield barriers), (barriers));
VDGL_GL_FN(void, glGetTextureSubImage, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void* pixels), (texture, level, xoffset, yoffset, zoffset, width, height, depth, format, type, bufSize, pixels));
VDGL_GL_FN(void, glGetCompressedTextureSubImage, (GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void* pixels), (texture, level, xoffset, yoffset, zoffset, width, height, depth, bufSize, pixels));
VDGL_GL_FN(GLenum, glGetGraphicsResetStatus, (void), ());
VDGL_GL_FN(void, glGetnCompressedTexImage, (GLenum target, GLint lod, GLsizei bufSize, void* pixels), (target, lod, bufSize, pixels));
VDGL_GL_FN(void, glGetnTexImage, (GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* pixels), (target, level, format, type, bufSize, pixels));
VDGL_GL_FN(void, glGetnUniformdv, (GLuint program, GLint location, GLsizei bufSize, GLdouble* params), (program, location, bufSize, params));
VDGL_GL_FN(void, glGetnUniformfv, (GLuint program, GLint location, GLsizei bufSize, GLfloat* params), (program, location, bufSize, params));
VDGL_GL_FN(void, glGetnUniformiv, (GLuint program, GLint location, GLsizei bufSize, GLint* params), (program, location, bufSize, params));
VDGL_GL_FN(void, glGetnUniformuiv, (GLuint program, GLint location, GLsizei bufSize, GLuint* params), (program, location, bufSize, params));
VDGL_GL_FN(void, glReadnPixels, (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data), (x, y, width, height, format, type, bufSize, data));
VDGL_GL_FN(void, glTextureBarrier, (void), ());


//////
////// 4.6
//////

#define GL_SHADER_BINARY_FORMAT_SPIR_V 0x9551
#define GL_SPIR_V_BINARY 0x9552
#define GL_PARAMETER_BUFFER 0x80EE
#define GL_PARAMETER_BUFFER_BINDING 0x80EF
#define GL_CONTEXT_FLAG_NO_ERROR_BIT 0x00000008
#define GL_VERTICES_SUBMITTED 0x82EE
#define GL_PRIMITIVES_SUBMITTED 0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS 0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES 0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS 0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED 0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS 0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS 0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES 0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES 0x82F7
#define GL_POLYGON_OFFSET_CLAMP 0x8E1B
#define GL_SPIR_V_EXTENSIONS 0x9553
#define GL_NUM_SPIR_V_EXTENSIONS 0x9554
#define GL_TEXTURE_MAX_ANISOTROPY 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY 0x84FF
#define GL_TRANSFORM_FEEDBACK_OVERFLOW 0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW 0x82ED

VDGL_GL_FN(void, glSpecializeShader, (GLuint shader, const GLchar* pEntryPoint, GLuint numSpecializationConstants, const GLuint* pConstantIndex, const GLuint* pConstantValue), (shader, pEntryPoint, numSpecializationConstants, pConstantIndex, pConstantValue));
VDGL_GL_FN(void, glMultiDrawArraysIndirectCount, (GLenum mode, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride), (mode, indirect, drawcount, maxdrawcount, stride));
VDGL_GL_FN(void, glMultiDrawElementsIndirectCount, (GLenum mode, GLenum type, const void* indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride), (mode, type, indirect, drawcount, maxdrawcount, stride));
VDGL_GL_FN(void, glPolygonOffsetClamp, (GLfloat factor, GLfloat units, GLfloat clamp), (factor, units, clamp));

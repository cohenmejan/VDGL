#include "VDGL.h"
#include "GLDefinitions.h"

void VDGL::LoadGLFunctions() {

	//////
	////// 1.0
	//////

	VDGL_LOAD_FN(glCullFace);
	VDGL_LOAD_FN(glFrontFace);
	VDGL_LOAD_FN(glHint);
	VDGL_LOAD_FN(glLineWidth);
	VDGL_LOAD_FN(glPointSize);
	VDGL_LOAD_FN(glPolygonMode);
	VDGL_LOAD_FN(glScissor);
	VDGL_LOAD_FN(glTexParameterf);
	VDGL_LOAD_FN(glTexParameterfv);
	VDGL_LOAD_FN(glTexParameteri);
	VDGL_LOAD_FN(glTexParameteriv);
	VDGL_LOAD_FN(glTexImage1D);
	VDGL_LOAD_FN(glTexImage2D);
	VDGL_LOAD_FN(glDrawBuffer);
	VDGL_LOAD_FN(glClear);
	VDGL_LOAD_FN(glClearColor);
	VDGL_LOAD_FN(glClearStencil);
	VDGL_LOAD_FN(glClearDepth);
	VDGL_LOAD_FN(glStencilMask);
	VDGL_LOAD_FN(glColorMask);
	VDGL_LOAD_FN(glDepthMask);
	VDGL_LOAD_FN(glDisable);
	VDGL_LOAD_FN(glEnable);
	VDGL_LOAD_FN(glFinish);
	VDGL_LOAD_FN(glFlush);
	VDGL_LOAD_FN(glBlendFunc);
	VDGL_LOAD_FN(glLogicOp);
	VDGL_LOAD_FN(glStencilFunc);
	VDGL_LOAD_FN(glStencilOp);
	VDGL_LOAD_FN(glDepthFunc);
	VDGL_LOAD_FN(glPixelStoref);
	VDGL_LOAD_FN(glPixelStorei);
	VDGL_LOAD_FN(glReadBuffer);
	VDGL_LOAD_FN(glReadPixels);
	VDGL_LOAD_FN(glGetBooleanv);
	VDGL_LOAD_FN(glGetDoublev);
	VDGL_LOAD_FN(glGetError);
	VDGL_LOAD_FN(glGetFloatv);
	VDGL_LOAD_FN(glGetIntegerv);
	VDGL_LOAD_FN(glGetString);
	VDGL_LOAD_FN(glGetTexImage);
	VDGL_LOAD_FN(glGetTexParameterfv);
	VDGL_LOAD_FN(glGetTexParameteriv);
	VDGL_LOAD_FN(glGetTexLevelParameterfv);
	VDGL_LOAD_FN(glGetTexLevelParameteriv);
	VDGL_LOAD_FN(glIsEnabled);
	VDGL_LOAD_FN(glDepthRange);
	VDGL_LOAD_FN(glViewport);

	//////
	////// Get version
	//////

	const GLubyte* version = glGetString(GL_VERSION);
	int majorVersion = version[0] - '0';
	int minorVersion = version[2] - '0';

	//////
	////// 1.1
	//////

	if(majorVersion >= 1 && minorVersion >= 1) {
		VDGL_LOAD_FN(glDrawArrays);
		VDGL_LOAD_FN(glDrawElements);
		VDGL_LOAD_FN(glGetPointerv);
		VDGL_LOAD_FN(glPolygonOffset);
		VDGL_LOAD_FN(glCopyTexImage1D);
		VDGL_LOAD_FN(glCopyTexImage2D);
		VDGL_LOAD_FN(glCopyTexSubImage1D);
		VDGL_LOAD_FN(glCopyTexSubImage2D);
		VDGL_LOAD_FN(glTexSubImage1D);
		VDGL_LOAD_FN(glTexSubImage2D);
		VDGL_LOAD_FN(glBindTexture);
		VDGL_LOAD_FN(glDeleteTextures);
		VDGL_LOAD_FN(glGenTextures);
		VDGL_LOAD_FN(glIsTexture);
	}
	else {
		return;
	}

	//////
	////// 1.2
	//////

	if(majorVersion >= 1 && minorVersion >= 2) {
		VDGL_LOAD_FN(glDrawRangeElements);
		VDGL_LOAD_FN(glTexImage3D);
		VDGL_LOAD_FN(glTexSubImage3D);
		VDGL_LOAD_FN(glCopyTexSubImage3D);
	}
	else {
		return;
	}

	//////
	////// 1.3
	//////

	if(majorVersion >= 1 && minorVersion >= 3) {
		VDGL_LOAD_FN(glActiveTexture);
		VDGL_LOAD_FN(glSampleCoverage);
		VDGL_LOAD_FN(glCompressedTexImage3D);
		VDGL_LOAD_FN(glCompressedTexImage2D);
		VDGL_LOAD_FN(glCompressedTexImage1D);
		VDGL_LOAD_FN(glCompressedTexSubImage3D);
		VDGL_LOAD_FN(glCompressedTexSubImage2D);
		VDGL_LOAD_FN(glCompressedTexSubImage1D);
		VDGL_LOAD_FN(glGetCompressedTexImage);
	}
	else {
		return;
	}

	//////
	////// 1.4
	//////

	if(majorVersion >= 1 && minorVersion >= 4) {
		VDGL_LOAD_FN(glBlendFuncSeparate);
		VDGL_LOAD_FN(glMultiDrawArrays);
		VDGL_LOAD_FN(glMultiDrawElements);
		VDGL_LOAD_FN(glPointParameterf);
		VDGL_LOAD_FN(glPointParameterfv);
		VDGL_LOAD_FN(glPointParameteri);
		VDGL_LOAD_FN(glPointParameteriv);
		VDGL_LOAD_FN(glBlendColor);
		VDGL_LOAD_FN(glBlendEquation);
	}
	else {
		return;
	}

	//////
	////// 1.5
	//////

	if(majorVersion >= 1 && minorVersion >= 5) {
		VDGL_LOAD_FN(glGenQueries);
		VDGL_LOAD_FN(glDeleteQueries);
		VDGL_LOAD_FN(glIsQuery);
		VDGL_LOAD_FN(glBeginQuery);
		VDGL_LOAD_FN(glEndQuery);
		VDGL_LOAD_FN(glGetQueryiv);
		VDGL_LOAD_FN(glGetQueryObjectiv);
		VDGL_LOAD_FN(glGetQueryObjectuiv);
		VDGL_LOAD_FN(glBindBuffer);
		VDGL_LOAD_FN(glDeleteBuffers);
		VDGL_LOAD_FN(glGenBuffers);
		VDGL_LOAD_FN(glIsBuffer);
		VDGL_LOAD_FN(glBufferData);
		VDGL_LOAD_FN(glBufferSubData);
		VDGL_LOAD_FN(glGetBufferSubData);
		VDGL_LOAD_FN(glMapBuffer);
		VDGL_LOAD_FN(glUnmapBuffer);
		VDGL_LOAD_FN(glGetBufferParameteriv);
		VDGL_LOAD_FN(glGetBufferPointerv);
	}
	else {
		return;
	}

	//////
	////// 2.0
	//////

	if(majorVersion >= 2 && minorVersion >= 0) {
		VDGL_LOAD_FN(glBlendEquationSeparate);
		VDGL_LOAD_FN(glDrawBuffers);
		VDGL_LOAD_FN(glStencilOpSeparate);
		VDGL_LOAD_FN(glStencilFuncSeparate);
		VDGL_LOAD_FN(glStencilMaskSeparate);
		VDGL_LOAD_FN(glAttachShader);
		VDGL_LOAD_FN(glBindAttribLocation);
		VDGL_LOAD_FN(glCompileShader);
		VDGL_LOAD_FN(glCreateProgram);
		VDGL_LOAD_FN(glCreateShader);
		VDGL_LOAD_FN(glDeleteProgram);
		VDGL_LOAD_FN(glDeleteShader);
		VDGL_LOAD_FN(glDetachShader);
		VDGL_LOAD_FN(glDisableVertexAttribArray);
		VDGL_LOAD_FN(glEnableVertexAttribArray);
		VDGL_LOAD_FN(glGetActiveAttrib);
		VDGL_LOAD_FN(glGetActiveUniform);
		VDGL_LOAD_FN(glGetAttachedShaders);
		VDGL_LOAD_FN(glGetAttribLocation);
		VDGL_LOAD_FN(glGetProgramiv);
		VDGL_LOAD_FN(glGetProgramInfoLog);
		VDGL_LOAD_FN(glGetShaderiv);
		VDGL_LOAD_FN(glGetShaderInfoLog);
		VDGL_LOAD_FN(glGetShaderSource);
		VDGL_LOAD_FN(glGetUniformLocation);
		VDGL_LOAD_FN(glGetUniformfv);
		VDGL_LOAD_FN(glGetUniformiv);
		VDGL_LOAD_FN(glGetVertexAttribdv);
		VDGL_LOAD_FN(glGetVertexAttribfv);
		VDGL_LOAD_FN(glGetVertexAttribiv);
		VDGL_LOAD_FN(glGetVertexAttribPointerv);
		VDGL_LOAD_FN(glIsProgram);
		VDGL_LOAD_FN(glIsShader);
		VDGL_LOAD_FN(glLinkProgram);
		VDGL_LOAD_FN(glShaderSource);
		VDGL_LOAD_FN(glUseProgram);
		VDGL_LOAD_FN(glUniform1f);
		VDGL_LOAD_FN(glUniform2f);
		VDGL_LOAD_FN(glUniform3f);
		VDGL_LOAD_FN(glUniform4f);
		VDGL_LOAD_FN(glUniform1i);
		VDGL_LOAD_FN(glUniform2i);
		VDGL_LOAD_FN(glUniform3i);
		VDGL_LOAD_FN(glUniform4i);
		VDGL_LOAD_FN(glUniform1fv);
		VDGL_LOAD_FN(glUniform2fv);
		VDGL_LOAD_FN(glUniform3fv);
		VDGL_LOAD_FN(glUniform4fv);
		VDGL_LOAD_FN(glUniform1iv);
		VDGL_LOAD_FN(glUniform2iv);
		VDGL_LOAD_FN(glUniform3iv);
		VDGL_LOAD_FN(glUniform4iv);
		VDGL_LOAD_FN(glUniformMatrix2fv);
		VDGL_LOAD_FN(glUniformMatrix3fv);
		VDGL_LOAD_FN(glUniformMatrix4fv);
		VDGL_LOAD_FN(glValidateProgram);
		VDGL_LOAD_FN(glVertexAttrib1d);
		VDGL_LOAD_FN(glVertexAttrib1dv);
		VDGL_LOAD_FN(glVertexAttrib1f);
		VDGL_LOAD_FN(glVertexAttrib1fv);
		VDGL_LOAD_FN(glVertexAttrib1s);
		VDGL_LOAD_FN(glVertexAttrib1sv);
		VDGL_LOAD_FN(glVertexAttrib2d);
		VDGL_LOAD_FN(glVertexAttrib2dv);
		VDGL_LOAD_FN(glVertexAttrib2f);
		VDGL_LOAD_FN(glVertexAttrib2fv);
		VDGL_LOAD_FN(glVertexAttrib2s);
		VDGL_LOAD_FN(glVertexAttrib2sv);
		VDGL_LOAD_FN(glVertexAttrib3d);
		VDGL_LOAD_FN(glVertexAttrib3dv);
		VDGL_LOAD_FN(glVertexAttrib3f);
		VDGL_LOAD_FN(glVertexAttrib3fv);
		VDGL_LOAD_FN(glVertexAttrib3s);
		VDGL_LOAD_FN(glVertexAttrib3sv);
		VDGL_LOAD_FN(glVertexAttrib4Nbv);
		VDGL_LOAD_FN(glVertexAttrib4Niv);
		VDGL_LOAD_FN(glVertexAttrib4Nsv);
		VDGL_LOAD_FN(glVertexAttrib4Nub);
		VDGL_LOAD_FN(glVertexAttrib4Nubv);
		VDGL_LOAD_FN(glVertexAttrib4Nuiv);
		VDGL_LOAD_FN(glVertexAttrib4Nusv);
		VDGL_LOAD_FN(glVertexAttrib4bv);
		VDGL_LOAD_FN(glVertexAttrib4d);
		VDGL_LOAD_FN(glVertexAttrib4dv);
		VDGL_LOAD_FN(glVertexAttrib4f);
		VDGL_LOAD_FN(glVertexAttrib4fv);
		VDGL_LOAD_FN(glVertexAttrib4iv);
		VDGL_LOAD_FN(glVertexAttrib4s);
		VDGL_LOAD_FN(glVertexAttrib4sv);
		VDGL_LOAD_FN(glVertexAttrib4ubv);
		VDGL_LOAD_FN(glVertexAttrib4uiv);
		VDGL_LOAD_FN(glVertexAttrib4usv);
		VDGL_LOAD_FN(glVertexAttribPointer);
	}
	else {
		return;
	}

	//////
	////// 2.1
	//////

	if(majorVersion >= 2 && minorVersion >= 1) {
		VDGL_LOAD_FN(glUniformMatrix2x3fv);
		VDGL_LOAD_FN(glUniformMatrix3x2fv);
		VDGL_LOAD_FN(glUniformMatrix2x4fv);
		VDGL_LOAD_FN(glUniformMatrix4x2fv);
		VDGL_LOAD_FN(glUniformMatrix3x4fv);
		VDGL_LOAD_FN(glUniformMatrix4x3fv);
	}
	else {
		return;
	}

	//////
	////// 3.0
	//////

	if(majorVersion >= 3 && minorVersion >= 0) {
		VDGL_LOAD_FN(glColorMaski);
		VDGL_LOAD_FN(glGetBooleani_v);
		VDGL_LOAD_FN(glGetIntegeri_v);
		VDGL_LOAD_FN(glEnablei);
		VDGL_LOAD_FN(glDisablei);
		VDGL_LOAD_FN(glIsEnabledi);
		VDGL_LOAD_FN(glBeginTransformFeedback);
		VDGL_LOAD_FN(glEndTransformFeedback);
		VDGL_LOAD_FN(glBindBufferRange);
		VDGL_LOAD_FN(glBindBufferBase);
		VDGL_LOAD_FN(glTransformFeedbackVaryings);
		VDGL_LOAD_FN(glGetTransformFeedbackVarying);
		VDGL_LOAD_FN(glClampColor);
		VDGL_LOAD_FN(glBeginConditionalRender);
		VDGL_LOAD_FN(glEndConditionalRender);
		VDGL_LOAD_FN(glVertexAttribIPointer);
		VDGL_LOAD_FN(glGetVertexAttribIiv);
		VDGL_LOAD_FN(glGetVertexAttribIuiv);
		VDGL_LOAD_FN(glVertexAttribI1i);
		VDGL_LOAD_FN(glVertexAttribI2i);
		VDGL_LOAD_FN(glVertexAttribI3i);
		VDGL_LOAD_FN(glVertexAttribI4i);
		VDGL_LOAD_FN(glVertexAttribI1ui);
		VDGL_LOAD_FN(glVertexAttribI2ui);
		VDGL_LOAD_FN(glVertexAttribI3ui);
		VDGL_LOAD_FN(glVertexAttribI4ui);
		VDGL_LOAD_FN(glVertexAttribI1iv);
		VDGL_LOAD_FN(glVertexAttribI2iv);
		VDGL_LOAD_FN(glVertexAttribI3iv);
		VDGL_LOAD_FN(glVertexAttribI4iv);
		VDGL_LOAD_FN(glVertexAttribI1uiv);
		VDGL_LOAD_FN(glVertexAttribI2uiv);
		VDGL_LOAD_FN(glVertexAttribI3uiv);
		VDGL_LOAD_FN(glVertexAttribI4uiv);
		VDGL_LOAD_FN(glVertexAttribI4bv);
		VDGL_LOAD_FN(glVertexAttribI4sv);
		VDGL_LOAD_FN(glVertexAttribI4ubv);
		VDGL_LOAD_FN(glVertexAttribI4usv);
		VDGL_LOAD_FN(glGetUniformuiv);
		VDGL_LOAD_FN(glBindFragDataLocation);
		VDGL_LOAD_FN(glGetFragDataLocation);
		VDGL_LOAD_FN(glUniform1ui);
		VDGL_LOAD_FN(glUniform2ui);
		VDGL_LOAD_FN(glUniform3ui);
		VDGL_LOAD_FN(glUniform4ui);
		VDGL_LOAD_FN(glUniform1uiv);
		VDGL_LOAD_FN(glUniform2uiv);
		VDGL_LOAD_FN(glUniform3uiv);
		VDGL_LOAD_FN(glUniform4uiv);
		VDGL_LOAD_FN(glTexParameterIiv);
		VDGL_LOAD_FN(glTexParameterIuiv);
		VDGL_LOAD_FN(glGetTexParameterIiv);
		VDGL_LOAD_FN(glGetTexParameterIuiv);
		VDGL_LOAD_FN(glClearBufferiv);
		VDGL_LOAD_FN(glClearBufferuiv);
		VDGL_LOAD_FN(glClearBufferfv);
		VDGL_LOAD_FN(glClearBufferfi);
		VDGL_LOAD_FN(glGetStringi);
		VDGL_LOAD_FN(glIsRenderbuffer);
		VDGL_LOAD_FN(glBindRenderbuffer);
		VDGL_LOAD_FN(glDeleteRenderbuffers);
		VDGL_LOAD_FN(glGenRenderbuffers);
		VDGL_LOAD_FN(glRenderbufferStorage);
		VDGL_LOAD_FN(glGetRenderbufferParameteriv);
		VDGL_LOAD_FN(glIsFramebuffer);
		VDGL_LOAD_FN(glBindFramebuffer);
		VDGL_LOAD_FN(glDeleteFramebuffers);
		VDGL_LOAD_FN(glGenFramebuffers);
		VDGL_LOAD_FN(glCheckFramebufferStatus);
		VDGL_LOAD_FN(glFramebufferTexture1D);
		VDGL_LOAD_FN(glFramebufferTexture2D);
		VDGL_LOAD_FN(glFramebufferTexture3D);
		VDGL_LOAD_FN(glFramebufferRenderbuffer);
		VDGL_LOAD_FN(glGetFramebufferAttachmentParameteriv);
		VDGL_LOAD_FN(glGenerateMipmap);
		VDGL_LOAD_FN(glBlitFramebuffer);
		VDGL_LOAD_FN(glRenderbufferStorageMultisample);
		VDGL_LOAD_FN(glFramebufferTextureLayer);
		VDGL_LOAD_FN(glMapBufferRange);
		VDGL_LOAD_FN(glFlushMappedBufferRange);
		VDGL_LOAD_FN(glBindVertexArray);
		VDGL_LOAD_FN(glDeleteVertexArrays);
		VDGL_LOAD_FN(glGenVertexArrays);
		VDGL_LOAD_FN(glIsVertexArray);
	}
	else {
		return;
	}

	//////
	////// 3.1
	//////

	if(majorVersion >= 3 && minorVersion >= 1) {
		VDGL_LOAD_FN(glDrawArraysInstanced);
		VDGL_LOAD_FN(glDrawElementsInstanced);
		VDGL_LOAD_FN(glTexBuffer);
		VDGL_LOAD_FN(glPrimitiveRestartIndex);
		VDGL_LOAD_FN(glCopyBufferSubData);
		VDGL_LOAD_FN(glGetUniformIndices);
		VDGL_LOAD_FN(glGetActiveUniformsiv);
		VDGL_LOAD_FN(glGetActiveUniformName);
		VDGL_LOAD_FN(glGetUniformBlockIndex);
		VDGL_LOAD_FN(glGetActiveUniformBlockiv);
		VDGL_LOAD_FN(glGetActiveUniformBlockName);
		VDGL_LOAD_FN(glUniformBlockBinding);
	}
	else {
		return;
	}

	//////
	////// 3.2
	//////

	if(majorVersion >= 3 && minorVersion >= 2) {
		VDGL_LOAD_FN(glDrawElementsBaseVertex);
		VDGL_LOAD_FN(glDrawRangeElementsBaseVertex);
		VDGL_LOAD_FN(glDrawElementsInstancedBaseVertex);
		VDGL_LOAD_FN(glMultiDrawElementsBaseVertex);
		VDGL_LOAD_FN(glProvokingVertex);
		VDGL_LOAD_FN(glFenceSync);
		VDGL_LOAD_FN(glIsSync);
		VDGL_LOAD_FN(glDeleteSync);
		VDGL_LOAD_FN(glClientWaitSync);
		VDGL_LOAD_FN(glWaitSync);
		VDGL_LOAD_FN(glGetInteger64v);
		VDGL_LOAD_FN(glGetSynciv);
		VDGL_LOAD_FN(glGetInteger64i_v);
		VDGL_LOAD_FN(glGetBufferParameteri64v);
		VDGL_LOAD_FN(glFramebufferTexture);
		VDGL_LOAD_FN(glTexImage2DMultisample);
		VDGL_LOAD_FN(glTexImage3DMultisample);
		VDGL_LOAD_FN(glGetMultisamplefv);
		VDGL_LOAD_FN(glSampleMaski);
	}
	else {
		return;
	}

	//////
	////// 3.3
	//////

	if(majorVersion >= 3 && minorVersion >= 3) {
		VDGL_LOAD_FN(glBindFragDataLocationIndexed);
		VDGL_LOAD_FN(glGetFragDataIndex);
		VDGL_LOAD_FN(glGenSamplers);
		VDGL_LOAD_FN(glDeleteSamplers);
		VDGL_LOAD_FN(glIsSampler);
		VDGL_LOAD_FN(glBindSampler);
		VDGL_LOAD_FN(glSamplerParameteri);
		VDGL_LOAD_FN(glSamplerParameteriv);
		VDGL_LOAD_FN(glSamplerParameterf);
		VDGL_LOAD_FN(glSamplerParameterfv);
		VDGL_LOAD_FN(glSamplerParameterIiv);
		VDGL_LOAD_FN(glSamplerParameterIuiv);
		VDGL_LOAD_FN(glGetSamplerParameteriv);
		VDGL_LOAD_FN(glGetSamplerParameterIiv);
		VDGL_LOAD_FN(glGetSamplerParameterfv);
		VDGL_LOAD_FN(glGetSamplerParameterIuiv);
		VDGL_LOAD_FN(glQueryCounter);
		VDGL_LOAD_FN(glGetQueryObjecti64v);
		VDGL_LOAD_FN(glGetQueryObjectui64v);
		VDGL_LOAD_FN(glVertexAttribDivisor);
		VDGL_LOAD_FN(glVertexAttribP1ui);
		VDGL_LOAD_FN(glVertexAttribP1uiv);
		VDGL_LOAD_FN(glVertexAttribP2ui);
		VDGL_LOAD_FN(glVertexAttribP2uiv);
		VDGL_LOAD_FN(glVertexAttribP3ui);
		VDGL_LOAD_FN(glVertexAttribP3uiv);
		VDGL_LOAD_FN(glVertexAttribP4ui);
		VDGL_LOAD_FN(glVertexAttribP4uiv);
	}
	else {
		return;
	}

	//////
	////// 4.0
	//////

	if(majorVersion >= 4 && minorVersion >= 0) {
		VDGL_LOAD_FN(glMinSampleShading);
		VDGL_LOAD_FN(glBlendEquationi);
		VDGL_LOAD_FN(glBlendEquationSeparatei);
		VDGL_LOAD_FN(glBlendFunci);
		VDGL_LOAD_FN(glBlendFuncSeparatei);
		VDGL_LOAD_FN(glDrawArraysIndirect);
		VDGL_LOAD_FN(glDrawElementsIndirect);
		VDGL_LOAD_FN(glUniform1d);
		VDGL_LOAD_FN(glUniform2d);
		VDGL_LOAD_FN(glUniform3d);
		VDGL_LOAD_FN(glUniform4d);
		VDGL_LOAD_FN(glUniform1dv);
		VDGL_LOAD_FN(glUniform2dv);
		VDGL_LOAD_FN(glUniform3dv);
		VDGL_LOAD_FN(glUniform4dv);
		VDGL_LOAD_FN(glUniformMatrix2dv);
		VDGL_LOAD_FN(glUniformMatrix3dv);
		VDGL_LOAD_FN(glUniformMatrix4dv);
		VDGL_LOAD_FN(glUniformMatrix2x3dv);
		VDGL_LOAD_FN(glUniformMatrix2x4dv);
		VDGL_LOAD_FN(glUniformMatrix3x2dv);
		VDGL_LOAD_FN(glUniformMatrix3x4dv);
		VDGL_LOAD_FN(glUniformMatrix4x2dv);
		VDGL_LOAD_FN(glUniformMatrix4x3dv);
		VDGL_LOAD_FN(glGetUniformdv);
		VDGL_LOAD_FN(glGetSubroutineUniformLocation);
		VDGL_LOAD_FN(glGetSubroutineIndex);
		VDGL_LOAD_FN(glGetActiveSubroutineUniformiv);
		VDGL_LOAD_FN(glGetActiveSubroutineUniformName);
		VDGL_LOAD_FN(glGetActiveSubroutineName);
		VDGL_LOAD_FN(glUniformSubroutinesuiv);
		VDGL_LOAD_FN(glGetUniformSubroutineuiv);
		VDGL_LOAD_FN(glGetProgramStageiv);
		VDGL_LOAD_FN(glPatchParameteri);
		VDGL_LOAD_FN(glPatchParameterfv);
		VDGL_LOAD_FN(glBindTransformFeedback);
		VDGL_LOAD_FN(glDeleteTransformFeedbacks);
		VDGL_LOAD_FN(glGenTransformFeedbacks);
		VDGL_LOAD_FN(glIsTransformFeedback);
		VDGL_LOAD_FN(glPauseTransformFeedback);
		VDGL_LOAD_FN(glResumeTransformFeedback);
		VDGL_LOAD_FN(glDrawTransformFeedback);
		VDGL_LOAD_FN(glDrawTransformFeedbackStream);
		VDGL_LOAD_FN(glBeginQueryIndexed);
		VDGL_LOAD_FN(glEndQueryIndexed);
		VDGL_LOAD_FN(glGetQueryIndexediv);
	}
	else {
		return;
	}

	//////
	////// 4.1
	//////

	if(majorVersion >= 4 && minorVersion >= 1) {
		VDGL_LOAD_FN(glReleaseShaderCompiler);
		VDGL_LOAD_FN(glShaderBinary);
		VDGL_LOAD_FN(glGetShaderPrecisionFormat);
		VDGL_LOAD_FN(glDepthRangef);
		VDGL_LOAD_FN(glClearDepthf);
		VDGL_LOAD_FN(glGetProgramBinary);
		VDGL_LOAD_FN(glProgramBinary);
		VDGL_LOAD_FN(glProgramParameteri);
		VDGL_LOAD_FN(glUseProgramStages);
		VDGL_LOAD_FN(glActiveShaderProgram);
		VDGL_LOAD_FN(glCreateShaderProgramv);
		VDGL_LOAD_FN(glBindProgramPipeline);
		VDGL_LOAD_FN(glDeleteProgramPipelines);
		VDGL_LOAD_FN(glGenProgramPipelines);
		VDGL_LOAD_FN(glIsProgramPipeline);
		VDGL_LOAD_FN(glGetProgramPipelineiv);
		VDGL_LOAD_FN(glProgramUniform1i);
		VDGL_LOAD_FN(glProgramUniform1iv);
		VDGL_LOAD_FN(glProgramUniform1f);
		VDGL_LOAD_FN(glProgramUniform1fv);
		VDGL_LOAD_FN(glProgramUniform1d);
		VDGL_LOAD_FN(glProgramUniform1dv);
		VDGL_LOAD_FN(glProgramUniform1ui);
		VDGL_LOAD_FN(glProgramUniform1uiv);
		VDGL_LOAD_FN(glProgramUniform2i);
		VDGL_LOAD_FN(glProgramUniform2iv);
		VDGL_LOAD_FN(glProgramUniform2f);
		VDGL_LOAD_FN(glProgramUniform2fv);
		VDGL_LOAD_FN(glProgramUniform2d);
		VDGL_LOAD_FN(glProgramUniform2dv);
		VDGL_LOAD_FN(glProgramUniform2ui);
		VDGL_LOAD_FN(glProgramUniform2uiv);
		VDGL_LOAD_FN(glProgramUniform3i);
		VDGL_LOAD_FN(glProgramUniform3iv);
		VDGL_LOAD_FN(glProgramUniform3f);
		VDGL_LOAD_FN(glProgramUniform3fv);
		VDGL_LOAD_FN(glProgramUniform3d);
		VDGL_LOAD_FN(glProgramUniform3dv);
		VDGL_LOAD_FN(glProgramUniform3ui);
		VDGL_LOAD_FN(glProgramUniform3uiv);
		VDGL_LOAD_FN(glProgramUniform4i);
		VDGL_LOAD_FN(glProgramUniform4iv);
		VDGL_LOAD_FN(glProgramUniform4f);
		VDGL_LOAD_FN(glProgramUniform4fv);
		VDGL_LOAD_FN(glProgramUniform4d);
		VDGL_LOAD_FN(glProgramUniform4dv);
		VDGL_LOAD_FN(glProgramUniform4ui);
		VDGL_LOAD_FN(glProgramUniform4uiv);
		VDGL_LOAD_FN(glProgramUniformMatrix2fv);
		VDGL_LOAD_FN(glProgramUniformMatrix3fv);
		VDGL_LOAD_FN(glProgramUniformMatrix4fv);
		VDGL_LOAD_FN(glProgramUniformMatrix2dv);
		VDGL_LOAD_FN(glProgramUniformMatrix3dv);
		VDGL_LOAD_FN(glProgramUniformMatrix4dv);
		VDGL_LOAD_FN(glProgramUniformMatrix2x3fv);
		VDGL_LOAD_FN(glProgramUniformMatrix3x2fv);
		VDGL_LOAD_FN(glProgramUniformMatrix2x4fv);
		VDGL_LOAD_FN(glProgramUniformMatrix4x2fv);
		VDGL_LOAD_FN(glProgramUniformMatrix3x4fv);
		VDGL_LOAD_FN(glProgramUniformMatrix4x3fv);
		VDGL_LOAD_FN(glProgramUniformMatrix2x3dv);
		VDGL_LOAD_FN(glProgramUniformMatrix3x2dv);
		VDGL_LOAD_FN(glProgramUniformMatrix2x4dv);
		VDGL_LOAD_FN(glProgramUniformMatrix4x2dv);
		VDGL_LOAD_FN(glProgramUniformMatrix3x4dv);
		VDGL_LOAD_FN(glProgramUniformMatrix4x3dv);
		VDGL_LOAD_FN(glValidateProgramPipeline);
		VDGL_LOAD_FN(glGetProgramPipelineInfoLog);
		VDGL_LOAD_FN(glVertexAttribL1d);
		VDGL_LOAD_FN(glVertexAttribL2d);
		VDGL_LOAD_FN(glVertexAttribL3d);
		VDGL_LOAD_FN(glVertexAttribL4d);
		VDGL_LOAD_FN(glVertexAttribL1dv);
		VDGL_LOAD_FN(glVertexAttribL2dv);
		VDGL_LOAD_FN(glVertexAttribL3dv);
		VDGL_LOAD_FN(glVertexAttribL4dv);
		VDGL_LOAD_FN(glVertexAttribLPointer);
		VDGL_LOAD_FN(glGetVertexAttribLdv);
		VDGL_LOAD_FN(glViewportArrayv);
		VDGL_LOAD_FN(glViewportIndexedf);
		VDGL_LOAD_FN(glViewportIndexedfv);
		VDGL_LOAD_FN(glScissorArrayv);
		VDGL_LOAD_FN(glScissorIndexed);
		VDGL_LOAD_FN(glScissorIndexedv);
		VDGL_LOAD_FN(glDepthRangeArrayv);
		VDGL_LOAD_FN(glDepthRangeIndexed);
		VDGL_LOAD_FN(glGetFloati_v);
		VDGL_LOAD_FN(glGetDoublei_v);
	}
	else {
		return;
	}

	//////
	////// 4.2
	//////

	if(majorVersion >= 4 && minorVersion >= 2) {
		VDGL_LOAD_FN(glDrawArraysInstancedBaseInstance);
		VDGL_LOAD_FN(glDrawElementsInstancedBaseInstance);
		VDGL_LOAD_FN(glDrawElementsInstancedBaseVertexBaseInstance);
		VDGL_LOAD_FN(glGetInternalformativ);
		VDGL_LOAD_FN(glGetActiveAtomicCounterBufferiv);
		VDGL_LOAD_FN(glBindImageTexture);
		VDGL_LOAD_FN(glMemoryBarrier);
		VDGL_LOAD_FN(glTexStorage1D);
		VDGL_LOAD_FN(glTexStorage2D);
		VDGL_LOAD_FN(glTexStorage3D);
		VDGL_LOAD_FN(glDrawTransformFeedbackInstanced);
		VDGL_LOAD_FN(glDrawTransformFeedbackStreamInstanced);
	}
	else {
		return;
	}

	//////
	////// 4.3
	//////

	if(majorVersion >= 4 && minorVersion >= 3) {
		VDGL_LOAD_FN(glClearBufferData);
		VDGL_LOAD_FN(glClearBufferSubData);
		VDGL_LOAD_FN(glDispatchCompute);
		VDGL_LOAD_FN(glDispatchComputeIndirect);
		VDGL_LOAD_FN(glCopyImageSubData);
		VDGL_LOAD_FN(glFramebufferParameteri);
		VDGL_LOAD_FN(glGetFramebufferParameteriv);
		VDGL_LOAD_FN(glGetInternalformati64v);
		VDGL_LOAD_FN(glInvalidateTexSubImage);
		VDGL_LOAD_FN(glInvalidateTexImage);
		VDGL_LOAD_FN(glInvalidateBufferSubData);
		VDGL_LOAD_FN(glInvalidateBufferData);
		VDGL_LOAD_FN(glInvalidateFramebuffer);
		VDGL_LOAD_FN(glInvalidateSubFramebuffer);
		VDGL_LOAD_FN(glMultiDrawArraysIndirect);
		VDGL_LOAD_FN(glMultiDrawElementsIndirect);
		VDGL_LOAD_FN(glGetProgramInterfaceiv);
		VDGL_LOAD_FN(glGetProgramResourceIndex);
		VDGL_LOAD_FN(glGetProgramResourceName);
		VDGL_LOAD_FN(glGetProgramResourceiv);
		VDGL_LOAD_FN(glGetProgramResourceLocation);
		VDGL_LOAD_FN(glGetProgramResourceLocationIndex);
		VDGL_LOAD_FN(glShaderStorageBlockBinding);
		VDGL_LOAD_FN(glTexBufferRange);
		VDGL_LOAD_FN(glTexStorage2DMultisample);
		VDGL_LOAD_FN(glTexStorage3DMultisample);
		VDGL_LOAD_FN(glTextureView);
		VDGL_LOAD_FN(glBindVertexBuffer);
		VDGL_LOAD_FN(glVertexAttribFormat);
		VDGL_LOAD_FN(glVertexAttribIFormat);
		VDGL_LOAD_FN(glVertexAttribLFormat);
		VDGL_LOAD_FN(glVertexAttribBinding);
		VDGL_LOAD_FN(glVertexBindingDivisor);
		VDGL_LOAD_FN(glDebugMessageControl);
		VDGL_LOAD_FN(glDebugMessageInsert);
		VDGL_LOAD_FN(glDebugMessageCallback);
		VDGL_LOAD_FN(glGetDebugMessageLog);
		VDGL_LOAD_FN(glPushDebugGroup);
		VDGL_LOAD_FN(glPopDebugGroup);
		VDGL_LOAD_FN(glObjectLabel);
		VDGL_LOAD_FN(glGetObjectLabel);
		VDGL_LOAD_FN(glObjectPtrLabel);
		VDGL_LOAD_FN(glGetObjectPtrLabel);
	}
	else {
		return;
	}

	//////
	////// 4.4
	//////

	if(majorVersion >= 4 && minorVersion >= 4) {
		VDGL_LOAD_FN(glBufferStorage);
		VDGL_LOAD_FN(glClearTexImage);
		VDGL_LOAD_FN(glClearTexSubImage);
		VDGL_LOAD_FN(glBindBuffersBase);
		VDGL_LOAD_FN(glBindBuffersRange);
		VDGL_LOAD_FN(glBindTextures);
		VDGL_LOAD_FN(glBindSamplers);
		VDGL_LOAD_FN(glBindImageTextures);
		VDGL_LOAD_FN(glBindVertexBuffers);
	}
	else {
		return;
	}

	//////
	////// 4.5
	//////

	if(majorVersion >= 4 && minorVersion >= 5) {
		VDGL_LOAD_FN(glClipControl);
		VDGL_LOAD_FN(glCreateTransformFeedbacks);
		VDGL_LOAD_FN(glTransformFeedbackBufferBase);
		VDGL_LOAD_FN(glTransformFeedbackBufferRange);
		VDGL_LOAD_FN(glGetTransformFeedbackiv);
		VDGL_LOAD_FN(glGetTransformFeedbacki_v);
		VDGL_LOAD_FN(glGetTransformFeedbacki64_v);
		VDGL_LOAD_FN(glCreateBuffers);
		VDGL_LOAD_FN(glNamedBufferStorage);
		VDGL_LOAD_FN(glNamedBufferData);
		VDGL_LOAD_FN(glNamedBufferSubData);
		VDGL_LOAD_FN(glCopyNamedBufferSubData);
		VDGL_LOAD_FN(glClearNamedBufferData);
		VDGL_LOAD_FN(glClearNamedBufferSubData);
		VDGL_LOAD_FN(glMapNamedBuffer);
		VDGL_LOAD_FN(glMapNamedBufferRange);
		VDGL_LOAD_FN(glUnmapNamedBuffer);
		VDGL_LOAD_FN(glFlushMappedNamedBufferRange);
		VDGL_LOAD_FN(glGetNamedBufferParameteriv);
		VDGL_LOAD_FN(glGetNamedBufferParameteri64v);
		VDGL_LOAD_FN(glGetNamedBufferPointerv);
		VDGL_LOAD_FN(glGetNamedBufferSubData);
		VDGL_LOAD_FN(glCreateFramebuffers);
		VDGL_LOAD_FN(glNamedFramebufferRenderbuffer);
		VDGL_LOAD_FN(glNamedFramebufferParameteri);
		VDGL_LOAD_FN(glNamedFramebufferTexture);
		VDGL_LOAD_FN(glNamedFramebufferTextureLayer);
		VDGL_LOAD_FN(glNamedFramebufferDrawBuffer);
		VDGL_LOAD_FN(glNamedFramebufferDrawBuffers);
		VDGL_LOAD_FN(glNamedFramebufferReadBuffer);
		VDGL_LOAD_FN(glInvalidateNamedFramebufferData);
		VDGL_LOAD_FN(glInvalidateNamedFramebufferSubData);
		VDGL_LOAD_FN(glClearNamedFramebufferiv);
		VDGL_LOAD_FN(glClearNamedFramebufferuiv);
		VDGL_LOAD_FN(glClearNamedFramebufferfv);
		VDGL_LOAD_FN(glClearNamedFramebufferfi);
		VDGL_LOAD_FN(glBlitNamedFramebuffer);
		VDGL_LOAD_FN(glCheckNamedFramebufferStatus);
		VDGL_LOAD_FN(glGetNamedFramebufferParameteriv);
		VDGL_LOAD_FN(glGetNamedFramebufferAttachmentParameteriv);
		VDGL_LOAD_FN(glCreateRenderbuffers);
		VDGL_LOAD_FN(glNamedRenderbufferStorage);
		VDGL_LOAD_FN(glNamedRenderbufferStorageMultisample);
		VDGL_LOAD_FN(glGetNamedRenderbufferParameteriv);
		VDGL_LOAD_FN(glCreateTextures);
		VDGL_LOAD_FN(glTextureBuffer);
		VDGL_LOAD_FN(glTextureBufferRange);
		VDGL_LOAD_FN(glTextureStorage1D);
		VDGL_LOAD_FN(glTextureStorage2D);
		VDGL_LOAD_FN(glTextureStorage3D);
		VDGL_LOAD_FN(glTextureStorage2DMultisample);
		VDGL_LOAD_FN(glTextureStorage3DMultisample);
		VDGL_LOAD_FN(glTextureSubImage1D);
		VDGL_LOAD_FN(glTextureSubImage2D);
		VDGL_LOAD_FN(glTextureSubImage3D);
		VDGL_LOAD_FN(glCompressedTextureSubImage1D);
		VDGL_LOAD_FN(glCompressedTextureSubImage2D);
		VDGL_LOAD_FN(glCompressedTextureSubImage3D);
		VDGL_LOAD_FN(glCopyTextureSubImage1D);
		VDGL_LOAD_FN(glCopyTextureSubImage2D);
		VDGL_LOAD_FN(glCopyTextureSubImage3D);
		VDGL_LOAD_FN(glTextureParameterf);
		VDGL_LOAD_FN(glTextureParameterfv);
		VDGL_LOAD_FN(glTextureParameteri);
		VDGL_LOAD_FN(glTextureParameterIiv);
		VDGL_LOAD_FN(glTextureParameterIuiv);
		VDGL_LOAD_FN(glTextureParameteriv);
		VDGL_LOAD_FN(glGenerateTextureMipmap);
		VDGL_LOAD_FN(glBindTextureUnit);
		VDGL_LOAD_FN(glGetTextureImage);
		VDGL_LOAD_FN(glGetCompressedTextureImage);
		VDGL_LOAD_FN(glGetTextureLevelParameterfv);
		VDGL_LOAD_FN(glGetTextureLevelParameteriv);
		VDGL_LOAD_FN(glGetTextureParameterfv);
		VDGL_LOAD_FN(glGetTextureParameterIiv);
		VDGL_LOAD_FN(glGetTextureParameterIuiv);
		VDGL_LOAD_FN(glGetTextureParameteriv);
		VDGL_LOAD_FN(glCreateVertexArrays);
		VDGL_LOAD_FN(glDisableVertexArrayAttrib);
		VDGL_LOAD_FN(glEnableVertexArrayAttrib);
		VDGL_LOAD_FN(glVertexArrayElementBuffer);
		VDGL_LOAD_FN(glVertexArrayVertexBuffer);
		VDGL_LOAD_FN(glVertexArrayVertexBuffers);
		VDGL_LOAD_FN(glVertexArrayAttribBinding);
		VDGL_LOAD_FN(glVertexArrayAttribFormat);
		VDGL_LOAD_FN(glVertexArrayAttribIFormat);
		VDGL_LOAD_FN(glVertexArrayAttribLFormat);
		VDGL_LOAD_FN(glVertexArrayBindingDivisor);
		VDGL_LOAD_FN(glGetVertexArrayiv);
		VDGL_LOAD_FN(glGetVertexArrayIndexediv);
		VDGL_LOAD_FN(glGetVertexArrayIndexed64iv);
		VDGL_LOAD_FN(glCreateSamplers);
		VDGL_LOAD_FN(glCreateProgramPipelines);
		VDGL_LOAD_FN(glCreateQueries);
		VDGL_LOAD_FN(glGetQueryBufferObjecti64v);
		VDGL_LOAD_FN(glGetQueryBufferObjectiv);
		VDGL_LOAD_FN(glGetQueryBufferObjectui64v);
		VDGL_LOAD_FN(glGetQueryBufferObjectuiv);
		VDGL_LOAD_FN(glMemoryBarrierByRegion);
		VDGL_LOAD_FN(glGetTextureSubImage);
		VDGL_LOAD_FN(glGetCompressedTextureSubImage);
		VDGL_LOAD_FN(glGetGraphicsResetStatus);
		VDGL_LOAD_FN(glGetnCompressedTexImage);
		VDGL_LOAD_FN(glGetnTexImage);
		VDGL_LOAD_FN(glGetnUniformdv);
		VDGL_LOAD_FN(glGetnUniformfv);
		VDGL_LOAD_FN(glGetnUniformiv);
		VDGL_LOAD_FN(glGetnUniformuiv);
		VDGL_LOAD_FN(glReadnPixels);
		VDGL_LOAD_FN(glTextureBarrier);
	}
	else {
		return;
	}

	//////
	////// 4.6
	//////

	if(majorVersion >= 4 && minorVersion >= 6) {
		VDGL_LOAD_FN(glSpecializeShader);
		VDGL_LOAD_FN(glMultiDrawArraysIndirectCount);
		VDGL_LOAD_FN(glMultiDrawElementsIndirectCount);
		VDGL_LOAD_FN(glPolygonOffsetClamp);
	}
	else {
		return;
	}
}

void VDGL::UnloadGLFunctions() {
	_vdgl_glCullFace = nullptr;
	_vdgl_glFrontFace = nullptr;
	_vdgl_glHint = nullptr;
	_vdgl_glLineWidth = nullptr;
	_vdgl_glPointSize = nullptr;
	_vdgl_glPolygonMode = nullptr;
	_vdgl_glScissor = nullptr;
	_vdgl_glTexParameterf = nullptr;
	_vdgl_glTexParameterfv = nullptr;
	_vdgl_glTexParameteri = nullptr;
	_vdgl_glTexParameteriv = nullptr;
	_vdgl_glTexImage1D = nullptr;
	_vdgl_glTexImage2D = nullptr;
	_vdgl_glDrawBuffer = nullptr;
	_vdgl_glClear = nullptr;
	_vdgl_glClearColor = nullptr;
	_vdgl_glClearStencil = nullptr;
	_vdgl_glClearDepth = nullptr;
	_vdgl_glStencilMask = nullptr;
	_vdgl_glColorMask = nullptr;
	_vdgl_glDepthMask = nullptr;
	_vdgl_glDisable = nullptr;
	_vdgl_glEnable = nullptr;
	_vdgl_glFinish = nullptr;
	_vdgl_glFlush = nullptr;
	_vdgl_glBlendFunc = nullptr;
	_vdgl_glLogicOp = nullptr;
	_vdgl_glStencilFunc = nullptr;
	_vdgl_glStencilOp = nullptr;
	_vdgl_glDepthFunc = nullptr;
	_vdgl_glPixelStoref = nullptr;
	_vdgl_glPixelStorei = nullptr;
	_vdgl_glReadBuffer = nullptr;
	_vdgl_glReadPixels = nullptr;
	_vdgl_glGetBooleanv = nullptr;
	_vdgl_glGetDoublev = nullptr;
	_vdgl_glGetError = nullptr;
	_vdgl_glGetFloatv = nullptr;
	_vdgl_glGetIntegerv = nullptr;
	_vdgl_glGetString = nullptr;
	_vdgl_glGetTexImage = nullptr;
	_vdgl_glGetTexParameterfv = nullptr;
	_vdgl_glGetTexParameteriv = nullptr;
	_vdgl_glGetTexLevelParameterfv = nullptr;
	_vdgl_glGetTexLevelParameteriv = nullptr;
	_vdgl_glIsEnabled = nullptr;
	_vdgl_glDepthRange = nullptr;
	_vdgl_glViewport = nullptr;
	_vdgl_glDrawArrays = nullptr;
	_vdgl_glDrawElements = nullptr;
	_vdgl_glGetPointerv = nullptr;
	_vdgl_glPolygonOffset = nullptr;
	_vdgl_glCopyTexImage1D = nullptr;
	_vdgl_glCopyTexImage2D = nullptr;
	_vdgl_glCopyTexSubImage1D = nullptr;
	_vdgl_glCopyTexSubImage2D = nullptr;
	_vdgl_glTexSubImage1D = nullptr;
	_vdgl_glTexSubImage2D = nullptr;
	_vdgl_glBindTexture = nullptr;
	_vdgl_glDeleteTextures = nullptr;
	_vdgl_glGenTextures = nullptr;
	_vdgl_glIsTexture = nullptr;
	_vdgl_glDrawRangeElements = nullptr;
	_vdgl_glTexImage3D = nullptr;
	_vdgl_glTexSubImage3D = nullptr;
	_vdgl_glCopyTexSubImage3D = nullptr;
	_vdgl_glActiveTexture = nullptr;
	_vdgl_glSampleCoverage = nullptr;
	_vdgl_glCompressedTexImage3D = nullptr;
	_vdgl_glCompressedTexImage2D = nullptr;
	_vdgl_glCompressedTexImage1D = nullptr;
	_vdgl_glCompressedTexSubImage3D = nullptr;
	_vdgl_glCompressedTexSubImage2D = nullptr;
	_vdgl_glCompressedTexSubImage1D = nullptr;
	_vdgl_glGetCompressedTexImage = nullptr;
	_vdgl_glBlendFuncSeparate = nullptr;
	_vdgl_glMultiDrawArrays = nullptr;
	_vdgl_glMultiDrawElements = nullptr;
	_vdgl_glPointParameterf = nullptr;
	_vdgl_glPointParameterfv = nullptr;
	_vdgl_glPointParameteri = nullptr;
	_vdgl_glPointParameteriv = nullptr;
	_vdgl_glBlendColor = nullptr;
	_vdgl_glBlendEquation = nullptr;
	_vdgl_glGenQueries = nullptr;
	_vdgl_glDeleteQueries = nullptr;
	_vdgl_glIsQuery = nullptr;
	_vdgl_glBeginQuery = nullptr;
	_vdgl_glEndQuery = nullptr;
	_vdgl_glGetQueryiv = nullptr;
	_vdgl_glGetQueryObjectiv = nullptr;
	_vdgl_glGetQueryObjectuiv = nullptr;
	_vdgl_glBindBuffer = nullptr;
	_vdgl_glDeleteBuffers = nullptr;
	_vdgl_glGenBuffers = nullptr;
	_vdgl_glIsBuffer = nullptr;
	_vdgl_glBufferData = nullptr;
	_vdgl_glBufferSubData = nullptr;
	_vdgl_glGetBufferSubData = nullptr;
	_vdgl_glMapBuffer = nullptr;
	_vdgl_glUnmapBuffer = nullptr;
	_vdgl_glGetBufferParameteriv = nullptr;
	_vdgl_glGetBufferPointerv = nullptr;
	_vdgl_glBlendEquationSeparate = nullptr;
	_vdgl_glDrawBuffers = nullptr;
	_vdgl_glStencilOpSeparate = nullptr;
	_vdgl_glStencilFuncSeparate = nullptr;
	_vdgl_glStencilMaskSeparate = nullptr;
	_vdgl_glAttachShader = nullptr;
	_vdgl_glBindAttribLocation = nullptr;
	_vdgl_glCompileShader = nullptr;
	_vdgl_glCreateProgram = nullptr;
	_vdgl_glCreateShader = nullptr;
	_vdgl_glDeleteProgram = nullptr;
	_vdgl_glDeleteShader = nullptr;
	_vdgl_glDetachShader = nullptr;
	_vdgl_glDisableVertexAttribArray = nullptr;
	_vdgl_glEnableVertexAttribArray = nullptr;
	_vdgl_glGetActiveAttrib = nullptr;
	_vdgl_glGetActiveUniform = nullptr;
	_vdgl_glGetAttachedShaders = nullptr;
	_vdgl_glGetAttribLocation = nullptr;
	_vdgl_glGetProgramiv = nullptr;
	_vdgl_glGetProgramInfoLog = nullptr;
	_vdgl_glGetShaderiv = nullptr;
	_vdgl_glGetShaderInfoLog = nullptr;
	_vdgl_glGetShaderSource = nullptr;
	_vdgl_glGetUniformLocation = nullptr;
	_vdgl_glGetUniformfv = nullptr;
	_vdgl_glGetUniformiv = nullptr;
	_vdgl_glGetVertexAttribdv = nullptr;
	_vdgl_glGetVertexAttribfv = nullptr;
	_vdgl_glGetVertexAttribiv = nullptr;
	_vdgl_glGetVertexAttribPointerv = nullptr;
	_vdgl_glIsProgram = nullptr;
	_vdgl_glIsShader = nullptr;
	_vdgl_glLinkProgram = nullptr;
	_vdgl_glShaderSource = nullptr;
	_vdgl_glUseProgram = nullptr;
	_vdgl_glUniform1f = nullptr;
	_vdgl_glUniform2f = nullptr;
	_vdgl_glUniform3f = nullptr;
	_vdgl_glUniform4f = nullptr;
	_vdgl_glUniform1i = nullptr;
	_vdgl_glUniform2i = nullptr;
	_vdgl_glUniform3i = nullptr;
	_vdgl_glUniform4i = nullptr;
	_vdgl_glUniform1fv = nullptr;
	_vdgl_glUniform2fv = nullptr;
	_vdgl_glUniform3fv = nullptr;
	_vdgl_glUniform4fv = nullptr;
	_vdgl_glUniform1iv = nullptr;
	_vdgl_glUniform2iv = nullptr;
	_vdgl_glUniform3iv = nullptr;
	_vdgl_glUniform4iv = nullptr;
	_vdgl_glUniformMatrix2fv = nullptr;
	_vdgl_glUniformMatrix3fv = nullptr;
	_vdgl_glUniformMatrix4fv = nullptr;
	_vdgl_glValidateProgram = nullptr;
	_vdgl_glVertexAttrib1d = nullptr;
	_vdgl_glVertexAttrib1dv = nullptr;
	_vdgl_glVertexAttrib1f = nullptr;
	_vdgl_glVertexAttrib1fv = nullptr;
	_vdgl_glVertexAttrib1s = nullptr;
	_vdgl_glVertexAttrib1sv = nullptr;
	_vdgl_glVertexAttrib2d = nullptr;
	_vdgl_glVertexAttrib2dv = nullptr;
	_vdgl_glVertexAttrib2f = nullptr;
	_vdgl_glVertexAttrib2fv = nullptr;
	_vdgl_glVertexAttrib2s = nullptr;
	_vdgl_glVertexAttrib2sv = nullptr;
	_vdgl_glVertexAttrib3d = nullptr;
	_vdgl_glVertexAttrib3dv = nullptr;
	_vdgl_glVertexAttrib3f = nullptr;
	_vdgl_glVertexAttrib3fv = nullptr;
	_vdgl_glVertexAttrib3s = nullptr;
	_vdgl_glVertexAttrib3sv = nullptr;
	_vdgl_glVertexAttrib4Nbv = nullptr;
	_vdgl_glVertexAttrib4Niv = nullptr;
	_vdgl_glVertexAttrib4Nsv = nullptr;
	_vdgl_glVertexAttrib4Nub = nullptr;
	_vdgl_glVertexAttrib4Nubv = nullptr;
	_vdgl_glVertexAttrib4Nuiv = nullptr;
	_vdgl_glVertexAttrib4Nusv = nullptr;
	_vdgl_glVertexAttrib4bv = nullptr;
	_vdgl_glVertexAttrib4d = nullptr;
	_vdgl_glVertexAttrib4dv = nullptr;
	_vdgl_glVertexAttrib4f = nullptr;
	_vdgl_glVertexAttrib4fv = nullptr;
	_vdgl_glVertexAttrib4iv = nullptr;
	_vdgl_glVertexAttrib4s = nullptr;
	_vdgl_glVertexAttrib4sv = nullptr;
	_vdgl_glVertexAttrib4ubv = nullptr;
	_vdgl_glVertexAttrib4uiv = nullptr;
	_vdgl_glVertexAttrib4usv = nullptr;
	_vdgl_glVertexAttribPointer = nullptr;
	_vdgl_glUniformMatrix2x3fv = nullptr;
	_vdgl_glUniformMatrix3x2fv = nullptr;
	_vdgl_glUniformMatrix2x4fv = nullptr;
	_vdgl_glUniformMatrix4x2fv = nullptr;
	_vdgl_glUniformMatrix3x4fv = nullptr;
	_vdgl_glUniformMatrix4x3fv = nullptr;
	_vdgl_glColorMaski = nullptr;
	_vdgl_glGetBooleani_v = nullptr;
	_vdgl_glGetIntegeri_v = nullptr;
	_vdgl_glEnablei = nullptr;
	_vdgl_glDisablei = nullptr;
	_vdgl_glIsEnabledi = nullptr;
	_vdgl_glBeginTransformFeedback = nullptr;
	_vdgl_glEndTransformFeedback = nullptr;
	_vdgl_glBindBufferRange = nullptr;
	_vdgl_glBindBufferBase = nullptr;
	_vdgl_glTransformFeedbackVaryings = nullptr;
	_vdgl_glGetTransformFeedbackVarying = nullptr;
	_vdgl_glClampColor = nullptr;
	_vdgl_glBeginConditionalRender = nullptr;
	_vdgl_glEndConditionalRender = nullptr;
	_vdgl_glVertexAttribIPointer = nullptr;
	_vdgl_glGetVertexAttribIiv = nullptr;
	_vdgl_glGetVertexAttribIuiv = nullptr;
	_vdgl_glVertexAttribI1i = nullptr;
	_vdgl_glVertexAttribI2i = nullptr;
	_vdgl_glVertexAttribI3i = nullptr;
	_vdgl_glVertexAttribI4i = nullptr;
	_vdgl_glVertexAttribI1ui = nullptr;
	_vdgl_glVertexAttribI2ui = nullptr;
	_vdgl_glVertexAttribI3ui = nullptr;
	_vdgl_glVertexAttribI4ui = nullptr;
	_vdgl_glVertexAttribI1iv = nullptr;
	_vdgl_glVertexAttribI2iv = nullptr;
	_vdgl_glVertexAttribI3iv = nullptr;
	_vdgl_glVertexAttribI4iv = nullptr;
	_vdgl_glVertexAttribI1uiv = nullptr;
	_vdgl_glVertexAttribI2uiv = nullptr;
	_vdgl_glVertexAttribI3uiv = nullptr;
	_vdgl_glVertexAttribI4uiv = nullptr;
	_vdgl_glVertexAttribI4bv = nullptr;
	_vdgl_glVertexAttribI4sv = nullptr;
	_vdgl_glVertexAttribI4ubv = nullptr;
	_vdgl_glVertexAttribI4usv = nullptr;
	_vdgl_glGetUniformuiv = nullptr;
	_vdgl_glBindFragDataLocation = nullptr;
	_vdgl_glGetFragDataLocation = nullptr;
	_vdgl_glUniform1ui = nullptr;
	_vdgl_glUniform2ui = nullptr;
	_vdgl_glUniform3ui = nullptr;
	_vdgl_glUniform4ui = nullptr;
	_vdgl_glUniform1uiv = nullptr;
	_vdgl_glUniform2uiv = nullptr;
	_vdgl_glUniform3uiv = nullptr;
	_vdgl_glUniform4uiv = nullptr;
	_vdgl_glTexParameterIiv = nullptr;
	_vdgl_glTexParameterIuiv = nullptr;
	_vdgl_glGetTexParameterIiv = nullptr;
	_vdgl_glGetTexParameterIuiv = nullptr;
	_vdgl_glClearBufferiv = nullptr;
	_vdgl_glClearBufferuiv = nullptr;
	_vdgl_glClearBufferfv = nullptr;
	_vdgl_glClearBufferfi = nullptr;
	_vdgl_glGetStringi = nullptr;
	_vdgl_glIsRenderbuffer = nullptr;
	_vdgl_glBindRenderbuffer = nullptr;
	_vdgl_glDeleteRenderbuffers = nullptr;
	_vdgl_glGenRenderbuffers = nullptr;
	_vdgl_glRenderbufferStorage = nullptr;
	_vdgl_glGetRenderbufferParameteriv = nullptr;
	_vdgl_glIsFramebuffer = nullptr;
	_vdgl_glBindFramebuffer = nullptr;
	_vdgl_glDeleteFramebuffers = nullptr;
	_vdgl_glGenFramebuffers = nullptr;
	_vdgl_glCheckFramebufferStatus = nullptr;
	_vdgl_glFramebufferTexture1D = nullptr;
	_vdgl_glFramebufferTexture2D = nullptr;
	_vdgl_glFramebufferTexture3D = nullptr;
	_vdgl_glFramebufferRenderbuffer = nullptr;
	_vdgl_glGetFramebufferAttachmentParameteriv = nullptr;
	_vdgl_glGenerateMipmap = nullptr;
	_vdgl_glBlitFramebuffer = nullptr;
	_vdgl_glRenderbufferStorageMultisample = nullptr;
	_vdgl_glFramebufferTextureLayer = nullptr;
	_vdgl_glMapBufferRange = nullptr;
	_vdgl_glFlushMappedBufferRange = nullptr;
	_vdgl_glBindVertexArray = nullptr;
	_vdgl_glDeleteVertexArrays = nullptr;
	_vdgl_glGenVertexArrays = nullptr;
	_vdgl_glIsVertexArray = nullptr;
	_vdgl_glDrawArraysInstanced = nullptr;
	_vdgl_glDrawElementsInstanced = nullptr;
	_vdgl_glTexBuffer = nullptr;
	_vdgl_glPrimitiveRestartIndex = nullptr;
	_vdgl_glCopyBufferSubData = nullptr;
	_vdgl_glGetUniformIndices = nullptr;
	_vdgl_glGetActiveUniformsiv = nullptr;
	_vdgl_glGetActiveUniformName = nullptr;
	_vdgl_glGetUniformBlockIndex = nullptr;
	_vdgl_glGetActiveUniformBlockiv = nullptr;
	_vdgl_glGetActiveUniformBlockName = nullptr;
	_vdgl_glUniformBlockBinding = nullptr;
	_vdgl_glDrawElementsBaseVertex = nullptr;
	_vdgl_glDrawRangeElementsBaseVertex = nullptr;
	_vdgl_glDrawElementsInstancedBaseVertex = nullptr;
	_vdgl_glMultiDrawElementsBaseVertex = nullptr;
	_vdgl_glProvokingVertex = nullptr;
	_vdgl_glFenceSync = nullptr;
	_vdgl_glIsSync = nullptr;
	_vdgl_glDeleteSync = nullptr;
	_vdgl_glClientWaitSync = nullptr;
	_vdgl_glWaitSync = nullptr;
	_vdgl_glGetInteger64v = nullptr;
	_vdgl_glGetSynciv = nullptr;
	_vdgl_glGetInteger64i_v = nullptr;
	_vdgl_glGetBufferParameteri64v = nullptr;
	_vdgl_glFramebufferTexture = nullptr;
	_vdgl_glTexImage2DMultisample = nullptr;
	_vdgl_glTexImage3DMultisample = nullptr;
	_vdgl_glGetMultisamplefv = nullptr;
	_vdgl_glSampleMaski = nullptr;
	_vdgl_glBindFragDataLocationIndexed = nullptr;
	_vdgl_glGetFragDataIndex = nullptr;
	_vdgl_glGenSamplers = nullptr;
	_vdgl_glDeleteSamplers = nullptr;
	_vdgl_glIsSampler = nullptr;
	_vdgl_glBindSampler = nullptr;
	_vdgl_glSamplerParameteri = nullptr;
	_vdgl_glSamplerParameteriv = nullptr;
	_vdgl_glSamplerParameterf = nullptr;
	_vdgl_glSamplerParameterfv = nullptr;
	_vdgl_glSamplerParameterIiv = nullptr;
	_vdgl_glSamplerParameterIuiv = nullptr;
	_vdgl_glGetSamplerParameteriv = nullptr;
	_vdgl_glGetSamplerParameterIiv = nullptr;
	_vdgl_glGetSamplerParameterfv = nullptr;
	_vdgl_glGetSamplerParameterIuiv = nullptr;
	_vdgl_glQueryCounter = nullptr;
	_vdgl_glGetQueryObjecti64v = nullptr;
	_vdgl_glGetQueryObjectui64v = nullptr;
	_vdgl_glVertexAttribDivisor = nullptr;
	_vdgl_glVertexAttribP1ui = nullptr;
	_vdgl_glVertexAttribP1uiv = nullptr;
	_vdgl_glVertexAttribP2ui = nullptr;
	_vdgl_glVertexAttribP2uiv = nullptr;
	_vdgl_glVertexAttribP3ui = nullptr;
	_vdgl_glVertexAttribP3uiv = nullptr;
	_vdgl_glVertexAttribP4ui = nullptr;
	_vdgl_glVertexAttribP4uiv = nullptr;
	_vdgl_glMinSampleShading = nullptr;
	_vdgl_glBlendEquationi = nullptr;
	_vdgl_glBlendEquationSeparatei = nullptr;
	_vdgl_glBlendFunci = nullptr;
	_vdgl_glBlendFuncSeparatei = nullptr;
	_vdgl_glDrawArraysIndirect = nullptr;
	_vdgl_glDrawElementsIndirect = nullptr;
	_vdgl_glUniform1d = nullptr;
	_vdgl_glUniform2d = nullptr;
	_vdgl_glUniform3d = nullptr;
	_vdgl_glUniform4d = nullptr;
	_vdgl_glUniform1dv = nullptr;
	_vdgl_glUniform2dv = nullptr;
	_vdgl_glUniform3dv = nullptr;
	_vdgl_glUniform4dv = nullptr;
	_vdgl_glUniformMatrix2dv = nullptr;
	_vdgl_glUniformMatrix3dv = nullptr;
	_vdgl_glUniformMatrix4dv = nullptr;
	_vdgl_glUniformMatrix2x3dv = nullptr;
	_vdgl_glUniformMatrix2x4dv = nullptr;
	_vdgl_glUniformMatrix3x2dv = nullptr;
	_vdgl_glUniformMatrix3x4dv = nullptr;
	_vdgl_glUniformMatrix4x2dv = nullptr;
	_vdgl_glUniformMatrix4x3dv = nullptr;
	_vdgl_glGetUniformdv = nullptr;
	_vdgl_glGetSubroutineUniformLocation = nullptr;
	_vdgl_glGetSubroutineIndex = nullptr;
	_vdgl_glGetActiveSubroutineUniformiv = nullptr;
	_vdgl_glGetActiveSubroutineUniformName = nullptr;
	_vdgl_glGetActiveSubroutineName = nullptr;
	_vdgl_glUniformSubroutinesuiv = nullptr;
	_vdgl_glGetUniformSubroutineuiv = nullptr;
	_vdgl_glGetProgramStageiv = nullptr;
	_vdgl_glPatchParameteri = nullptr;
	_vdgl_glPatchParameterfv = nullptr;
	_vdgl_glBindTransformFeedback = nullptr;
	_vdgl_glDeleteTransformFeedbacks = nullptr;
	_vdgl_glGenTransformFeedbacks = nullptr;
	_vdgl_glIsTransformFeedback = nullptr;
	_vdgl_glPauseTransformFeedback = nullptr;
	_vdgl_glResumeTransformFeedback = nullptr;
	_vdgl_glDrawTransformFeedback = nullptr;
	_vdgl_glDrawTransformFeedbackStream = nullptr;
	_vdgl_glBeginQueryIndexed = nullptr;
	_vdgl_glEndQueryIndexed = nullptr;
	_vdgl_glGetQueryIndexediv = nullptr;
	_vdgl_glReleaseShaderCompiler = nullptr;
	_vdgl_glShaderBinary = nullptr;
	_vdgl_glGetShaderPrecisionFormat = nullptr;
	_vdgl_glDepthRangef = nullptr;
	_vdgl_glClearDepthf = nullptr;
	_vdgl_glGetProgramBinary = nullptr;
	_vdgl_glProgramBinary = nullptr;
	_vdgl_glProgramParameteri = nullptr;
	_vdgl_glUseProgramStages = nullptr;
	_vdgl_glActiveShaderProgram = nullptr;
	_vdgl_glCreateShaderProgramv = nullptr;
	_vdgl_glBindProgramPipeline = nullptr;
	_vdgl_glDeleteProgramPipelines = nullptr;
	_vdgl_glGenProgramPipelines = nullptr;
	_vdgl_glIsProgramPipeline = nullptr;
	_vdgl_glGetProgramPipelineiv = nullptr;
	_vdgl_glProgramUniform1i = nullptr;
	_vdgl_glProgramUniform1iv = nullptr;
	_vdgl_glProgramUniform1f = nullptr;
	_vdgl_glProgramUniform1fv = nullptr;
	_vdgl_glProgramUniform1d = nullptr;
	_vdgl_glProgramUniform1dv = nullptr;
	_vdgl_glProgramUniform1ui = nullptr;
	_vdgl_glProgramUniform1uiv = nullptr;
	_vdgl_glProgramUniform2i = nullptr;
	_vdgl_glProgramUniform2iv = nullptr;
	_vdgl_glProgramUniform2f = nullptr;
	_vdgl_glProgramUniform2fv = nullptr;
	_vdgl_glProgramUniform2d = nullptr;
	_vdgl_glProgramUniform2dv = nullptr;
	_vdgl_glProgramUniform2ui = nullptr;
	_vdgl_glProgramUniform2uiv = nullptr;
	_vdgl_glProgramUniform3i = nullptr;
	_vdgl_glProgramUniform3iv = nullptr;
	_vdgl_glProgramUniform3f = nullptr;
	_vdgl_glProgramUniform3fv = nullptr;
	_vdgl_glProgramUniform3d = nullptr;
	_vdgl_glProgramUniform3dv = nullptr;
	_vdgl_glProgramUniform3ui = nullptr;
	_vdgl_glProgramUniform3uiv = nullptr;
	_vdgl_glProgramUniform4i = nullptr;
	_vdgl_glProgramUniform4iv = nullptr;
	_vdgl_glProgramUniform4f = nullptr;
	_vdgl_glProgramUniform4fv = nullptr;
	_vdgl_glProgramUniform4d = nullptr;
	_vdgl_glProgramUniform4dv = nullptr;
	_vdgl_glProgramUniform4ui = nullptr;
	_vdgl_glProgramUniform4uiv = nullptr;
	_vdgl_glProgramUniformMatrix2fv = nullptr;
	_vdgl_glProgramUniformMatrix3fv = nullptr;
	_vdgl_glProgramUniformMatrix4fv = nullptr;
	_vdgl_glProgramUniformMatrix2dv = nullptr;
	_vdgl_glProgramUniformMatrix3dv = nullptr;
	_vdgl_glProgramUniformMatrix4dv = nullptr;
	_vdgl_glProgramUniformMatrix2x3fv = nullptr;
	_vdgl_glProgramUniformMatrix3x2fv = nullptr;
	_vdgl_glProgramUniformMatrix2x4fv = nullptr;
	_vdgl_glProgramUniformMatrix4x2fv = nullptr;
	_vdgl_glProgramUniformMatrix3x4fv = nullptr;
	_vdgl_glProgramUniformMatrix4x3fv = nullptr;
	_vdgl_glProgramUniformMatrix2x3dv = nullptr;
	_vdgl_glProgramUniformMatrix3x2dv = nullptr;
	_vdgl_glProgramUniformMatrix2x4dv = nullptr;
	_vdgl_glProgramUniformMatrix4x2dv = nullptr;
	_vdgl_glProgramUniformMatrix3x4dv = nullptr;
	_vdgl_glProgramUniformMatrix4x3dv = nullptr;
	_vdgl_glValidateProgramPipeline = nullptr;
	_vdgl_glGetProgramPipelineInfoLog = nullptr;
	_vdgl_glVertexAttribL1d = nullptr;
	_vdgl_glVertexAttribL2d = nullptr;
	_vdgl_glVertexAttribL3d = nullptr;
	_vdgl_glVertexAttribL4d = nullptr;
	_vdgl_glVertexAttribL1dv = nullptr;
	_vdgl_glVertexAttribL2dv = nullptr;
	_vdgl_glVertexAttribL3dv = nullptr;
	_vdgl_glVertexAttribL4dv = nullptr;
	_vdgl_glVertexAttribLPointer = nullptr;
	_vdgl_glGetVertexAttribLdv = nullptr;
	_vdgl_glViewportArrayv = nullptr;
	_vdgl_glViewportIndexedf = nullptr;
	_vdgl_glViewportIndexedfv = nullptr;
	_vdgl_glScissorArrayv = nullptr;
	_vdgl_glScissorIndexed = nullptr;
	_vdgl_glScissorIndexedv = nullptr;
	_vdgl_glDepthRangeArrayv = nullptr;
	_vdgl_glDepthRangeIndexed = nullptr;
	_vdgl_glGetFloati_v = nullptr;
	_vdgl_glGetDoublei_v = nullptr;
	_vdgl_glDrawArraysInstancedBaseInstance = nullptr;
	_vdgl_glDrawElementsInstancedBaseInstance = nullptr;
	_vdgl_glDrawElementsInstancedBaseVertexBaseInstance = nullptr;
	_vdgl_glGetInternalformativ = nullptr;
	_vdgl_glGetActiveAtomicCounterBufferiv = nullptr;
	_vdgl_glBindImageTexture = nullptr;
	_vdgl_glMemoryBarrier = nullptr;
	_vdgl_glTexStorage1D = nullptr;
	_vdgl_glTexStorage2D = nullptr;
	_vdgl_glTexStorage3D = nullptr;
	_vdgl_glDrawTransformFeedbackInstanced = nullptr;
	_vdgl_glDrawTransformFeedbackStreamInstanced = nullptr;
	_vdgl_glClearBufferData = nullptr;
	_vdgl_glClearBufferSubData = nullptr;
	_vdgl_glDispatchCompute = nullptr;
	_vdgl_glDispatchComputeIndirect = nullptr;
	_vdgl_glCopyImageSubData = nullptr;
	_vdgl_glFramebufferParameteri = nullptr;
	_vdgl_glGetFramebufferParameteriv = nullptr;
	_vdgl_glGetInternalformati64v = nullptr;
	_vdgl_glInvalidateTexSubImage = nullptr;
	_vdgl_glInvalidateTexImage = nullptr;
	_vdgl_glInvalidateBufferSubData = nullptr;
	_vdgl_glInvalidateBufferData = nullptr;
	_vdgl_glInvalidateFramebuffer = nullptr;
	_vdgl_glInvalidateSubFramebuffer = nullptr;
	_vdgl_glMultiDrawArraysIndirect = nullptr;
	_vdgl_glMultiDrawElementsIndirect = nullptr;
	_vdgl_glGetProgramInterfaceiv = nullptr;
	_vdgl_glGetProgramResourceIndex = nullptr;
	_vdgl_glGetProgramResourceName = nullptr;
	_vdgl_glGetProgramResourceiv = nullptr;
	_vdgl_glGetProgramResourceLocation = nullptr;
	_vdgl_glGetProgramResourceLocationIndex = nullptr;
	_vdgl_glShaderStorageBlockBinding = nullptr;
	_vdgl_glTexBufferRange = nullptr;
	_vdgl_glTexStorage2DMultisample = nullptr;
	_vdgl_glTexStorage3DMultisample = nullptr;
	_vdgl_glTextureView = nullptr;
	_vdgl_glBindVertexBuffer = nullptr;
	_vdgl_glVertexAttribFormat = nullptr;
	_vdgl_glVertexAttribIFormat = nullptr;
	_vdgl_glVertexAttribLFormat = nullptr;
	_vdgl_glVertexAttribBinding = nullptr;
	_vdgl_glVertexBindingDivisor = nullptr;
	_vdgl_glDebugMessageControl = nullptr;
	_vdgl_glDebugMessageInsert = nullptr;
	_vdgl_glDebugMessageCallback = nullptr;
	_vdgl_glGetDebugMessageLog = nullptr;
	_vdgl_glPushDebugGroup = nullptr;
	_vdgl_glPopDebugGroup = nullptr;
	_vdgl_glObjectLabel = nullptr;
	_vdgl_glGetObjectLabel = nullptr;
	_vdgl_glObjectPtrLabel = nullptr;
	_vdgl_glGetObjectPtrLabel = nullptr;
	_vdgl_glBufferStorage = nullptr;
	_vdgl_glClearTexImage = nullptr;
	_vdgl_glClearTexSubImage = nullptr;
	_vdgl_glBindBuffersBase = nullptr;
	_vdgl_glBindBuffersRange = nullptr;
	_vdgl_glBindTextures = nullptr;
	_vdgl_glBindSamplers = nullptr;
	_vdgl_glBindImageTextures = nullptr;
	_vdgl_glBindVertexBuffers = nullptr;
	_vdgl_glClipControl = nullptr;
	_vdgl_glCreateTransformFeedbacks = nullptr;
	_vdgl_glTransformFeedbackBufferBase = nullptr;
	_vdgl_glTransformFeedbackBufferRange = nullptr;
	_vdgl_glGetTransformFeedbackiv = nullptr;
	_vdgl_glGetTransformFeedbacki_v = nullptr;
	_vdgl_glGetTransformFeedbacki64_v = nullptr;
	_vdgl_glCreateBuffers = nullptr;
	_vdgl_glNamedBufferStorage = nullptr;
	_vdgl_glNamedBufferData = nullptr;
	_vdgl_glNamedBufferSubData = nullptr;
	_vdgl_glCopyNamedBufferSubData = nullptr;
	_vdgl_glClearNamedBufferData = nullptr;
	_vdgl_glClearNamedBufferSubData = nullptr;
	_vdgl_glMapNamedBuffer = nullptr;
	_vdgl_glMapNamedBufferRange = nullptr;
	_vdgl_glUnmapNamedBuffer = nullptr;
	_vdgl_glFlushMappedNamedBufferRange = nullptr;
	_vdgl_glGetNamedBufferParameteriv = nullptr;
	_vdgl_glGetNamedBufferParameteri64v = nullptr;
	_vdgl_glGetNamedBufferPointerv = nullptr;
	_vdgl_glGetNamedBufferSubData = nullptr;
	_vdgl_glCreateFramebuffers = nullptr;
	_vdgl_glNamedFramebufferRenderbuffer = nullptr;
	_vdgl_glNamedFramebufferParameteri = nullptr;
	_vdgl_glNamedFramebufferTexture = nullptr;
	_vdgl_glNamedFramebufferTextureLayer = nullptr;
	_vdgl_glNamedFramebufferDrawBuffer = nullptr;
	_vdgl_glNamedFramebufferDrawBuffers = nullptr;
	_vdgl_glNamedFramebufferReadBuffer = nullptr;
	_vdgl_glInvalidateNamedFramebufferData = nullptr;
	_vdgl_glInvalidateNamedFramebufferSubData = nullptr;
	_vdgl_glClearNamedFramebufferiv = nullptr;
	_vdgl_glClearNamedFramebufferuiv = nullptr;
	_vdgl_glClearNamedFramebufferfv = nullptr;
	_vdgl_glClearNamedFramebufferfi = nullptr;
	_vdgl_glBlitNamedFramebuffer = nullptr;
	_vdgl_glCheckNamedFramebufferStatus = nullptr;
	_vdgl_glGetNamedFramebufferParameteriv = nullptr;
	_vdgl_glGetNamedFramebufferAttachmentParameteriv = nullptr;
	_vdgl_glCreateRenderbuffers = nullptr;
	_vdgl_glNamedRenderbufferStorage = nullptr;
	_vdgl_glNamedRenderbufferStorageMultisample = nullptr;
	_vdgl_glGetNamedRenderbufferParameteriv = nullptr;
	_vdgl_glCreateTextures = nullptr;
	_vdgl_glTextureBuffer = nullptr;
	_vdgl_glTextureBufferRange = nullptr;
	_vdgl_glTextureStorage1D = nullptr;
	_vdgl_glTextureStorage2D = nullptr;
	_vdgl_glTextureStorage3D = nullptr;
	_vdgl_glTextureStorage2DMultisample = nullptr;
	_vdgl_glTextureStorage3DMultisample = nullptr;
	_vdgl_glTextureSubImage1D = nullptr;
	_vdgl_glTextureSubImage2D = nullptr;
	_vdgl_glTextureSubImage3D = nullptr;
	_vdgl_glCompressedTextureSubImage1D = nullptr;
	_vdgl_glCompressedTextureSubImage2D = nullptr;
	_vdgl_glCompressedTextureSubImage3D = nullptr;
	_vdgl_glCopyTextureSubImage1D = nullptr;
	_vdgl_glCopyTextureSubImage2D = nullptr;
	_vdgl_glCopyTextureSubImage3D = nullptr;
	_vdgl_glTextureParameterf = nullptr;
	_vdgl_glTextureParameterfv = nullptr;
	_vdgl_glTextureParameteri = nullptr;
	_vdgl_glTextureParameterIiv = nullptr;
	_vdgl_glTextureParameterIuiv = nullptr;
	_vdgl_glTextureParameteriv = nullptr;
	_vdgl_glGenerateTextureMipmap = nullptr;
	_vdgl_glBindTextureUnit = nullptr;
	_vdgl_glGetTextureImage = nullptr;
	_vdgl_glGetCompressedTextureImage = nullptr;
	_vdgl_glGetTextureLevelParameterfv = nullptr;
	_vdgl_glGetTextureLevelParameteriv = nullptr;
	_vdgl_glGetTextureParameterfv = nullptr;
	_vdgl_glGetTextureParameterIiv = nullptr;
	_vdgl_glGetTextureParameterIuiv = nullptr;
	_vdgl_glGetTextureParameteriv = nullptr;
	_vdgl_glCreateVertexArrays = nullptr;
	_vdgl_glDisableVertexArrayAttrib = nullptr;
	_vdgl_glEnableVertexArrayAttrib = nullptr;
	_vdgl_glVertexArrayElementBuffer = nullptr;
	_vdgl_glVertexArrayVertexBuffer = nullptr;
	_vdgl_glVertexArrayVertexBuffers = nullptr;
	_vdgl_glVertexArrayAttribBinding = nullptr;
	_vdgl_glVertexArrayAttribFormat = nullptr;
	_vdgl_glVertexArrayAttribIFormat = nullptr;
	_vdgl_glVertexArrayAttribLFormat = nullptr;
	_vdgl_glVertexArrayBindingDivisor = nullptr;
	_vdgl_glGetVertexArrayiv = nullptr;
	_vdgl_glGetVertexArrayIndexediv = nullptr;
	_vdgl_glGetVertexArrayIndexed64iv = nullptr;
	_vdgl_glCreateSamplers = nullptr;
	_vdgl_glCreateProgramPipelines = nullptr;
	_vdgl_glCreateQueries = nullptr;
	_vdgl_glGetQueryBufferObjecti64v = nullptr;
	_vdgl_glGetQueryBufferObjectiv = nullptr;
	_vdgl_glGetQueryBufferObjectui64v = nullptr;
	_vdgl_glGetQueryBufferObjectuiv = nullptr;
	_vdgl_glMemoryBarrierByRegion = nullptr;
	_vdgl_glGetTextureSubImage = nullptr;
	_vdgl_glGetCompressedTextureSubImage = nullptr;
	_vdgl_glGetGraphicsResetStatus = nullptr;
	_vdgl_glGetnCompressedTexImage = nullptr;
	_vdgl_glGetnTexImage = nullptr;
	_vdgl_glGetnUniformdv = nullptr;
	_vdgl_glGetnUniformfv = nullptr;
	_vdgl_glGetnUniformiv = nullptr;
	_vdgl_glGetnUniformuiv = nullptr;
	_vdgl_glReadnPixels = nullptr;
	_vdgl_glTextureBarrier = nullptr;
	_vdgl_glSpecializeShader = nullptr;
	_vdgl_glMultiDrawArraysIndirectCount = nullptr;
	_vdgl_glMultiDrawElementsIndirectCount = nullptr;
	_vdgl_glPolygonOffsetClamp = nullptr;
}
#include "Core.h"
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
	glCullFace = nullptr;
	glFrontFace = nullptr;
	glHint = nullptr;
	glLineWidth = nullptr;
	glPointSize = nullptr;
	glPolygonMode = nullptr;
	glScissor = nullptr;
	glTexParameterf = nullptr;
	glTexParameterfv = nullptr;
	glTexParameteri = nullptr;
	glTexParameteriv = nullptr;
	glTexImage1D = nullptr;
	glTexImage2D = nullptr;
	glDrawBuffer = nullptr;
	glClear = nullptr;
	glClearColor = nullptr;
	glClearStencil = nullptr;
	glClearDepth = nullptr;
	glStencilMask = nullptr;
	glColorMask = nullptr;
	glDepthMask = nullptr;
	glDisable = nullptr;
	glEnable = nullptr;
	glFinish = nullptr;
	glFlush = nullptr;
	glBlendFunc = nullptr;
	glLogicOp = nullptr;
	glStencilFunc = nullptr;
	glStencilOp = nullptr;
	glDepthFunc = nullptr;
	glPixelStoref = nullptr;
	glPixelStorei = nullptr;
	glReadBuffer = nullptr;
	glReadPixels = nullptr;
	glGetBooleanv = nullptr;
	glGetDoublev = nullptr;
	glGetError = nullptr;
	glGetFloatv = nullptr;
	glGetIntegerv = nullptr;
	glGetString = nullptr;
	glGetTexImage = nullptr;
	glGetTexParameterfv = nullptr;
	glGetTexParameteriv = nullptr;
	glGetTexLevelParameterfv = nullptr;
	glGetTexLevelParameteriv = nullptr;
	glIsEnabled = nullptr;
	glDepthRange = nullptr;
	glViewport = nullptr;
	glDrawArrays = nullptr;
	glDrawElements = nullptr;
	glGetPointerv = nullptr;
	glPolygonOffset = nullptr;
	glCopyTexImage1D = nullptr;
	glCopyTexImage2D = nullptr;
	glCopyTexSubImage1D = nullptr;
	glCopyTexSubImage2D = nullptr;
	glTexSubImage1D = nullptr;
	glTexSubImage2D = nullptr;
	glBindTexture = nullptr;
	glDeleteTextures = nullptr;
	glGenTextures = nullptr;
	glIsTexture = nullptr;
	glDrawRangeElements = nullptr;
	glTexImage3D = nullptr;
	glTexSubImage3D = nullptr;
	glCopyTexSubImage3D = nullptr;
	glActiveTexture = nullptr;
	glSampleCoverage = nullptr;
	glCompressedTexImage3D = nullptr;
	glCompressedTexImage2D = nullptr;
	glCompressedTexImage1D = nullptr;
	glCompressedTexSubImage3D = nullptr;
	glCompressedTexSubImage2D = nullptr;
	glCompressedTexSubImage1D = nullptr;
	glGetCompressedTexImage = nullptr;
	glBlendFuncSeparate = nullptr;
	glMultiDrawArrays = nullptr;
	glMultiDrawElements = nullptr;
	glPointParameterf = nullptr;
	glPointParameterfv = nullptr;
	glPointParameteri = nullptr;
	glPointParameteriv = nullptr;
	glBlendColor = nullptr;
	glBlendEquation = nullptr;
	glGenQueries = nullptr;
	glDeleteQueries = nullptr;
	glIsQuery = nullptr;
	glBeginQuery = nullptr;
	glEndQuery = nullptr;
	glGetQueryiv = nullptr;
	glGetQueryObjectiv = nullptr;
	glGetQueryObjectuiv = nullptr;
	glBindBuffer = nullptr;
	glDeleteBuffers = nullptr;
	glGenBuffers = nullptr;
	glIsBuffer = nullptr;
	glBufferData = nullptr;
	glBufferSubData = nullptr;
	glGetBufferSubData = nullptr;
	glMapBuffer = nullptr;
	glUnmapBuffer = nullptr;
	glGetBufferParameteriv = nullptr;
	glGetBufferPointerv = nullptr;
	glBlendEquationSeparate = nullptr;
	glDrawBuffers = nullptr;
	glStencilOpSeparate = nullptr;
	glStencilFuncSeparate = nullptr;
	glStencilMaskSeparate = nullptr;
	glAttachShader = nullptr;
	glBindAttribLocation = nullptr;
	glCompileShader = nullptr;
	glCreateProgram = nullptr;
	glCreateShader = nullptr;
	glDeleteProgram = nullptr;
	glDeleteShader = nullptr;
	glDetachShader = nullptr;
	glDisableVertexAttribArray = nullptr;
	glEnableVertexAttribArray = nullptr;
	glGetActiveAttrib = nullptr;
	glGetActiveUniform = nullptr;
	glGetAttachedShaders = nullptr;
	glGetAttribLocation = nullptr;
	glGetProgramiv = nullptr;
	glGetProgramInfoLog = nullptr;
	glGetShaderiv = nullptr;
	glGetShaderInfoLog = nullptr;
	glGetShaderSource = nullptr;
	glGetUniformLocation = nullptr;
	glGetUniformfv = nullptr;
	glGetUniformiv = nullptr;
	glGetVertexAttribdv = nullptr;
	glGetVertexAttribfv = nullptr;
	glGetVertexAttribiv = nullptr;
	glGetVertexAttribPointerv = nullptr;
	glIsProgram = nullptr;
	glIsShader = nullptr;
	glLinkProgram = nullptr;
	glShaderSource = nullptr;
	glUseProgram = nullptr;
	glUniform1f = nullptr;
	glUniform2f = nullptr;
	glUniform3f = nullptr;
	glUniform4f = nullptr;
	glUniform1i = nullptr;
	glUniform2i = nullptr;
	glUniform3i = nullptr;
	glUniform4i = nullptr;
	glUniform1fv = nullptr;
	glUniform2fv = nullptr;
	glUniform3fv = nullptr;
	glUniform4fv = nullptr;
	glUniform1iv = nullptr;
	glUniform2iv = nullptr;
	glUniform3iv = nullptr;
	glUniform4iv = nullptr;
	glUniformMatrix2fv = nullptr;
	glUniformMatrix3fv = nullptr;
	glUniformMatrix4fv = nullptr;
	glValidateProgram = nullptr;
	glVertexAttrib1d = nullptr;
	glVertexAttrib1dv = nullptr;
	glVertexAttrib1f = nullptr;
	glVertexAttrib1fv = nullptr;
	glVertexAttrib1s = nullptr;
	glVertexAttrib1sv = nullptr;
	glVertexAttrib2d = nullptr;
	glVertexAttrib2dv = nullptr;
	glVertexAttrib2f = nullptr;
	glVertexAttrib2fv = nullptr;
	glVertexAttrib2s = nullptr;
	glVertexAttrib2sv = nullptr;
	glVertexAttrib3d = nullptr;
	glVertexAttrib3dv = nullptr;
	glVertexAttrib3f = nullptr;
	glVertexAttrib3fv = nullptr;
	glVertexAttrib3s = nullptr;
	glVertexAttrib3sv = nullptr;
	glVertexAttrib4Nbv = nullptr;
	glVertexAttrib4Niv = nullptr;
	glVertexAttrib4Nsv = nullptr;
	glVertexAttrib4Nub = nullptr;
	glVertexAttrib4Nubv = nullptr;
	glVertexAttrib4Nuiv = nullptr;
	glVertexAttrib4Nusv = nullptr;
	glVertexAttrib4bv = nullptr;
	glVertexAttrib4d = nullptr;
	glVertexAttrib4dv = nullptr;
	glVertexAttrib4f = nullptr;
	glVertexAttrib4fv = nullptr;
	glVertexAttrib4iv = nullptr;
	glVertexAttrib4s = nullptr;
	glVertexAttrib4sv = nullptr;
	glVertexAttrib4ubv = nullptr;
	glVertexAttrib4uiv = nullptr;
	glVertexAttrib4usv = nullptr;
	glVertexAttribPointer = nullptr;
	glUniformMatrix2x3fv = nullptr;
	glUniformMatrix3x2fv = nullptr;
	glUniformMatrix2x4fv = nullptr;
	glUniformMatrix4x2fv = nullptr;
	glUniformMatrix3x4fv = nullptr;
	glUniformMatrix4x3fv = nullptr;
	glColorMaski = nullptr;
	glGetBooleani_v = nullptr;
	glGetIntegeri_v = nullptr;
	glEnablei = nullptr;
	glDisablei = nullptr;
	glIsEnabledi = nullptr;
	glBeginTransformFeedback = nullptr;
	glEndTransformFeedback = nullptr;
	glBindBufferRange = nullptr;
	glBindBufferBase = nullptr;
	glTransformFeedbackVaryings = nullptr;
	glGetTransformFeedbackVarying = nullptr;
	glClampColor = nullptr;
	glBeginConditionalRender = nullptr;
	glEndConditionalRender = nullptr;
	glVertexAttribIPointer = nullptr;
	glGetVertexAttribIiv = nullptr;
	glGetVertexAttribIuiv = nullptr;
	glVertexAttribI1i = nullptr;
	glVertexAttribI2i = nullptr;
	glVertexAttribI3i = nullptr;
	glVertexAttribI4i = nullptr;
	glVertexAttribI1ui = nullptr;
	glVertexAttribI2ui = nullptr;
	glVertexAttribI3ui = nullptr;
	glVertexAttribI4ui = nullptr;
	glVertexAttribI1iv = nullptr;
	glVertexAttribI2iv = nullptr;
	glVertexAttribI3iv = nullptr;
	glVertexAttribI4iv = nullptr;
	glVertexAttribI1uiv = nullptr;
	glVertexAttribI2uiv = nullptr;
	glVertexAttribI3uiv = nullptr;
	glVertexAttribI4uiv = nullptr;
	glVertexAttribI4bv = nullptr;
	glVertexAttribI4sv = nullptr;
	glVertexAttribI4ubv = nullptr;
	glVertexAttribI4usv = nullptr;
	glGetUniformuiv = nullptr;
	glBindFragDataLocation = nullptr;
	glGetFragDataLocation = nullptr;
	glUniform1ui = nullptr;
	glUniform2ui = nullptr;
	glUniform3ui = nullptr;
	glUniform4ui = nullptr;
	glUniform1uiv = nullptr;
	glUniform2uiv = nullptr;
	glUniform3uiv = nullptr;
	glUniform4uiv = nullptr;
	glTexParameterIiv = nullptr;
	glTexParameterIuiv = nullptr;
	glGetTexParameterIiv = nullptr;
	glGetTexParameterIuiv = nullptr;
	glClearBufferiv = nullptr;
	glClearBufferuiv = nullptr;
	glClearBufferfv = nullptr;
	glClearBufferfi = nullptr;
	glGetStringi = nullptr;
	glIsRenderbuffer = nullptr;
	glBindRenderbuffer = nullptr;
	glDeleteRenderbuffers = nullptr;
	glGenRenderbuffers = nullptr;
	glRenderbufferStorage = nullptr;
	glGetRenderbufferParameteriv = nullptr;
	glIsFramebuffer = nullptr;
	glBindFramebuffer = nullptr;
	glDeleteFramebuffers = nullptr;
	glGenFramebuffers = nullptr;
	glCheckFramebufferStatus = nullptr;
	glFramebufferTexture1D = nullptr;
	glFramebufferTexture2D = nullptr;
	glFramebufferTexture3D = nullptr;
	glFramebufferRenderbuffer = nullptr;
	glGetFramebufferAttachmentParameteriv = nullptr;
	glGenerateMipmap = nullptr;
	glBlitFramebuffer = nullptr;
	glRenderbufferStorageMultisample = nullptr;
	glFramebufferTextureLayer = nullptr;
	glMapBufferRange = nullptr;
	glFlushMappedBufferRange = nullptr;
	glBindVertexArray = nullptr;
	glDeleteVertexArrays = nullptr;
	glGenVertexArrays = nullptr;
	glIsVertexArray = nullptr;
	glDrawArraysInstanced = nullptr;
	glDrawElementsInstanced = nullptr;
	glTexBuffer = nullptr;
	glPrimitiveRestartIndex = nullptr;
	glCopyBufferSubData = nullptr;
	glGetUniformIndices = nullptr;
	glGetActiveUniformsiv = nullptr;
	glGetActiveUniformName = nullptr;
	glGetUniformBlockIndex = nullptr;
	glGetActiveUniformBlockiv = nullptr;
	glGetActiveUniformBlockName = nullptr;
	glUniformBlockBinding = nullptr;
	glDrawElementsBaseVertex = nullptr;
	glDrawRangeElementsBaseVertex = nullptr;
	glDrawElementsInstancedBaseVertex = nullptr;
	glMultiDrawElementsBaseVertex = nullptr;
	glProvokingVertex = nullptr;
	glFenceSync = nullptr;
	glIsSync = nullptr;
	glDeleteSync = nullptr;
	glClientWaitSync = nullptr;
	glWaitSync = nullptr;
	glGetInteger64v = nullptr;
	glGetSynciv = nullptr;
	glGetInteger64i_v = nullptr;
	glGetBufferParameteri64v = nullptr;
	glFramebufferTexture = nullptr;
	glTexImage2DMultisample = nullptr;
	glTexImage3DMultisample = nullptr;
	glGetMultisamplefv = nullptr;
	glSampleMaski = nullptr;
	glBindFragDataLocationIndexed = nullptr;
	glGetFragDataIndex = nullptr;
	glGenSamplers = nullptr;
	glDeleteSamplers = nullptr;
	glIsSampler = nullptr;
	glBindSampler = nullptr;
	glSamplerParameteri = nullptr;
	glSamplerParameteriv = nullptr;
	glSamplerParameterf = nullptr;
	glSamplerParameterfv = nullptr;
	glSamplerParameterIiv = nullptr;
	glSamplerParameterIuiv = nullptr;
	glGetSamplerParameteriv = nullptr;
	glGetSamplerParameterIiv = nullptr;
	glGetSamplerParameterfv = nullptr;
	glGetSamplerParameterIuiv = nullptr;
	glQueryCounter = nullptr;
	glGetQueryObjecti64v = nullptr;
	glGetQueryObjectui64v = nullptr;
	glVertexAttribDivisor = nullptr;
	glVertexAttribP1ui = nullptr;
	glVertexAttribP1uiv = nullptr;
	glVertexAttribP2ui = nullptr;
	glVertexAttribP2uiv = nullptr;
	glVertexAttribP3ui = nullptr;
	glVertexAttribP3uiv = nullptr;
	glVertexAttribP4ui = nullptr;
	glVertexAttribP4uiv = nullptr;
	glMinSampleShading = nullptr;
	glBlendEquationi = nullptr;
	glBlendEquationSeparatei = nullptr;
	glBlendFunci = nullptr;
	glBlendFuncSeparatei = nullptr;
	glDrawArraysIndirect = nullptr;
	glDrawElementsIndirect = nullptr;
	glUniform1d = nullptr;
	glUniform2d = nullptr;
	glUniform3d = nullptr;
	glUniform4d = nullptr;
	glUniform1dv = nullptr;
	glUniform2dv = nullptr;
	glUniform3dv = nullptr;
	glUniform4dv = nullptr;
	glUniformMatrix2dv = nullptr;
	glUniformMatrix3dv = nullptr;
	glUniformMatrix4dv = nullptr;
	glUniformMatrix2x3dv = nullptr;
	glUniformMatrix2x4dv = nullptr;
	glUniformMatrix3x2dv = nullptr;
	glUniformMatrix3x4dv = nullptr;
	glUniformMatrix4x2dv = nullptr;
	glUniformMatrix4x3dv = nullptr;
	glGetUniformdv = nullptr;
	glGetSubroutineUniformLocation = nullptr;
	glGetSubroutineIndex = nullptr;
	glGetActiveSubroutineUniformiv = nullptr;
	glGetActiveSubroutineUniformName = nullptr;
	glGetActiveSubroutineName = nullptr;
	glUniformSubroutinesuiv = nullptr;
	glGetUniformSubroutineuiv = nullptr;
	glGetProgramStageiv = nullptr;
	glPatchParameteri = nullptr;
	glPatchParameterfv = nullptr;
	glBindTransformFeedback = nullptr;
	glDeleteTransformFeedbacks = nullptr;
	glGenTransformFeedbacks = nullptr;
	glIsTransformFeedback = nullptr;
	glPauseTransformFeedback = nullptr;
	glResumeTransformFeedback = nullptr;
	glDrawTransformFeedback = nullptr;
	glDrawTransformFeedbackStream = nullptr;
	glBeginQueryIndexed = nullptr;
	glEndQueryIndexed = nullptr;
	glGetQueryIndexediv = nullptr;
	glReleaseShaderCompiler = nullptr;
	glShaderBinary = nullptr;
	glGetShaderPrecisionFormat = nullptr;
	glDepthRangef = nullptr;
	glClearDepthf = nullptr;
	glGetProgramBinary = nullptr;
	glProgramBinary = nullptr;
	glProgramParameteri = nullptr;
	glUseProgramStages = nullptr;
	glActiveShaderProgram = nullptr;
	glCreateShaderProgramv = nullptr;
	glBindProgramPipeline = nullptr;
	glDeleteProgramPipelines = nullptr;
	glGenProgramPipelines = nullptr;
	glIsProgramPipeline = nullptr;
	glGetProgramPipelineiv = nullptr;
	glProgramUniform1i = nullptr;
	glProgramUniform1iv = nullptr;
	glProgramUniform1f = nullptr;
	glProgramUniform1fv = nullptr;
	glProgramUniform1d = nullptr;
	glProgramUniform1dv = nullptr;
	glProgramUniform1ui = nullptr;
	glProgramUniform1uiv = nullptr;
	glProgramUniform2i = nullptr;
	glProgramUniform2iv = nullptr;
	glProgramUniform2f = nullptr;
	glProgramUniform2fv = nullptr;
	glProgramUniform2d = nullptr;
	glProgramUniform2dv = nullptr;
	glProgramUniform2ui = nullptr;
	glProgramUniform2uiv = nullptr;
	glProgramUniform3i = nullptr;
	glProgramUniform3iv = nullptr;
	glProgramUniform3f = nullptr;
	glProgramUniform3fv = nullptr;
	glProgramUniform3d = nullptr;
	glProgramUniform3dv = nullptr;
	glProgramUniform3ui = nullptr;
	glProgramUniform3uiv = nullptr;
	glProgramUniform4i = nullptr;
	glProgramUniform4iv = nullptr;
	glProgramUniform4f = nullptr;
	glProgramUniform4fv = nullptr;
	glProgramUniform4d = nullptr;
	glProgramUniform4dv = nullptr;
	glProgramUniform4ui = nullptr;
	glProgramUniform4uiv = nullptr;
	glProgramUniformMatrix2fv = nullptr;
	glProgramUniformMatrix3fv = nullptr;
	glProgramUniformMatrix4fv = nullptr;
	glProgramUniformMatrix2dv = nullptr;
	glProgramUniformMatrix3dv = nullptr;
	glProgramUniformMatrix4dv = nullptr;
	glProgramUniformMatrix2x3fv = nullptr;
	glProgramUniformMatrix3x2fv = nullptr;
	glProgramUniformMatrix2x4fv = nullptr;
	glProgramUniformMatrix4x2fv = nullptr;
	glProgramUniformMatrix3x4fv = nullptr;
	glProgramUniformMatrix4x3fv = nullptr;
	glProgramUniformMatrix2x3dv = nullptr;
	glProgramUniformMatrix3x2dv = nullptr;
	glProgramUniformMatrix2x4dv = nullptr;
	glProgramUniformMatrix4x2dv = nullptr;
	glProgramUniformMatrix3x4dv = nullptr;
	glProgramUniformMatrix4x3dv = nullptr;
	glValidateProgramPipeline = nullptr;
	glGetProgramPipelineInfoLog = nullptr;
	glVertexAttribL1d = nullptr;
	glVertexAttribL2d = nullptr;
	glVertexAttribL3d = nullptr;
	glVertexAttribL4d = nullptr;
	glVertexAttribL1dv = nullptr;
	glVertexAttribL2dv = nullptr;
	glVertexAttribL3dv = nullptr;
	glVertexAttribL4dv = nullptr;
	glVertexAttribLPointer = nullptr;
	glGetVertexAttribLdv = nullptr;
	glViewportArrayv = nullptr;
	glViewportIndexedf = nullptr;
	glViewportIndexedfv = nullptr;
	glScissorArrayv = nullptr;
	glScissorIndexed = nullptr;
	glScissorIndexedv = nullptr;
	glDepthRangeArrayv = nullptr;
	glDepthRangeIndexed = nullptr;
	glGetFloati_v = nullptr;
	glGetDoublei_v = nullptr;
	glDrawArraysInstancedBaseInstance = nullptr;
	glDrawElementsInstancedBaseInstance = nullptr;
	glDrawElementsInstancedBaseVertexBaseInstance = nullptr;
	glGetInternalformativ = nullptr;
	glGetActiveAtomicCounterBufferiv = nullptr;
	glBindImageTexture = nullptr;
	glMemoryBarrier = nullptr;
	glTexStorage1D = nullptr;
	glTexStorage2D = nullptr;
	glTexStorage3D = nullptr;
	glDrawTransformFeedbackInstanced = nullptr;
	glDrawTransformFeedbackStreamInstanced = nullptr;
	glClearBufferData = nullptr;
	glClearBufferSubData = nullptr;
	glDispatchCompute = nullptr;
	glDispatchComputeIndirect = nullptr;
	glCopyImageSubData = nullptr;
	glFramebufferParameteri = nullptr;
	glGetFramebufferParameteriv = nullptr;
	glGetInternalformati64v = nullptr;
	glInvalidateTexSubImage = nullptr;
	glInvalidateTexImage = nullptr;
	glInvalidateBufferSubData = nullptr;
	glInvalidateBufferData = nullptr;
	glInvalidateFramebuffer = nullptr;
	glInvalidateSubFramebuffer = nullptr;
	glMultiDrawArraysIndirect = nullptr;
	glMultiDrawElementsIndirect = nullptr;
	glGetProgramInterfaceiv = nullptr;
	glGetProgramResourceIndex = nullptr;
	glGetProgramResourceName = nullptr;
	glGetProgramResourceiv = nullptr;
	glGetProgramResourceLocation = nullptr;
	glGetProgramResourceLocationIndex = nullptr;
	glShaderStorageBlockBinding = nullptr;
	glTexBufferRange = nullptr;
	glTexStorage2DMultisample = nullptr;
	glTexStorage3DMultisample = nullptr;
	glTextureView = nullptr;
	glBindVertexBuffer = nullptr;
	glVertexAttribFormat = nullptr;
	glVertexAttribIFormat = nullptr;
	glVertexAttribLFormat = nullptr;
	glVertexAttribBinding = nullptr;
	glVertexBindingDivisor = nullptr;
	glDebugMessageControl = nullptr;
	glDebugMessageInsert = nullptr;
	glDebugMessageCallback = nullptr;
	glGetDebugMessageLog = nullptr;
	glPushDebugGroup = nullptr;
	glPopDebugGroup = nullptr;
	glObjectLabel = nullptr;
	glGetObjectLabel = nullptr;
	glObjectPtrLabel = nullptr;
	glGetObjectPtrLabel = nullptr;
	glBufferStorage = nullptr;
	glClearTexImage = nullptr;
	glClearTexSubImage = nullptr;
	glBindBuffersBase = nullptr;
	glBindBuffersRange = nullptr;
	glBindTextures = nullptr;
	glBindSamplers = nullptr;
	glBindImageTextures = nullptr;
	glBindVertexBuffers = nullptr;
	glClipControl = nullptr;
	glCreateTransformFeedbacks = nullptr;
	glTransformFeedbackBufferBase = nullptr;
	glTransformFeedbackBufferRange = nullptr;
	glGetTransformFeedbackiv = nullptr;
	glGetTransformFeedbacki_v = nullptr;
	glGetTransformFeedbacki64_v = nullptr;
	glCreateBuffers = nullptr;
	glNamedBufferStorage = nullptr;
	glNamedBufferData = nullptr;
	glNamedBufferSubData = nullptr;
	glCopyNamedBufferSubData = nullptr;
	glClearNamedBufferData = nullptr;
	glClearNamedBufferSubData = nullptr;
	glMapNamedBuffer = nullptr;
	glMapNamedBufferRange = nullptr;
	glUnmapNamedBuffer = nullptr;
	glFlushMappedNamedBufferRange = nullptr;
	glGetNamedBufferParameteriv = nullptr;
	glGetNamedBufferParameteri64v = nullptr;
	glGetNamedBufferPointerv = nullptr;
	glGetNamedBufferSubData = nullptr;
	glCreateFramebuffers = nullptr;
	glNamedFramebufferRenderbuffer = nullptr;
	glNamedFramebufferParameteri = nullptr;
	glNamedFramebufferTexture = nullptr;
	glNamedFramebufferTextureLayer = nullptr;
	glNamedFramebufferDrawBuffer = nullptr;
	glNamedFramebufferDrawBuffers = nullptr;
	glNamedFramebufferReadBuffer = nullptr;
	glInvalidateNamedFramebufferData = nullptr;
	glInvalidateNamedFramebufferSubData = nullptr;
	glClearNamedFramebufferiv = nullptr;
	glClearNamedFramebufferuiv = nullptr;
	glClearNamedFramebufferfv = nullptr;
	glClearNamedFramebufferfi = nullptr;
	glBlitNamedFramebuffer = nullptr;
	glCheckNamedFramebufferStatus = nullptr;
	glGetNamedFramebufferParameteriv = nullptr;
	glGetNamedFramebufferAttachmentParameteriv = nullptr;
	glCreateRenderbuffers = nullptr;
	glNamedRenderbufferStorage = nullptr;
	glNamedRenderbufferStorageMultisample = nullptr;
	glGetNamedRenderbufferParameteriv = nullptr;
	glCreateTextures = nullptr;
	glTextureBuffer = nullptr;
	glTextureBufferRange = nullptr;
	glTextureStorage1D = nullptr;
	glTextureStorage2D = nullptr;
	glTextureStorage3D = nullptr;
	glTextureStorage2DMultisample = nullptr;
	glTextureStorage3DMultisample = nullptr;
	glTextureSubImage1D = nullptr;
	glTextureSubImage2D = nullptr;
	glTextureSubImage3D = nullptr;
	glCompressedTextureSubImage1D = nullptr;
	glCompressedTextureSubImage2D = nullptr;
	glCompressedTextureSubImage3D = nullptr;
	glCopyTextureSubImage1D = nullptr;
	glCopyTextureSubImage2D = nullptr;
	glCopyTextureSubImage3D = nullptr;
	glTextureParameterf = nullptr;
	glTextureParameterfv = nullptr;
	glTextureParameteri = nullptr;
	glTextureParameterIiv = nullptr;
	glTextureParameterIuiv = nullptr;
	glTextureParameteriv = nullptr;
	glGenerateTextureMipmap = nullptr;
	glBindTextureUnit = nullptr;
	glGetTextureImage = nullptr;
	glGetCompressedTextureImage = nullptr;
	glGetTextureLevelParameterfv = nullptr;
	glGetTextureLevelParameteriv = nullptr;
	glGetTextureParameterfv = nullptr;
	glGetTextureParameterIiv = nullptr;
	glGetTextureParameterIuiv = nullptr;
	glGetTextureParameteriv = nullptr;
	glCreateVertexArrays = nullptr;
	glDisableVertexArrayAttrib = nullptr;
	glEnableVertexArrayAttrib = nullptr;
	glVertexArrayElementBuffer = nullptr;
	glVertexArrayVertexBuffer = nullptr;
	glVertexArrayVertexBuffers = nullptr;
	glVertexArrayAttribBinding = nullptr;
	glVertexArrayAttribFormat = nullptr;
	glVertexArrayAttribIFormat = nullptr;
	glVertexArrayAttribLFormat = nullptr;
	glVertexArrayBindingDivisor = nullptr;
	glGetVertexArrayiv = nullptr;
	glGetVertexArrayIndexediv = nullptr;
	glGetVertexArrayIndexed64iv = nullptr;
	glCreateSamplers = nullptr;
	glCreateProgramPipelines = nullptr;
	glCreateQueries = nullptr;
	glGetQueryBufferObjecti64v = nullptr;
	glGetQueryBufferObjectiv = nullptr;
	glGetQueryBufferObjectui64v = nullptr;
	glGetQueryBufferObjectuiv = nullptr;
	glMemoryBarrierByRegion = nullptr;
	glGetTextureSubImage = nullptr;
	glGetCompressedTextureSubImage = nullptr;
	glGetGraphicsResetStatus = nullptr;
	glGetnCompressedTexImage = nullptr;
	glGetnTexImage = nullptr;
	glGetnUniformdv = nullptr;
	glGetnUniformfv = nullptr;
	glGetnUniformiv = nullptr;
	glGetnUniformuiv = nullptr;
	glReadnPixels = nullptr;
	glTextureBarrier = nullptr;
	glSpecializeShader = nullptr;
	glMultiDrawArraysIndirectCount = nullptr;
	glMultiDrawElementsIndirectCount = nullptr;
	glPolygonOffsetClamp = nullptr;
}
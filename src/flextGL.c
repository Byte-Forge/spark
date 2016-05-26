/* WARNING: This file was automatically generated */
/* Do not edit. */

#include "flextGL.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if defined(_WIN32) || defined(WIN32) 
#define FLEXT_CALL __stdcall
#else
#define FLEXT_CALL
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* FLEXT_C_EXTENSION
 * Compiling in strict c leads to errors due to void* to function ptr
 * cast being illegal. Mark as extension so that the compiler will 
 * accept it.
 */
#if defined(__GNUC__) || defined(__clang__)
#define FLEXT_C_EXTENSION(x) __extension__(x)
#else
#define FLEXT_C_EXTENSION(x) x
#endif

typedef void(FLEXT_CALL *GLPROC)();

void flextLoadOpenGLFunctions(void);

static void open_libgl(void);
static void close_libgl(void);
static GLPROC get_proc(const char *proc);
static void add_extension(const char* extension);

int flextInit(void)
{
    GLint minor, major;
    GLint num_extensions;
    int i;

    open_libgl();
    flextLoadOpenGLFunctions();
    close_libgl();

    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    /* --- Check for minimal version and profile --- */

    if (major * 10 + minor < 30) {
#if !defined(FLEXT_NO_LOGGING)	
        fprintf(stderr, "Error: OpenGL version 3.0 not supported.\n");
        fprintf(stderr, "       Your version is %d.%d.\n", major, minor);
        fprintf(stderr, "       Try updating your graphics driver.\n");
#endif
        return GL_FALSE;
    }


    /* --- Check for extensions --- */

    glGetIntegerv(GL_NUM_EXTENSIONS, &num_extensions);
    
    for (i = 0; i < num_extensions; i++) {
        add_extension((const char*)glGetStringi(GL_EXTENSIONS, i));
    }

    if (!FLEXT_ARB_uniform_buffer_object) {
        fprintf(stderr, "Error: OpenGL extension GL_ARB_uniform_buffer_object not supported.\n");
        fprintf(stderr, "       Try updating your graphics driver.\n");
        return GL_FALSE;
    }

    return GL_TRUE;
}



void flextLoadOpenGLFunctions(void)
{
    /* --- Function pointer loading --- */


    /* GL_ARB_uniform_buffer_object */

    glpfGetActiveUniformBlockName = (PFNGLGETACTIVEUNIFORMBLOCKNAME_PROC*)get_proc("glGetActiveUniformBlockName");
    glpfGetActiveUniformBlockiv = (PFNGLGETACTIVEUNIFORMBLOCKIV_PROC*)get_proc("glGetActiveUniformBlockiv");
    glpfGetActiveUniformName = (PFNGLGETACTIVEUNIFORMNAME_PROC*)get_proc("glGetActiveUniformName");
    glpfGetActiveUniformsiv = (PFNGLGETACTIVEUNIFORMSIV_PROC*)get_proc("glGetActiveUniformsiv");
    glpfGetUniformBlockIndex = (PFNGLGETUNIFORMBLOCKINDEX_PROC*)get_proc("glGetUniformBlockIndex");
    glpfGetUniformIndices = (PFNGLGETUNIFORMINDICES_PROC*)get_proc("glGetUniformIndices");
    glpfUniformBlockBinding = (PFNGLUNIFORMBLOCKBINDING_PROC*)get_proc("glUniformBlockBinding");


    /* GL_VERSION_1_2 */

    glpfCopyTexSubImage3D = (PFNGLCOPYTEXSUBIMAGE3D_PROC*)get_proc("glCopyTexSubImage3D");
    glpfDrawRangeElements = (PFNGLDRAWRANGEELEMENTS_PROC*)get_proc("glDrawRangeElements");
    glpfTexImage3D = (PFNGLTEXIMAGE3D_PROC*)get_proc("glTexImage3D");
    glpfTexSubImage3D = (PFNGLTEXSUBIMAGE3D_PROC*)get_proc("glTexSubImage3D");


    /* GL_VERSION_1_3 */

    glpfActiveTexture = (PFNGLACTIVETEXTURE_PROC*)get_proc("glActiveTexture");
    glpfClientActiveTexture = (PFNGLCLIENTACTIVETEXTURE_PROC*)get_proc("glClientActiveTexture");
    glpfCompressedTexImage1D = (PFNGLCOMPRESSEDTEXIMAGE1D_PROC*)get_proc("glCompressedTexImage1D");
    glpfCompressedTexImage2D = (PFNGLCOMPRESSEDTEXIMAGE2D_PROC*)get_proc("glCompressedTexImage2D");
    glpfCompressedTexImage3D = (PFNGLCOMPRESSEDTEXIMAGE3D_PROC*)get_proc("glCompressedTexImage3D");
    glpfCompressedTexSubImage1D = (PFNGLCOMPRESSEDTEXSUBIMAGE1D_PROC*)get_proc("glCompressedTexSubImage1D");
    glpfCompressedTexSubImage2D = (PFNGLCOMPRESSEDTEXSUBIMAGE2D_PROC*)get_proc("glCompressedTexSubImage2D");
    glpfCompressedTexSubImage3D = (PFNGLCOMPRESSEDTEXSUBIMAGE3D_PROC*)get_proc("glCompressedTexSubImage3D");
    glpfGetCompressedTexImage = (PFNGLGETCOMPRESSEDTEXIMAGE_PROC*)get_proc("glGetCompressedTexImage");
    glpfLoadTransposeMatrixd = (PFNGLLOADTRANSPOSEMATRIXD_PROC*)get_proc("glLoadTransposeMatrixd");
    glpfLoadTransposeMatrixf = (PFNGLLOADTRANSPOSEMATRIXF_PROC*)get_proc("glLoadTransposeMatrixf");
    glpfMultTransposeMatrixd = (PFNGLMULTTRANSPOSEMATRIXD_PROC*)get_proc("glMultTransposeMatrixd");
    glpfMultTransposeMatrixf = (PFNGLMULTTRANSPOSEMATRIXF_PROC*)get_proc("glMultTransposeMatrixf");
    glpfMultiTexCoord1d = (PFNGLMULTITEXCOORD1D_PROC*)get_proc("glMultiTexCoord1d");
    glpfMultiTexCoord1dv = (PFNGLMULTITEXCOORD1DV_PROC*)get_proc("glMultiTexCoord1dv");
    glpfMultiTexCoord1f = (PFNGLMULTITEXCOORD1F_PROC*)get_proc("glMultiTexCoord1f");
    glpfMultiTexCoord1fv = (PFNGLMULTITEXCOORD1FV_PROC*)get_proc("glMultiTexCoord1fv");
    glpfMultiTexCoord1i = (PFNGLMULTITEXCOORD1I_PROC*)get_proc("glMultiTexCoord1i");
    glpfMultiTexCoord1iv = (PFNGLMULTITEXCOORD1IV_PROC*)get_proc("glMultiTexCoord1iv");
    glpfMultiTexCoord1s = (PFNGLMULTITEXCOORD1S_PROC*)get_proc("glMultiTexCoord1s");
    glpfMultiTexCoord1sv = (PFNGLMULTITEXCOORD1SV_PROC*)get_proc("glMultiTexCoord1sv");
    glpfMultiTexCoord2d = (PFNGLMULTITEXCOORD2D_PROC*)get_proc("glMultiTexCoord2d");
    glpfMultiTexCoord2dv = (PFNGLMULTITEXCOORD2DV_PROC*)get_proc("glMultiTexCoord2dv");
    glpfMultiTexCoord2f = (PFNGLMULTITEXCOORD2F_PROC*)get_proc("glMultiTexCoord2f");
    glpfMultiTexCoord2fv = (PFNGLMULTITEXCOORD2FV_PROC*)get_proc("glMultiTexCoord2fv");
    glpfMultiTexCoord2i = (PFNGLMULTITEXCOORD2I_PROC*)get_proc("glMultiTexCoord2i");
    glpfMultiTexCoord2iv = (PFNGLMULTITEXCOORD2IV_PROC*)get_proc("glMultiTexCoord2iv");
    glpfMultiTexCoord2s = (PFNGLMULTITEXCOORD2S_PROC*)get_proc("glMultiTexCoord2s");
    glpfMultiTexCoord2sv = (PFNGLMULTITEXCOORD2SV_PROC*)get_proc("glMultiTexCoord2sv");
    glpfMultiTexCoord3d = (PFNGLMULTITEXCOORD3D_PROC*)get_proc("glMultiTexCoord3d");
    glpfMultiTexCoord3dv = (PFNGLMULTITEXCOORD3DV_PROC*)get_proc("glMultiTexCoord3dv");
    glpfMultiTexCoord3f = (PFNGLMULTITEXCOORD3F_PROC*)get_proc("glMultiTexCoord3f");
    glpfMultiTexCoord3fv = (PFNGLMULTITEXCOORD3FV_PROC*)get_proc("glMultiTexCoord3fv");
    glpfMultiTexCoord3i = (PFNGLMULTITEXCOORD3I_PROC*)get_proc("glMultiTexCoord3i");
    glpfMultiTexCoord3iv = (PFNGLMULTITEXCOORD3IV_PROC*)get_proc("glMultiTexCoord3iv");
    glpfMultiTexCoord3s = (PFNGLMULTITEXCOORD3S_PROC*)get_proc("glMultiTexCoord3s");
    glpfMultiTexCoord3sv = (PFNGLMULTITEXCOORD3SV_PROC*)get_proc("glMultiTexCoord3sv");
    glpfMultiTexCoord4d = (PFNGLMULTITEXCOORD4D_PROC*)get_proc("glMultiTexCoord4d");
    glpfMultiTexCoord4dv = (PFNGLMULTITEXCOORD4DV_PROC*)get_proc("glMultiTexCoord4dv");
    glpfMultiTexCoord4f = (PFNGLMULTITEXCOORD4F_PROC*)get_proc("glMultiTexCoord4f");
    glpfMultiTexCoord4fv = (PFNGLMULTITEXCOORD4FV_PROC*)get_proc("glMultiTexCoord4fv");
    glpfMultiTexCoord4i = (PFNGLMULTITEXCOORD4I_PROC*)get_proc("glMultiTexCoord4i");
    glpfMultiTexCoord4iv = (PFNGLMULTITEXCOORD4IV_PROC*)get_proc("glMultiTexCoord4iv");
    glpfMultiTexCoord4s = (PFNGLMULTITEXCOORD4S_PROC*)get_proc("glMultiTexCoord4s");
    glpfMultiTexCoord4sv = (PFNGLMULTITEXCOORD4SV_PROC*)get_proc("glMultiTexCoord4sv");
    glpfSampleCoverage = (PFNGLSAMPLECOVERAGE_PROC*)get_proc("glSampleCoverage");


    /* GL_VERSION_1_4 */

    glpfBlendColor = (PFNGLBLENDCOLOR_PROC*)get_proc("glBlendColor");
    glpfBlendEquation = (PFNGLBLENDEQUATION_PROC*)get_proc("glBlendEquation");
    glpfBlendFuncSeparate = (PFNGLBLENDFUNCSEPARATE_PROC*)get_proc("glBlendFuncSeparate");
    glpfFogCoordPointer = (PFNGLFOGCOORDPOINTER_PROC*)get_proc("glFogCoordPointer");
    glpfFogCoordd = (PFNGLFOGCOORDD_PROC*)get_proc("glFogCoordd");
    glpfFogCoorddv = (PFNGLFOGCOORDDV_PROC*)get_proc("glFogCoorddv");
    glpfFogCoordf = (PFNGLFOGCOORDF_PROC*)get_proc("glFogCoordf");
    glpfFogCoordfv = (PFNGLFOGCOORDFV_PROC*)get_proc("glFogCoordfv");
    glpfMultiDrawArrays = (PFNGLMULTIDRAWARRAYS_PROC*)get_proc("glMultiDrawArrays");
    glpfMultiDrawElements = (PFNGLMULTIDRAWELEMENTS_PROC*)get_proc("glMultiDrawElements");
    glpfPointParameterf = (PFNGLPOINTPARAMETERF_PROC*)get_proc("glPointParameterf");
    glpfPointParameterfv = (PFNGLPOINTPARAMETERFV_PROC*)get_proc("glPointParameterfv");
    glpfPointParameteri = (PFNGLPOINTPARAMETERI_PROC*)get_proc("glPointParameteri");
    glpfPointParameteriv = (PFNGLPOINTPARAMETERIV_PROC*)get_proc("glPointParameteriv");
    glpfSecondaryColor3b = (PFNGLSECONDARYCOLOR3B_PROC*)get_proc("glSecondaryColor3b");
    glpfSecondaryColor3bv = (PFNGLSECONDARYCOLOR3BV_PROC*)get_proc("glSecondaryColor3bv");
    glpfSecondaryColor3d = (PFNGLSECONDARYCOLOR3D_PROC*)get_proc("glSecondaryColor3d");
    glpfSecondaryColor3dv = (PFNGLSECONDARYCOLOR3DV_PROC*)get_proc("glSecondaryColor3dv");
    glpfSecondaryColor3f = (PFNGLSECONDARYCOLOR3F_PROC*)get_proc("glSecondaryColor3f");
    glpfSecondaryColor3fv = (PFNGLSECONDARYCOLOR3FV_PROC*)get_proc("glSecondaryColor3fv");
    glpfSecondaryColor3i = (PFNGLSECONDARYCOLOR3I_PROC*)get_proc("glSecondaryColor3i");
    glpfSecondaryColor3iv = (PFNGLSECONDARYCOLOR3IV_PROC*)get_proc("glSecondaryColor3iv");
    glpfSecondaryColor3s = (PFNGLSECONDARYCOLOR3S_PROC*)get_proc("glSecondaryColor3s");
    glpfSecondaryColor3sv = (PFNGLSECONDARYCOLOR3SV_PROC*)get_proc("glSecondaryColor3sv");
    glpfSecondaryColor3ub = (PFNGLSECONDARYCOLOR3UB_PROC*)get_proc("glSecondaryColor3ub");
    glpfSecondaryColor3ubv = (PFNGLSECONDARYCOLOR3UBV_PROC*)get_proc("glSecondaryColor3ubv");
    glpfSecondaryColor3ui = (PFNGLSECONDARYCOLOR3UI_PROC*)get_proc("glSecondaryColor3ui");
    glpfSecondaryColor3uiv = (PFNGLSECONDARYCOLOR3UIV_PROC*)get_proc("glSecondaryColor3uiv");
    glpfSecondaryColor3us = (PFNGLSECONDARYCOLOR3US_PROC*)get_proc("glSecondaryColor3us");
    glpfSecondaryColor3usv = (PFNGLSECONDARYCOLOR3USV_PROC*)get_proc("glSecondaryColor3usv");
    glpfSecondaryColorPointer = (PFNGLSECONDARYCOLORPOINTER_PROC*)get_proc("glSecondaryColorPointer");
    glpfWindowPos2d = (PFNGLWINDOWPOS2D_PROC*)get_proc("glWindowPos2d");
    glpfWindowPos2dv = (PFNGLWINDOWPOS2DV_PROC*)get_proc("glWindowPos2dv");
    glpfWindowPos2f = (PFNGLWINDOWPOS2F_PROC*)get_proc("glWindowPos2f");
    glpfWindowPos2fv = (PFNGLWINDOWPOS2FV_PROC*)get_proc("glWindowPos2fv");
    glpfWindowPos2i = (PFNGLWINDOWPOS2I_PROC*)get_proc("glWindowPos2i");
    glpfWindowPos2iv = (PFNGLWINDOWPOS2IV_PROC*)get_proc("glWindowPos2iv");
    glpfWindowPos2s = (PFNGLWINDOWPOS2S_PROC*)get_proc("glWindowPos2s");
    glpfWindowPos2sv = (PFNGLWINDOWPOS2SV_PROC*)get_proc("glWindowPos2sv");
    glpfWindowPos3d = (PFNGLWINDOWPOS3D_PROC*)get_proc("glWindowPos3d");
    glpfWindowPos3dv = (PFNGLWINDOWPOS3DV_PROC*)get_proc("glWindowPos3dv");
    glpfWindowPos3f = (PFNGLWINDOWPOS3F_PROC*)get_proc("glWindowPos3f");
    glpfWindowPos3fv = (PFNGLWINDOWPOS3FV_PROC*)get_proc("glWindowPos3fv");
    glpfWindowPos3i = (PFNGLWINDOWPOS3I_PROC*)get_proc("glWindowPos3i");
    glpfWindowPos3iv = (PFNGLWINDOWPOS3IV_PROC*)get_proc("glWindowPos3iv");
    glpfWindowPos3s = (PFNGLWINDOWPOS3S_PROC*)get_proc("glWindowPos3s");
    glpfWindowPos3sv = (PFNGLWINDOWPOS3SV_PROC*)get_proc("glWindowPos3sv");


    /* GL_VERSION_1_5 */

    glpfBeginQuery = (PFNGLBEGINQUERY_PROC*)get_proc("glBeginQuery");
    glpfBindBuffer = (PFNGLBINDBUFFER_PROC*)get_proc("glBindBuffer");
    glpfBufferData = (PFNGLBUFFERDATA_PROC*)get_proc("glBufferData");
    glpfBufferSubData = (PFNGLBUFFERSUBDATA_PROC*)get_proc("glBufferSubData");
    glpfDeleteBuffers = (PFNGLDELETEBUFFERS_PROC*)get_proc("glDeleteBuffers");
    glpfDeleteQueries = (PFNGLDELETEQUERIES_PROC*)get_proc("glDeleteQueries");
    glpfEndQuery = (PFNGLENDQUERY_PROC*)get_proc("glEndQuery");
    glpfGenBuffers = (PFNGLGENBUFFERS_PROC*)get_proc("glGenBuffers");
    glpfGenQueries = (PFNGLGENQUERIES_PROC*)get_proc("glGenQueries");
    glpfGetBufferParameteriv = (PFNGLGETBUFFERPARAMETERIV_PROC*)get_proc("glGetBufferParameteriv");
    glpfGetBufferPointerv = (PFNGLGETBUFFERPOINTERV_PROC*)get_proc("glGetBufferPointerv");
    glpfGetBufferSubData = (PFNGLGETBUFFERSUBDATA_PROC*)get_proc("glGetBufferSubData");
    glpfGetQueryObjectiv = (PFNGLGETQUERYOBJECTIV_PROC*)get_proc("glGetQueryObjectiv");
    glpfGetQueryObjectuiv = (PFNGLGETQUERYOBJECTUIV_PROC*)get_proc("glGetQueryObjectuiv");
    glpfGetQueryiv = (PFNGLGETQUERYIV_PROC*)get_proc("glGetQueryiv");
    glpfIsBuffer = (PFNGLISBUFFER_PROC*)get_proc("glIsBuffer");
    glpfIsQuery = (PFNGLISQUERY_PROC*)get_proc("glIsQuery");
    glpfMapBuffer = (PFNGLMAPBUFFER_PROC*)get_proc("glMapBuffer");
    glpfUnmapBuffer = (PFNGLUNMAPBUFFER_PROC*)get_proc("glUnmapBuffer");


    /* GL_VERSION_2_0 */

    glpfAttachShader = (PFNGLATTACHSHADER_PROC*)get_proc("glAttachShader");
    glpfBindAttribLocation = (PFNGLBINDATTRIBLOCATION_PROC*)get_proc("glBindAttribLocation");
    glpfBlendEquationSeparate = (PFNGLBLENDEQUATIONSEPARATE_PROC*)get_proc("glBlendEquationSeparate");
    glpfCompileShader = (PFNGLCOMPILESHADER_PROC*)get_proc("glCompileShader");
    glpfCreateProgram = (PFNGLCREATEPROGRAM_PROC*)get_proc("glCreateProgram");
    glpfCreateShader = (PFNGLCREATESHADER_PROC*)get_proc("glCreateShader");
    glpfDeleteProgram = (PFNGLDELETEPROGRAM_PROC*)get_proc("glDeleteProgram");
    glpfDeleteShader = (PFNGLDELETESHADER_PROC*)get_proc("glDeleteShader");
    glpfDetachShader = (PFNGLDETACHSHADER_PROC*)get_proc("glDetachShader");
    glpfDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAY_PROC*)get_proc("glDisableVertexAttribArray");
    glpfDrawBuffers = (PFNGLDRAWBUFFERS_PROC*)get_proc("glDrawBuffers");
    glpfEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAY_PROC*)get_proc("glEnableVertexAttribArray");
    glpfGetActiveAttrib = (PFNGLGETACTIVEATTRIB_PROC*)get_proc("glGetActiveAttrib");
    glpfGetActiveUniform = (PFNGLGETACTIVEUNIFORM_PROC*)get_proc("glGetActiveUniform");
    glpfGetAttachedShaders = (PFNGLGETATTACHEDSHADERS_PROC*)get_proc("glGetAttachedShaders");
    glpfGetAttribLocation = (PFNGLGETATTRIBLOCATION_PROC*)get_proc("glGetAttribLocation");
    glpfGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOG_PROC*)get_proc("glGetProgramInfoLog");
    glpfGetProgramiv = (PFNGLGETPROGRAMIV_PROC*)get_proc("glGetProgramiv");
    glpfGetShaderInfoLog = (PFNGLGETSHADERINFOLOG_PROC*)get_proc("glGetShaderInfoLog");
    glpfGetShaderSource = (PFNGLGETSHADERSOURCE_PROC*)get_proc("glGetShaderSource");
    glpfGetShaderiv = (PFNGLGETSHADERIV_PROC*)get_proc("glGetShaderiv");
    glpfGetUniformLocation = (PFNGLGETUNIFORMLOCATION_PROC*)get_proc("glGetUniformLocation");
    glpfGetUniformfv = (PFNGLGETUNIFORMFV_PROC*)get_proc("glGetUniformfv");
    glpfGetUniformiv = (PFNGLGETUNIFORMIV_PROC*)get_proc("glGetUniformiv");
    glpfGetVertexAttribPointerv = (PFNGLGETVERTEXATTRIBPOINTERV_PROC*)get_proc("glGetVertexAttribPointerv");
    glpfGetVertexAttribdv = (PFNGLGETVERTEXATTRIBDV_PROC*)get_proc("glGetVertexAttribdv");
    glpfGetVertexAttribfv = (PFNGLGETVERTEXATTRIBFV_PROC*)get_proc("glGetVertexAttribfv");
    glpfGetVertexAttribiv = (PFNGLGETVERTEXATTRIBIV_PROC*)get_proc("glGetVertexAttribiv");
    glpfIsProgram = (PFNGLISPROGRAM_PROC*)get_proc("glIsProgram");
    glpfIsShader = (PFNGLISSHADER_PROC*)get_proc("glIsShader");
    glpfLinkProgram = (PFNGLLINKPROGRAM_PROC*)get_proc("glLinkProgram");
    glpfShaderSource = (PFNGLSHADERSOURCE_PROC*)get_proc("glShaderSource");
    glpfStencilFuncSeparate = (PFNGLSTENCILFUNCSEPARATE_PROC*)get_proc("glStencilFuncSeparate");
    glpfStencilMaskSeparate = (PFNGLSTENCILMASKSEPARATE_PROC*)get_proc("glStencilMaskSeparate");
    glpfStencilOpSeparate = (PFNGLSTENCILOPSEPARATE_PROC*)get_proc("glStencilOpSeparate");
    glpfUniform1f = (PFNGLUNIFORM1F_PROC*)get_proc("glUniform1f");
    glpfUniform1fv = (PFNGLUNIFORM1FV_PROC*)get_proc("glUniform1fv");
    glpfUniform1i = (PFNGLUNIFORM1I_PROC*)get_proc("glUniform1i");
    glpfUniform1iv = (PFNGLUNIFORM1IV_PROC*)get_proc("glUniform1iv");
    glpfUniform2f = (PFNGLUNIFORM2F_PROC*)get_proc("glUniform2f");
    glpfUniform2fv = (PFNGLUNIFORM2FV_PROC*)get_proc("glUniform2fv");
    glpfUniform2i = (PFNGLUNIFORM2I_PROC*)get_proc("glUniform2i");
    glpfUniform2iv = (PFNGLUNIFORM2IV_PROC*)get_proc("glUniform2iv");
    glpfUniform3f = (PFNGLUNIFORM3F_PROC*)get_proc("glUniform3f");
    glpfUniform3fv = (PFNGLUNIFORM3FV_PROC*)get_proc("glUniform3fv");
    glpfUniform3i = (PFNGLUNIFORM3I_PROC*)get_proc("glUniform3i");
    glpfUniform3iv = (PFNGLUNIFORM3IV_PROC*)get_proc("glUniform3iv");
    glpfUniform4f = (PFNGLUNIFORM4F_PROC*)get_proc("glUniform4f");
    glpfUniform4fv = (PFNGLUNIFORM4FV_PROC*)get_proc("glUniform4fv");
    glpfUniform4i = (PFNGLUNIFORM4I_PROC*)get_proc("glUniform4i");
    glpfUniform4iv = (PFNGLUNIFORM4IV_PROC*)get_proc("glUniform4iv");
    glpfUniformMatrix2fv = (PFNGLUNIFORMMATRIX2FV_PROC*)get_proc("glUniformMatrix2fv");
    glpfUniformMatrix3fv = (PFNGLUNIFORMMATRIX3FV_PROC*)get_proc("glUniformMatrix3fv");
    glpfUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FV_PROC*)get_proc("glUniformMatrix4fv");
    glpfUseProgram = (PFNGLUSEPROGRAM_PROC*)get_proc("glUseProgram");
    glpfValidateProgram = (PFNGLVALIDATEPROGRAM_PROC*)get_proc("glValidateProgram");
    glpfVertexAttrib1d = (PFNGLVERTEXATTRIB1D_PROC*)get_proc("glVertexAttrib1d");
    glpfVertexAttrib1dv = (PFNGLVERTEXATTRIB1DV_PROC*)get_proc("glVertexAttrib1dv");
    glpfVertexAttrib1f = (PFNGLVERTEXATTRIB1F_PROC*)get_proc("glVertexAttrib1f");
    glpfVertexAttrib1fv = (PFNGLVERTEXATTRIB1FV_PROC*)get_proc("glVertexAttrib1fv");
    glpfVertexAttrib1s = (PFNGLVERTEXATTRIB1S_PROC*)get_proc("glVertexAttrib1s");
    glpfVertexAttrib1sv = (PFNGLVERTEXATTRIB1SV_PROC*)get_proc("glVertexAttrib1sv");
    glpfVertexAttrib2d = (PFNGLVERTEXATTRIB2D_PROC*)get_proc("glVertexAttrib2d");
    glpfVertexAttrib2dv = (PFNGLVERTEXATTRIB2DV_PROC*)get_proc("glVertexAttrib2dv");
    glpfVertexAttrib2f = (PFNGLVERTEXATTRIB2F_PROC*)get_proc("glVertexAttrib2f");
    glpfVertexAttrib2fv = (PFNGLVERTEXATTRIB2FV_PROC*)get_proc("glVertexAttrib2fv");
    glpfVertexAttrib2s = (PFNGLVERTEXATTRIB2S_PROC*)get_proc("glVertexAttrib2s");
    glpfVertexAttrib2sv = (PFNGLVERTEXATTRIB2SV_PROC*)get_proc("glVertexAttrib2sv");
    glpfVertexAttrib3d = (PFNGLVERTEXATTRIB3D_PROC*)get_proc("glVertexAttrib3d");
    glpfVertexAttrib3dv = (PFNGLVERTEXATTRIB3DV_PROC*)get_proc("glVertexAttrib3dv");
    glpfVertexAttrib3f = (PFNGLVERTEXATTRIB3F_PROC*)get_proc("glVertexAttrib3f");
    glpfVertexAttrib3fv = (PFNGLVERTEXATTRIB3FV_PROC*)get_proc("glVertexAttrib3fv");
    glpfVertexAttrib3s = (PFNGLVERTEXATTRIB3S_PROC*)get_proc("glVertexAttrib3s");
    glpfVertexAttrib3sv = (PFNGLVERTEXATTRIB3SV_PROC*)get_proc("glVertexAttrib3sv");
    glpfVertexAttrib4Nbv = (PFNGLVERTEXATTRIB4NBV_PROC*)get_proc("glVertexAttrib4Nbv");
    glpfVertexAttrib4Niv = (PFNGLVERTEXATTRIB4NIV_PROC*)get_proc("glVertexAttrib4Niv");
    glpfVertexAttrib4Nsv = (PFNGLVERTEXATTRIB4NSV_PROC*)get_proc("glVertexAttrib4Nsv");
    glpfVertexAttrib4Nub = (PFNGLVERTEXATTRIB4NUB_PROC*)get_proc("glVertexAttrib4Nub");
    glpfVertexAttrib4Nubv = (PFNGLVERTEXATTRIB4NUBV_PROC*)get_proc("glVertexAttrib4Nubv");
    glpfVertexAttrib4Nuiv = (PFNGLVERTEXATTRIB4NUIV_PROC*)get_proc("glVertexAttrib4Nuiv");
    glpfVertexAttrib4Nusv = (PFNGLVERTEXATTRIB4NUSV_PROC*)get_proc("glVertexAttrib4Nusv");
    glpfVertexAttrib4bv = (PFNGLVERTEXATTRIB4BV_PROC*)get_proc("glVertexAttrib4bv");
    glpfVertexAttrib4d = (PFNGLVERTEXATTRIB4D_PROC*)get_proc("glVertexAttrib4d");
    glpfVertexAttrib4dv = (PFNGLVERTEXATTRIB4DV_PROC*)get_proc("glVertexAttrib4dv");
    glpfVertexAttrib4f = (PFNGLVERTEXATTRIB4F_PROC*)get_proc("glVertexAttrib4f");
    glpfVertexAttrib4fv = (PFNGLVERTEXATTRIB4FV_PROC*)get_proc("glVertexAttrib4fv");
    glpfVertexAttrib4iv = (PFNGLVERTEXATTRIB4IV_PROC*)get_proc("glVertexAttrib4iv");
    glpfVertexAttrib4s = (PFNGLVERTEXATTRIB4S_PROC*)get_proc("glVertexAttrib4s");
    glpfVertexAttrib4sv = (PFNGLVERTEXATTRIB4SV_PROC*)get_proc("glVertexAttrib4sv");
    glpfVertexAttrib4ubv = (PFNGLVERTEXATTRIB4UBV_PROC*)get_proc("glVertexAttrib4ubv");
    glpfVertexAttrib4uiv = (PFNGLVERTEXATTRIB4UIV_PROC*)get_proc("glVertexAttrib4uiv");
    glpfVertexAttrib4usv = (PFNGLVERTEXATTRIB4USV_PROC*)get_proc("glVertexAttrib4usv");
    glpfVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTER_PROC*)get_proc("glVertexAttribPointer");


    /* GL_VERSION_2_1 */

    glpfUniformMatrix2x3fv = (PFNGLUNIFORMMATRIX2X3FV_PROC*)get_proc("glUniformMatrix2x3fv");
    glpfUniformMatrix2x4fv = (PFNGLUNIFORMMATRIX2X4FV_PROC*)get_proc("glUniformMatrix2x4fv");
    glpfUniformMatrix3x2fv = (PFNGLUNIFORMMATRIX3X2FV_PROC*)get_proc("glUniformMatrix3x2fv");
    glpfUniformMatrix3x4fv = (PFNGLUNIFORMMATRIX3X4FV_PROC*)get_proc("glUniformMatrix3x4fv");
    glpfUniformMatrix4x2fv = (PFNGLUNIFORMMATRIX4X2FV_PROC*)get_proc("glUniformMatrix4x2fv");
    glpfUniformMatrix4x3fv = (PFNGLUNIFORMMATRIX4X3FV_PROC*)get_proc("glUniformMatrix4x3fv");


    /* GL_VERSION_3_0 */

    glpfBeginConditionalRender = (PFNGLBEGINCONDITIONALRENDER_PROC*)get_proc("glBeginConditionalRender");
    glpfBeginTransformFeedback = (PFNGLBEGINTRANSFORMFEEDBACK_PROC*)get_proc("glBeginTransformFeedback");
    glpfBindBufferBase = (PFNGLBINDBUFFERBASE_PROC*)get_proc("glBindBufferBase");
    glpfBindBufferRange = (PFNGLBINDBUFFERRANGE_PROC*)get_proc("glBindBufferRange");
    glpfBindFragDataLocation = (PFNGLBINDFRAGDATALOCATION_PROC*)get_proc("glBindFragDataLocation");
    glpfBindFramebuffer = (PFNGLBINDFRAMEBUFFER_PROC*)get_proc("glBindFramebuffer");
    glpfBindRenderbuffer = (PFNGLBINDRENDERBUFFER_PROC*)get_proc("glBindRenderbuffer");
    glpfBindVertexArray = (PFNGLBINDVERTEXARRAY_PROC*)get_proc("glBindVertexArray");
    glpfBlitFramebuffer = (PFNGLBLITFRAMEBUFFER_PROC*)get_proc("glBlitFramebuffer");
    glpfCheckFramebufferStatus = (PFNGLCHECKFRAMEBUFFERSTATUS_PROC*)get_proc("glCheckFramebufferStatus");
    glpfClampColor = (PFNGLCLAMPCOLOR_PROC*)get_proc("glClampColor");
    glpfClearBufferfi = (PFNGLCLEARBUFFERFI_PROC*)get_proc("glClearBufferfi");
    glpfClearBufferfv = (PFNGLCLEARBUFFERFV_PROC*)get_proc("glClearBufferfv");
    glpfClearBufferiv = (PFNGLCLEARBUFFERIV_PROC*)get_proc("glClearBufferiv");
    glpfClearBufferuiv = (PFNGLCLEARBUFFERUIV_PROC*)get_proc("glClearBufferuiv");
    glpfColorMaski = (PFNGLCOLORMASKI_PROC*)get_proc("glColorMaski");
    glpfDeleteFramebuffers = (PFNGLDELETEFRAMEBUFFERS_PROC*)get_proc("glDeleteFramebuffers");
    glpfDeleteRenderbuffers = (PFNGLDELETERENDERBUFFERS_PROC*)get_proc("glDeleteRenderbuffers");
    glpfDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYS_PROC*)get_proc("glDeleteVertexArrays");
    glpfDisablei = (PFNGLDISABLEI_PROC*)get_proc("glDisablei");
    glpfEnablei = (PFNGLENABLEI_PROC*)get_proc("glEnablei");
    glpfEndConditionalRender = (PFNGLENDCONDITIONALRENDER_PROC*)get_proc("glEndConditionalRender");
    glpfEndTransformFeedback = (PFNGLENDTRANSFORMFEEDBACK_PROC*)get_proc("glEndTransformFeedback");
    glpfFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGE_PROC*)get_proc("glFlushMappedBufferRange");
    glpfFramebufferRenderbuffer = (PFNGLFRAMEBUFFERRENDERBUFFER_PROC*)get_proc("glFramebufferRenderbuffer");
    glpfFramebufferTexture1D = (PFNGLFRAMEBUFFERTEXTURE1D_PROC*)get_proc("glFramebufferTexture1D");
    glpfFramebufferTexture2D = (PFNGLFRAMEBUFFERTEXTURE2D_PROC*)get_proc("glFramebufferTexture2D");
    glpfFramebufferTexture3D = (PFNGLFRAMEBUFFERTEXTURE3D_PROC*)get_proc("glFramebufferTexture3D");
    glpfFramebufferTextureLayer = (PFNGLFRAMEBUFFERTEXTURELAYER_PROC*)get_proc("glFramebufferTextureLayer");
    glpfGenFramebuffers = (PFNGLGENFRAMEBUFFERS_PROC*)get_proc("glGenFramebuffers");
    glpfGenRenderbuffers = (PFNGLGENRENDERBUFFERS_PROC*)get_proc("glGenRenderbuffers");
    glpfGenVertexArrays = (PFNGLGENVERTEXARRAYS_PROC*)get_proc("glGenVertexArrays");
    glpfGenerateMipmap = (PFNGLGENERATEMIPMAP_PROC*)get_proc("glGenerateMipmap");
    glpfGetBooleani_v = (PFNGLGETBOOLEANI_V_PROC*)get_proc("glGetBooleani_v");
    glpfGetFragDataLocation = (PFNGLGETFRAGDATALOCATION_PROC*)get_proc("glGetFragDataLocation");
    glpfGetFramebufferAttachmentParameteriv = (PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIV_PROC*)get_proc("glGetFramebufferAttachmentParameteriv");
    glpfGetIntegeri_v = (PFNGLGETINTEGERI_V_PROC*)get_proc("glGetIntegeri_v");
    glpfGetRenderbufferParameteriv = (PFNGLGETRENDERBUFFERPARAMETERIV_PROC*)get_proc("glGetRenderbufferParameteriv");
    glpfGetStringi = (PFNGLGETSTRINGI_PROC*)get_proc("glGetStringi");
    glpfGetTexParameterIiv = (PFNGLGETTEXPARAMETERIIV_PROC*)get_proc("glGetTexParameterIiv");
    glpfGetTexParameterIuiv = (PFNGLGETTEXPARAMETERIUIV_PROC*)get_proc("glGetTexParameterIuiv");
    glpfGetTransformFeedbackVarying = (PFNGLGETTRANSFORMFEEDBACKVARYING_PROC*)get_proc("glGetTransformFeedbackVarying");
    glpfGetUniformuiv = (PFNGLGETUNIFORMUIV_PROC*)get_proc("glGetUniformuiv");
    glpfGetVertexAttribIiv = (PFNGLGETVERTEXATTRIBIIV_PROC*)get_proc("glGetVertexAttribIiv");
    glpfGetVertexAttribIuiv = (PFNGLGETVERTEXATTRIBIUIV_PROC*)get_proc("glGetVertexAttribIuiv");
    glpfIsEnabledi = (PFNGLISENABLEDI_PROC*)get_proc("glIsEnabledi");
    glpfIsFramebuffer = (PFNGLISFRAMEBUFFER_PROC*)get_proc("glIsFramebuffer");
    glpfIsRenderbuffer = (PFNGLISRENDERBUFFER_PROC*)get_proc("glIsRenderbuffer");
    glpfIsVertexArray = (PFNGLISVERTEXARRAY_PROC*)get_proc("glIsVertexArray");
    glpfMapBufferRange = (PFNGLMAPBUFFERRANGE_PROC*)get_proc("glMapBufferRange");
    glpfRenderbufferStorage = (PFNGLRENDERBUFFERSTORAGE_PROC*)get_proc("glRenderbufferStorage");
    glpfRenderbufferStorageMultisample = (PFNGLRENDERBUFFERSTORAGEMULTISAMPLE_PROC*)get_proc("glRenderbufferStorageMultisample");
    glpfTexParameterIiv = (PFNGLTEXPARAMETERIIV_PROC*)get_proc("glTexParameterIiv");
    glpfTexParameterIuiv = (PFNGLTEXPARAMETERIUIV_PROC*)get_proc("glTexParameterIuiv");
    glpfTransformFeedbackVaryings = (PFNGLTRANSFORMFEEDBACKVARYINGS_PROC*)get_proc("glTransformFeedbackVaryings");
    glpfUniform1ui = (PFNGLUNIFORM1UI_PROC*)get_proc("glUniform1ui");
    glpfUniform1uiv = (PFNGLUNIFORM1UIV_PROC*)get_proc("glUniform1uiv");
    glpfUniform2ui = (PFNGLUNIFORM2UI_PROC*)get_proc("glUniform2ui");
    glpfUniform2uiv = (PFNGLUNIFORM2UIV_PROC*)get_proc("glUniform2uiv");
    glpfUniform3ui = (PFNGLUNIFORM3UI_PROC*)get_proc("glUniform3ui");
    glpfUniform3uiv = (PFNGLUNIFORM3UIV_PROC*)get_proc("glUniform3uiv");
    glpfUniform4ui = (PFNGLUNIFORM4UI_PROC*)get_proc("glUniform4ui");
    glpfUniform4uiv = (PFNGLUNIFORM4UIV_PROC*)get_proc("glUniform4uiv");
    glpfVertexAttribI1i = (PFNGLVERTEXATTRIBI1I_PROC*)get_proc("glVertexAttribI1i");
    glpfVertexAttribI1iv = (PFNGLVERTEXATTRIBI1IV_PROC*)get_proc("glVertexAttribI1iv");
    glpfVertexAttribI1ui = (PFNGLVERTEXATTRIBI1UI_PROC*)get_proc("glVertexAttribI1ui");
    glpfVertexAttribI1uiv = (PFNGLVERTEXATTRIBI1UIV_PROC*)get_proc("glVertexAttribI1uiv");
    glpfVertexAttribI2i = (PFNGLVERTEXATTRIBI2I_PROC*)get_proc("glVertexAttribI2i");
    glpfVertexAttribI2iv = (PFNGLVERTEXATTRIBI2IV_PROC*)get_proc("glVertexAttribI2iv");
    glpfVertexAttribI2ui = (PFNGLVERTEXATTRIBI2UI_PROC*)get_proc("glVertexAttribI2ui");
    glpfVertexAttribI2uiv = (PFNGLVERTEXATTRIBI2UIV_PROC*)get_proc("glVertexAttribI2uiv");
    glpfVertexAttribI3i = (PFNGLVERTEXATTRIBI3I_PROC*)get_proc("glVertexAttribI3i");
    glpfVertexAttribI3iv = (PFNGLVERTEXATTRIBI3IV_PROC*)get_proc("glVertexAttribI3iv");
    glpfVertexAttribI3ui = (PFNGLVERTEXATTRIBI3UI_PROC*)get_proc("glVertexAttribI3ui");
    glpfVertexAttribI3uiv = (PFNGLVERTEXATTRIBI3UIV_PROC*)get_proc("glVertexAttribI3uiv");
    glpfVertexAttribI4bv = (PFNGLVERTEXATTRIBI4BV_PROC*)get_proc("glVertexAttribI4bv");
    glpfVertexAttribI4i = (PFNGLVERTEXATTRIBI4I_PROC*)get_proc("glVertexAttribI4i");
    glpfVertexAttribI4iv = (PFNGLVERTEXATTRIBI4IV_PROC*)get_proc("glVertexAttribI4iv");
    glpfVertexAttribI4sv = (PFNGLVERTEXATTRIBI4SV_PROC*)get_proc("glVertexAttribI4sv");
    glpfVertexAttribI4ubv = (PFNGLVERTEXATTRIBI4UBV_PROC*)get_proc("glVertexAttribI4ubv");
    glpfVertexAttribI4ui = (PFNGLVERTEXATTRIBI4UI_PROC*)get_proc("glVertexAttribI4ui");
    glpfVertexAttribI4uiv = (PFNGLVERTEXATTRIBI4UIV_PROC*)get_proc("glVertexAttribI4uiv");
    glpfVertexAttribI4usv = (PFNGLVERTEXATTRIBI4USV_PROC*)get_proc("glVertexAttribI4usv");
    glpfVertexAttribIPointer = (PFNGLVERTEXATTRIBIPOINTER_PROC*)get_proc("glVertexAttribIPointer");


}

/* ----------------------- Extension flag definitions ---------------------- */
int FLEXT_ARB_uniform_buffer_object = GL_FALSE;

/* ---------------------- Function pointer definitions --------------------- */

/* GL_ARB_uniform_buffer_object */

PFNGLGETACTIVEUNIFORMBLOCKNAME_PROC* glpfGetActiveUniformBlockName = NULL;
PFNGLGETACTIVEUNIFORMBLOCKIV_PROC* glpfGetActiveUniformBlockiv = NULL;
PFNGLGETACTIVEUNIFORMNAME_PROC* glpfGetActiveUniformName = NULL;
PFNGLGETACTIVEUNIFORMSIV_PROC* glpfGetActiveUniformsiv = NULL;
PFNGLGETUNIFORMBLOCKINDEX_PROC* glpfGetUniformBlockIndex = NULL;
PFNGLGETUNIFORMINDICES_PROC* glpfGetUniformIndices = NULL;
PFNGLUNIFORMBLOCKBINDING_PROC* glpfUniformBlockBinding = NULL;

/* GL_VERSION_1_2 */

PFNGLCOPYTEXSUBIMAGE3D_PROC* glpfCopyTexSubImage3D = NULL;
PFNGLDRAWRANGEELEMENTS_PROC* glpfDrawRangeElements = NULL;
PFNGLTEXIMAGE3D_PROC* glpfTexImage3D = NULL;
PFNGLTEXSUBIMAGE3D_PROC* glpfTexSubImage3D = NULL;

/* GL_VERSION_1_3 */

PFNGLACTIVETEXTURE_PROC* glpfActiveTexture = NULL;
PFNGLCLIENTACTIVETEXTURE_PROC* glpfClientActiveTexture = NULL;
PFNGLCOMPRESSEDTEXIMAGE1D_PROC* glpfCompressedTexImage1D = NULL;
PFNGLCOMPRESSEDTEXIMAGE2D_PROC* glpfCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE3D_PROC* glpfCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1D_PROC* glpfCompressedTexSubImage1D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2D_PROC* glpfCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3D_PROC* glpfCompressedTexSubImage3D = NULL;
PFNGLGETCOMPRESSEDTEXIMAGE_PROC* glpfGetCompressedTexImage = NULL;
PFNGLLOADTRANSPOSEMATRIXD_PROC* glpfLoadTransposeMatrixd = NULL;
PFNGLLOADTRANSPOSEMATRIXF_PROC* glpfLoadTransposeMatrixf = NULL;
PFNGLMULTTRANSPOSEMATRIXD_PROC* glpfMultTransposeMatrixd = NULL;
PFNGLMULTTRANSPOSEMATRIXF_PROC* glpfMultTransposeMatrixf = NULL;
PFNGLMULTITEXCOORD1D_PROC* glpfMultiTexCoord1d = NULL;
PFNGLMULTITEXCOORD1DV_PROC* glpfMultiTexCoord1dv = NULL;
PFNGLMULTITEXCOORD1F_PROC* glpfMultiTexCoord1f = NULL;
PFNGLMULTITEXCOORD1FV_PROC* glpfMultiTexCoord1fv = NULL;
PFNGLMULTITEXCOORD1I_PROC* glpfMultiTexCoord1i = NULL;
PFNGLMULTITEXCOORD1IV_PROC* glpfMultiTexCoord1iv = NULL;
PFNGLMULTITEXCOORD1S_PROC* glpfMultiTexCoord1s = NULL;
PFNGLMULTITEXCOORD1SV_PROC* glpfMultiTexCoord1sv = NULL;
PFNGLMULTITEXCOORD2D_PROC* glpfMultiTexCoord2d = NULL;
PFNGLMULTITEXCOORD2DV_PROC* glpfMultiTexCoord2dv = NULL;
PFNGLMULTITEXCOORD2F_PROC* glpfMultiTexCoord2f = NULL;
PFNGLMULTITEXCOORD2FV_PROC* glpfMultiTexCoord2fv = NULL;
PFNGLMULTITEXCOORD2I_PROC* glpfMultiTexCoord2i = NULL;
PFNGLMULTITEXCOORD2IV_PROC* glpfMultiTexCoord2iv = NULL;
PFNGLMULTITEXCOORD2S_PROC* glpfMultiTexCoord2s = NULL;
PFNGLMULTITEXCOORD2SV_PROC* glpfMultiTexCoord2sv = NULL;
PFNGLMULTITEXCOORD3D_PROC* glpfMultiTexCoord3d = NULL;
PFNGLMULTITEXCOORD3DV_PROC* glpfMultiTexCoord3dv = NULL;
PFNGLMULTITEXCOORD3F_PROC* glpfMultiTexCoord3f = NULL;
PFNGLMULTITEXCOORD3FV_PROC* glpfMultiTexCoord3fv = NULL;
PFNGLMULTITEXCOORD3I_PROC* glpfMultiTexCoord3i = NULL;
PFNGLMULTITEXCOORD3IV_PROC* glpfMultiTexCoord3iv = NULL;
PFNGLMULTITEXCOORD3S_PROC* glpfMultiTexCoord3s = NULL;
PFNGLMULTITEXCOORD3SV_PROC* glpfMultiTexCoord3sv = NULL;
PFNGLMULTITEXCOORD4D_PROC* glpfMultiTexCoord4d = NULL;
PFNGLMULTITEXCOORD4DV_PROC* glpfMultiTexCoord4dv = NULL;
PFNGLMULTITEXCOORD4F_PROC* glpfMultiTexCoord4f = NULL;
PFNGLMULTITEXCOORD4FV_PROC* glpfMultiTexCoord4fv = NULL;
PFNGLMULTITEXCOORD4I_PROC* glpfMultiTexCoord4i = NULL;
PFNGLMULTITEXCOORD4IV_PROC* glpfMultiTexCoord4iv = NULL;
PFNGLMULTITEXCOORD4S_PROC* glpfMultiTexCoord4s = NULL;
PFNGLMULTITEXCOORD4SV_PROC* glpfMultiTexCoord4sv = NULL;
PFNGLSAMPLECOVERAGE_PROC* glpfSampleCoverage = NULL;

/* GL_VERSION_1_4 */

PFNGLBLENDCOLOR_PROC* glpfBlendColor = NULL;
PFNGLBLENDEQUATION_PROC* glpfBlendEquation = NULL;
PFNGLBLENDFUNCSEPARATE_PROC* glpfBlendFuncSeparate = NULL;
PFNGLFOGCOORDPOINTER_PROC* glpfFogCoordPointer = NULL;
PFNGLFOGCOORDD_PROC* glpfFogCoordd = NULL;
PFNGLFOGCOORDDV_PROC* glpfFogCoorddv = NULL;
PFNGLFOGCOORDF_PROC* glpfFogCoordf = NULL;
PFNGLFOGCOORDFV_PROC* glpfFogCoordfv = NULL;
PFNGLMULTIDRAWARRAYS_PROC* glpfMultiDrawArrays = NULL;
PFNGLMULTIDRAWELEMENTS_PROC* glpfMultiDrawElements = NULL;
PFNGLPOINTPARAMETERF_PROC* glpfPointParameterf = NULL;
PFNGLPOINTPARAMETERFV_PROC* glpfPointParameterfv = NULL;
PFNGLPOINTPARAMETERI_PROC* glpfPointParameteri = NULL;
PFNGLPOINTPARAMETERIV_PROC* glpfPointParameteriv = NULL;
PFNGLSECONDARYCOLOR3B_PROC* glpfSecondaryColor3b = NULL;
PFNGLSECONDARYCOLOR3BV_PROC* glpfSecondaryColor3bv = NULL;
PFNGLSECONDARYCOLOR3D_PROC* glpfSecondaryColor3d = NULL;
PFNGLSECONDARYCOLOR3DV_PROC* glpfSecondaryColor3dv = NULL;
PFNGLSECONDARYCOLOR3F_PROC* glpfSecondaryColor3f = NULL;
PFNGLSECONDARYCOLOR3FV_PROC* glpfSecondaryColor3fv = NULL;
PFNGLSECONDARYCOLOR3I_PROC* glpfSecondaryColor3i = NULL;
PFNGLSECONDARYCOLOR3IV_PROC* glpfSecondaryColor3iv = NULL;
PFNGLSECONDARYCOLOR3S_PROC* glpfSecondaryColor3s = NULL;
PFNGLSECONDARYCOLOR3SV_PROC* glpfSecondaryColor3sv = NULL;
PFNGLSECONDARYCOLOR3UB_PROC* glpfSecondaryColor3ub = NULL;
PFNGLSECONDARYCOLOR3UBV_PROC* glpfSecondaryColor3ubv = NULL;
PFNGLSECONDARYCOLOR3UI_PROC* glpfSecondaryColor3ui = NULL;
PFNGLSECONDARYCOLOR3UIV_PROC* glpfSecondaryColor3uiv = NULL;
PFNGLSECONDARYCOLOR3US_PROC* glpfSecondaryColor3us = NULL;
PFNGLSECONDARYCOLOR3USV_PROC* glpfSecondaryColor3usv = NULL;
PFNGLSECONDARYCOLORPOINTER_PROC* glpfSecondaryColorPointer = NULL;
PFNGLWINDOWPOS2D_PROC* glpfWindowPos2d = NULL;
PFNGLWINDOWPOS2DV_PROC* glpfWindowPos2dv = NULL;
PFNGLWINDOWPOS2F_PROC* glpfWindowPos2f = NULL;
PFNGLWINDOWPOS2FV_PROC* glpfWindowPos2fv = NULL;
PFNGLWINDOWPOS2I_PROC* glpfWindowPos2i = NULL;
PFNGLWINDOWPOS2IV_PROC* glpfWindowPos2iv = NULL;
PFNGLWINDOWPOS2S_PROC* glpfWindowPos2s = NULL;
PFNGLWINDOWPOS2SV_PROC* glpfWindowPos2sv = NULL;
PFNGLWINDOWPOS3D_PROC* glpfWindowPos3d = NULL;
PFNGLWINDOWPOS3DV_PROC* glpfWindowPos3dv = NULL;
PFNGLWINDOWPOS3F_PROC* glpfWindowPos3f = NULL;
PFNGLWINDOWPOS3FV_PROC* glpfWindowPos3fv = NULL;
PFNGLWINDOWPOS3I_PROC* glpfWindowPos3i = NULL;
PFNGLWINDOWPOS3IV_PROC* glpfWindowPos3iv = NULL;
PFNGLWINDOWPOS3S_PROC* glpfWindowPos3s = NULL;
PFNGLWINDOWPOS3SV_PROC* glpfWindowPos3sv = NULL;

/* GL_VERSION_1_5 */

PFNGLBEGINQUERY_PROC* glpfBeginQuery = NULL;
PFNGLBINDBUFFER_PROC* glpfBindBuffer = NULL;
PFNGLBUFFERDATA_PROC* glpfBufferData = NULL;
PFNGLBUFFERSUBDATA_PROC* glpfBufferSubData = NULL;
PFNGLDELETEBUFFERS_PROC* glpfDeleteBuffers = NULL;
PFNGLDELETEQUERIES_PROC* glpfDeleteQueries = NULL;
PFNGLENDQUERY_PROC* glpfEndQuery = NULL;
PFNGLGENBUFFERS_PROC* glpfGenBuffers = NULL;
PFNGLGENQUERIES_PROC* glpfGenQueries = NULL;
PFNGLGETBUFFERPARAMETERIV_PROC* glpfGetBufferParameteriv = NULL;
PFNGLGETBUFFERPOINTERV_PROC* glpfGetBufferPointerv = NULL;
PFNGLGETBUFFERSUBDATA_PROC* glpfGetBufferSubData = NULL;
PFNGLGETQUERYOBJECTIV_PROC* glpfGetQueryObjectiv = NULL;
PFNGLGETQUERYOBJECTUIV_PROC* glpfGetQueryObjectuiv = NULL;
PFNGLGETQUERYIV_PROC* glpfGetQueryiv = NULL;
PFNGLISBUFFER_PROC* glpfIsBuffer = NULL;
PFNGLISQUERY_PROC* glpfIsQuery = NULL;
PFNGLMAPBUFFER_PROC* glpfMapBuffer = NULL;
PFNGLUNMAPBUFFER_PROC* glpfUnmapBuffer = NULL;

/* GL_VERSION_2_0 */

PFNGLATTACHSHADER_PROC* glpfAttachShader = NULL;
PFNGLBINDATTRIBLOCATION_PROC* glpfBindAttribLocation = NULL;
PFNGLBLENDEQUATIONSEPARATE_PROC* glpfBlendEquationSeparate = NULL;
PFNGLCOMPILESHADER_PROC* glpfCompileShader = NULL;
PFNGLCREATEPROGRAM_PROC* glpfCreateProgram = NULL;
PFNGLCREATESHADER_PROC* glpfCreateShader = NULL;
PFNGLDELETEPROGRAM_PROC* glpfDeleteProgram = NULL;
PFNGLDELETESHADER_PROC* glpfDeleteShader = NULL;
PFNGLDETACHSHADER_PROC* glpfDetachShader = NULL;
PFNGLDISABLEVERTEXATTRIBARRAY_PROC* glpfDisableVertexAttribArray = NULL;
PFNGLDRAWBUFFERS_PROC* glpfDrawBuffers = NULL;
PFNGLENABLEVERTEXATTRIBARRAY_PROC* glpfEnableVertexAttribArray = NULL;
PFNGLGETACTIVEATTRIB_PROC* glpfGetActiveAttrib = NULL;
PFNGLGETACTIVEUNIFORM_PROC* glpfGetActiveUniform = NULL;
PFNGLGETATTACHEDSHADERS_PROC* glpfGetAttachedShaders = NULL;
PFNGLGETATTRIBLOCATION_PROC* glpfGetAttribLocation = NULL;
PFNGLGETPROGRAMINFOLOG_PROC* glpfGetProgramInfoLog = NULL;
PFNGLGETPROGRAMIV_PROC* glpfGetProgramiv = NULL;
PFNGLGETSHADERINFOLOG_PROC* glpfGetShaderInfoLog = NULL;
PFNGLGETSHADERSOURCE_PROC* glpfGetShaderSource = NULL;
PFNGLGETSHADERIV_PROC* glpfGetShaderiv = NULL;
PFNGLGETUNIFORMLOCATION_PROC* glpfGetUniformLocation = NULL;
PFNGLGETUNIFORMFV_PROC* glpfGetUniformfv = NULL;
PFNGLGETUNIFORMIV_PROC* glpfGetUniformiv = NULL;
PFNGLGETVERTEXATTRIBPOINTERV_PROC* glpfGetVertexAttribPointerv = NULL;
PFNGLGETVERTEXATTRIBDV_PROC* glpfGetVertexAttribdv = NULL;
PFNGLGETVERTEXATTRIBFV_PROC* glpfGetVertexAttribfv = NULL;
PFNGLGETVERTEXATTRIBIV_PROC* glpfGetVertexAttribiv = NULL;
PFNGLISPROGRAM_PROC* glpfIsProgram = NULL;
PFNGLISSHADER_PROC* glpfIsShader = NULL;
PFNGLLINKPROGRAM_PROC* glpfLinkProgram = NULL;
PFNGLSHADERSOURCE_PROC* glpfShaderSource = NULL;
PFNGLSTENCILFUNCSEPARATE_PROC* glpfStencilFuncSeparate = NULL;
PFNGLSTENCILMASKSEPARATE_PROC* glpfStencilMaskSeparate = NULL;
PFNGLSTENCILOPSEPARATE_PROC* glpfStencilOpSeparate = NULL;
PFNGLUNIFORM1F_PROC* glpfUniform1f = NULL;
PFNGLUNIFORM1FV_PROC* glpfUniform1fv = NULL;
PFNGLUNIFORM1I_PROC* glpfUniform1i = NULL;
PFNGLUNIFORM1IV_PROC* glpfUniform1iv = NULL;
PFNGLUNIFORM2F_PROC* glpfUniform2f = NULL;
PFNGLUNIFORM2FV_PROC* glpfUniform2fv = NULL;
PFNGLUNIFORM2I_PROC* glpfUniform2i = NULL;
PFNGLUNIFORM2IV_PROC* glpfUniform2iv = NULL;
PFNGLUNIFORM3F_PROC* glpfUniform3f = NULL;
PFNGLUNIFORM3FV_PROC* glpfUniform3fv = NULL;
PFNGLUNIFORM3I_PROC* glpfUniform3i = NULL;
PFNGLUNIFORM3IV_PROC* glpfUniform3iv = NULL;
PFNGLUNIFORM4F_PROC* glpfUniform4f = NULL;
PFNGLUNIFORM4FV_PROC* glpfUniform4fv = NULL;
PFNGLUNIFORM4I_PROC* glpfUniform4i = NULL;
PFNGLUNIFORM4IV_PROC* glpfUniform4iv = NULL;
PFNGLUNIFORMMATRIX2FV_PROC* glpfUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX3FV_PROC* glpfUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX4FV_PROC* glpfUniformMatrix4fv = NULL;
PFNGLUSEPROGRAM_PROC* glpfUseProgram = NULL;
PFNGLVALIDATEPROGRAM_PROC* glpfValidateProgram = NULL;
PFNGLVERTEXATTRIB1D_PROC* glpfVertexAttrib1d = NULL;
PFNGLVERTEXATTRIB1DV_PROC* glpfVertexAttrib1dv = NULL;
PFNGLVERTEXATTRIB1F_PROC* glpfVertexAttrib1f = NULL;
PFNGLVERTEXATTRIB1FV_PROC* glpfVertexAttrib1fv = NULL;
PFNGLVERTEXATTRIB1S_PROC* glpfVertexAttrib1s = NULL;
PFNGLVERTEXATTRIB1SV_PROC* glpfVertexAttrib1sv = NULL;
PFNGLVERTEXATTRIB2D_PROC* glpfVertexAttrib2d = NULL;
PFNGLVERTEXATTRIB2DV_PROC* glpfVertexAttrib2dv = NULL;
PFNGLVERTEXATTRIB2F_PROC* glpfVertexAttrib2f = NULL;
PFNGLVERTEXATTRIB2FV_PROC* glpfVertexAttrib2fv = NULL;
PFNGLVERTEXATTRIB2S_PROC* glpfVertexAttrib2s = NULL;
PFNGLVERTEXATTRIB2SV_PROC* glpfVertexAttrib2sv = NULL;
PFNGLVERTEXATTRIB3D_PROC* glpfVertexAttrib3d = NULL;
PFNGLVERTEXATTRIB3DV_PROC* glpfVertexAttrib3dv = NULL;
PFNGLVERTEXATTRIB3F_PROC* glpfVertexAttrib3f = NULL;
PFNGLVERTEXATTRIB3FV_PROC* glpfVertexAttrib3fv = NULL;
PFNGLVERTEXATTRIB3S_PROC* glpfVertexAttrib3s = NULL;
PFNGLVERTEXATTRIB3SV_PROC* glpfVertexAttrib3sv = NULL;
PFNGLVERTEXATTRIB4NBV_PROC* glpfVertexAttrib4Nbv = NULL;
PFNGLVERTEXATTRIB4NIV_PROC* glpfVertexAttrib4Niv = NULL;
PFNGLVERTEXATTRIB4NSV_PROC* glpfVertexAttrib4Nsv = NULL;
PFNGLVERTEXATTRIB4NUB_PROC* glpfVertexAttrib4Nub = NULL;
PFNGLVERTEXATTRIB4NUBV_PROC* glpfVertexAttrib4Nubv = NULL;
PFNGLVERTEXATTRIB4NUIV_PROC* glpfVertexAttrib4Nuiv = NULL;
PFNGLVERTEXATTRIB4NUSV_PROC* glpfVertexAttrib4Nusv = NULL;
PFNGLVERTEXATTRIB4BV_PROC* glpfVertexAttrib4bv = NULL;
PFNGLVERTEXATTRIB4D_PROC* glpfVertexAttrib4d = NULL;
PFNGLVERTEXATTRIB4DV_PROC* glpfVertexAttrib4dv = NULL;
PFNGLVERTEXATTRIB4F_PROC* glpfVertexAttrib4f = NULL;
PFNGLVERTEXATTRIB4FV_PROC* glpfVertexAttrib4fv = NULL;
PFNGLVERTEXATTRIB4IV_PROC* glpfVertexAttrib4iv = NULL;
PFNGLVERTEXATTRIB4S_PROC* glpfVertexAttrib4s = NULL;
PFNGLVERTEXATTRIB4SV_PROC* glpfVertexAttrib4sv = NULL;
PFNGLVERTEXATTRIB4UBV_PROC* glpfVertexAttrib4ubv = NULL;
PFNGLVERTEXATTRIB4UIV_PROC* glpfVertexAttrib4uiv = NULL;
PFNGLVERTEXATTRIB4USV_PROC* glpfVertexAttrib4usv = NULL;
PFNGLVERTEXATTRIBPOINTER_PROC* glpfVertexAttribPointer = NULL;

/* GL_VERSION_2_1 */

PFNGLUNIFORMMATRIX2X3FV_PROC* glpfUniformMatrix2x3fv = NULL;
PFNGLUNIFORMMATRIX2X4FV_PROC* glpfUniformMatrix2x4fv = NULL;
PFNGLUNIFORMMATRIX3X2FV_PROC* glpfUniformMatrix3x2fv = NULL;
PFNGLUNIFORMMATRIX3X4FV_PROC* glpfUniformMatrix3x4fv = NULL;
PFNGLUNIFORMMATRIX4X2FV_PROC* glpfUniformMatrix4x2fv = NULL;
PFNGLUNIFORMMATRIX4X3FV_PROC* glpfUniformMatrix4x3fv = NULL;

/* GL_VERSION_3_0 */

PFNGLBEGINCONDITIONALRENDER_PROC* glpfBeginConditionalRender = NULL;
PFNGLBEGINTRANSFORMFEEDBACK_PROC* glpfBeginTransformFeedback = NULL;
PFNGLBINDBUFFERBASE_PROC* glpfBindBufferBase = NULL;
PFNGLBINDBUFFERRANGE_PROC* glpfBindBufferRange = NULL;
PFNGLBINDFRAGDATALOCATION_PROC* glpfBindFragDataLocation = NULL;
PFNGLBINDFRAMEBUFFER_PROC* glpfBindFramebuffer = NULL;
PFNGLBINDRENDERBUFFER_PROC* glpfBindRenderbuffer = NULL;
PFNGLBINDVERTEXARRAY_PROC* glpfBindVertexArray = NULL;
PFNGLBLITFRAMEBUFFER_PROC* glpfBlitFramebuffer = NULL;
PFNGLCHECKFRAMEBUFFERSTATUS_PROC* glpfCheckFramebufferStatus = NULL;
PFNGLCLAMPCOLOR_PROC* glpfClampColor = NULL;
PFNGLCLEARBUFFERFI_PROC* glpfClearBufferfi = NULL;
PFNGLCLEARBUFFERFV_PROC* glpfClearBufferfv = NULL;
PFNGLCLEARBUFFERIV_PROC* glpfClearBufferiv = NULL;
PFNGLCLEARBUFFERUIV_PROC* glpfClearBufferuiv = NULL;
PFNGLCOLORMASKI_PROC* glpfColorMaski = NULL;
PFNGLDELETEFRAMEBUFFERS_PROC* glpfDeleteFramebuffers = NULL;
PFNGLDELETERENDERBUFFERS_PROC* glpfDeleteRenderbuffers = NULL;
PFNGLDELETEVERTEXARRAYS_PROC* glpfDeleteVertexArrays = NULL;
PFNGLDISABLEI_PROC* glpfDisablei = NULL;
PFNGLENABLEI_PROC* glpfEnablei = NULL;
PFNGLENDCONDITIONALRENDER_PROC* glpfEndConditionalRender = NULL;
PFNGLENDTRANSFORMFEEDBACK_PROC* glpfEndTransformFeedback = NULL;
PFNGLFLUSHMAPPEDBUFFERRANGE_PROC* glpfFlushMappedBufferRange = NULL;
PFNGLFRAMEBUFFERRENDERBUFFER_PROC* glpfFramebufferRenderbuffer = NULL;
PFNGLFRAMEBUFFERTEXTURE1D_PROC* glpfFramebufferTexture1D = NULL;
PFNGLFRAMEBUFFERTEXTURE2D_PROC* glpfFramebufferTexture2D = NULL;
PFNGLFRAMEBUFFERTEXTURE3D_PROC* glpfFramebufferTexture3D = NULL;
PFNGLFRAMEBUFFERTEXTURELAYER_PROC* glpfFramebufferTextureLayer = NULL;
PFNGLGENFRAMEBUFFERS_PROC* glpfGenFramebuffers = NULL;
PFNGLGENRENDERBUFFERS_PROC* glpfGenRenderbuffers = NULL;
PFNGLGENVERTEXARRAYS_PROC* glpfGenVertexArrays = NULL;
PFNGLGENERATEMIPMAP_PROC* glpfGenerateMipmap = NULL;
PFNGLGETBOOLEANI_V_PROC* glpfGetBooleani_v = NULL;
PFNGLGETFRAGDATALOCATION_PROC* glpfGetFragDataLocation = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIV_PROC* glpfGetFramebufferAttachmentParameteriv = NULL;
PFNGLGETINTEGERI_V_PROC* glpfGetIntegeri_v = NULL;
PFNGLGETRENDERBUFFERPARAMETERIV_PROC* glpfGetRenderbufferParameteriv = NULL;
PFNGLGETSTRINGI_PROC* glpfGetStringi = NULL;
PFNGLGETTEXPARAMETERIIV_PROC* glpfGetTexParameterIiv = NULL;
PFNGLGETTEXPARAMETERIUIV_PROC* glpfGetTexParameterIuiv = NULL;
PFNGLGETTRANSFORMFEEDBACKVARYING_PROC* glpfGetTransformFeedbackVarying = NULL;
PFNGLGETUNIFORMUIV_PROC* glpfGetUniformuiv = NULL;
PFNGLGETVERTEXATTRIBIIV_PROC* glpfGetVertexAttribIiv = NULL;
PFNGLGETVERTEXATTRIBIUIV_PROC* glpfGetVertexAttribIuiv = NULL;
PFNGLISENABLEDI_PROC* glpfIsEnabledi = NULL;
PFNGLISFRAMEBUFFER_PROC* glpfIsFramebuffer = NULL;
PFNGLISRENDERBUFFER_PROC* glpfIsRenderbuffer = NULL;
PFNGLISVERTEXARRAY_PROC* glpfIsVertexArray = NULL;
PFNGLMAPBUFFERRANGE_PROC* glpfMapBufferRange = NULL;
PFNGLRENDERBUFFERSTORAGE_PROC* glpfRenderbufferStorage = NULL;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLE_PROC* glpfRenderbufferStorageMultisample = NULL;
PFNGLTEXPARAMETERIIV_PROC* glpfTexParameterIiv = NULL;
PFNGLTEXPARAMETERIUIV_PROC* glpfTexParameterIuiv = NULL;
PFNGLTRANSFORMFEEDBACKVARYINGS_PROC* glpfTransformFeedbackVaryings = NULL;
PFNGLUNIFORM1UI_PROC* glpfUniform1ui = NULL;
PFNGLUNIFORM1UIV_PROC* glpfUniform1uiv = NULL;
PFNGLUNIFORM2UI_PROC* glpfUniform2ui = NULL;
PFNGLUNIFORM2UIV_PROC* glpfUniform2uiv = NULL;
PFNGLUNIFORM3UI_PROC* glpfUniform3ui = NULL;
PFNGLUNIFORM3UIV_PROC* glpfUniform3uiv = NULL;
PFNGLUNIFORM4UI_PROC* glpfUniform4ui = NULL;
PFNGLUNIFORM4UIV_PROC* glpfUniform4uiv = NULL;
PFNGLVERTEXATTRIBI1I_PROC* glpfVertexAttribI1i = NULL;
PFNGLVERTEXATTRIBI1IV_PROC* glpfVertexAttribI1iv = NULL;
PFNGLVERTEXATTRIBI1UI_PROC* glpfVertexAttribI1ui = NULL;
PFNGLVERTEXATTRIBI1UIV_PROC* glpfVertexAttribI1uiv = NULL;
PFNGLVERTEXATTRIBI2I_PROC* glpfVertexAttribI2i = NULL;
PFNGLVERTEXATTRIBI2IV_PROC* glpfVertexAttribI2iv = NULL;
PFNGLVERTEXATTRIBI2UI_PROC* glpfVertexAttribI2ui = NULL;
PFNGLVERTEXATTRIBI2UIV_PROC* glpfVertexAttribI2uiv = NULL;
PFNGLVERTEXATTRIBI3I_PROC* glpfVertexAttribI3i = NULL;
PFNGLVERTEXATTRIBI3IV_PROC* glpfVertexAttribI3iv = NULL;
PFNGLVERTEXATTRIBI3UI_PROC* glpfVertexAttribI3ui = NULL;
PFNGLVERTEXATTRIBI3UIV_PROC* glpfVertexAttribI3uiv = NULL;
PFNGLVERTEXATTRIBI4BV_PROC* glpfVertexAttribI4bv = NULL;
PFNGLVERTEXATTRIBI4I_PROC* glpfVertexAttribI4i = NULL;
PFNGLVERTEXATTRIBI4IV_PROC* glpfVertexAttribI4iv = NULL;
PFNGLVERTEXATTRIBI4SV_PROC* glpfVertexAttribI4sv = NULL;
PFNGLVERTEXATTRIBI4UBV_PROC* glpfVertexAttribI4ubv = NULL;
PFNGLVERTEXATTRIBI4UI_PROC* glpfVertexAttribI4ui = NULL;
PFNGLVERTEXATTRIBI4UIV_PROC* glpfVertexAttribI4uiv = NULL;
PFNGLVERTEXATTRIBI4USV_PROC* glpfVertexAttribI4usv = NULL;
PFNGLVERTEXATTRIBIPOINTER_PROC* glpfVertexAttribIPointer = NULL;



static void add_extension(const char* extension)
{
    if (strcmp("GL_ARB_uniform_buffer_object", extension) == 0) {
        FLEXT_ARB_uniform_buffer_object = GL_TRUE;
    }
}


/* ------------------ get_proc from Slavomir Kaslev's gl3w ----------------- */

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <windows.h>

static HMODULE libgl;

static void open_libgl(void)
{
    libgl = LoadLibraryA("opengl32.dll");
}

static void close_libgl(void)
{
    FreeLibrary(libgl);
}

static GLPROC get_proc(const char *proc)
{
    GLPROC res;

    res = wglGetProcAddress(proc);
    if (!res)
        res = GetProcAddress(libgl, proc);
    return res;
}
#elif defined(__APPLE__) || defined(__APPLE_CC__)
#include <Carbon/Carbon.h>

CFBundleRef bundle;
CFURLRef bundleURL;

static void open_libgl(void)
{
    bundleURL = CFURLCreateWithFileSystemPath(kCFAllocatorDefault,
                CFSTR("/System/Library/Frameworks/OpenGL.framework"),
                kCFURLPOSIXPathStyle, true);

    bundle = CFBundleCreate(kCFAllocatorDefault, bundleURL);
    assert(bundle != NULL);
}

static void close_libgl(void)
{
    CFRelease(bundle);
    CFRelease(bundleURL);
}

static GLPROC get_proc(const char *proc)
{
    GLPROC res;

    CFStringRef procname = CFStringCreateWithCString(kCFAllocatorDefault, proc,
                kCFStringEncodingASCII);
    FLEXT_C_EXTENSION(res = CFBundleGetFunctionPointerForName(bundle, procname));
    CFRelease(procname);
    return res;
}
#elif defined(ANDROID)
#include <EGL/egl.h>

static void open_libgl(void)
{
    // nothing to do
}

static void close_libgl(void)
{
    // nothing to do
}

static GLPROC get_proc(const char *proc)
{
    GLPROC res;
    res = eglGetProcAddress((const char *) proc);
    return res;
}
#else
#include <dlfcn.h>
#include <GL/glx.h>

static void *libgl;

static void open_libgl(void)
{
    libgl = dlopen("libGL.so.1", RTLD_LAZY | RTLD_GLOBAL);
}

static void close_libgl(void)
{
    dlclose(libgl);
}

static GLPROC get_proc(const char *proc)
{
    GLPROC res;

    res = glXGetProcAddress((const GLubyte *) proc);
    if (!res) {
        FLEXT_C_EXTENSION(res = dlsym(libgl, proc));
    }
    return res;
}
#endif

#ifdef __cplusplus
}
#endif

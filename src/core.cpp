#include <spark/core.hpp>
#include "flextGL.h"
#include "nanovg.h"
#include "nanovg_gl.h"
using namespace spark;

struct Core::priv
{
	NVGcontext * nvg_context;
};

Core::Core(const bool initGL)
{
	//Init GL
	if (initGL)
	{
		flextInit();
	}
		
	m_private = std::make_unique<Core::priv>();
	#ifdef NANOVG_GL3_IMPLEMENTATION
	m_private->nvg_context = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
	#else
	m_private->nvg_context = nvgCreateGL2(NVG_ANTIALIAS | NVG_STENCIL_STROKES);
	#endif
}

Core::~Core()
{
	
}

bool Core::AddFont(const std::string& name, const std::string& path)
{
	int result = nvgCreateFont(m_private->nvg_context, name.c_str(), path.c_str());
	if (result == -1)
		return false;
	else
		return true;
}

bool Core::AddFont(const std::string& name, const uint8_t* memory, const int size)
{
	int result = nvgCreateFontMem(m_private->nvg_context, name.c_str(),(unsigned char*)memory,size,0);
	if (result == -1)
		return false;
	else
		return true;
}

std::shared_ptr<View> Core::CreateView(const unsigned int width, const unsigned int height)
{
	m_views.push_back(std::make_shared<View>(width,height));
	return m_views.back();
}

void* Core::GetPaintContext()
{
	return m_private->nvg_context;
}
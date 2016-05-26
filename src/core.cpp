#include <spark/core.hpp>
#include "flextGL.h"
#include "nanovg.h"
#define NANOVG_GL3_IMPLEMENTATION
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
	m_private->nvg_context = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);
}

Core::~Core()
{

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
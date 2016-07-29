#include <spark/core.hpp>
#include <spark/grid.hpp>
#include <spark/label.hpp>
#include <iostream>
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

std::shared_ptr<View> Core::CreateView(const unsigned int width, const unsigned int height)
{
	m_views.push_back(std::make_shared<View>(width,height));
	return m_views.back();
}

std::shared_ptr<View> Core::CreateView(const unsigned int width, const unsigned int height, const std::string &file, std::map<std::string, std::function<void(std::shared_ptr<IElement>)>> &functions)
{
	std::shared_ptr<View> view = std::make_shared<View>(width, height);
	m_views.push_back(view);

	// TODO: parse a view file here instead

	auto element = std::make_shared<Grid>();

	m_fps = std::make_shared<ILabel>();
	m_fps->SetText("testest");
	m_fps->SetBorderSize(0.0);
	m_fps->SetBackgroundColor(vec4<unsigned int>(255, 0, 0, 255));
	m_fps->SetFontSize(26.0f);
	m_fps->SetFont("ui/fonts/Delicious-Bold.otf"); //get the paths from the engine
	m_fps->SetFunction(functions["get_fps"]);
	element->AddChildren(m_fps);

	m_renderedTris = std::make_shared<ILabel>();
	m_renderedTris->SetText("testetest");
	m_renderedTris->SetFontSize(26.0f);
	m_renderedTris->SetBorderSize(0.0);
	m_renderedTris->SetBackgroundColor(vec4<unsigned int>(0, 0, 0, 0));
	m_renderedTris->SetFont("ui/fonts/Delicious-Bold.otf");
	m_fps->SetFunction(functions["get_rendered_polygons"]);
	m_renderedTris->SetMargin(vec4<unsigned int>(30, 0, 0, 0));
	element->AddChildren(m_renderedTris);


	m_decrease_brush_button = std::make_shared<IButton>("ui/buttons/decrease_brush_width.png");
	m_decrease_brush_button->SetFunction(functions["decrease_brush"]);
	m_decrease_brush_button->SetWidth(50);
	m_decrease_brush_button->SetHeight(50);
	m_decrease_brush_button->SetBorderRadius(25);
	m_decrease_brush_button->SetMargin(vec4<unsigned int>(0, 0, 0, 750));
	m_decrease_brush_button->SetBackgroundColor(vec4<unsigned int>(255, 0, 0, 255));
	element->AddChildren(m_decrease_brush_button);

	m_image = std::make_shared<IImage>("ui/gondor.png");
	m_image->SetWidth(400);
	m_image->SetHeight(250);
	m_image->SetMargin(vec4<unsigned int>(350, 0, 0, 0));
	element->AddChildren(m_image);

	view->SetRoot(element);

	return m_views.back();
}

void* Core::GetPaintContext()
{
	return m_private->nvg_context;
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
	int result = nvgCreateFontMem(m_private->nvg_context, name.c_str(), (unsigned char*)memory, size, 0);
	if (result == -1)
		return false;
	else
		return true;
}
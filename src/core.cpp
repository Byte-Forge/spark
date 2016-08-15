#include <spark/core.hpp>
#include <spark/grid.hpp>
#include <spark/label.hpp>
#include <spark/button.hpp>
#include <iostream>
#include "flextGL.h"
#include "nanovg.h"
#include "nanovg_gl.h"

using namespace spark;

Core* Core::s_instance = nullptr;

struct Core::priv
{
	NVGcontext * nvg_context;
};

Core::Core(const bool initGL)
{

	s_instance = this;
	
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

std::function<void(std::shared_ptr<spark::IElement>)> Core::GetFunction(std::string &name)
{
	const auto& it = m_functions.find(name);
	if (it == m_functions.end())
	{
		std::cout << "WARNING!: no function defined for: " + name << std::endl;
		return [](std::shared_ptr<spark::IElement> e) { std::cout << "WARNING!: no function defined for this element" << std::endl; };
	}
	return m_functions[name];
}

std::shared_ptr<IElement>& Core::GetNamedElement(std::string name)
{
	const auto& it = m_namedElements.find(name);
	if (it == m_namedElements.end())
	{
		std::cout << "WARNING!: no element with name " << name << " found! " << std::endl;
	}
	return m_namedElements[name];
}

std::vector<std::string> Core::GetVisibleNamedElements()
{
	std::vector<std::string> elements;
	for (const auto &elem : m_namedElements)
	{
		if (elem.second->IsVisible())
		{
			elements.push_back(elem.second->GetName());
		}
	}
	return elements;
}

void Core::AddScriptEngine(std::shared_ptr<IScriptEngine> engine)
{
	m_scriptengines.push_back(engine);
}

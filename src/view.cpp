#include <spark/view.hpp>
#include <spark/core.hpp>
#include <nanovg.h>

using namespace spark;

View::View(const unsigned int width, const unsigned int height) : m_width(width),m_height(height)
{

}

void View::SetRoot(std::shared_ptr<IContainer> root)
{
	m_root = root;
	m_root->OnInitialize();
}

void View::Render(const PaintEvent& ev)
{
	nvgBeginFrame((NVGcontext*)ev.context, m_width, m_height,ev.ratio);
	Dimension dim = Dimension();
	dim.box = vec4<unsigned int>(0, 0, m_width, m_height);
	m_root->OnPaint(ev,dim);
	nvgEndFrame((NVGcontext*)ev.context);
}
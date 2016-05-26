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
}

void View::Render(const PaintEvent& ev)
{
	nvgBeginFrame((NVGcontext*)ev.context, m_width, m_height,ev.ratio);
	m_root->OnPaint(ev);
	nvgEndFrame((NVGcontext*)ev.context);
}
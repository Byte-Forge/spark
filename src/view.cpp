#include <spark/view.hpp>
#include <spark/core.hpp>
#include <spark/textbox.hpp>
#include <iostream>
#include <nanovg.h>

using namespace spark;

View::View(const unsigned int width, const unsigned int height) : m_width(width), m_height(height), m_mouse(Mouse()), m_keyboard(Keyboard())
{
	m_dim = { 0, 0, m_width, m_height };
}

void View::SetRoot(std::shared_ptr<IContainer> root)
{
	m_root = root;
	m_root->OnInitialize();
}

void View::Render(const PaintEvent& ev)
{
	nvgBeginFrame((NVGcontext*)ev.context, m_width, m_height,ev.ratio);
	m_root->OnPaint(ev, m_dim);
	nvgEndFrame((NVGcontext*)ev.context);
}

void View::Update()
{
	m_root->Update(m_mouse, m_keyboard,shared_from_this());
	m_mouse.ToReleased();
}

void View::Resize(const unsigned int width, const unsigned int height)
{
	m_width = width;
	m_height = height;
	m_dim = { 0, 0, m_width, m_height };
}

void View::SetKeyState(const int key, const int action, const int mods)
{
	m_keyboard.SetKeyState(key, action, mods);
	auto tb = std::dynamic_pointer_cast<Textbox>(m_activeTb);
	if(tb!=nullptr)
		tb->OnKeyboard(static_cast<KeyboardCode>(key),action,mods);
}
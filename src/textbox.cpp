#include <spark/textbox.hpp>
#include <nanovg.h>
#include <iostream>
#include <spark/view.hpp>
#include <cctype>
#include <spark/core.hpp>

using namespace spark;

Textbox::Textbox() : IElement()
{
	m_bg_color = vec4<unsigned int>(0, 0, 0, 100);
	m_border_radius = 5;
	m_border_color = vec4<unsigned int>(0, 0, 0, 255);
	m_border_size = 2;
}

Textbox::~Textbox()
{

}

void Textbox::SetVisible(const bool visible)
{
	m_visible = visible;
}

void Textbox::OnInitialize()
{

}

void Textbox::OnPaint(const PaintEvent& ev, const Dimension& box)
{
	if (m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);

		CalcPosition(box);

		nvgBeginPath(vg);
		nvgRoundedRect(vg, m_box.x, m_box.y, m_box.width, m_box.height, m_border_radius);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		nvgStrokeColor(vg, nvgRGBA(m_border_color.x, m_border_color.y, m_border_color.z, m_border_color.w));
		nvgStrokeWidth(vg, m_border_size);
		nvgStroke(vg);

		if (m_label != nullptr)
		{
			m_label->OnPaint(ev, m_box);
		}
	}
}

void Textbox::Update(Mouse mouse, Keyboard keyboard,std::shared_ptr<View> view)
{
	if (m_visible)
	{
		MouseOver(mouse);
		m_update(shared_from_this());
		if (m_hovered && mouse.ButtonJustReleased(MouseCode::MOUSE_LEFT))
		{
			view->SetActiveTb(shared_from_this());
		}
	}
}

void Textbox::SetLabel(std::shared_ptr<Label> label)
{
	m_label = label;
}

void Textbox::OnKeyboard(const KeyboardCode key, int action, int mods)
{
	if (action != PRESSED)
		return;
	if (key == KEY_BACKSPACE)
	{
		m_label->GetText().pop_back();
	}
	else if (key == KEY_ENTER)
	{
		auto &label = std::dynamic_pointer_cast<Label>(Core::GetCore()->GetNamedElement("consoleLabel"));
		label->SetText(label->GetText() + '\n' + m_label->GetText());
		m_label->SetText("");
	}
	else
	{
		char letter = static_cast<char>(key);
		if (!(mods & MOD_SHIFT))
		{
			letter = std::tolower(letter);
		}
		m_label->SetText(m_label->GetText() + letter);
	}
}
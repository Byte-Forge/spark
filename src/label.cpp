#include <spark/label.hpp>
#include <nanovg.h>
#include <vector>
#include "util.hpp"
#include <iostream>
#include <sstream>

using namespace spark;

Label::Label() : m_text(""), m_size(18.f), m_font("arial-sans"), m_font_color(0,0,0,255), IElement()
{
	m_bg_color = vec4<unsigned int> (0,0,0,0);
}

void Label::OnInitialize()
{

}

void Label::SetVisible(const bool visible)
{
	m_visible = visible;
}

void Label::OnPaint(const PaintEvent& ev,const Dimension& box)
{
	if(m_visible)
	{
		NVGcontext* vg = static_cast<NVGcontext*>(ev.context);
		
		m_width = m_text.length() * m_size * 0.5f + m_padding.w + m_padding.y; 
		m_height = m_size + m_padding.x + m_padding.z;

		CalcPosition(box);
		m_position.y += m_size * 0.5f;

		int num_rows = (box.height / m_height) - 2;
		std::vector<std::string> lines = split(m_text, '\n');

		while (num_rows < lines.size())
		{
			lines.erase(lines.begin());
		}

		nvgBeginPath(vg);
		nvgRoundedRect(vg, m_box.x , m_box.y, m_box.width, m_box.height, m_border_radius);
		nvgFillColor(vg, nvgRGBA(m_bg_color.x, m_bg_color.y, m_bg_color.z, m_bg_color.w));
		nvgFill(vg);

		nvgStrokeColor(vg, nvgRGBA(m_border_color.x, m_border_color.y, m_border_color.z, m_border_color.w));
		nvgStrokeWidth(vg, m_border_size);
		nvgStroke(vg);

		nvgTextAlign(vg, NVG_ALIGN_LEFT | NVG_ALIGN_MIDDLE);
		
		nvgFontSize(vg, m_size);
		nvgFontFace(vg, m_font.c_str());

		vec2<int> pos = vec2<int>(m_position.x, m_position.y);
		for (auto line : lines)
		{
			float bounds[4];
			std::vector<std::string> words = split(line, ' ');
			pos.x = m_position.x;
			for (auto word : words)
			{
				std::vector<std::string> substrings = split(word, "\\c");

				nvgTextBoxBounds(vg, pos.x, pos.y, m_box.width, substrings[0].c_str(), NULL, bounds);
				nvgFillColor(vg, nvgRGBA(m_font_color.x, m_font_color.y, m_font_color.z, m_font_color.w));
				nvgTextBox(vg, bounds[0], bounds[1], m_box.width, substrings[0].c_str(), NULL);
				pos.x += bounds[2] - bounds[0] + 3;

				if (substrings.size() > 1)
				{
					for (std::string string : substrings)
					{
						if (string == substrings.front())
							continue;

						int count = 1;
						if (string[0] == 'r')
						{
							nvgFillColor(vg, nvgRGBA(255, 0, 0, 255));
						}
						else if (string[0] == 'g')
						{
							nvgFillColor(vg, nvgRGBA(0, 255, 0, 255));
						}
						else if (string[0] == 'b')
						{
							nvgFillColor(vg, nvgRGBA(0, 0, 255, 255));
						}
						else if (string[0] == 'y')
						{
							nvgFillColor(vg, nvgRGBA(255, 255, 0, 255));
						}
						else if (string[0] == 'o')
						{
							nvgFillColor(vg, nvgRGBA(255, 140, 0, 255));
						}
						else 
						{
							std::string red = std::string() + string[0] + string[1];
							std::string green = std::string() + string[2] + string[3];
							std::string blue = std::string() + string[4] + string[5];
							std::string alpha = std::string() + string[6] + string[7];
							nvgFillColor(vg, nvgRGBA(std::stoul(red, nullptr, 16), std::stoul(green, nullptr, 16), std::stoul(blue, nullptr, 16), std::stoul(alpha, nullptr, 16)));
							count = 8;
						}

						string.erase(0, count);
						nvgTextBoxBounds(vg, pos.x, pos.y, m_box.width, string.c_str(), NULL, bounds);
						nvgTextBox(vg, bounds[0], bounds[1], m_box.width, string.c_str(), NULL);
						pos.x += bounds[2] - bounds[0] + 3;
					}
				}
			}
			pos.y += m_height;
		}
	}
}

void Label::Update(Mouse mouse, Keyboard keyboard,std::shared_ptr<View> view)
{
	if (m_visible)
	{
		m_update(shared_from_this());
	}
}

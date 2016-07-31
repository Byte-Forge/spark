#include <spark/element.hpp>
#include <iostream>

using namespace spark;

IElement::IElement() : m_margin(0), m_padding(0), m_index(0), m_width(0), m_height(0),
m_horizontalAlignment(LEFT), m_verticalAlignment(TOP),
m_border_size(0), m_border_color(0,0,0,255), m_border_radius(0), m_visible(true),
m_bg_color(255, 255, 255, 255), m_function([](std::shared_ptr<IElement> e) { })
{

}

void IElement::CalcPosition(const Dimension& box)
{
	m_position = vec2<int>(box.x + m_margin.w, box.y + m_margin.x);

	if ((m_width + m_margin.y + m_margin.w) > box.width)
		m_width = box.width - m_margin.y - m_margin.w;
	if ((m_height + m_margin.x + m_margin.z) > box.height)
		m_height = box.height - m_margin.x - m_margin.z;

	if (m_horizontalAlignment == LEFT)
	{
		//LEFT is default, do nothing
	}
	else if (m_horizontalAlignment == RIGHT)
	{
		m_position.x = box.x + box.width - m_width - m_margin.y;
	}
	else if (m_horizontalAlignment == CENTER)
	{
		m_position.x = box.x + box.width/2 - m_width/2;
	}
	else if(m_horizontalAlignment == STRETCH)
	{
		m_width = box.width - m_margin.y - m_margin.w;
	}

	if (m_verticalAlignment == TOP)
	{
		//TOP is default, do nothin
	}
	else if (m_verticalAlignment == BOTTOM)
	{
		m_position.y = box.y + box.height - m_height - m_margin.z;
	}
	else if (m_verticalAlignment == CENTER)
	{
		m_position.y =box.y + box.height/2 - m_height/2;
	}
	else if (m_verticalAlignment == STRETCH)
	{
		m_height = box.height - m_margin.x - m_margin.z;
	}

	m_box = { m_position.x, m_position.y, m_width, m_height };
}
#include <spark/element.hpp>
#include <iostream>

using namespace spark;

IElement::IElement() : m_margin(0), m_padding(0), m_index(0), m_width(0), m_height(0),
m_horizontalAlignment(LEFT), m_verticalAlignment(TOP),
m_border_size(0), m_border_color(0, 0, 0, 255), m_border_radius(0), m_visible(true),
m_gridRow(0), m_gridColumn(0), m_rowSpan(1), m_columnSpan(1),
m_bg_color(255, 255, 255, 255), m_function([](std::shared_ptr<IElement> e) { })
{

}

void IElement::CalcPosition(const Dimension& box)
{
	m_position = vec2<int>(box.x + m_margin.w, box.y + m_margin.x);

	if (m_width == 0)
	{
		m_width = box.width;
	}
	if (m_height == 0)
		m_height = box.height;

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

bool IElement::MouseOver(vec2<int> mouse_pos)
{
	if (mouse_pos.x >= m_box.x && mouse_pos.x <= (m_box.x + m_box.width)
		&& mouse_pos.y >= m_box.y && mouse_pos.y <= (m_box.y + m_box.height))
	{
		if (m_border_radius == 0)
		{
			return true;
		}

		//test for the 4 rounded corners
		else
		{
			vec2<int> upperLeft = vec2<int>(m_box.x + m_border_radius, m_box.y + m_border_radius);
			vec2<int> upperRight = vec2<int>(m_box.x + m_box.width - m_border_radius, m_box.y + m_border_radius);
			vec2<int> lowerLeft = vec2<int>(m_box.x + m_border_radius, m_box.y + m_box.height - m_border_radius);
			vec2<int> lowerRight = vec2<int>(m_box.x + m_box.width - m_border_radius, m_box.y + m_box.height - m_border_radius);

			if (mouse_pos.x < upperLeft.x && mouse_pos.y < upperLeft.y)
			{
				if (mouse_pos.distance(upperLeft) <= m_border_radius)
				{
					return true;
				}
			}
			else if (mouse_pos.x > upperRight.x && mouse_pos.y < upperRight.y)
			{
				if (mouse_pos.distance(upperRight) <= m_border_radius)
				{
					return true;
				}
			}
			else if (mouse_pos.x < lowerLeft.x && mouse_pos.y > lowerLeft.y)
			{
				if (mouse_pos.distance(lowerLeft) <= m_border_radius)
				{
					return true;
				}
			}
			else if (mouse_pos.x > lowerRight.x && mouse_pos.y > lowerRight.y)
			{
				if (mouse_pos.distance(lowerRight) <= m_border_radius)
				{
					return true;
				}
			}
			else
			{
				return true;
			}
		}
	}
	return false;
}
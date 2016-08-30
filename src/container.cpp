#include <spark/container.hpp>
#include <iostream>

using namespace spark;

IContainer::IContainer() : IElement(), m_vertical_scroll(0), m_horizontal_scroll(0), m_x_slider(Slider(HORIZONTAL)), m_y_slider(Slider(VERTICAL)), m_scroll_x(false), m_scroll_y(false)
{
	m_horizontalAlignment = STRETCH;
	m_verticalAlignment = STRETCH;
	m_bg_color = vec4<unsigned int>(0, 0, 0, 0);
	m_childs_width = 0;
	m_childs_height = 0;
}

void IContainer::SetImage(std::shared_ptr<Image> image)
{
	m_image = image;
	m_image->SetHorizontalAlignment(STRETCH);
	m_image->SetVerticalAlignment(STRETCH);
}

void IContainer::AddChild(std::shared_ptr<IElement> child)
{
	int height = child->GetHeight();
	if (height > m_childs_height)
		m_childs_height = height;
	int width = child->GetWidth();
	if (width > m_childs_width)
		m_childs_width = width;

	m_children.push_back(child);
}
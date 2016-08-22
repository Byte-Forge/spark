#include <spark/container.hpp>
#include <iostream>

using namespace spark;

IContainer::IContainer() : IElement(), m_vertical_scroll(false), m_horizontal_scroll(false)
{
	m_horizontalAlignment = STRETCH;
	m_verticalAlignment = STRETCH;
	m_bg_color = vec4<unsigned int>(0, 0, 0, 0);
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
	if (height > m_child_max_height)
		m_child_max_height = height;
	int width = child->GetWidth();
	if (width > m_child_max_width)
		m_child_max_width = width;

	m_children.push_back(child);
}
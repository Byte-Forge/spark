#include <spark/container.hpp>

using namespace spark;

IContainer::IContainer() : IElement()
{
	m_horizontalAlignment = STRETCH;
	m_verticalAlignment = STRETCH;
	m_bg_color = vec4<unsigned int>(0, 0, 0, 0);
}

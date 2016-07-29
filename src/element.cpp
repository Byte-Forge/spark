#include <spark/element.hpp>
using namespace spark;

IElement::IElement() : m_margin(0),m_padding(0), m_index(0), m_width(0), m_height(0), 
m_border_size(0), m_border_color(0,0,0,255), m_border_radius(0), m_visible(true),
m_bg_color(255, 255, 255, 255), m_function([]() { })
{

}

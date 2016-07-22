#include <spark/button.hpp>
#include <nanovg.h>
#include <iostream>

using namespace spark;

IButton::IButton() : IElement()
{
	
}

void IButton::OnInitialize()
{
	std::cout << "Initialized label" << std::endl;
}

void IButton::OnPaint(const PaintEvent& ev,const Dimension& box)
{
	if(m_visible)
	{

	}
}

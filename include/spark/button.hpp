#pragma once
#include <string>
#include "element.hpp"


namespace spark
{	
	class IButton : public IElement
	{
	public:
		IButton();
	
        void OnPaint(const PaintEvent& ev,const Dimension& box);
        void OnInitialize();
       	
	private:

	};
}

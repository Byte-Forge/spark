#pragma once
#include <string>
#include <functional>
#include "element.hpp"
#include "image.hpp"


namespace spark
{	
	class IButton : public IElement
	{
	public:
		IButton();
		IButton(const std::string imgFile);
	
        void OnPaint(const PaintEvent& ev,const Dimension& box);
        void OnInitialize();
		void Update(Mouse mouse);
		void SetFunction(std::function<void()> func) { m_function = func; }

	private:
		vec4<unsigned int> m_border_box;
		std::function<void()> m_function;
		std::shared_ptr<IImage> m_image;
	};
}

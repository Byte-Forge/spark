#pragma once
#include "element.hpp"
#include "image.hpp"
#include "vector.hpp"
#include "slider.hpp"
#include <list>

namespace spark
{
	class IContainer : public IElement
	{
	public:
		IContainer();

		void AddChild(std::shared_ptr<IElement> child);

		inline std::list<std::shared_ptr<IElement>> GetChildren()
		{
			return m_children;
		}

		void SetImage(std::shared_ptr<Image> image);

	protected:
		std::shared_ptr<Image> m_image;
		virtual void PaintChildren(const PaintEvent& ev, const Dimension& dim) = 0;
		std::list<std::shared_ptr<IElement>> m_children; 
		int m_childs_width;
		int m_childs_height;
		int m_vertical_scroll;
		int m_max_vertical_scroll;
		int m_horizontal_scroll;
		int m_max_horizontal_scroll;
		bool m_scroll_x;
		bool m_scroll_y;

		int m_sliderSize = 10;

		Slider m_x_slider;
		Slider m_y_slider;
	};
}

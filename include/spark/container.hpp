#pragma once
#include "element.hpp"
#include "image.hpp"
#include "vector.hpp"
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
		int m_child_max_width;
		int m_child_max_height;
		bool m_vertical_scroll;
		bool m_horizontal_scroll;
	};
}

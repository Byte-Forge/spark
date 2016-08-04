#pragma once
#include "element.hpp"
#include "image.hpp"
#include "vector.hpp"

namespace spark
{
	class IContainer : public IElement
	{
	public:
		IContainer();

		void AddChildren(std::shared_ptr<IElement> child)
		{
			m_children.insert(child);
		}

		inline std::set<std::shared_ptr<IElement>> GetChildren()
		{
			return m_children;
		}

		void SetImage(const std::string& imgFile);

	protected:
		std::shared_ptr<IImage> m_image;
		virtual void PaintChildren(const PaintEvent& ev, const Dimension& dim) = 0;
		std::set<std::shared_ptr<IElement>> m_children; //do sth to order these for stackpanel etc
	};
}

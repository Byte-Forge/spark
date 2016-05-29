#pragma once
#include "element.hpp"
#include "vector.hpp"

namespace spark
{
	class IContainer : public IElement
	{
	public:
		void AddChildren(std::shared_ptr<IElement> child)
		{
			child->OnInitialize();
			m_children.insert(child);
		}

	protected:
		virtual void PaintChildren(const PaintEvent& ev,const Dimension& dim) = 0;
		std::set<std::shared_ptr<IElement>> m_children;
	};
}

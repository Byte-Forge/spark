#pragma once
#include "element.hpp"
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

	protected:
		virtual void PaintChildren(const PaintEvent& ev, const Dimension& dim) = 0;
		std::set<std::shared_ptr<IElement>> m_children;
	};
}

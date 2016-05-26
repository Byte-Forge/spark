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
			m_children.insert(child);
		}
	protected:
		std::set<std::shared_ptr<IElement>> m_children;
	};
}
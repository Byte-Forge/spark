#pragma once
#include "container.hpp"

namespace spark
{
    class View
    {
	public:
		View(const unsigned int width, const unsigned int height);
		void SetRoot(std::shared_ptr<IContainer> root);
		inline std::shared_ptr<IContainer> GetRoot() {return m_root;}
		void Render(const PaintEvent& ev);
	private:
		std::shared_ptr<IContainer> m_root;
		unsigned int m_width,m_height;
    };
}
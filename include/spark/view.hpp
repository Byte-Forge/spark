#pragma once
#include "container.hpp"
#include "input.hpp"

namespace spark
{
    class View
    {
	public:
		View(const unsigned int width, const unsigned int height);

		void SetRoot(std::shared_ptr<IContainer> root);
		inline std::shared_ptr<IContainer> GetRoot() {return m_root;}
		void Render(const PaintEvent& ev);
		void Update();
		void Resize(const unsigned int width, const unsigned int height);

		void SetMousePosition(int x, int y) { m_mouse.SetMousePosition(x, y); }
		vec2<int> GetMousePosition() { return m_mouse.GetMousePosition(); }

		inline void SetMouseState(const int key, int action, const int mods) { m_mouse.SetMouseState(key, action, mods); }

	private:
		std::shared_ptr<IContainer> m_root;
		unsigned int m_width, m_height;

		Mouse m_mouse;
		Keyboard m_keyboard;
    };
}
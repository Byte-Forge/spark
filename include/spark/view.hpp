#pragma once
#include "input.hpp"
#include "container.hpp"

namespace spark
{
    class View : public std::enable_shared_from_this<View>
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

		void RestoreJustPressed() { m_mouse.ToReleased(); };

		inline void SetMouseState(const int key, const int action, const int mods) { m_mouse.SetMouseState(key, action, mods); }
		void SetKeyState(const int key, const int action, const int mods);
		inline void SetActiveTb(std::shared_ptr<IElement> tb) {m_activeTb = tb; }

	private:
		std::shared_ptr<IContainer> m_root;
		unsigned int m_width, m_height;
		Dimension m_dim;
		std::shared_ptr<IElement> m_activeTb;
		Mouse m_mouse;
		Keyboard m_keyboard;
    };
}
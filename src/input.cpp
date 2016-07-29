#include <spark/input.hpp>

using namespace spark;

vec2<int> Mouse::m_position;
std::map<MouseCode, int> Mouse::m_mouseInputs;

KeyboardCode Keyboard::m_key_pressed;

void Mouse::ToReleased()
{
	for (auto &it = m_mouseInputs.begin(); it != m_mouseInputs.end(); it++)
	{
		if (it->second == JUST_RELEASED)
			it->second = RELEASED;
	}
}

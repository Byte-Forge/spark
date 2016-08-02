#include <spark/input.hpp>

using namespace spark;

vec2<int> Mouse::m_position;
std::map<MouseCode, int> Mouse::m_mouseInputs;

KeyboardCode Keyboard::m_key_pressed;

void Mouse::ToReleased()
{
	for (auto input : m_mouseInputs)
	{
		if (input.second == JUST_RELEASED)
			input.second = RELEASED;
	}
}

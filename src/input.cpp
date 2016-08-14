#include <spark/input.hpp>

using namespace spark;

vec2<int> Mouse::m_position;
std::map<MouseCode, int> Mouse::m_mouseInputs;
std::map<KeyboardCode, int> Keyboard::m_keyInputs;

void Mouse::ToReleased()
{
	for (auto input : m_mouseInputs)
	{
		if (input.second == JUST_RELEASED)
			input.second = RELEASED;
	}
}

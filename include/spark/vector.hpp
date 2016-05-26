#pragma once

namespace spark
{
	template<typename T> class vec4
	{
	public:
		vec4(unsigned int xyzw)
		{
			x = y = z = w = xyzw;
		}

		union
		{
			T xyzw[4];
			T x, y, z, w;
		};
	};
}
#pragma once

namespace spark
{
	template<typename T> class vec4
	{
	public:
		vec4()
		{
			x = y = z = w = 0;
		}

		vec4(unsigned int xyzw)
		{
			x = y = z = w = xyzw;
		}

		vec4(unsigned int c1, unsigned int c2,
			unsigned int c3, unsigned int c4)
		{
			x = c1;
			y = c2;
			z = c3;
			w = c4;
		}

		union
		{
			T xyzw[4];
			struct
			{
				T x, y, z, w;
			};
		};
	};
}
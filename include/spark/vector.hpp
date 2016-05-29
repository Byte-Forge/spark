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
	
	template<typename T> class vec2
	{
	public:
		vec2()
		{
			x = y = 0;
		}

		vec2(unsigned int xy)
		{
			x = y = xy;
		}

		vec2(unsigned int c1, unsigned int c2)
		{
			x = c1;
			y = c2;
		}

		union
		{
			T xy[2];
			struct
			{
				T x, y;
			};
		};
	};
}

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

		vec4(T xyzw)
		{
			x = y = z = w = xyzw;
		}

		vec4(T c1, T c2,
			T c3, T c4)
		{
			x = c1;
			y = c2;
			z = c3;
			w = c4;
		}

		bool operator ==(const vec4& v)
		{
			if((x == v.x) &&
				(y == v.y) &&
				(z == v.z) &&
				(w == v.w))
				return true;
			else
				return false;
		}
		
		bool operator !=(const vec4& v)
		{
			if((x == v.x) &&
				(y == v.y) &&
				(z == v.z) &&
				(w == v.w))
				return false;
			else
				return true;
		}
		
		vec4 operator +(const vec4& v)
		{
			return vec4(x + v.x, y + v.y, z + v.z, w + v.w);
		}
		
		vec4 &operator +=(const vec4& v)
		{
			x += v.x;
			y += v.y;
			z += v.z;
			w += v.w;
			return *this;
		}

		vec4 operator -(const vec4& v)
		{
			return vec4(x - v.x, y - v.y, z - v.z, w - v.w);
		}
		
		vec4 &operator -=(const vec4& v)
		{
			x -= v.x;
			y -= v.y;
			z -= v.z;
			w -= v.w;
			return *this;
		}
		
		vec4 operator *(const vec4& v)
		{
			return vec4(x * v.x, y * v.y, z * v.z, w * v.w);
		}
		
		vec4 &operator *=(const vec4& v)
		{
			x *= v.x;
			y *= v.y;
			z *= v.z;
			w *= v.w;
			return *this;
		}
		
		vec4 operator /(const vec4& v)
		{
			return vec4(x / v.x, y / v.y, z / v.z, w / v.w);
		}
		
		vec4 &operator /=(const vec4& v)
		{
			x /= v.x;
			y /= v.y;
			z /= v.z;
			w /= v.w;
			return *this;
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

		vec2(T xy)
		{
			x = y = xy;
		}

		vec2(T c1, T c2)
		{
			x = c1;
			y = c2;
		}
		
		bool operator ==(const vec2& v)
		{
			if((x == v.x) &&
				(y == v.y))
				return true;
			else
				return false;
		}
		
		bool operator !=(const vec2& v)
		{
			if((x == v.x) &&
				(y == v.y))
				return false;
			else
				return true;
		}
		
		vec2 operator +(const vec2& v)
		{
			return vec2(x + v.x, y + v.y);
		}
		
		vec2 &operator +=(const vec2& v)
		{
			x += v.x;
			y += v.y;
			return *this;
		}

		vec2 operator -(const vec2& v)
		{
			return vec2(x - v.x, y - v.y);
		}
		
		vec2 &operator -=(const vec2& v)
		{
			x -= v.x;
			y -= v.y;
			return *this;
		}
		
		vec2 operator *(const vec2& v)
		{
			return vec2(x * v.x, y * v.y);
		}
		
		vec2 &operator *=(const vec2& v)
		{
			x *= v.x;
			y *= v.y;
			return *this;
		}
		
		vec2 operator /(const vec2& v)
		{
			return vec2(x / v.x, y / v.y);
		}
		
		vec2 &operator /=(const vec2& v)
		{
			x /= v.x;
			y /= v.y;
			return *this;
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

#ifndef __VECTOR_3_H__
#define __VECTOR_3_H__

class Vector3
{
public:
	float x, y, z;

	Vector3() {}
	Vector3(const Vector3 &a) : x(a.x), y(a.y), z(a.z) {}
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

	Vector3 &operator = (const Vector3 &a)
	{
		x = a.x; y = a.y; z = a.z;
		return *this;
	}

	bool operator == (const Vector3 &a)
	{
		return a.x == x && a.y == y && a.z == z;
	}

	bool operator != (const Vector3 &a)
	{
		return a.x != x || a.y != y || a.z != z;
	}

	void zero() { x = y = z = 0.0f; }

	Vector3 operator - () const
	{
		return Vector3(-x, -y, -z);
	}

	Vector3 operator + (const Vector3 &a)
	{
		return Vector3(x + a.x, y + a.y, z + a.z);
	}

	Vector3 operator - (const Vector3 &a)
	{
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	Vector3 operator * (float a) const
	{
		return Vector3(a * x, a * y, a * z);	
	}

	Vector3 operator / (float a) const
	{
		float oneOverA = 1.0f / a;
		return Vector3(oneOverA * x, oneOverA * y, oneOverA * z);
	}

	Vector3 operator += (const Vector3 &a)
	{
		x += a.x; y += a.y; z += a.z;
		return *this;
	}
	
	Vector3 operator -= (const Vector3 &a)
	{
		x -= a.x; y -= a.y; z -= a.z;
		return *this;
	}

	Vector3 operator *= (float a) const
	{
		x *= a; y *= a; z *= a;
		return *this;
	}

	Vector3 operator /= (float a) const
	{
		float oneOverA = 1.0f / a;
		x *= oneOverA; y *= oneOverA; z *= oneOverA;
		return *this;
	}

	void normalize()
	{
		float magSq = x * x + y * y + z * z;

		if (magSq > 0.0f)
		{
			float oneOverA = 1.0f / sqrt(magSq);
			x *= oneOverA; y *= oneOverA; z *= oneOverA;
		}
	}

	float operator * (const Vector3 &a) const 
	{
		return a.x * x + a.y * y + a.z * z;
	}
};

inline float vectorMag(const Vector3 &a)
{
	return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b)
{
	return Vector3(
			a.y * b.z - a.z * b.y,
			a.z * b.x - a.x * b.z,
			a.x * b.y - a.y * b.x
			);
}

inline Vector3 operator * (float k, const Vector3 &v)
{
	return Vector3(k * v.x, k * v.y, k * v.z);
}

inline float distance(const Vector3 &a, const Vector3 &b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;

	return sqrt(dx * dx + dy * dy + dz * dz);
}

extern const Vector3 kZeroVecotr;

#endif

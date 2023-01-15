#include "Vector2D.h"

namespace MATH {

	Vector2D::Vector2D(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2D::Vector2D()
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}

	void Vector2D::Add(double x, double y)
	{
		this->x += x;
		this->y += y;
	}

	void Vector2D::Subtract(double x, double y)
	{
		this->x -= x;
		this->y -= y;
	}

	void Vector2D::Multiply(double x, double y)
	{
		this->x *= x;
		this->y *= y;
	}

	void Vector2D::Divide(double x, double y)
	{
		this->x /= x;
		this->y /= y;
	}
}



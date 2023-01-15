#pragma once

namespace MATH {
	class Vector2D
	{
	public:
		Vector2D(double x, double y);
		Vector2D();

		inline double setX(double x) { this->x = x; }
		inline double setY(double y) { this->y = y; }

		inline double getX() { return this->x; };
		inline double getY() { return this->y; };

		void Add(double x, double y);
		void Subtract(double x, double y);
		void Multiply(double x, double y);
		void Divide(double x, double y);

	private:
		double x, y;

	};
}



#pragma once
#include "shape.h"

namespace CSG2D
{
	class Rectangle : public Shape
	{
	private:
		double a, b;
	public:
		Rectangle(const sf::Vector2f& position, double a_, double b_, double angl_ = 0) : Shape(position, angl_), a(a_), b(b_) {}
		bool isIn(const sf::Vector2f& test_position) const override;
	};
}



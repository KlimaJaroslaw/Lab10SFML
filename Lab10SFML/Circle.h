#pragma once
#include "shape.h"

namespace CSG2D
{
	class Circle : public Shape
	{
	private:
		float radius_;
	public:
		Circle(const sf::Vector2f& position, double radius) : Shape(position, 0.0), radius_(radius) {}
		bool isIn(const sf::Vector2f& test_position) const override;
	};
}



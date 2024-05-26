#include "Circle.h"
#include "functions.h"

bool CSG2D::Circle::isIn(const sf::Vector2f& test_position) const
{
	sf::Vector2f newVector(position_.x - test_position.x, position_.y - test_position.y);
	return length(newVector) < radius_;
}
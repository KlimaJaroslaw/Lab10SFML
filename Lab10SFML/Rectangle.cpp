#include "Rectangle.h"
#include "functions.h"

bool CSG2D::Rectangle::isIn(const sf::Vector2f& test_position) const
{
	sf::Vector2f rectRotated = rotate(position_, angle_rad_);
	sf::Vector2f pointRotated = rotate(test_position, angle_rad_);

	return !(abs(pointRotated.x - rectRotated.x) > a / 2 || abs(pointRotated.y - rectRotated.y) > b / 2);
}
#include "ComplexShape.h"
#include "functions.h"

CSG2D::ComplexShape::ComplexShape(std::shared_ptr<CSG2D::Shape> shapeOne_, std::shared_ptr<CSG2D::Shape> shapeTwo_, OPERATION operation_, sf::Vector2f position_, float rot_) : Shape(position_, rot_), operation(operation_), shapeOne(shapeOne_), shapeTow(shapeTwo_)
{
}

bool CSG2D::ComplexShape::isIn(const sf::Vector2f& placeOnScreen) const
{
	sf::Vector2f posRotated = rotate(position_, angle_rad_);
	sf::Vector2f pointRotated = rotate(placeOnScreen, angle_rad_);

	switch (operation)
	{
	case CSG2D::OPERATION::UNION:
		return (shapeOne->isIn(pointRotated - posRotated) || shapeTow->isIn(pointRotated - posRotated));
	case CSG2D::OPERATION::DIFFERENCE:
		return (shapeOne->isIn(pointRotated - posRotated) && !shapeTow->isIn(pointRotated - posRotated));
	case CSG2D::OPERATION::INTERSECTION:
		return (shapeOne->isIn(pointRotated - posRotated) && shapeTow->isIn(pointRotated - posRotated));
	default:
		return false;
	}
	return true;
}





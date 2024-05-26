#pragma once
#include "shape.h"
#include "operation.h"

namespace CSG2D
{
	class ComplexShape : public Shape
	{
	private:
		OPERATION operation;
		std::shared_ptr<CSG2D::Shape> shapeOne;
		std::shared_ptr<CSG2D::Shape> shapeTow;
	public:
		ComplexShape(std::shared_ptr<CSG2D::Shape> shapeOne_, std::shared_ptr<CSG2D::Shape> shapeTwo_, OPERATION operation_, sf::Vector2f position_ = sf::Vector2f(0, 0), float rot_ = 0);
		bool isIn(const sf::Vector2f& placeOnScreen) const override;
	};
}


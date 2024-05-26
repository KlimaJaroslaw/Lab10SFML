#include "functions.h"
#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "complexshape.h"

sf::Vector2f rotate(const sf::Vector2f& v, float angle_rad)
{
	const float cs = std::cos(angle_rad);
	const float sn = std::sin(angle_rad);

	return { v.x * cs - v.y * sn, v.x * sn + v.y * cs };
}

void updateTexture(sf::Texture& t, const CSG2D::Shape& s, const sf::Color& foreground_color, const sf::Color& background_color)
{
	const auto tex_size = t.getSize();
	std::vector<sf::Uint8> tex_data(tex_size.x * tex_size.y * 4u, 0u);
	const sf::Vector2f center = sf::Vector2f(tex_size) / 2.f - sf::Vector2f(0.5f, 0.5f);
	for (std::size_t py = 0u; py < tex_size.y; ++py)
	{
		for (std::size_t px = 0u; px < tex_size.x; ++px)
		{
			auto pos = sf::Vector2f(px, py) - center;
			pos.y = -pos.y;

			const auto color = s.isIn(pos) ? foreground_color : background_color;

			const std::size_t pi = py * tex_size.x + px;
			const auto i = pi * 4u;
			tex_data[i] = color.r;
			tex_data[i + 1u] = color.g;
			tex_data[i + 2u] = color.b;
			tex_data[i + 3u] = color.a;
		}
	}
	t.update(tex_data.data());
}

std::shared_ptr<CSG2D::Shape> createCSG2DScene()
{
	//Logo C++
	auto op = CSG2D::OPERATION::DIFFERENCE;
	auto circleBig = std::make_shared<CSG2D::Circle>(sf::Vector2f(0.f, 0.f), 10.f);
	auto circleSmall = std::make_shared<CSG2D::Circle>(sf::Vector2f(0.f, 0.f), 7.f);
	auto cPartOne = std::make_shared<CSG2D::ComplexShape>(circleBig, circleSmall, op, sf::Vector2f(00.f, 00.f));

	op = CSG2D::OPERATION::DIFFERENCE;
	auto rectBig = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(11.f, 0.f), 20.f, 20.f, 3.14f / 4);
	auto cObject = std::make_shared<CSG2D:: ComplexShape>(cPartOne, rectBig, op, sf::Vector2f(-10.f, 0.f));

	op = CSG2D::OPERATION::UNION;
	auto rectHorizontal = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(0, 0), 17.f, 1.f);
	auto rectVertical = std::make_shared<CSG2D::Rectangle>(sf::Vector2f(0, 0), 3.f, 10.f);

	auto plusOne = std::make_shared<CSG2D::ComplexShape>(rectHorizontal, rectVertical, op, sf::Vector2f(00.f, 00.f));
	auto plusTwo = std::make_shared<CSG2D::ComplexShape>(rectHorizontal, rectVertical, op, sf::Vector2f(22.f, 00.f));

	op = CSG2D::OPERATION::UNION;
	auto plusesObject = std::make_shared<CSG2D::ComplexShape>(plusOne, plusTwo, op, sf::Vector2f(0, 00.f));
	auto cppObject = std::make_shared<CSG2D::ComplexShape>(cObject, plusesObject, op, sf::Vector2f(00.f, 10.f));
	return cppObject;
}

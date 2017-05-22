#include <SFML/Graphics.hpp>
#include <iostream>

namespace Tetris {

class TetrisObject {
public:
	TetrisObject() : x(0), y(0)
	{
		auto testShape = new sf::RectangleShape();
		sf::Vector2f shapeSize(std::rand() % 200, 100);
		testShape->setSize(shapeSize);
		testShape->setOutlineThickness(3);
		testShape->setOutlineColor(sf::Color::Black);
		testShape->setFillColor(sf::Color(255, 255, 200));
		testShape->setOrigin(100, 100);

		rect = testShape;
		finished = false;

	}
	~TetrisObject()
	{
		std::cout << "deleted\n";
		delete this->rect;
	}
	uint32_t x;
	uint32_t y;
	bool finished;
	sf::RectangleShape *rect;
};
}

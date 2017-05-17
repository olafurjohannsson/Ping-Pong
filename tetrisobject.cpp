#include <SFML/Graphics.hpp>

class TetrisObject {
public:
	TetrisObject()
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
	uint32_t x = 0;
	uint32_t y = 0;
	bool finished;
	sf::RectangleShape *rect;
};

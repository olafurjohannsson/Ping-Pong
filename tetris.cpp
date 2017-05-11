
#include <SFML/Graphics.hpp>

#include <cmath>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace Tetris {
	class TetrisObject {
	public:
		TetrisObject()
		{
			auto testShape = new sf::RectangleShape();
			sf::Vector2f shapeSize(25, 100);
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
			//delete this->rect;
		}
		uint32_t x = 0;
		uint32_t y = 0;
		bool finished;
		sf::RectangleShape *rect;
	};
	constexpr double pi() { return std::atan(1)*4; }

	const std::string currentDateTime() {
	    time_t     now = time(0);
	    struct tm  tstruct;
	    char       buf[80];
	    tstruct = *localtime(&now);
	    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
	    // for more information about date/time format
	    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	    return buf;
	}

	class Game {

	public:
		Game(uint32_t gameWidth = 800, uint32_t gameHeight = 600) :
            gameWidth(gameWidth), gameHeight(gameHeight),
			window(NULL), isPlaying(false)
		{
			sf::VideoMode vm(this->gameWidth, this->gameHeight, 32);
			std::string name = "Tetris";
            
            this->window = new sf::RenderWindow(vm, name,
					sf::Style::Titlebar | sf::Style::Close);
            
            

		}
        ~Game()
        {
            delete this->window;
        }

		void test()
		{
			std::stringstream ss;
			ss << "Game started at ";
		    ss << Tetris::currentDateTime() << std::endl;
		    std::cout << ss.str();



		}

		bool showMessage(std::string message, sf::RenderWindow &rf)
		{
			try {
				rf.clear(sf::Color(50, 200, 50));
				sf::Text initScreenMessage;
				sf::Font font;
				if (!font.loadFromFile("resources/sansation.ttf"))
					return false;
				initScreenMessage.setFont(font);
				initScreenMessage.setCharacterSize(40);
				initScreenMessage.setPosition(this->gameWidth / 2, this->gameHeight / 2);
				initScreenMessage.setString(std::move(message));
				rf.draw(initScreenMessage);
			}
			catch (...) {
				return false;
			}
			return false;
		}

		void play()
		{

			auto testShape = new Tetris::TetrisObject;

		    std::vector<Tetris::TetrisObject*> rectangles;
		    rectangles.push_back(testShape);

		    testShape->x = 100.f, testShape->y = 100.f;
		    // quid pro quo
		    // yes, we like fancy words too
			while (this->window->isOpen())
			{
				sf::Event event;
				while (this->window->pollEvent(event))
				{
					// Window closed or escape key pressed: exit
					if ((event.type == sf::Event::Closed) ||
					   ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
					{
						this->window->close();
						break;
					}

					if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
					{
						if (!this->isPlaying)
						{
							this->isPlaying = true;
							std::cout << "isPlaying true \n";
							this->showMessage("isPlaying true", *this->window);


						}
					}
				}

				this->window->clear(sf::Color(50, 200, 50));

				if (this->isPlaying)
				{
					for (auto shape : rectangles)
					{
						std::cout << "x: " << shape->x << ", y: " << shape->y << std::endl;

						if (shape->finished)
						{
							this->window->draw(*shape->rect);
						}
						else if (shape->y > this->gameHeight)
						{
							shape->finished = true;

							auto newShape = new Tetris::TetrisObject;
							newShape->y = 100.f;
							newShape->x = std::rand() % this->gameWidth;
							rectangles.push_back(newShape);
						}
						else
						{
							shape->rect->setPosition(shape->x, shape->y++);
							this->window->draw(*shape->rect);
						}
					}
				}
				else
				{
					this->showMessage("test", *this->window);
				}

				this->window->display();
			}
		}

    private:
        uint32_t gameWidth;
        uint32_t gameHeight;
        bool isPlaying;
        sf::RenderWindow *window;
        typedef sf::RenderWindow* rw;
	};

}


int main(int argc, char **argv)
{
	Tetris::Game game;

	game.test();
	game.play();


    return EXIT_SUCCESS;
}


#include <SFML/Graphics.hpp>

#include <cmath>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

namespace Tetris {
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

		void play()
		{
		    sf::RectangleShape testShape;
		    sf::Vector2f shapeSize(25, 100);
		    testShape.setSize(shapeSize);
		    testShape.setOutlineThickness(3);
		    testShape.setOutlineColor(sf::Color::Black);
		    testShape.setFillColor(sf::Color(100, 100, 200));
		    testShape.setOrigin(100, 100);


		    sf::Text initScreenMessage;
		    initScreenMessage.setString("test");

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
						}
					}
				}

				this->window->clear(sf::Color(50, 200, 50));

				if (this->isPlaying)
				{
					this->window->draw(testShape);
				}
				else
				{
					this->window->draw(initScreenMessage);
				}

				this->window->display();
			}
		}

    private:
        uint32_t gameWidth;
        uint32_t gameHeight;
        bool isPlaying;
        sf::RenderWindow *window;
	};

}


int main(int argc, char **argv)
{
	Tetris::Game game;

	game.test();
	game.play();


    return EXIT_SUCCESS;
}


#include <SFML/Graphics.hpp>

#include <cmath>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/*
 * Create base TetrisShape class that all tetris shapes inherit from
 *
 * Create 2x2 grid of 1000x1000
 * Create random 4 block cubes and make them traverse the well
 *
 *
 *
 */

namespace Tetris {

	class Piece {
		public:
			uint32_t size_x;
			uint32_t size_y;

		private:
			sf::Vector2f shape_size;
	};

	class Tetrimino {
		
	};


	//constexpr double pi() { return std::atan(1)*4; }

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

	/*
	 *
	 * Game board that pieces are places on
	 */
	class Board
	{
	public:
		Board()
		{

		}



		bool place_shape(sf::RenderWindow &rf, Tetris::TetrisObject shape)
		{
			//*shape.rect->setPosition(100.f, 100.f);
			
			rf.draw(*shape.rect);
			return true;
		}
	private:
		uint32_t size_x;
		uint32_t size_y;
	};

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

		void dispose()
		{

		}

		void play()
		{

			auto testShape = new Tetris::TetrisObject;

		    std::vector<Tetris::TetrisObject*> rectangles;
		    rectangles.push_back(testShape);

		    testShape->x = 100.f, testShape->y = 100.f;
		    enum {
		    	none,
		    	up,
				right,
				down,
				left
		    } key_state = none;
			
			sf::Texture texture;
			texture.loadFromFile("sprites.png");
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

					if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Up))
					{
						key_state = up;
					}
					if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Right))
					{
						std::cout << "right\n";
						key_state = right;
					}
					if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Down))
					{
						key_state = down;
					}
					if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Left))
					{
						std::cout << "left\n";
						key_state = left;
					}

				}

				this->window->clear(sf::Color(50, 200, 50));
				// Declare and load a texture
				for (int x = 0; x < 100; x++)
				{
					for (int y = 0; y < 100; y++)
					{
						sf::Sprite sprite;
						sprite.setTexture(texture);
						sprite.setTextureRect(sf::IntRect(10, 10, 50, 30));
				
						sprite.setColor(sf::Color(255, 255, 255, 200));
						sprite.setPosition(x, y);
						
						this->window->draw(sprite);
					}
				}
				
				
				// Draw it
				

				if (this->isPlaying)
				{
					for (auto shape : rectangles)
					{
						std::cout << "x: " << shape->x << ", y: " << shape->y << std::endl;

						if (event.type == sf::Event::KeyPressed)
						{
							if (key_state == right)
							{
								shape->x++;
							}
							if (key_state == left)
							{
								shape->x--;
							}
							if (key_state == down)
							{
								//shape->y++;
							}
							if (key_state == up)
							{
								//shape->y--;
							}
						}


						if (shape->finished)
						{
							this->window->draw(*shape->rect);
						}
						else
						{
//							rectangles.erase(std::remove_if(rectangles.begin(), rectangles.end(),
//									[&rectangles, &shape](Tetris::TetrisObject* &x)
//									{
//										if (x->x > shape->x)
//										{
//											std::cout << "if (x.x > shape->x)\n";
//
//										}
////										return true;
////									}));

							if (shape->y > this->gameHeight)
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
				}
				else
				{
					this->showMessage("test", *this->window);
				}

				this->window->display();
			}
			for (auto rect : rectangles)
			{
				delete rect;
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




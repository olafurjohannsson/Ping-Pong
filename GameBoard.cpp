
#include <SFML/Graphics.hpp>

namespace Tetris {

typedef sf::RenderWindow* rw_ptr;

class GameBoard
{
public:

    GameBoard();
    ~GameBoard();

    bool draw();

private:
    rw_ptr window;

};

}
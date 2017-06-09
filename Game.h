/*
 * Game.h
 *
 *  Created on: May 23, 2017
 *      Author: olafurj
 */

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>

namespace Tetris {

class Game {
public:
	Game();
	virtual ~Game();
	static void Start();
	static const char* GameName;
private:
	static bool IsExiting();
	static void GameLoop();
	enum GameState {
		Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting
	};
	static GameState _gameState;
	static sf::RenderWindow _mainWindow;


};

} /* namespace Tetris */

#endif /* GAME_H_ */

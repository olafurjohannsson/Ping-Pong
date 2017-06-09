/*
 * Game.cpp
 *
 *  Created on: May 23, 2017
 *      Author: olafurj
 */

#include "Game.h"

namespace Tetris {

Game::Game() {
	// TODO Auto-generated constructor stub

}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::Start(void)
{
	if (_gameState != Uninitialized)
		return;

	_mainWindow.create(sf::VideoMode(1024, 768, 32), Game::GameName);
	_gameState = Game::Playing;

	while (!IsExiting())
		GameLoop();

	_mainWindow.close();
}

bool Game::IsExiting()
{
  if(_gameState == Game::Exiting)
    return true;
  else
    return false;
}

void Game::GameLoop()
{
  sf::Event currentEvent;
  while(_mainWindow.pollEvent(currentEvent))
  {

    switch(_gameState)
    {
      case Game::Playing:
        {
          _mainWindow.clear(sf::Color(255,0,0));
          _mainWindow.display();

          if(currentEvent.key.code == sf::Event::Closed)
            {
              _gameState = Game::Exiting;
            }
          break;
        }
    }
  }
}


Game::GameState Game::_gameState = Uninitialized;
const char* Game::GameName = "Tetris";
sf::RenderWindow Game::_mainWindow;

} /* namespace Tetris */

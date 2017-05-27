

#include <iostream>
#include <string>

#include "helpers.cpp"
#include "game.h"

int main(int argc, char **argv)
{
	try {
		std::cout << "Game started " << Helper::currentDateTime() << std::endl;

		Tetris::Game::Start();

		std::cout << "Game stopped " << Helper::currentDateTime() << std::endl;

	}
	catch (...) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}

#include "Game.h"
#include "PapuEngine.h"

Game::Game()
{
}

bool Game::init() {
	Papu::init();
	SDL_GL_SetAttribute(
				SDL_GL_ACCELERATED_VISUAL, 1);
	initSystems();
	onInit();
	addScreens();
	return true;
}

void Game::exit() {
}

void Game::update() {

}


Game::~Game()
{
}

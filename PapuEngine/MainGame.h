#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "Sprite.h"

enum class GameState
{
	PLAY, EXIT
};


class MainGame
{
private:
	int _witdh;
	int _height;
	SDL_Window* _window;
	void init();
	Sprite _sprite;
	void procesInput();
	
public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void run();
	void draw();
	void update();
};


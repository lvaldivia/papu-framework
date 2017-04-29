#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "GLS_Program.h"
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
	float _time;
	SDL_Window* _window;
	void init();
	Sprite _sprite;
	void procesInput();
	GLS_Program _program;
	
public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void initShaders();
	void run();
	void draw();
	void update();
};


#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "GLS_Program.h"
#include "Sprite.h"
#include <vector>
#include "Window.h"
#include "Camera2D.h"

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
	Camera2D _camera;
	Window _window;
	void init();
	void procesInput();
	GLS_Program _program;
	vector<Sprite*> _sprites;
	
public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void initShaders();
	void run();
	void draw();
	void update();
};


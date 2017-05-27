#pragma once
#include <SDL\SDL.h>
#include <GL\glew.h>
#include "GLS_Program.h"
#include "Sprite.h"
#include "Window.h"
#include "Camera2D.h"
#include <vector>
#include "InputManager.h"

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
	Window _window;
	InputManager _inputManager;
	void init();
	void procesInput();
	void handleInput();
	GLS_Program _program;
	vector<Sprite*> _sprites;
	Camera2D _camera;
	const float CAMERA_SPEED = 0.05f;
	const float SCALE_SPEED = 0.1f;
	
public:
	MainGame();
	~MainGame();
	GameState _gameState;
	void initShaders();
	void run();
	void draw();
	void update();
};


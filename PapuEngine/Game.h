#pragma once
#include "Window.h"
#include "InputManager.h"
class ScreenList;
class IGameScreen;

class Game
{
protected:
	bool init();
	void update();
	void draw();
	bool initSystems();
	bool _isRunning = false;
	Window _window;
	InputManager _inputManager;
public:
	Game();
	virtual ~Game();
	void run();
	void exit();
	virtual void onInit() = 0;
	virtual void addScreens() = 0;
	virtual void onExit() = 0;
	void onSDLEvent(SDL_Event& event);
	IGameScreen* _currentScreen = nullptr;
	
};


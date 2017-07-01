#pragma once

#include <SDL\SDL.h>
#include "IGameScreen.h"
#include <Box2D\Box2D.h>
#include "Camera2D.h"
#include "GLS_Program.h"
#include "Window.h"
#include "GLTexture.h"
#include "SpriteBacth.h"
#include "GUI.h"

class GamePlayScreen : public IGameScreen
{
private:
	GLS_Program _program;
	Camera2D _camera2d;
	Window* _window = nullptr;
	SpriteBacth _spriteBatch;
	GLTexture _texture;
	GUI _gui;
	
	std::unique_ptr<b2World> _world;

public:
	GamePlayScreen(Window* window);
	~GamePlayScreen();
	bool onExitClicked();
	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;
	void initWorld();
	virtual void initGUI()override;
	virtual void draw()override;
	virtual void update()override;
	virtual void initSystem() override;
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;
	virtual void checkInput() override;
};


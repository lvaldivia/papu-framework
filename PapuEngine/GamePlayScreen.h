#pragma once

#include <SDL\SDL.h>
#include "IGameScreen.h"
#include <Box2D\Box2D.h>
#include "Camera2D.h"
#include "GLS_Program.h"
#include "Window.h"
#include "GLTexture.h"
#include "SpriteBacth.h"
#include "SpriteFont.h"
#include "GUI.h"
#include "Level.h"
#include "Human.h"
#include "Zombie.h"
#include "Agent.h"
#include "Player.h"
#include <vector>

class GamePlayScreen : public IGameScreen
{
private:
	GLS_Program _program;
	Camera2D _camera2d;
	Window* _window = nullptr;
	SpriteBacth _spriteBatch;
	GLTexture _texture;
	GUI _gui;
	int _currentLevel;
	vector<Level*> _levels;
	std::unique_ptr<b2World> _world;
	vector<Human*>  _humans;
	vector<Zombie*> _zombies;
	Player* _player;
	SpriteFont* _spriteFont;
	SpriteBacth  _hudSpriteBatch;
	Camera2D _hudCamera;
	void drawHud();

public:
	GamePlayScreen(Window* window);
	~GamePlayScreen();
	bool onExitClicked();
	void initWorld();
	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;
	
	virtual void initGUI()override;
	virtual void draw()override;
	virtual void update()override;
	virtual void initSystem() override;
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;
	virtual void checkInput() override;
};


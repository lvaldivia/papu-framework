#pragma once
#include "IGameScreen.h"
#include "Window.h"
#include "SpriteBacth.h"
#include "GUI.h"

class MenuScreen : public IGameScreen
{
private:
	Window* _window = nullptr;
	SpriteBacth _spriteBatch;
	bool onGameClicked(const CEGUI::EventArgs& e);
	bool onExitClicked(const CEGUI::EventArgs& e);
	GUI _gui;
public:
	MenuScreen(Window* window);
	virtual void build() override;
	virtual void destroy() override;
	virtual void onExit() override;
	virtual void onEntry() override;
	virtual void update() override;
	virtual void draw() override;
	virtual int getNextScreen() const override;
	virtual int getPreviousScreen() const override;
	virtual void checkInput() override;
	~MenuScreen();
};


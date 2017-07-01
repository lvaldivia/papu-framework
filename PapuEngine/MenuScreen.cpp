#include "MenuScreen.h"


MenuScreen::MenuScreen(Window* window) :
	_window(window)
{
}

MenuScreen::~MenuScreen()
{
}
bool MenuScreen::onGameClicked(const CEGUI::EventArgs& e)
{
	_currentState = ScreenState::CHANGE_NEXT;
	return true;
}
bool MenuScreen::onExitClicked(const CEGUI::EventArgs& e)
{
	_currentState = ScreenState::EXIT_APPLICATION;
	return true;
}

void MenuScreen::build() {

}
void MenuScreen::destroy() {
	_gui.destroy();
}
void MenuScreen::onExit() {

}
void MenuScreen::onEntry() {

}
void MenuScreen::update() {

}
void MenuScreen::draw() {

}
int MenuScreen::getNextScreen()const {
	return -1;
}
int MenuScreen::getPreviousScreen() const{
	return -1;
}
void MenuScreen::checkInput() {

}



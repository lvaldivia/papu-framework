#include "MenuScreen.h"
#include "ScreenIndices.h"

MenuScreen::MenuScreen(Window* window) :
	_window(window)
{
	_screenIndex = SCREEN_INDEX_MENU;
}

void MenuScreen::initGUI() {
	_gui.init("GUI");
	_gui.loadScheme("TaharezLook.scheme");
	_gui.loadScheme("AlfiskoSkin.scheme");

	
	_gui.setFont("DejaVuSans-10");
	CEGUI::PushButton* gameButton =
		static_cast<CEGUI::PushButton*>(
			_gui.createWidget("AlfiskoSkin/Button",
				glm::vec4(0.45f, 0.45f, 0.1f, 0.05f), glm::vec4(0.0f),
				"Game Button"));
	gameButton->setText("Game");
	gameButton->subscribeEvent(CEGUI::PushButton::EventClicked,
		CEGUI::Event::Subscriber(&MenuScreen::onGameClicked, this));

	CEGUI::PushButton* exitButton =
		static_cast<CEGUI::PushButton*>(
			_gui.createWidget("AlfiskoSkin/Button",
				glm::vec4(0.45f, 0.65f, 0.1f, 0.05f), glm::vec4(0.0f),
				"Exit Button"));
	exitButton->setText("Exit");
	exitButton->subscribeEvent(CEGUI::PushButton::EventClicked,
		CEGUI::Event::Subscriber(&MenuScreen::onExitClicked, this));
}

void MenuScreen::initSystem() {
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
	initGUI();
}
void MenuScreen::update() {
	checkInput();
}
void MenuScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_gui.draw();
}
int MenuScreen::getNextScreen()const {
	return SCREEN_INDEX_GAMEPLAY;
}
int MenuScreen::getPreviousScreen() const{
	return SCREEN_INDEX_NO_SCREEN;
}
void MenuScreen::checkInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		_gui.onSDLEvent(evnt);
	}
}



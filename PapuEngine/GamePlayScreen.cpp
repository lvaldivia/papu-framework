#include "GamePlayScreen.h"
#include "Game.h"
#include "ScreenIndices.h"

bool GamePlayScreen::onExitClicked()
{
	_currentState = ScreenState::EXIT_APPLICATION;
	return true;
}

GamePlayScreen::GamePlayScreen(Window* window):
	_window(window)
{
	_screenIndex = SCREEN_INDEX_GAMEPLAY;
}


GamePlayScreen::~GamePlayScreen()
{
}


void GamePlayScreen::build() {

}
void GamePlayScreen::destroy() {

}
void GamePlayScreen::onExit() {
}

void GamePlayScreen::onEntry() {
	initWorld();
	initSystem();
	_spriteBatch.init();
	initGUI();
	_camera2d.init(_window->getScreenWidth(),
		_window->getScreenHeight());
}

void GamePlayScreen::initWorld() {
	b2Vec2 gravity(0.0f, -0.8f);
	_world = std::make_unique<b2World>(gravity);
	b2BodyDef grounDef;
	grounDef.position.Set(0.0f, -30.0f);
	b2Body* groundBody = _world->CreateBody(&grounDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(10.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);
}

void GamePlayScreen::initGUI()
{
	_gui.init("GUI");
	_gui.loadScheme("TaharezLook.scheme");
	_gui.loadScheme("AlfiskoSkin.scheme");
	CEGUI::PushButton* testButton =
		static_cast<CEGUI::PushButton*>(
		_gui.createWidget("AlfiskoSkin/Button",
			glm::vec4(0.5f, 0.5f, 0.1f, 0.05f), glm::vec4(0.0f), 
			"Test Button"));

	testButton->subscribeEvent(
		CEGUI::PushButton::EventClicked,
		CEGUI::Event::Subscriber(
			&GamePlayScreen::onExitClicked, this)

	);


	_gui.setMouseCursor("AlfiskoSkin/MouseArrow");
	_gui.showMouseCursor();
	SDL_ShowCursor(0);

	CEGUI::Combobox* testCombo = static_cast<CEGUI::Combobox*>
		(_gui.createWidget("TaharezLook/Combobox",
			glm::vec4(0.2f, 0.5f, 0.1f, 0.05f), glm::vec4(0.0f),
			"Combobox"));

}

void GamePlayScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();
	_spriteBatch.begin();
	_spriteBatch.end();
	_spriteBatch.renderBatch();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();
	_gui.draw();
}
void GamePlayScreen::update() {
	checkInput();
}

void GamePlayScreen::initSystem()
{
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}


void GamePlayScreen::checkInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		_game->onSDLEvent(evnt);
		_gui.onSDLEvent(evnt);
	}
}

int GamePlayScreen::getNextScreen() const {
	return SCREEN_INDEX_NO_SCREEN;
};

int GamePlayScreen::getPreviousScreen() const {
	return SCREEN_INDEX_MENU;
}

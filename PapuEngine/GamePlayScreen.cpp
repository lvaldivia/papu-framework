#include "GamePlayScreen.h"
#include "Game.h"
#include "ScreenIndices.h"

#include "ResourceManager.h"
#include <random>


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
	_texture = ResourceManager::getTexture("Textures/red_bricks.png");
	std::mt19937 randomGenerator;
	std::uniform_real_distribution<float>xPos(-10.0f, 10.0f);
	std::uniform_real_distribution<float>yPos(-5.0f, 15.0f);
	std::uniform_real_distribution<float>size(0.5f, 2.5f);

	const int NUM_BOXES = 50;

	for (int i = 0; i < NUM_BOXES; i++)
	{
		Block block;
		block.init(_world.get(), glm::vec2(xPos(randomGenerator), 
			yPos(randomGenerator)),
			glm::vec2(size(randomGenerator)
						,size(randomGenerator)), _texture,
			ColorRGBA(255, 255, 255, 255), true);

		_blocks.push_back(block);
	}

	initSystem();

	_spriteBatch.init();
	_hudBatch.init();

	initGUI();

	_camera2d.init(_window->getScreenWidth(),
		_window->getScreenHeight());
	_camera2d.setScale(32.0f);

	_hudCamera.init(_window->getScreenWidth(),
		_window->getScreenHeight());
	_hudCamera.setPosition(
		glm::vec2(_window->getScreenWidth() / 2.0f,
				_window->getScreenHeight() / 2.0f));

	_spriteFont = new SpriteFont("Fonts/arial.ttf",64);
}

void GamePlayScreen::initWorld() {
	b2Vec2 gravity(0.0f, -0.08f);
	_world = std::make_unique<b2World>(gravity);
	b2BodyDef grounDef;
	grounDef.position.Set(0.0f, -15.0f);
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
	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera2d.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	_spriteBatch.begin();

	for (auto& b: _blocks) {
		b.draw(_spriteBatch);
	}
	_spriteBatch.end();
	_spriteBatch.renderBatch();

	drawHUD();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	_gui.draw();
}
void GamePlayScreen::update() {
	_camera2d.update();
	_hudCamera.update();
	_world->Step(1.0f / 60.f, 6, 2);
	checkInput();
}

void  GamePlayScreen::drawHUD() {
	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _hudCamera.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	char buffer[256];

	_hudBatch.begin();
	sprintf_s(buffer, " HOLA %d", 10);
	_spriteFont->draw(_hudBatch, buffer, glm::vec2(0, 0),
		glm::vec2(0.5), 0.0f, ColorRGBA(255, 255, 255, 255));
	sprintf_s(buffer, " HOLA2 %d", 10);
	_spriteFont->draw(_hudBatch, buffer, glm::vec2(0, 36),
		glm::vec2(0.5), 0.0f, ColorRGBA(255, 255, 255, 255));
	_hudBatch.end();
	_hudBatch.renderBatch();

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

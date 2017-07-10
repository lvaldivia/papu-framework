#include "GamePlayScreen.h"
#include "Game.h"
#include "ScreenIndices.h"
#include <random>
#include <ctime>

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
	_currentLevel = 0;
	_levels.push_back(new Level("Levels/level1.txt"));
	_spriteBatch.init();
	_hudSpriteBatch.init();
	initGUI();
	_spriteFont = new SpriteFont("Fonts/arial.ttf", 64);
	_camera2d.init(_window->getScreenWidth(),
		_window->getScreenHeight());

	
	_player = new Player();
	_player->init(1.0f, _levels[_currentLevel]->getPlayerPosition(), &_game->_inputManager, &_camera2d);
	_humans.push_back(_player);

	const std::vector<glm::vec2>& zombiePosition =
		_levels[_currentLevel]->getZombiesPosition();

	for (size_t i = 0; i < zombiePosition.size(); i++)
	{
		_zombies.push_back(new Zombie());
		_zombies.back()->init(1.3f, zombiePosition[i]);
	}

	std::mt19937 randomEngine(time(nullptr));
	std::uniform_int_distribution<int>randPosX(
		1, _levels[_currentLevel]->getWidth() - 2);
	std::uniform_int_distribution<int>randPosY(
		1, _levels[_currentLevel]->getHeight() - 2);

	for (int i = 0; i < _levels[_currentLevel]->getNumHumans(); i++)
	{
		_humans.push_back(new Human());
		glm::vec2 pos(randPosX(randomEngine)*TILE_WIDTH,
			randPosY(randomEngine)*TILE_WIDTH);
		_humans.back()->init(1.0f, pos);
	}
}

void GamePlayScreen::drawHud() {
	char buffer[256];

	glm::mat4 projectionMatrix = _hudCamera.getCameraMatrix();
	GLint pUniform = _program.getUniformLocation("P");
	glUniformMatrix4fv(pUniform, 1, GL_FALSE, &projectionMatrix[0][0]);
	_hudSpriteBatch.begin();
	sprintf_s(buffer, "Num Humans %d",10);
	_spriteFont->draw(_hudSpriteBatch, buffer, glm::vec2(0, 0),
		glm::vec2(0.5), 0.0f, ColorRGBA(255, 255, 255, 255));

	sprintf_s(buffer, "Num Zombies %d", 10);
	_spriteFont->draw(_hudSpriteBatch, buffer, glm::vec2(0, 36),
		glm::vec2(0.5), 0.0f, ColorRGBA(255, 255, 255, 255));
	_hudSpriteBatch.end();
	_hudSpriteBatch.renderBatch();

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
}

void GamePlayScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();
	_spriteBatch.begin();
	_levels[_currentLevel]->draw();
	for (size_t i = 0; i < _humans.size(); i++)
	{
		_humans[i]->draw(_spriteBatch);
	}

	for (size_t i = 0; i < _zombies.size(); i++)
	{
		_zombies[i]->draw(_spriteBatch);
	}


	_spriteBatch.end();
	_spriteBatch.renderBatch();
	glActiveTexture(GL_TEXTURE0);
	GLuint pLocation =
		_program.getUniformLocation("P");

	glm::mat4 cameraMatrix = _camera2d.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));
	//drawHud();
	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();
	//_gui.draw();
}
void GamePlayScreen::update() {
	checkInput();
	_camera2d.update();
	
	for (size_t i = 0; i < _humans.size(); i++)
	{

		_humans[i]->update(_levels[_currentLevel]->getLevelData(), _humans, _zombies);
	}

	for (size_t i = 0; i < _zombies.size(); i++)
	{
		_zombies[i]->update(_levels[_currentLevel]->getLevelData(),
			_humans, _zombies);
	}

	_camera2d.setPosition(_player->getPosition());

	_hudCamera.update();
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

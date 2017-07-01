#include "GamePlayScreen.h"
#include "Game.h"

GamePlayScreen::GamePlayScreen(Window* window):
	_window(window)
{
	
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
	b2Vec2 gravity(0.0f, -0.8f);
	_world = std::make_unique<b2World>(gravity);

	b2BodyDef grounDef;
	grounDef.position.Set(0.0f, -30.0f);
	b2Body* groundBody = _world->CreateBody(&grounDef);
	b2PolygonShape groundBox;
	groundBox.SetAsBox(10.0f, 10.0f);
	groundBody->CreateFixture(&groundBox, 0.0f);

	_program.compileShaders("Shaders/ColorRGBAShaderVert.txt",
		"Shaders/ColorRGBAShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColorRGBA");
	_program.addAtribute("vertexUV");
	_program.linkShader();

	_spriteBatch.init();
	_camera2d.init(_window->getScreenWidth(),
		_window->getScreenHeight());
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
}
void GamePlayScreen::update() {
	checkInput();
}

void GamePlayScreen::checkInput() {
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		_game->onSDLEvent(evnt);
	}
}

int GamePlayScreen::getNextScreen() const {
	return -1;
};

int GamePlayScreen::getPreviousScreen() const {
	return -1;
}

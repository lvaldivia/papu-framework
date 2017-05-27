#include "MainGame.h"
#include "Sprite.h"
#include "ImageLoader.h"
#include "Engine.h"



void MainGame::run() {
	init();
	_sprites.push_back(new Sprite());
	_sprites.back()->init(-1, -1, 1, 1, "Textures/Paper_Mario_.png");

	_sprites.push_back(new Sprite());
	_sprites.back()->init(0, -1, 1, 1, "Textures/Paper_Mario_.png");
	update();
}
void MainGame::init() {
	Papu::init();
	_window.create("Papu", _witdh, _height, 0);
	initShaders();
}

void MainGame::initShaders() {
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}


void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();

	glActiveTexture(GL_TEXTURE0);
	//glBindTexture(GL_TEXTURE_2D, _texture.id);

	GLuint timeLocation = 
		_program.getUniformLocation("time");

	glUniform1f(timeLocation,_time);

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 2);
	_time+=0.0002;

	glm::mat4 cameraMatrix = _camera.getCameraMatrix();
	GLuint pLocation =
		_program.getUniformLocation("P");

	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	

	for (int i = 0; i < _sprites.size(); i++)
	{
		_sprites[i]->draw();
	}
	_program.unuse();
	_window.swapWindow();
}

void MainGame::procesInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
			case SDL_MOUSEMOTION:
			break;
		}
	}

}

void MainGame::update() {

	while (_gameState != GameState::EXIT) {
		procesInput();
		draw();
		_camera.update();
	}
}


MainGame::MainGame(): _witdh(800),
					  _height(600),
					  _gameState(GameState::PLAY),
					  _time(0)
{
	_camera.init(_witdh, _height);
}


MainGame::~MainGame()
{
}

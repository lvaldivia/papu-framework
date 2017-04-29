#include "MainGame.h"
#include "Sprite.h"

void MainGame::run() {
	init();
	_sprite.init(-1,-1,1,1);
	update();
}
void MainGame::init() {

	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Papu engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _witdh, _height, SDL_WINDOW_OPENGL);
	if (_window == nullptr) {
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	
	GLenum error = glewInit();
	if (error != GLEW_OK) {

	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	initShaders();
}

void MainGame::initShaders() {
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.linkShader();
}


void MainGame::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();
	_sprite.draw();
	_program.unuse();
	SDL_GL_SwapWindow(_window);
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
		
	}
}


MainGame::MainGame()
{
	_window = nullptr;
	_witdh = 800;
	_height = 600;
	_gameState = GameState::PLAY;
}


MainGame::~MainGame()
{
}

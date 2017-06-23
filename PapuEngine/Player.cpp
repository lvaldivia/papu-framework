#include "Player.h"
#include <SDL\SDL.h>


void Player::init(float speed, glm::vec2 position, InputManager* inputManager, Camera2D* camera) {
	_speed = speed;
	_position = position;
	_camera = camera;
	_inputManager = inputManager;
	color.set(0, 0, 185, 255);
}
void Player::update(const std::vector<std::string>& levelData,
	std::vector<Human*>& humans,
<<<<<<< HEAD
	std::vector<Zombie*>& zombies) {
	if (_inputManager->isKeyDown(SDLK_w)) {
=======
	std::vector<Zombie*>& zombies,
	std::vector<Bullet>& bullets
	) {
	if (_inputManager->isKeyPressed(SDLK_w)) {
>>>>>>> 0fd86f4c6b69ea1352a0b34799d2f7dbe1c4f137
		_position.y += _speed;
	}
	if (_inputManager->isKeyDown(SDLK_s)) {
		_position.y -= _speed;
	}
	if (_inputManager->isKeyDown(SDLK_a)) {
		_position.x -= _speed;
	}
	if (_inputManager->isKeyDown(SDLK_d)) {
		_position.x += _speed;
	}
	collideWithLevel(levelData);

	if (_inputManager->isKeyPressed(SDLK_1) && _guns.size() >= 0) {
		_currentGun = 0;
	}
	else if (_inputManager->isKeyPressed(SDLK_2) && _guns.size() >= 1) {
		_currentGun = 1;
	}
	else if (_inputManager->isKeyPressed(SDLK_3) && _guns.size() >= 2) {
		_currentGun = 2;
	}

	if (_currentGun != -1) {
		glm::vec2 mouseCoords = _camera->convertScreenToWorl(_inputManager->getMouseCoords());
		glm::vec2 centerPos = _position * glm::vec2(AGENT_RADIUS);
		glm::vec2 direction = glm::normalize(mouseCoords - centerPos);
		_guns[_currentGun]->update(_inputManager->isKeyPressed(SDL_BUTTON_LEFT),
			centerPos, direction,bullets);
	}
}


void Player::addGun(Gun* gun) {
	_guns.push_back(gun);
	if (_currentGun == -1) {
		_currentGun = 0;
	}
}


Player::Player():_currentGun(-1)
{
}


Player::~Player()
{
}

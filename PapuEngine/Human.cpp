#include "Human.h"
#include <random>
#include <glm\gtx\rotate_vector.hpp>
#include <ctime>

Human::Human():_frames(0)
{
}

void Human::init(float speed, glm::vec2 pos) {
	_speed = speed;
	color.set(255, 0, 0, 255);
	_position = pos;
	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float>randDir(-1.0f, 1.0f);
	
	_direction = glm::vec2(randDir(randomEngine), randDir(randomEngine));
	if (_direction.length() == 0) {
		_direction = glm::vec2(1.0f, 1.0f);
	}
	_direction = glm::normalize(_direction);
}

void Human::update(const std::vector<std::string>& levelData, std::vector<Human*>& humans,
	std::vector<Zombie*> zombies) {

	static std::mt19937 randomEngine(time(nullptr));
	static std::uniform_real_distribution<float>randRotate(-40.0f, 40.0f);

	_position += _direction * _speed;
	/*if (_frames == 100) {
		_direction = glm::rotate(_direction, randRotate(randomEngine));
		_frames = 0;
	}
	else {
		_frames++;
	}*/

	if (collideWithLevel(levelData)) {
		_direction = glm::rotate(_direction, randRotate(randomEngine));
	}
	
	collideWithLevel(levelData);
}

Human::~Human()
{
}

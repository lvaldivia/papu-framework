#include "Human.h"
#include <random>


Human::Human()
{
}

void Human::init(float speed, glm::vec2 position) {
	_speed = speed;
	color.set(185, 0, 0, 255);
	_position = position;

	static 
}

void Human::update(const std::vector<std::string>& levelData,
	std::vector<Human*>& humans,
	std::vector<Zombie*>& zombies) {

}

Human::~Human()
{
}

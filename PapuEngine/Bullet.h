#pragma once
#include <glm/glm.hpp>
#include "SpriteBacth.h"


class Human;
class Zombie;
const int BULLET_RADIUS = 5;

class Bullet


{
private:
	float _speed;
	glm::vec2 _direction;
	glm::vec2 _position;
	float _damage;
public:
	Bullet(glm::vec2 position, glm::vec2 diection, float damage, float speed);
	~Bullet();
	void draw(SpriteBacth& spriteBatch);
	void update(std::vector<Human*>& humans,
		std::vector<Zombie*>& zombies);

};


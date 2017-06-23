#include "Bullet.h"
#include "ResourceManager.h"
#include "GLTexture.h"
#include "ResourceManager.h"




void Bullet::draw(SpriteBacth& spriteBatch) {
	glm::vec4 destRect(_position.x + BULLET_RADIUS, _position.y + BULLET_RADIUS, BULLET_RADIUS * 2, BULLET_RADIUS * 2);
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);

	Color color;
	color.set(75, 75, 75, 255);
	spriteBatch.draw(destRect, uvRect, ResourceManager::getTexture("Textures/circle.png").id, 0.0f, color);
}

Bullet::Bullet(glm::vec2 position, glm::vec2 direction, float damage, float speed)
{
	_damage = damage;
	_position = position;
	_direction = direction;
	_speed = speed;
}

void Bullet::update(std::vector<Human*>& humans,
	std::vector<Zombie*>& zombies) {
	_position += _direction * _speed;
}

Bullet::~Bullet()
{
}

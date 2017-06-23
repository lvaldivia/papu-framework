#pragma once
#include <string>
#include <glm/glm.hpp>
#include <vector>
#include "Bullet.h"

class Gun
{
private:
	int _fireRate;
	float _spread;
	int _bulletsPerShot;
	std::string _name;
	float _bulletSpeed;
	float _bulletDamage;
	int _frameCounter;
	void fire(const glm::vec2& direction, const glm::vec2& position, std::vector<Bullet>& bullets);
public:
	Gun(std::string name, int fireRate, int bulletPersShot,float spread, float bulletDamage, float bulletSpeed);
	~Gun();
	void update(bool isMouseDown, const glm::vec2& position, const glm::vec2& direction, std::vector<Bullet>& bullets);
	
};


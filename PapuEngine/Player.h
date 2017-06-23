#pragma once
#include "Human.h"
#include "InputManager.h"
#include "Gun.h"
#include <vector>
#include "Camera2D.h"
#include "Bullet.h"

class Player: public Human
{
private:
	InputManager* _inputManager;
	int _currentGun;
	std::vector<Gun*> _guns;
	Camera2D* _camera;
public:
	Player();
	~Player();
	void addGun(Gun* gun);
	void init(float speed, glm::vec2 position, InputManager* inputManager, Camera2D* camera);
	void update(const std::vector<std::string>& levelData,
		std::vector<Human*>& humans,
		std::vector<Zombie*>& zombies,
		std::vector<Bullet>& bullets );
};


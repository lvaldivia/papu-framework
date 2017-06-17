#pragma once
#include "Agent.h"
class Zombie :public Agent
{
public:
	Zombie();
	void init(float speed, glm::vec2 position);
	void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans,
		std::vector<Zombie*> zombies);
	~Zombie();
	Human* getNearestHuman(std::vector<Human*>& humans);
};


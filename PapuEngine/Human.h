#pragma once
#include "Agent.h"

class Human : public Agent
{
private:
	glm::vec2 _direction;
	int _frames;
public:
	Human();
	void init(float speed, glm::vec2 pos);
	virtual void update(const std::vector<std::string>& levelData, std::vector<Human*>& humans,
		std::vector<Zombie*> zombies);
	~Human();
};


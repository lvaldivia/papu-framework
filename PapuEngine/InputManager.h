#pragma once
#include <glm\glm.hpp>
#include <unordered_map>

class InputManager

{
private:
	std::unordered_map<unsigned int, bool> _keys;
	glm::vec2 _mouseCoords;

public:
	InputManager();
	glm::vec2 getMouseCoords() const {
		return _mouseCoords;
	}
	void setMouseCoords(float x, float y);
	void pressKey(unsigned int keyCode);
	void releaseKey(unsigned int keyCode);
	bool isKeyPressed(unsigned int keycode);
	~InputManager();
};


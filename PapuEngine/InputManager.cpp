#include "InputManager.h"



InputManager::InputManager():_mouseCoords(0.0f,0.0f)
{
}

void InputManager::setMouseCoords(float x, float y) {
	_mouseCoords.x = x;
	_mouseCoords.y = y;
}
void InputManager::pressKey(unsigned int keyCode) {
	_keys[keyCode] = true;
}
void InputManager::releaseKey(unsigned int keyCode) {
	_keys[keyCode] = false;
}
bool InputManager::isKeyPressed(unsigned int keycode) {
	auto it = _keys.find(keycode);
	if (it != _keys.end()) {
		return it->second;
	}
	return false;
}

InputManager::~InputManager()
{
}

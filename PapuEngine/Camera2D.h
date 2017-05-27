#pragma once
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

class Camera2D
{
private:
	glm::vec2 _position;
	float _scale;
	int _screenWidth;
	int _screenHeight;
	bool _needsUpdateMatrix;
	glm::mat4 _cameraMatrix;
	glm::mat4 _orthoMatrix;

public:
	void update();
	void init(int screenWidth, int screenHeight);

	glm::vec2 getPosition() {return _position;}

	void setPosition(const glm::vec2& newPosition) {
		_position = newPosition;
		_needsUpdateMatrix = true;
	}
	void setScale(float newScale) {
		_scale = newScale;
		_needsUpdateMatrix = true;
	}

	glm::mat4 getCameraMatrix() {
		return _cameraMatrix;
	}


	Camera2D();
	~Camera2D();
};


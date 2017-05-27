#include "Camera2D.h"

void Camera2D::init(int screenWidth, int screenHeight) {
	_screenHeight = screenHeight;
	_screenWidth = screenWidth;
	_orthoMatrix = glm::ortho(0.0f, (float)_screenWidth, 
							0.0f, (float)_screenHeight);
}

void Camera2D::update() {
	if (_needsUpdateMatrix) {
		glm::vec3 translate(-_position.x, 
							-_position.y, 0.0f);
		_cameraMatrix = glm::translate(_orthoMatrix, translate);
		glm::vec3 scale(_scale, _scale, 0.0f);
		_needsUpdateMatrix = false;
	}
}

Camera2D::Camera2D():_scale(1.0f),
					_screenWidth(500),
					_screenHeight(500),
					_cameraMatrix(1.0f)
{
}


Camera2D::~Camera2D()
{
}

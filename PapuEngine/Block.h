#pragma once
#include <Box2D\Box2D.h>
#include <glm\glm.hpp>
#include "Vertex.h"
#include "SpriteBacth.h"
#include "GLTexture.h"


class Block
{
public:
	Block();

	void init(b2World* world, 
			  const glm::vec2& position,
			const glm::vec2& dimensions,
			GLTexture texture,
			ColorRGBA color,
			bool isDynamic,
			float angle = 0.0f,
			glm::vec4 uvRect = glm::vec4(0.0f,0.0f,1.0f,1.0f));
	void destroy(b2World* world);
	void draw(SpriteBacth& spriteBatch);
	~Block();
private:
	glm::vec4 _uvRect;
	glm::vec2 _position;
	b2Body* _body = nullptr;
	b2Fixture* _fixture = nullptr;
	ColorRGBA _color;
	glm::vec2 _dimensions;
	GLTexture _texture;
};


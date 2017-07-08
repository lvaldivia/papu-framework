#include "Block.h"



Block::Block()
{
}


void Block::init(b2World* world,
	const glm::vec2& position,
	const glm::vec2& dimensions,
	GLTexture texture,
	ColorRGBA color,
	bool isDynamic,
	float angle,
	glm::vec4 uvRect) {
	_dimensions = dimensions;
	_position = position;
	_texture = texture;
	_color = color;
	_uvRect = uvRect;

	b2BodyDef bodyDef;
	if (isDynamic) {
		bodyDef.type = b2_dynamicBody;
	}
	else {
		bodyDef.type = b2_staticBody;
	}
	bodyDef.position.Set(_position.x, _position.y);
	_body = world->CreateBody(&bodyDef);
	b2PolygonShape boxShape;
	boxShape.SetAsBox(dimensions.x / 2.0f, dimensions.y / 2.0f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	_fixture = _body->CreateFixture(&fixtureDef);
}
void Block::destroy(b2World* world) {
	world->DestroyBody(_body);
}
void Block::draw(SpriteBacth& spriteBatch) {
	glm::vec4 descRect;
	descRect.x = _body->GetPosition().x - _dimensions.x / 2.0f;
	descRect.y = _body->GetPosition().y - _dimensions.y / 2.0f;
	descRect.z = _dimensions.x;
	descRect.w = _dimensions.y;
	spriteBatch.draw(descRect, _uvRect, _texture.id, 0.0f, _color);

}


Block::~Block()
{
}

#include "Sprite.h"
#include "Vertex.h"
#include <cstddef>

Sprite::Sprite()
{
	_vobID = 0;
}

void Sprite::init(float x, float y, int width ,int height)
{
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	if (_vobID == 0) {
		glGenBuffers(1, &_vobID);
	}

	Vertex vertexData[6];

	vertexData[0].setPosition(_x + _width, _y + _height);
	vertexData[1].setPosition(_x, _y + _height);
	vertexData[2].setPosition(_x, _y);
	vertexData[3].setPosition(_x, _y);
	vertexData[4].setPosition(_x + _width, _y);
	vertexData[5].setPosition(_x + _width, _y + _height);


	for (int i = 0; i < 6; i++)
	{
		vertexData[i].setColor(255, 0, 0, 255);
	}

	vertexData[1].setColor(0, 0, 255, 255);
	vertexData[4].setColor(0, 255, 0, 255);

	glBindBuffer(GL_ARRAY_BUFFER, _vobID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), 
					vertexData, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, _vobID);
	glEnableVertexAttribArray(0);
	//primer atributo position
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
							(void*)offsetof(Vertex,position));

	//segundo atributo color
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex),
		(void*)offsetof(Vertex, color));

	glDrawArrays(GL_TRIANGLES,0,6);
	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Sprite::~Sprite()
{
	if (_vobID != 0) {
		glDeleteBuffers(1, &_vobID);
	}
}

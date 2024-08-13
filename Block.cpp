#include "Block.h"

Block::Block(float t_X, float t_Y, float t_Width, float t_Height)
{
	shape_1.setPosition(t_X, t_Y);
	shape_1.setSize({ t_Width,t_Height });
	shape_1.setFillColor(Color::Yellow);
	shape_1.setOrigin(t_Width / 2.f, t_Height / 2.f);
}

Block::Block()
{
}


Vector2f Block::getPosition()
{
	return shape_1.getPosition();
}

float Block::left()
{
	return this->shape_1.getPosition().x - shape_1.getSize().x / 2.f;
}

float Block::right()
{
	return this->shape_1.getPosition().x + shape_1.getSize().x / 2.f;
}

float Block::top()
{
	return this->shape_1.getPosition().y - shape_1.getSize().y / 2.f;
}

float Block::bottom()
{
	return this->shape_1.getPosition().y + shape_1.getSize().y / 2.f;
}

bool Block::is_destroyed()
{

	return this->destroyed;
}

void Block::destroy()
{

	this->destroyed = true;
}

Vector2f Block::getSize()
{
	return shape_1.getSize();
}

void Block::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape_1, state);
}


#include "BlockK.h"

BlockK::BlockK(float t_X, float t_Y, float t_Width, float t_Height)
{
	shape_1.setPosition(t_X, t_Y);
	shape_1.setSize({ t_Width,t_Height });
	shape_1.setFillColor(Color::White);
	shape_1.setOrigin(t_Width / 2.f, t_Height / 2.f);
}

BlockK::~BlockK()
{
}


Vector2f BlockK::getPosition()
{
	return shape_1.getPosition();
}

float BlockK::left()
{
	return this->shape_1.getPosition().x - shape_1.getSize().x / 2.f;
}

float BlockK::right()
{
	return this->shape_1.getPosition().x + shape_1.getSize().x / 2.f;
}

float BlockK::top()
{
	return this->shape_1.getPosition().y - shape_1.getSize().y / 2.f;
}

float BlockK::bottom()
{
	return this->shape_1.getPosition().y + shape_1.getSize().y / 2.f;
}

Vector2f BlockK::getSize()
{
	return shape_1.getSize();
}

void BlockK::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape_1, state);
}


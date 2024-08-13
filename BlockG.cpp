#include "BlockG.h"

BlockG::BlockG(float t_X, float t_Y, float t_Width, float t_Height)
{
	shape_1.setPosition(t_X, t_Y);
	shape_1.setSize({ t_Width,t_Height });
	shape_1.setFillColor(Color::Green);
	shape_1.setOrigin(t_Width / 2.f, t_Height / 2.f);
}


Vector2f BlockG::getPosition()
{
	return shape_1.getPosition();
}

float BlockG::left()
{
	return this->shape_1.getPosition().x - shape_1.getSize().x / 2.f;
}

float BlockG::right()
{
	return this->shape_1.getPosition().x + shape_1.getSize().x / 2.f;
}

float BlockG::top()
{
	return this->shape_1.getPosition().y - shape_1.getSize().y / 2.f;
}

float BlockG::bottom()
{
	return this->shape_1.getPosition().y + shape_1.getSize().y / 2.f;
}

bool BlockG::is_destroyed()
{
	return this->destroyed;
}

void BlockG::destroy()
{
	if (once == false && twice == false)
	{
		once = true;

	}
	else if (once == true && twice == false	)						//¿eby pada³o po 2 razach
	{
		twice = true;

	}
	else if (once == true && twice == true)
	{
		this->destroyed = true;
		once = false;
		twice = false;
	}
}

Vector2f BlockG::getSize()
{
	return shape_1.getSize();
}

void BlockG::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape_1, state);
}


#include "BlockR.h"

BlockR::BlockR(float t_X, float t_Y, float t_Width, float t_Height)
{
	shape_1.setPosition(t_X, t_Y);
	shape_1.setSize({ t_Width,t_Height });
	shape_1.setFillColor(Color::Red);
	shape_1.setOrigin(t_Width / 2.f, t_Height / 2.f);
}

//void BlockR::update()
//{
//
//}

Vector2f BlockR::getPosition()
{
	return shape_1.getPosition();
}

float BlockR::left()
{
	return this->shape_1.getPosition().x - shape_1.getSize().x / 2.f;
}

float BlockR::right()
{
	return this->shape_1.getPosition().x + shape_1.getSize().x / 2.f;
}

float BlockR::top()
{
	return this->shape_1.getPosition().y - shape_1.getSize().y / 2.f;
}

float BlockR::bottom()
{
	return this->shape_1.getPosition().y + shape_1.getSize().y / 2.f;
}

bool BlockR::is_destroyed()
{
	return this->destroyed;
}

void BlockR::destroy()
{
	if (once == false)
	{
		once = true;
	
	}
	else							//¿eby pada³o po 2 razach
	{
		this->destroyed = true;

		once = false;
	}
}

Vector2f BlockR::getSize()
{
	return shape_1.getSize();
}

void BlockR::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape_1, state);
}


#include "Buff.h"

Buff::Buff()
{
}

Buff::Buff(float t_X, float t_Y)
{
	shape.setPosition(600, 1001);
	shape.setRadius(this->buff_radius);
	shape.setFillColor(Color::Green);
	shape.setOrigin(this->buff_radius, this->buff_radius / 2.f);
}


void Buff::update()
{
	shape.move(this->velocity);
	if (this->bottom() > (frame+map_height))
	{
		shape.setFillColor(Color::Black);
	}
	if (this->top() < (frame))
	{
		shape.setFillColor(Color::Black);
	}

}


void Buff::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float Buff::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float Buff::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Buff::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float Buff::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

Vector2f Buff::getPosition()
{
	return shape.getPosition();
}

void Buff::setPosition(float x, float y)
{
	shape.setPosition(x,y);
}

void Buff::move_up()
{
	this->velocity.y = -buff_velocity*10;
}

void Buff::move_down()
{
	buff_velocity=2.f;
	this->velocity.y = buff_velocity;
}

void Buff::set_fill_color()
{
	shape.setFillColor(Color::Green);
}

bool Buff::paused(bool pause)
{

	if (pause == true)
	{
		velocity.x = x;
		velocity.y = y;
		return false;
	}
	else if (pause == false)
	{
		x = velocity.x;
		y = velocity.y;
		velocity.x = 0.f;
		velocity.y = 0.f;
		return true;
	}

}
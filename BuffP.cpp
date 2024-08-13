#include "BuffP.h"

BuffP::BuffP()
{
}

BuffP::BuffP(float t_X, float t_Y)
{
	shape.setPosition(600, 1001);
	shape.setRadius(this->BuffP_radius);
	shape.setFillColor(Color::Red);
	shape.setOrigin(this->BuffP_radius, this->BuffP_radius / 2.f);
}


void BuffP::update()
{
	shape.move(this->velocity);
	if (this->bottom() > (frame + map_height))
	{
		shape.setFillColor(Color::Black);
	}
	if (this->top() < (frame))
	{
		shape.setFillColor(Color::Black);
	}

}


void BuffP::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float BuffP::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float BuffP::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float BuffP::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float BuffP::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

Vector2f BuffP::getPosition()
{
	return shape.getPosition();
}

void BuffP::setPosition(float x, float y)
{
	shape.setPosition(x, y);
}

void BuffP::move_up()
{
	this->velocity.y = -BuffP_velocity * 10;
}

void BuffP::move_down()
{
	BuffP_velocity = 2.f;
	this->velocity.y = BuffP_velocity;
}

void BuffP::set_fill_color()
{
	shape.setFillColor(Color::Red);
}

bool BuffP::paused(bool pause)
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
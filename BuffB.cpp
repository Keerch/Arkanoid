#include "BuffB.h"

BuffB::BuffB()
{
}

BuffB::BuffB(float t_X, float t_Y)
{
	shape.setPosition(600, 1001);
	shape.setRadius(this->BuffB_radius);
	shape.setFillColor(Color::Black);
	shape.setOrigin(this->BuffB_radius, this->BuffB_radius / 2.f);
}


void BuffB::update()
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


void BuffB::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

float BuffB::left()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float BuffB::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float BuffB::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}

float BuffB::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}

Vector2f BuffB::getPosition()
{
	return shape.getPosition();
}

void BuffB::setPosition(float x, float y)
{
	shape.setPosition(x, y);
}

void BuffB::move_up()
{
	this->velocity.y = -BuffB_velocity * 10;
}

void BuffB::move_down()
{
	BuffB_velocity = 2.f;
	this->velocity.y = BuffB_velocity;
}

void BuffB::set_fill_color()
{
	shape.setFillColor(Color::Black);
}

bool BuffB::paused(bool pause)
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
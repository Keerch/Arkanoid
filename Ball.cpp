#include "Ball.h"
#include "Paddle.h"

Ball::Ball()
{
}

Ball::Ball(float t_X, float t_Y)
{
	shape_1.setPosition(t_X, t_Y);
	shape_1.setRadius(this->ball_extern_radius);
	shape_1.setFillColor(Color::Green);
	shape_1.setOrigin(this->ball_extern_radius, this->ball_extern_radius / 2.f);
	shape_2.setPosition(t_X, t_Y);
	shape_2.setRadius(this->ball_intern_radius);
	shape_2.setFillColor(Color::White);
	shape_2.setOrigin(this->ball_intern_radius, ((this->ball_intern_radius / 2.f) - (ball_intern_radius / 7.f)));

}


void Ball::update()
{
	shape_1.move(this->velocity);
	shape_2.move(this->velocity);
	if (this->left() < frame)
	{
		velocity.x = ball_velocity;
		
	}
	else if (this->right() > map_width+frame)
	{
		velocity.x = -ball_velocity;
	}
	if (this->top() < frame)
	{
		velocity.y = ball_velocity;
	}
	if (this->bottom() > (map_height+frame))
	{
		velocity.y = -ball_velocity;
	}
	if (clocking == 0)
	{
		shape_1.setFillColor(Color::Green);
		shape_2.setFillColor(Color::White);
		penetration = false;
	}
	else if (clocking > 0 && clocking < 299)
	{
		shape_1.setFillColor(Color::Black);
		shape_2.setFillColor(Color::Black);
		--clocking;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > frame +50 && k == false && velocity.y == 0)
	{

		velocity.x = -ball_velocity-5;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < (frame + map_width-50) && k == false && velocity.y == 0)
	{
		velocity.x = ball_velocity+5;
	}
	else if (velocity.y == 0)
	{
		velocity.x = 0;
	}

}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape_1, state);
	target.draw(this->shape_2, state);
}

float Ball::left()
{
	return this->shape_1.getPosition().x - shape_1.getRadius();
}

float Ball::right()
{
	return this->shape_1.getPosition().x + shape_1.getRadius();
}

float Ball::top()
{
	return this->shape_1.getPosition().y - shape_1.getRadius();
}

float Ball::bottom()
{
	return this->shape_1.getPosition().y + shape_1.getRadius();
}

void Ball::move_up()
{
	this->velocity.y = -ball_velocity;
}

void Ball::move_down()
{
	this->velocity.y = ball_velocity;
}

void Ball::move_left()
{
	this->velocity.x = -ball_velocity;
}

void Ball::move_right()
{
	this->velocity.y = ball_velocity;
}


Vector2f Ball::getPosition()
{
	return shape_1.getPosition();
}

bool Ball::paused(bool k)
{

	if (k == true)
	{
		velocity.x = x;
		velocity.y = y;
		return k = false;
	}
	else if (k == false)
	{
		x = velocity.x;
		y = velocity.y;
		velocity.x = 0.f;
		velocity.y = 0.f;
		return k = true;
	}
	
}

void Ball::start(bool start)
{
	if (start == false)
	{
		velocity.x = ball_velocity;
		velocity.y = ball_velocity;
		pilka = true;
	}
}


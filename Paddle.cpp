#include "Paddle.h"


Paddle::Paddle(float t_X, float t_Y)
{
	shape_1.setPosition(t_X, t_Y);
	shape_1.setSize({ this->paddle_width-4, this->paddle_height-4 });
	shape_1.setFillColor(Color::White);
	shape_1.setOrigin((this->paddle_width-4)/2.f, (this->paddle_height-4) / 2.f);
	shape_2.setPosition(t_X, t_Y);
	shape_2.setRadius(this->paddle_radius);
	shape_2.setFillColor(Color::Red);
	shape_2.setOrigin(this->paddle_radius+ (paddle_width /2)-3, (this->paddle_radius / 2.f)+5);
	shape_3.setPosition(t_X, t_Y);
	shape_3.setRadius(this->paddle_radius);
	shape_3.setFillColor(Color::Red);
	shape_3.setOrigin(this->paddle_radius- (paddle_width / 2) +3, (this->paddle_radius / 2.f)+5);
	shape_4.setPosition(t_X, t_Y);
	shape_4.setSize({ this->paddle_width, this->paddle_height });
	shape_4.setFillColor(Color::Red);
	shape_4.setOrigin(this->paddle_width / 2.f, this->paddle_height / 2.f);
}
Paddle::Paddle()
{

}


void Paddle::update()
{

	this->shape_1.move(this->velocity);
	this->shape_2.move(this->velocity);
	this->shape_3.move(this->velocity);
	this->shape_4.move(this->velocity);
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left()>frame && k == false)
	{
		velocity.x = -paddle_velocity;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < (frame+map_width) && k==false)
	{
		velocity.x = paddle_velocity;
	}
	else
	{
		velocity.x = 0;
	}
	if (clocking == 0)
	{
		shape_1.setSize({ this->paddle_width - 4, this->paddle_height - 4 });
		shape_1.setOrigin((this->paddle_width - 4) / 2.f, (this->paddle_height - 4) / 2.f);
		shape_2.setRadius(this->paddle_radius);
		shape_2.setOrigin(this->paddle_radius + (paddle_width / 2) - 3, (this->paddle_radius / 2.f) + 5);
		shape_3.setRadius(this->paddle_radius);
		shape_3.setOrigin(this->paddle_radius - (paddle_width / 2) + 3, (this->paddle_radius / 2.f) + 5);
		shape_4.setSize({ this->paddle_width, this->paddle_height });
		shape_4.setOrigin(this->paddle_width / 2.f, this->paddle_height / 2.f);
		

	}


	else if (clocking > 500 && clocking <= 1000)
	{
		penetration = true;

		 // cout << clocking << "\n";
		--clocking;
	}
	else if (clocking < 500)
	{
		penetration = false;
		--clocking;
	}
	else if (clocking > 0 && clocking < 500)
	{
		--clocking;
		//cout << clocking << "\n";
	}

}

Vector2f Paddle::getPosition()
{
	return shape_4.getPosition();
}

bool Paddle::paused(bool pause)
{
	if (pause == true)
	{
		return k = false;
	}
	else if (pause == false)
	{

		return k = true;

	}
}

void Paddle::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape_4, state);
	target.draw(this->shape_3, state);
	target.draw(this->shape_2, state);
	target.draw(this->shape_1, state);
}

//void Paddle::move_for()
//{
//	velocity.x = paddle_velocity;
//}

float Paddle::left()
{
	return ((this->shape_2.getPosition().x)- (paddle_width / 2)) - shape_2.getRadius();
}

float Paddle::right()
{
	return ((this->shape_3.getPosition().x) + (paddle_width / 2)) + shape_3.getRadius();
}

float Paddle::top()
{
	return this->shape_4.getPosition().y - shape_4.getSize().y/2.f;
}

float Paddle::bottom()
{
	return this->shape_4.getPosition().y + shape_4.getSize().y/2.f;
}


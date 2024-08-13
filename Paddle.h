#pragma once
#include <SFML\Graphics.hpp>
#include<iostream>


using namespace sf;
using namespace std;


class Paddle : public Drawable
{
public:

	bool k = false;
	Paddle(float t_X, float t_Y);
	Paddle();
	~Paddle() = default;
	float left();
	float right();
	float top();
	float bottom();
	void update();
	Vector2f getPosition();
	RectangleShape shape_1, shape_4;
	CircleShape shape_2, shape_3;
	bool paused(bool);
	float paddle_width{ 100.f };
	const float paddle_height{ 20.f };
	int clocking{ 0 };
	bool penetration{ false };
	const float paddle_radius{ 10.f };

private:
	void draw(RenderTarget& target, RenderStates state) const override;
	float frame{ 100 };
	float map_width{ 800 };
	const float paddle_velocity{ 12.f };
	Vector2f velocity{ paddle_velocity,0.f };
	//void move_for();

};


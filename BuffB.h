#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <sstream>
#include"Ball.h"
using namespace sf;
using namespace std;

class BuffB : public Drawable
{
public:
	BuffB();
	~BuffB() = default;
	BuffB(float t_X, float t_Y);
	void update();
	float left();
	float right();
	float top();
	float bottom();
	Vector2f getPosition();
	void setPosition(float, float);
	float BuffB_velocity{ 3.f };
	void move_up();
	void set_fill_color();
	void move_down();
	bool paused(bool);
private:
	int x{  };
	int y{  };
	float frame{ 100 };
	float map_height{ 600 };
	CircleShape shape;
	const float BuffB_radius{ 6.f };
	void draw(RenderTarget& target, RenderStates state) const override;
	Vector2f velocity{ 0.f, BuffB_velocity };
	

};

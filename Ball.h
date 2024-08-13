#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include <sstream>
using namespace sf;
using namespace std;
class Ball : public Drawable
{
public:
	
	Ball();
	~Ball() = default;
	Ball(float t_X, float t_Y);
	void update();
	float left();
	float right();
	float top();
	float bottom();
	void move_up();
	void move_down();
	void move_left();
	void move_right();
	Vector2f getPosition();
	bool paused(bool);
	void start(bool);
	CircleShape shape_1;
	CircleShape shape_2;
	int clocking{ 0 };
	bool penetration{ false };
	bool k = false;
	bool pilka = false;
	float ball_velocity{ 7.f };
private:
	void draw(RenderTarget& target, RenderStates state) const override;
	int x{  };
	int y{  };
	float frame{ 100 };
	float map_width{ 800 };
	float map_height{ 600 };
	const float ball_extern_radius{ 12.f };
	const float ball_intern_radius{ 8.f };
	Vector2f velocity{ 0.f,0.f };
	
};


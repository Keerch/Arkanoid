#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class BlockG : public Drawable
{
public:
	BlockG(float t_X, float t_Y, float t_Width, float t_Height);
	~BlockG() = default;
	Vector2f getPosition();
	float left();
	float right();
	float top();
	float bottom();
	bool is_destroyed();
	void destroy();
	Vector2f getSize();
	bool once = false;
	bool twice = false;

private:
	virtual void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape_1;
	bool destroyed{ false };
};



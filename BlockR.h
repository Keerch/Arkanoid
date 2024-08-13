#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class BlockR : public Drawable
{
public:
	BlockR(float t_X, float t_Y, float t_Width, float t_Height);
	~BlockR() = default;
	Vector2f getPosition();
	float left();
	float right();
	float top();
	float bottom();
	bool is_destroyed();
	void destroy();
	Vector2f getSize();
	bool once = false;

private:
	virtual void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape_1;
	bool destroyed{ false };
};


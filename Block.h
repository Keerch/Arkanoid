#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Block : public Drawable
{
public:
	Block(float t_X, float t_Y, float t_Width, float t_Height);
	Block();
	~Block() = default;
	Vector2f getPosition();
	float left();
	float right();
	float top();
	float bottom();
	bool is_destroyed();
	void destroy();
	Vector2f getSize();


private:
	virtual void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape_1;
	bool destroyed{ false };
};


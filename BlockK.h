#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class BlockK : public Drawable
{
public:
	BlockK(float t_X, float t_Y, float t_Width, float t_Height);
	~BlockK();
	Vector2f getPosition();
	float left();
	float right();
	float top();
	float bottom();
	Vector2f getSize();


private:
	virtual void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape_1;

};


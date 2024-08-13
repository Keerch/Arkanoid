#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Frame : public Drawable
{
public:
	Frame(float t_X, float t_Y, float t_Width, float t_Height);
	Frame();
	~Frame() = default;
	Vector2f getPosition();
	Vector2f getSize();

private:
	virtual void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape shape;
};


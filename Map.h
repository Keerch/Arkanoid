#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Map : public Drawable
{
public:
	Map(float t_X, float t_Y, float t_Width, float t_Height);
	Map();
	~Map() = default;
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


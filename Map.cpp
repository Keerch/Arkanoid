#include "Map.h"

Map::Map(float t_X, float t_Y, float t_Width, float t_Height)
{
	shape_1.setPosition(t_X, t_Y);
	shape_1.setSize({ t_Width,t_Height });
	shape_1.setFillColor(Color::Blue);
	//shape.setOrigin(t_Width / 2.f, t_Height / 2.f);

}

Map::Map()
{
}


Vector2f Map::getPosition()
{
	return shape_1.getPosition();
}

float Map::left()
{
	return this->shape_1.getPosition().x - shape_1.getSize().x / 2.f;
}

float Map::right()
{
	return this->shape_1.getPosition().x + shape_1.getSize().x / 2.f;
}

float Map::top()
{
	return this->shape_1.getPosition().y - shape_1.getSize().y / 2.f;
}

float Map::bottom()
{
	return this->shape_1.getPosition().y + shape_1.getSize().y / 2.f;
}


Vector2f Map::getSize()
{
	return shape_1.getSize();
}

void Map::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape_1, state);
}

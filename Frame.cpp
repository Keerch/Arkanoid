#include "Frame.h"

Frame::Frame(float t_X, float t_Y, float t_Width, float t_Height)
{
	shape.setPosition(t_X, t_Y);
	shape.setSize({ t_Width,t_Height });
	shape.setFillColor(Color::Magenta);
	//shape.setOrigin(t_Width / 2.f, t_Height / 2.f);

}

Frame::Frame()
{
}

Vector2f Frame::getPosition()
{
	return shape.getPosition();
}

Vector2f Frame::getSize()
{
	return shape.getSize();
}

void Frame::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);

}

#include "Ball.h"

void Ball::initializeShape()
{
	this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color(rand() % 255 + 1, rand()% 255 + 1, rand()% 255 + 1);
	this->shape.setFillColor(color);
}

Ball::Ball()
{

}

Ball::~Ball()
{

}

//Functions
void Ball::update()
{

}

void Ball::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

#include "Ball.h"

void Ball::initializeShape(sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand() % 10 + 10));
	sf::Color color(rand() % 255 + 1, rand()% 255 + 1, rand()% 255 + 1);
	this->shape.setFillColor(color);
	this->shape.setPosition(sf::Vector2f(
		static_cast<float>(rand()% window.getSize().x - this->shape.getGlobalBounds().width), 
		static_cast<float>(rand()% window.getSize().y - this->shape.getGlobalBounds().height)));
}

Ball::Ball(sf::RenderWindow& window)
{
	this->initializeShape(window);
}

Ball::~Ball()
{

}

const sf::CircleShape Ball::getShape() const
{
	return this->shape;
}

//Functions
void Ball::update()
{

}

void Ball::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

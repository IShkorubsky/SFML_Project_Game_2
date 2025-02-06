#include "Ball.h"

/// <summary>
/// Initializes the variables of the ball
/// </summary>
/// <param name="window"></param>
void Ball::initializeShape(sf::RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand()% 10 + 10));
	sf::Color color(rand() % 255 + 1, rand()% 255 + 1, rand()% 255 + 1);
	this->shape.setFillColor(color);
	this->shape.setPosition(sf::Vector2f(
		static_cast<float>(rand()% window.getSize().x - this->shape.getGlobalBounds().width), 
		static_cast<float>(rand()% window.getSize().y - this->shape.getGlobalBounds().height)));
}

/// <summary>
/// Constructor
/// </summary>
/// <param name="window"></param>
Ball::Ball(sf::RenderWindow& window, int type)
{
	this->initializeShape(window);

	this->type = type;
}

/// <summary>
/// Deconstructor
/// </summary>
Ball::~Ball()
{

}

/// <summary>
/// Returns the shape of the ball
/// </summary>
/// <returns></returns>
const sf::CircleShape Ball::getShape() const
{
	return this->shape;
}

/// <summary>
/// Returns the type of ball
/// </summary>
/// <returns></returns>
const int& Ball::getType() const
{
	return this->type;
}

#pragma region Functions

/// <summary>
/// Updates the ball during runtime
/// </summary>
void Ball::update()
{

}

/// <summary>
/// Renders the ball to the screen
/// </summary>
/// <param name="target"></param>
void Ball::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

#pragma endregion
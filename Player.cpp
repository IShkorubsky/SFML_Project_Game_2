#include "Player.h"

void Player::initializeVariables()
{
	this->movementSpeed = 10.f;
}

void Player::initializeShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initializeVariables();
	this->initializeShape();
}

Player::~Player()
{

}

/// <summary>
/// Keyboard input
/// </summary>
void Player::updateInput()
{
	
	//Left and Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed,0.f);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}
	
	//Up and Down
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0.f, this->movementSpeed);
	}
}

/// <summary>
/// Window bound collision
/// </summary>
/// <param name="target"></param>
void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{
	//Left
	if (this->shape.getGlobalBounds().left <= 0.f)
	{
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	}
	//Right
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
	{
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	}
	//Top
	if (this->shape.getGlobalBounds().top <= 0.f)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	}
	//Bottom
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
	{
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);
	}
}

void Player::update(const sf::RenderTarget* target)
{
	updateInput();

	updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

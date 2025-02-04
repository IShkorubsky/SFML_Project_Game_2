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
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();
	if (playerBounds.left <= 0.f)
	{
		this->shape.setPosition(0.f, playerBounds.top);
	}
	//Right
	if (playerBounds.left + playerBounds.width >= target->getSize().x)
	{
		this->shape.setPosition(target->getSize().x - playerBounds.width, playerBounds.top);
	}
	//Top
	if (playerBounds.top <= 0.f)
	{
		this->shape.setPosition(playerBounds.left, 0.f);
	}
	//Bottom
	if (playerBounds.top + playerBounds.height >= target->getSize().y)
	{
		this->shape.setPosition(playerBounds.left, target->getSize().y - playerBounds.height);
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

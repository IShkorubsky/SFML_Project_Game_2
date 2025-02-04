#include "Player.h"

void Player::initializeVariables()
{

}

void Player::initializeShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.0f, 50.0f));
}

Player::Player()
{
	this->initializeVariables();
	this->initializeShape();
}

Player::~Player()
{

}

void Player::update()
{

}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

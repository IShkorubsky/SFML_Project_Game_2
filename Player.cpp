#include "Player.h"

/// <summary>
/// Initializes the variables of the player
/// </summary>
void Player::initializeVariables()
{
	this->movementSpeed = 5.f;

	this->hpMax = 10;
	this->hp = hpMax;
}

/// <summary>
/// Initializes the shape of the player
/// </summary>
void Player::initializeShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

/// <summary>
/// Constructor
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initializeVariables();
	this->initializeShape();
}

/// <summary>
/// Deconstructor
/// </summary>
Player::~Player()
{

}

#pragma region Functions

/// <summary>
/// Returns the shape of the player
/// </summary>
/// <returns></returns>
const sf::RectangleShape& Player::getShape() const
{
	return this->shape;
}

const int& Player::getHp() const
{
	return this->hp;
}

const int& Player::getHpMax() const
{
	return this->hpMax;
}

void Player::takeDamage(const int damage)
{
	if (this->hp >= 0)
	{
		this->hp -= damage;
	}
	else
	{
		//Gameover
	}
}

void Player::gainHealth(const int health)
{
	if (this->hp < this->hpMax) 
	{
		this->hp += health;
	}
	else 
	{
		this->hp = hpMax;
	}
}

/// <summary>
/// Keyboard input
/// </summary>
void Player::updateInput()
{

	//Left and Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}

	//Up and Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
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

/// <summary>
/// Updates the player
/// </summary>
/// <param name="target"></param>
void Player::update(const sf::RenderTarget* target)
{
	updateInput();

	updateWindowBoundsCollision(target);
}

/// <summary>
/// Renders the player to the screen
/// </summary>
/// <param name="target"></param>
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
#pragma endregion
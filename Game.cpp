#include "Game.h"

void Game::initializeVariables()
{
	this->endGame = false;
}

void Game::initializeWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "SFML Project - Game 2", sf::Style::Close | sf::Style::Titlebar);
}

//Constructors and Destructors
Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape) 
			{
				this->window->close();
			}
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	this->window->clear();

	//Render objects
	this->player.render(this->window);

	this->window->display();
}

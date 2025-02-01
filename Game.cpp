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

void Game::update()
{

}

void Game::render()
{

}

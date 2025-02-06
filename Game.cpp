#include "Game.h"

/// <summary>
/// Initializes the variables of the game
/// </summary>
void Game::initializeVariables()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxBalls = 10;
	this->points = 0;

}

/// <summary>
/// Initializes the game window
/// </summary>
void Game::initializeWindow()
{
	this->videoMode = sf::VideoMode(800, 600);
	this->window = new sf::RenderWindow(this->videoMode, "SFML Project - Game 2", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

/// <summary>
/// Initializes font to be used in the game
/// </summary>
void Game::initializeFont()
{
	if (!this->font.loadFromFile("Fonts/Hello Cupcake.otf"))
	{
		std::cout << "ERROR:GAME:INITIALIZEFONT::COULD NOT LOAD Hello Cupcake.otf" << "\n";
	}
}

/// <summary>
/// Initializes the text used in the game
/// </summary>
void Game::initializeText()
{
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(sf::Color::White);
	this->guiText.setCharacterSize(50);
}

/// <summary>
/// Constructor
/// </summary>
Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
	this->initializeFont();
	this->initializeText();
}

/// <summary>
/// Deconstructor
/// </summary>
Game::~Game()
{
	delete this->window;
}

#pragma region Functions

const bool Game::running() const
{
	return this->window->isOpen();
}

/// <summary>
/// Global event poll
/// </summary>
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

/// <summary>
/// Spawns the balls based on a timer and adds them to the vector
/// </summary>
void Game::spawnBalls()
{
	if (this->spawnTimer < this->spawnTimerMax)
	{
		this->spawnTimer += 1.f;
	}
	else
	{
		if (this->balls.size() < this->maxBalls)
		{
			this->balls.push_back(Ball(*this->window, rand() % BallType::NROFTYPES));

			this->spawnTimer = 0;
		}
	}
}

/// <summary>
/// Check for collision
/// </summary>
void Game::updateCollision()
{
	for (size_t i = 0; i < balls.size(); i++)
	{
		if (this->player.getShape().getGlobalBounds().intersects(this->balls[i].getShape().getGlobalBounds()))
		{
			this->balls.erase(this->balls.begin() + i);
			points++;
		}
	}
}

/// <summary>
/// Updates de game UI
/// </summary>
void Game::updateGui()
{
	std::stringstream ss;

	ss << "- Points: " << this->points;

	this->guiText.setString(ss.str());
}

/// <summary>
/// Game main Update function
/// </summary>
void Game::update()
{
	this->pollEvents();

	this->spawnBalls();
	this->player.update(this->window);
	this->updateCollision();
	this->updateGui();
}

void Game::renderGui(sf::RenderTarget* target)
{
	target->draw(this->guiText);
}

/// <summary>
/// Game main Render function
/// </summary>
void Game::render()
{
	this->window->clear();

	//Render objects
	this->player.render(this->window);

	for (auto i : this->balls)
	{
		i.render(*this->window);
	}

	this->renderGui(this->window);

	this->window->display();
}

#pragma endregion
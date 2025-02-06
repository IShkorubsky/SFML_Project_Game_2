#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <sstream>

#include "Player.h"
#include "Ball.h"

class Game
{
private:
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	bool endGame;
	sf::Event sfmlEvent;

	Player player;

	int points;
	sf::Font font;
	sf::Text guiText;

	std::vector<Ball> balls;
	float spawnTimerMax;
	float spawnTimer;
	int maxBalls;

	void initializeVariables();
	void initializeWindow();
	void initializeFont();
	void initializeText();

public:
	//Constructors and Destructors
	Game();
	~Game();

	//Accessors

	//Modifiers

	//Functions
	const bool running() const;
	void pollEvents();

	void spawnBalls();
	const int randomizeBallType();
	void updateCollision();
	void updateGui();
	void update();

	void renderGui(sf::RenderTarget* target);
	void render();
};


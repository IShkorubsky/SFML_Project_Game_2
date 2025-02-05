#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Ball
{
private:
	sf::CircleShape shape;

	void initializeShape(sf::RenderWindow& window);
public:
		Ball(sf::RenderWindow& window);
		virtual ~Ball();

		//Functions
		void update();
		void render(sf::RenderTarget& target);
};


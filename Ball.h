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

		const sf::CircleShape getShape() const;

		//Functions
		void update();
		void render(sf::RenderTarget& target);
};


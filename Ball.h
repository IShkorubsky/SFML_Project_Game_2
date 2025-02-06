#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

enum BallType {DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};

class Ball
{
private:
	sf::CircleShape shape;
	int type;

	void initializeShape(sf::RenderWindow& window);
public:
		Ball(sf::RenderWindow& window, int type);
		virtual ~Ball();

		//Accessor
		const sf::CircleShape getShape() const;
		const int& getType() const;

		//Functions
		void update();
		void render(sf::RenderTarget& target);
};


#include <memory>
#include <iostream>

#include "SFML\Graphics.hpp"
#include "GameState.h"
#include "Randutils.h"



int main()
{
	const double GAME_SPEED = 10.0;
	float deltaTime = 0.0f;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Epidemic");
	sf::Clock game_clock;
	randutils::mt19937_rng gRng;

	int g = gRng.uniform(50, 100);
	int b = gRng.uniform(100, 200);
	int r = 1;
	int p = gRng.uniform(1, 20);

	
	std::shared_ptr<GameState> gameState = std::make_shared<GameState>(g,b,r,p);
	bool mDown = false;

	game_clock.restart();

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
			if (event.type == sf::Event::Closed)
				window.close();

		if (!mDown && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			mDown = true;
			gameState.reset();
			g = gRng.uniform(50, 100);
			b = gRng.uniform(100, 200);
			r = 1;
			p = gRng.uniform(1, 20);
			gameState = std::make_shared<GameState>(g, b, r, p);
		}

		if (mDown && !sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			mDown = false;


		if (game_clock.getElapsedTime().asMilliseconds() + deltaTime >= GAME_SPEED)
		{
			deltaTime = game_clock.getElapsedTime().asMilliseconds() - GAME_SPEED;
			game_clock.restart();
			gameState->update();
		}

		window.clear(sf::Color::Black);
		window.draw(*gameState.get());
		window.display();
	}

	return 0;
}
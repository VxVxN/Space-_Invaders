// SpaceInvaders.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>

#include "Player.h"

int main()
{
	int windowsWidth = 640;
	int windowsHeidht = 480;
	RenderWindow window(sf::VideoMode(windowsWidth, windowsHeidht), "SpaceInvaders");

	Clock clock;

	Player player("sprites/working_sprites/sprite1.png", 427, 45, 97, 83, windowsWidth, windowsHeidht);
	player.setSpeedMovement(0.2f);
	player.setSpeedBullet(0.5f);
	player.setTimeReloadSeconds(0.5f);

	float playerX = (windowsWidth / 2) - (player.getWidth() / 2);
	float playerY = windowsHeidht - player.getHeight() - 10;
	player.setPosition(playerX, playerY);


	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart(); 
		time = time / 1000; 

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		player.draw(window, time);

		window.display();
	}

	return 0;
}
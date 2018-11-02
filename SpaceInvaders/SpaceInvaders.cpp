// SpaceInvaders.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <SFML/Graphics.hpp>
#include <list>

#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
	int windowsWidth = 640;
	int windowsHeidht = 480;
	RenderWindow window(sf::VideoMode(windowsWidth, windowsHeidht), "SpaceInvaders");

	Clock clock;

	Player player("sprites/working_sprites/sprite1.png", 427.f, 45.f, 97.f, 83.f, windowsWidth, windowsHeidht);
	player.setSpeedMovement(0.2f);
	player.setSpeedBullet(0.5f);
	player.setTimeReloadSeconds(0.5f);

	float playerX = (windowsWidth / 2) - (player.getWidth() / 2);
	float playerY = windowsHeidht - player.getHeight() - 10;
	player.setPosition(playerX, playerY);

	list<Enemy> enemies;

	Enemy e("sprites/working_sprites/sprite1.png", 20.f, 239.f, 35.f, 21.f, windowsWidth, windowsHeidht);
	for (int i(0); i < 5; i++) {
		enemies.push_back(e);
	}

	int x = 250;
	int y = 0;

	for (auto & enemy : enemies) {
		enemy.setPosition(x, y);
		x -= 35;
		y -= 20;
	}

	x = 250;
	y = 0;

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

		for (auto & enemy : enemies) {
			enemy.moveZigzag(x - 100, x + 100);
			enemy.draw(window, time);
		}

		player.draw(window, time);

		window.display();
	}

	return 0;
}
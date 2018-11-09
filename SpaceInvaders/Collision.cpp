#include "stdafx.h"
#include "Collision.h"

#include <iostream>

void Collision::setPlayer(Player & player)
{
	_player = &player;
}

void Collision::setEnemy(std::list<Enemy>& enemies)
{
	_enemies = &enemies;
}

void Collision::update(float time)
{
	for (std::list<Enemy>::iterator itEnemy = _enemies->begin(); itEnemy != _enemies->end(); itEnemy++) {
		for (std::list<CircleShape>::iterator itBullet = _player->_bullets.begin(); itBullet != _player->_bullets.end(); itBullet++) {            // bullet hited enemy
			bool isShotX = ((itEnemy->getX() + itEnemy->getWidth()) > itBullet->getPosition().x) && (itEnemy->getX() < itBullet->getPosition().x);
			bool isShotY = ((itEnemy->getY() + itEnemy->getHeight()) > itBullet->getPosition().y) && (itEnemy->getY() < itBullet->getPosition().y);
			if (isShotX && isShotY && itEnemy->getLife()) {
				itEnemy->die();
				_player->_score += 10;
				_player->_bullets.erase(itBullet);
				return;
			}
		}

		bool isHitX = ((itEnemy->getX() + itEnemy->getWidth()) > _player->getX()) && (itEnemy->getX() < (_player->getX() + _player->getWidth()));    // enemy hited player
		bool isHitY = ((itEnemy->getY() + itEnemy->getHeight()) > _player->getY()) && (itEnemy->getY() < (_player->getY() + _player->getWidth()));
		if (isHitX && isHitY && itEnemy->getLife()) {
			_player->_health -= 20;
			_enemies->erase(itEnemy);
			return;
		}

		for (std::list<CircleShape>::iterator itBullet = itEnemy->_bullets.begin(); itBullet != itEnemy->_bullets.end(); itBullet++) {            // bullet hited player
			bool isShotX = ((_player->getX() + _player->getWidth()) > itBullet->getPosition().x) && (_player->getX() < itBullet->getPosition().x);
			bool isShotY = ((_player->getY() + _player->getHeight()) > itBullet->getPosition().y) && (_player->getY() < itBullet->getPosition().y);
			if (isShotX && isShotY) {
				_player->_health -= 20;
				itEnemy->_bullets.erase(itBullet);
				return;
			}
		}

		if ((itEnemy->getY() + itEnemy->getHeight()) > itEnemy->_windowsHeidht || itEnemy->getLife() == false) {
			_enemies->erase(itEnemy);
			break;
		}
	}

}

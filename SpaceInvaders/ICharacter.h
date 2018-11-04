#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class ICharacter
{
public:

	Sprite sprite;

	ICharacter() = default;

	Sprite & getSprite();
	virtual void update(float time) = 0;
	virtual void die() = 0;

	void setFile(const String &strFile);
	const String getFile() const;

	void imageLoadFromFile(const String &strFile);
	Image getImage() const;

	Texture & getTexture();

	void setX(float x);
	float getX() const;

	void setY(float y);
	float getY() const;

	void setDX(float dx);
	float getDX() const;

	void setDY(float dy);
	float getDY() const;

	void setSpeed(float speed);
	float getSpeed() const;

	void setWidth(unsigned int  width);
	virtual unsigned int  getWidth() const;

	void setHeight(unsigned int  height);
	virtual unsigned int  getHeight() const;

	void setLife(bool life);
	bool getLife() const;

	void setTextureRect(float x, float y, float width, float height);

private:
	String _nameFileSprite;
	Image _image;
	Texture _texture;
	float _x, _y;
	float _dx, _dy;
	float _speed;
	unsigned int  _width, _height;
	bool _life;
};


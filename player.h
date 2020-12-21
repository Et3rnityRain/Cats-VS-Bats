#pragma once
#include <SFML/Graphics.hpp>
#include "world.h"
using namespace sf;

class Player
{
public:

	Player();
	float dx, dy;
	FloatRect player;
	int speed;

	int dir;
	int lastDir;
	float currentFrame = 0;

	bool onGround = false;
	bool isJump = false;

	Image charImg;
	Texture charTex;
	Sprite charSpr;

	bool end;

	void draw(RenderWindow& window, int& offsetX, int& offsetY);
	void update(float time);
	void collision(int dir);
};


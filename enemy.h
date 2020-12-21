#pragma once
#include <SFML/Graphics.hpp>
#include "world.h"
using namespace sf;

class Enemy
{
public:

    Enemy(int x, int y, int dir);
    float dx, dy;
    FloatRect enemy;

    int direction;
    float currentFrame;

    bool life;

    Image enemyImg;
    Texture enemyTex;
    Sprite enemySpr;

    void update(float time);
    void draw(RenderWindow& window, int& offsetX, int& offsetY);
    void collision(int dir);
};



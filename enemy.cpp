#include "enemy.h"

Enemy::Enemy(int x, int y, int dir)
{
	enemyImg.loadFromFile("C:/Users/Vova/Desktop/GreedyPugGame/Images/enemy.png");
	enemyTex.loadFromImage(enemyImg);
	enemySpr.setTexture(enemyTex);

	currentFrame = 0;
	direction = 0;
	life = true;

	if (dir == 1)
	{
		dx = 0.05;
		dy = 0;
	}
	else if (dir == -1)
	{
		dx = 0; 
		dy = 0.05;
	}
	else if (dir == 0)
	{
		dx = 0;
		dy = 0;
		direction = 1;
	}

	enemy = FloatRect(x, y, 85, 55); // 85;55
}

void Enemy::update(float time)
{
	enemy.left += dx * time;
	collision(0);
	enemy.top += dy * time;
	collision(1);

	currentFrame += 0.005 * time;
	if (currentFrame > 3)
		currentFrame -= 3;

	if (direction)
	{
		enemySpr.setTextureRect(IntRect(0, 55 * (int)currentFrame, 85, 55)); // 140;142 260;260
	}
	else
		enemySpr.setTextureRect(IntRect(0 + 85, 55 * (int)currentFrame, -85, 55));

	if (!life)
		dy = 0.1;
}

void Enemy::collision(int dir)
{
	for (int i = enemy.top / 32; i < (enemy.top + enemy.height) / 32; i++)
		for (int j = enemy.left / 32; j < (enemy.left + enemy.width) / 32; j++)
		{
			if (TileMap[i][j] == '/' || TileMap[i][j] == 'E' || TileMap[i][j] == 'e' || TileMap[i][j] == 'A' || TileMap[i][j] == 'C' || TileMap[i][j] == 'G' || TileMap[i][j] == 'g' || TileMap[i][j] == '1' || TileMap[i][j] == '2' || TileMap[i][j] == '3' || TileMap[i][j] == '4')
			{
				if ((dx > 0) && (dir == 0)) {
					enemy.left = j * 32 - enemy.width;
					dx = -dx;
					direction = 1;
				}
				else if ((dx < 0) && (dir == 0)) {
					enemy.left = j * 32 + 32;
					dx = -dx;
					direction = 0;
				}
				if ((dy > 0) && (dir == 1)) {
					enemy.top = i * 32 - enemy.height;
					dy = -dy;
					direction = 1;
					break;
				}
				else if ((dy < 0) && (dir == 1)) {
					enemy.top = i * 32 + 32;
					dy = -dy;
					direction = 0;
					break;
				}
			}
		}
}

void Enemy::draw(RenderWindow& window, int& offsetX, int& offsetY)
{
	enemySpr.setPosition(enemy.left - offsetX, enemy.top - offsetY);
	window.draw(enemySpr);
}



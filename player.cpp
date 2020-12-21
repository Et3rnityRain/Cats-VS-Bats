#include "player.h"

Player::Player()
{
	charImg.loadFromFile("C:/Users/Vova/Desktop/GreedyPugGame/Images/player.png");
	charTex.loadFromImage(charImg);
	charSpr.setTexture(charTex);

	player = FloatRect(150, 150, 38, 35);
	speed = 0.5;
	dx = 0;
	dy = 0;
	lastDir = 1;

	end = false;

	charSpr.setPosition(player.left, player.top);
}

void Player::update(float time)
{
	if (currentFrame > 8)
		currentFrame -= 8;

	switch (dir)
	{
	case 0:
		// Вверх
		if (onGround)
		{
			onGround = false;
			isJump = true;
		}
		break;
	case 1:
		// Вправо
		charSpr.setTextureRect(IntRect(7 + 37 * (int)currentFrame, 183, 35, 38));
		break;
	case 2:
		// Влево
		charSpr.setTextureRect(IntRect(7 + 35 + 37 * (int)currentFrame, 183, -35, 38));
		break;
	case 3:
		// Стоим на месте 
		if (currentFrame > 5)
			currentFrame -= 5;

		if (lastDir)
			charSpr.setTextureRect(IntRect(7 + 29 * (int)currentFrame, 85, 28, 38));
		else
			charSpr.setTextureRect(IntRect(7 + 28 + 29 * (int)currentFrame, 85, -28, 38));

		if (onGround)
		{
			dy = 0;
			dx = 0;
		}
		break;
	}

	if (!onGround)
		dy += 0.0005 * time;

	if (isJump)
	{
		if (lastDir)
			charSpr.setTextureRect(IntRect(189, 226, 31, 38));
		else
			charSpr.setTextureRect(IntRect(189 + 31, 226, -31, 38));
	}

	player.left += dx * time;
	collision(0);
	onGround = false;
	player.top += dy * time;
	collision(1);
	dx = 0;
}

void Player::draw(RenderWindow& window, int &offsetX, int &offsetY)
{
	charSpr.setPosition(player.left - offsetX, player.top - offsetY);
	window.draw(charSpr);
}

void Player::collision(int dir)
{
	for (int i = player.top / 32; i < (player.top + player.height) / 32; i++)
		for (int j = player.left / 32; j < (player.left + player.width) / 32; j++)
		{
			if (TileMap[i][j] == '/' || TileMap[i][j] == 'k' || TileMap[i][j] == 'E' || TileMap[i][j] == 'e' || TileMap[i][j] == 'A' || TileMap[i][j] == 'C' || TileMap[i][j] == 'G' || TileMap[i][j] == 'g' || TileMap[i][j] == '1' || TileMap[i][j] == '2' || TileMap[i][j] == '3' || TileMap[i][j] == '4')
			{
				if ((dx > 0) && (dir == 0))
					player.left = j * 32 - player.width;
				if ((dx < 0) && (dir == 0))
					player.left = j * 32 + 32;
				if ((dy > 0) && (dir == 1))
				{
					player.top = i * 32 - player.height;
					dy = 0;
					onGround = true;
					isJump = false;
				}
				if ((dy < 0) && (dir == 1))
				{
					player.top = i * 32 + 32;
					dy = 0;
				}
			}

			if (TileMap[i][j] == '0')
				end = true;
		}
}


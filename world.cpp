#include "world.h"

World::World() 
{
	mapImg.loadFromFile("C:/Users/Vova/Desktop/GreedyPugGame/Images/tiles.png");
	mapTex.loadFromImage(mapImg);
	mapSpr.setTexture(mapTex);
}

void World::draw(RenderWindow& window)
{
	window.clear();
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			// Нижняя земля
			if (TileMap[i][j] == 'E')
			{
				mapSpr.setTextureRect(IntRect(95, 60, 32, 32));
			}
			if (TileMap[i][j] == 'e')
			{
				mapSpr.setTextureRect(IntRect(17, 60, 32, 32));
			}
			if (TileMap[i][j] == 'k')
			{
				mapSpr.setTextureRect(IntRect(56, 99, 32, 32));
			}
			if (TileMap[i][j] == '1')
			{
				mapSpr.setTextureRect(IntRect(17, 99, 32, 32)); 
			}
			if (TileMap[i][j] == '2')
			{
				mapSpr.setTextureRect(IntRect(97, 99, 32, 32));
			}
			if (TileMap[i][j] == 'G')
			{
				mapSpr.setTextureRect(IntRect(57, 20, 32, 32));
			}
			if (TileMap[i][j] == 'g')
			{
				mapSpr.setTextureRect(IntRect(57, 60, 32, 32));
			}
			if (TileMap[i][j] == 'I')
			{
				mapSpr.setTextureRect(IntRect(133, 20, 32, 32));
			}
			

			// Летающие островки
			if (TileMap[i][j] == '3')
			{
				mapSpr.setTextureRect(IntRect(17, 134, 32, 32));
			}
			if (TileMap[i][j] == 'C')
			{
				mapSpr.setTextureRect(IntRect(57, 134, 32, 32));
			}
			if (TileMap[i][j] == '4')
			{
				mapSpr.setTextureRect(IntRect(96, 134, 32, 32));
			}
			if (TileMap[i][j] == 'A')
			{
				mapSpr.setTextureRect(IntRect(133, 134, 32, 32));
			}

			// Небо
			if (TileMap[i][j] == ' ')
			{
				mapSpr.setTextureRect(IntRect(180, 220, 32, 32));
			}
			if (TileMap[i][j] == '/')
			{
				mapSpr.setTextureRect(IntRect(180, 220, 32, 32));
			}

			// Дверь
			if (TileMap[i][j] == '0')
			{
				mapSpr.setTextureRect(IntRect(371, 188, 32, 32));
			}

			mapSpr.setPosition(j * 32 - offsetX, i * 32 - offsetY);
			window.draw(mapSpr);
		}
	}
}
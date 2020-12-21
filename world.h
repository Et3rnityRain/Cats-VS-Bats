#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
using namespace sf;

static const int width = 118;
static const int height = 19;

const String TileMap[height] = {
		"gggE//////////////////////eggggggggggggggE///////////////////////eggggggggggggggE/////////////////////////////////eggg",
		"gggE                      eggggggggggggggE                       eggggggggggggggE                                 eggg",
		"gggE                      eggggggggggggggE                       1kkkkkkkkkkkkkk2                                 eggg",
		"ggggCCCC4                 1kkkkkkkkkkkkkk2    3CCCC4                                         3CCCCCCCCCCCCCC4     eggg",
		"gggE                                                                                                              eggg",
		"gggE                                                     3CCCC4         3CCCCCCCCCCCCCC4                          eggg",
		"gggE             3CCCC4              3CCCC4                                                                       eggg",
		"gggE                                                                                                              eggg",
		"ggggCCCCCCC4                                                              3CCCC4                 3CCCC4           eggg",
		"gggE                      3CCCCCCCCCCCCCC4                                                                        eggg",
		"gggE                                                                                                              eggg",
		"gggE                                                        GGG                                                   eggg",
		"gggE           3CCCCCCCCCCCCC4           3CCCCCCCCCC4      GgggG          A           3CCCC4                  3CCCeggg",
		"gggE                                                      GgggggG                                                 eggg",
		"gggE                                                     GgggggggG                                                eggg",
		"gggE                                                    GgggggggggG                                               0ggg",
		"ggggGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGgggggggggggGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGgggg",
		"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg"
};

class World
{
public:

	World();

	int offsetX = 0;
	int offsetY = 0;

	Image mapImg;
	Texture mapTex;
	Sprite mapSpr;

	void draw(RenderWindow& window);
};


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "player.h"
#include "world.h"
#include "enemy.h"
#include <sstream>
using namespace sf;


int main()
{
    RenderWindow window(sf::VideoMode(1400, 608), "Game");
    Clock clock;
    Player plr;
    World wrld;

    SoundBuffer buffer;
    buffer.loadFromFile("C:/Users/Vova/Desktop/GreedyPugGame/Audio/jump.ogg");
    Sound jump(buffer);

    Music music;
    music.openFromFile("C:/Users/Vova/Desktop/GreedyPugGame/Audio/music.ogg");
    music.play();
    music.setLoop(true);

    const int enemyCount = 15;

    Enemy enemy[enemyCount] =
    {
        Enemy(350, 150, -1),
        Enemy(600, 250, 1),
        Enemy(150, 350, -1),
        Enemy(700, 450, 0),
        Enemy(1200, 350, 0),
        Enemy(1200, 230, 0),
        Enemy(1400, 200, -1),
        Enemy(1800, 400, -1),
        Enemy(1900, 350, -1),
        Enemy(3200, 250, -1),
        Enemy(2200, 250, -1),
        Enemy(3550, 150, 1),
        Enemy(3550, 450, 1),
        Enemy(3250, 350, 1),
        Enemy(3550, 450, 1)
    };

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds(); // Дать прошедшее время в микросекундах
        clock.restart(); // Перезагружает время
        time = time / 800; // Скорость игры

        plr.charSpr.setColor(Color::White);

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        // Реагирование на действия пользователя
        if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Space))
        {
            if (plr.onGround)
            {
                plr.dy = -0.45;
                jump.play();
            }
            plr.dir = 0;
            plr.currentFrame += 0.005 * time;
        }
        if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
        {
            plr.dx = 0.1;
            plr.dir = 1;
            plr.currentFrame += 0.005 * time;
            plr.lastDir = 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
        {
            plr.dx = -0.1;
            plr.dir = 2;
            plr.currentFrame += 0.005 * time;
            plr.lastDir = 0;
        }
        if (!Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::Left)
            && !Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::Right)
            && !Keyboard::isKeyPressed(Keyboard::W) && !Keyboard::isKeyPressed(Keyboard::Up) && !Keyboard::isKeyPressed(Keyboard::Space))
        {
            plr.dir = 3;
            plr.currentFrame += 0.005 * time;
        }

        plr.update(time);

        if (plr.end)
            window.close();

        for (int i = 0; i < enemyCount; i++)
            enemy[i].update(time);

        for (int i = 0; i < enemyCount; i++)
        {
            if (plr.player.intersects(enemy[i].enemy))
            {
                plr.charSpr.setColor(Color::Red);
                //window.close();
            }
        }

        if (plr.player.left > 1400 / 2 && plr.player.left < width * 32 - 1400 / 2)
            wrld.offsetX = plr.player.left - 1400 / 2;
        if (plr.player.top > 600 / 2 && plr.player.top < height * 32 - 600 / 2)
            wrld.offsetY = plr.player.top - 600 / 2;

        window.clear();
        wrld.draw(window);
        plr.draw(window, wrld.offsetX, wrld.offsetY);

        for (int i = 0; i < enemyCount; i++)
            enemy[i].draw(window, wrld.offsetX, wrld.offsetY);
       
        window.display();
    }
}

#include <SFML/Graphics.hpp>
#include "Bird.h"
#include "Pipes.h"
#include "Collision.h"
#include "Score.h"
#include "Text.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Flappy Bird");
    window.setFramerateLimit(360);
    sf::Clock delay;
    bool started = 0;

    sf::Texture t;                            //background
    t.loadFromFile("images//background.png");
    sf::Sprite background(t);

    Text gameOverText(140, 300, 3, 60, "Game Over! Press R for RESTART.", "fonts//Flappy-Bird.ttf" );  //text
    Text startText(300, 300, 3, 60, "Left click to start!.","fonts//Flappy-Bird.ttf" );

    sf::SoundBuffer buffer_g_o;              //sunete
    buffer_g_o.loadFromFile("sounds//game_over.wav");
    sf::Sound game_over_sound;
    game_over_sound.setBuffer(buffer_g_o);
    bool g_o_sound_played = 0;
                               //pasare, obstacole, collision
    Bird bird;

    Pipe first(600, "images//Pipe_up.png", "images//Pipe_down.png");
    Pipe second;
    second = first + 500;
    Pipe third(first);
    third += 1000;

    Score score;

    Collision objects(bird, first, second, third, score);

    while (window.isOpen())
    {
        objects.isCollide();
        objects.update();
        if (bird.getY() > 700) bird.die();

        window.clear();
        window.draw(background);
        bird.draw(window);
        for (auto i : { &first,&second,&third }) i->draw(window);
        score.draw(window);
        if (!started) startText.draw(window);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left && bird.isAlive())
                {
                    started = 1;
                    bird.jump();
                    bird.draw(window);
                }
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::R)
                {
                    for (auto i : { &first,&second,&third }) i->reset();
                    bird.reset(); //default
                    started = 0;
                    score.resetValue();
                    g_o_sound_played = 0;
                }
        }

        if (bird.isAlive())
        {
            if(started)
            {   if (delay.getElapsedTime().asSeconds() > 0.005)
                {
                    bird.fall();
                    delay.restart();
                }
            for (auto i : { &first,&second,&third }) i->move();
            }
        }
        else
        {
            gameOverText.draw(window);
            if(!g_o_sound_played) game_over_sound.play(), g_o_sound_played = 1;
        }
        window.display();
    }

    return 0;
}

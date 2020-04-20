#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Bird.h"
#include "Pipes.h"
#include "Collision.h"
#include "Text.h"
#include "Score.h"
#include "Objects.h"

int main()
{
    Bird bird;
    std::cin >> bird;

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Flappy Bird");
    window.setFramerateLimit(360);
    sf::Clock delay;
    bool started = 0;

    sf::Texture t;
    t.loadFromFile("images//background.png");
    sf::Sprite background(t);

    Text gameOverText(140, 300, 3, 50, "Game Over! Press R for RESTART", "fonts//arial.ttf" );  //text
    Text startText(300, 300, 3, 60, "Left click to start!","fonts//arial.ttf" );
    Text deathScoreText(140, 80, 3, 60, "0", "fonts//arial.ttf");
    Text deathHSText(140, 150, 3, 60, "0", "fonts//arial.ttf");

    sf::SoundBuffer buffer_g_o;              //sunete
    buffer_g_o.loadFromFile("sounds//game_over.wav");
    sf::Sound game_over_sound;
    game_over_sound.setBuffer(buffer_g_o);
    bool g_o_sound_played = 0;
                               //pasare, obstacole, collision
    Pipe first(600, "images//Pipe_up.png", "images//Pipe_down.png");
    Pipe* secondd = new Pipe(1100, "images//Pipe_up.png", "images//Pipe_down.png");
    Object &o = *secondd;
    Pipe &second = dynamic_cast<Pipe&>(o);
    Pipe third(first);
    third += 1000;

    Score score;

    Collision objects(bird, first, second, third, score);

    auto tooLow = [&]() {return bird.getY() > 700 && bird.isAlive();};

    while (window.isOpen())
    {
        objects.isCollide();

        if(tooLow())
        {
            score.insertScore();
            bird.die();
        }

        objects.update();

        window.clear();
        window.draw(background);
        bird.draw(window);
        for (auto i : { &first,&second,&third }) i->draw(window);
        score.draw(window);
        if (!started) startText.draw(window);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if(event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left && bird.isAlive())
                {
                    started = 1;
                    bird++;
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
                    bird--;
                    delay.restart();
                }
                for (auto i : { &first,&second,&third }) i->move();
            }
        }
        else
        {
            deathScoreText.setText("Score: " + std::to_string(score.getValue()));
            deathScoreText.draw(window);
            deathHSText.setText("Highscore: " + std::to_string(score.getHS()));
            deathHSText.draw(window);
            gameOverText.draw(window);
            if(!g_o_sound_played) game_over_sound.play(), g_o_sound_played = 1;
        }
        window.display();
    }
    std::cout << "Let's look at " << bird.get_name() << "'s accomplishments: \n" << score;
    delete secondd;
    return 0;
}

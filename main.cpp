#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Bird.h"
#include "Pipes.h"
#include "Collision.h"
#include "Text.h"
#include "Score.h"
#include "Objects.h"
#include "ObjFactory.h"

int main()
{
    /*sqlite3* db;
    int errDB;
    const char* sql;
    char* errMsg = 0;

    errDB = sqlite3_open("flappy_bird.db", &db);
    if (errDB) {
        std::cout << "Can't open database: %s\n" << sqlite3_errmsg(db);
        return 0;
    }
    else  std::cout << "Opened database successfully\n";

    sql = "CREATE TABLE PLAY_HISTORY("  \
            "ID             INT PRIMARY KEY     NOT NULL," \
            "NAME           TEXT    NOT NULL," \
            "HIGHSCORE      INT     NOT NULL );";

    errDB = sqlite3_exec(db, sql, callback, 0, &errMsg);

    if (errDB != SQLITE_OK) {
        std::cout << errMsg << '\n';
        sqlite3_free(errMsg);
    }
    else std::cout << "Table created successfully\n";

    sqlite3_close(db);*/
    ObjectFactory* factory = new ObjectFactory;

    Object* _bird = factory->Create("bird");
    Bird* bird = dynamic_cast<Bird*>(_bird);
    std::cin >> (*bird);
                                        //pasare, obstacole, collision
    Object* _first = factory->Create("pipe");
    Pipe* first = dynamic_cast<Pipe*>(_first);

    Object* _second = factory->Create("pipe");
    Pipe* second = dynamic_cast<Pipe*>(_second);
    *second += 500;

    Object* _third = factory->Create("pipe");
    Pipe* third = dynamic_cast<Pipe*>(_third);
    *third = *first + 1000;

    std::unique_ptr <Score> score = std::make_unique <Score>();

    Collision objects(*bird, *first, *second, *third, *score);

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Flappy Bird");
    window.setFramerateLimit(360);
    sf::Clock delay;
    bool started = 0;

    sf::Texture t;
    t.loadFromFile("images//background.png");
    sf::Sprite background(t);

    Text<int> gameOverText(140, 300, 3, 50, "Game Over! Press R for RESTART", "fonts//arial.ttf" );  //text
    Text<int> startText(300, 300, 3, 60, "Left click to start!","fonts//arial.ttf" );
    Text<int> deathScoreText(140, 80, 3, 60, "0", "fonts//arial.ttf");
    Text<int> deathHSText(140, 150, 3, 60, "0", "fonts//arial.ttf");

    sf::SoundBuffer buffer_g_o;              //sunete
    buffer_g_o.loadFromFile("sounds//game_over.wav");
    sf::Sound game_over_sound;
    game_over_sound.setBuffer(buffer_g_o);
    bool g_o_sound_played = 0;

    auto tooLow = [&]() { return bird->getY() > 700 && bird->isAlive(); };
    auto tooHigh = [&]() { return bird->getY() < -10 && bird->isAlive(); };

    while (window.isOpen())
    {
        objects.isCollide();

        if(tooLow() || tooHigh())
        {
            score->insertScore();
            bird->die();
        }

        objects.update();

        window.clear();
        window.draw(background);
        bird->draw(window);

        for(auto pipe : { first, second, third })
            pipe->draw(window);

        score->draw(window);
        if (!started) startText.draw(window);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();

            if(event.type == sf::Event::MouseButtonPressed)
                if (event.mouseButton.button == sf::Mouse::Left && bird->isAlive())
                {
                    started = 1;
                    (*bird)++;
                    bird->draw(window);
                }

            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::R)
                {
                   for(auto pipe : { first, second, third })
                        pipe->reset();
                    bird->reset();
                    started = 0;
                    score->resetValue();
                    g_o_sound_played = 0;
                }

        }

        if(bird->isAlive())
        {
            if(started)
            {   
                if (delay.getElapsedTime().asSeconds() > 0.005)
                {
                    (*bird)--;
                    delay.restart();
                }
                for(auto pipe : { first, second, third })
                        pipe->move();
            }
        }
        else
        {
            deathScoreText.setText("Score: " + std::to_string(score->getValue()));
            deathScoreText.draw(window);
            deathHSText.setText("Highscore: " + std::to_string(score->getHS()));
            deathHSText.draw(window);
            gameOverText.draw(window);
            if(!g_o_sound_played) game_over_sound.play(), g_o_sound_played = 1;
        }
        window.display();
    }


    std::cout << "Let's look at " << bird->get_name() << "'s accomplishments: \n" << *score;

    delete _bird;
    delete _first;
    delete _second;
    delete _third;
    delete factory;

    return 0;
}

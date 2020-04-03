#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

int main()
{
    sf::Window window(sf::VideoMode(1000, 800), "Flappy Bird");

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

        }
    }




    return 0;
}

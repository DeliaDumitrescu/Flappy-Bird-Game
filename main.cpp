#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Flappy Bird");
    sf::Texture t; t.loadFromFile("background.png"); sf::Sprite background(t);
    while (window.isOpen())
    {
        window.clear();
        window.draw(background);
        window.display();
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

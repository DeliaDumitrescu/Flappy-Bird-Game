#ifndef BIRD_H
#define BIRD_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Bird
{
private:
    sf::Texture t;
    sf::Sprite s;
    sf::SoundBuffer buffer;
    sf::Sound flap_sound;
    bool alive;
    float x, y, dy;
    int angle;
    std::string fileBird, fileSound;

public:
    Bird(int val_alive = 1, int val_x = 120, int val_y = 500, int val_dy = 0, int val_angle = 0, std::string val_fileBird = "images//bird.png", std::string val_fileSound = "sounds//flap.wav" );
    sf::Sprite get_sprite() const {return s;};
    void jump();
    void fall();
    void draw(sf::RenderWindow&);
    void reset();
    int getX() const { return x; }
    int getY() const { return y; }
    void die() { alive = 0; }
    bool isAlive() const { return alive; }
};

#endif // BIRD_H

#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Objects.h"

class Bird : public Object
{
private:
    std::string name;
    sf::Texture t;
    sf::Sprite s;
    sf::SoundBuffer buffer;
    sf::Sound flap_sound;
    bool alive;
    float dy;
    int angle;
    std::string fileBird, fileSound;

public:
    Bird(std::string val_name = "Your bird", int val_alive = 1, int val_x = 120, int val_y = 500, int val_dy = 0, int val_angle = 0, std::string val_fileBird = "images//bird.png", std::string val_fileSound = "sounds//flap.wav" );
    inline sf::Sprite get_sprite() const { return s; };
    inline std::string get_name() const { return name; };
    inline bool isAlive() const { return alive; }
    void jump();
    void fall();
    void reset();
    void die() { alive = 0; }
    void draw(sf::RenderWindow&) override;
    Bird& operator ++(int);
    Bird& operator --(int);
    friend std::istream& operator >>(std::istream&, Bird&);
    void manageExceptions();
};


#endif // BIRD_H

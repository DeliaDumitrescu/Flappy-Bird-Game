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

    static Bird* instance;
    Bird();
public:
    static Bird* GetInstance();

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

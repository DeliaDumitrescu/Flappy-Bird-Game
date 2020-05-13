#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Objects.h"
#include "Exceptions.h"

//Singleton
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
    Bird& operator =(const Bird&) = delete;
    Bird(const Bird&) = delete;
public:
    static Bird* GetInstance();

    inline sf::Sprite get_sprite() const { return s; };
    inline std::string get_name() const { return name; };
    inline bool isAlive() const { return alive; }
    void jump();
    void fall();
    void reset();
    void die() { alive = 0; }
    bool hitsPipe(float, float);
    void draw(sf::RenderWindow&) override;
    Bird& operator ++(int);
    Bird& operator --(int);
    friend std::istream& operator >>(std::istream&, Bird&);
    void manageExceptions();
};


#endif // BIRD_H

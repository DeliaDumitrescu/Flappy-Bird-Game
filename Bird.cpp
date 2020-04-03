#include "Bird.h"
#include <bits/stdc++.h>


Bird::Bird(){

    t.loadFromFile("bird.png");
    s.setTexture(t);
    s.setPosition(100, 500);
    x = 0;


};


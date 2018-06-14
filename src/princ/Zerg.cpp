//
// Created by Andy on 14/06/2018.
//

#include "../Unit.cpp"

class Zerg : Unit{
    int _regen_life;
public:
    Zerg(int life, int attack, int defense, string &&name, int regen) :
            Unit(life, attack, defense, name), _regen_life(regen) { }
};


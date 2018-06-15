//
// Created by Andy on 14/06/2018.
//

#include "../Unit.cpp"

class Zerg : public Unit{
    int _regen_life;
protected:
    Zerg(int life, int attack, int defense, int regen, string &&name) :
            Unit(life, attack, defense, (string &&)name), _regen_life(regen) { }
};


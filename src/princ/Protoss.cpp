//
// Created by Andy on 14/06/2018.
//

#include "../Unit.cpp"

class Protoss : Unit{
    int _shield, _regen_shield;
public:
    Protoss(int life, int attack, int defense, string &&name, int shield, int regen) :
            Unit(life, attack, defense, name), _shield(shield), _regen_shield(regen) { }
};


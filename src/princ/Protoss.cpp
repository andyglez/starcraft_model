//
// Created by Andy on 14/06/2018.
//

#include "../Unit.cpp"

class Protoss : public Unit{
    int _shield, _regen_shield;
protected:
    Protoss(int life, int attack, int defense, int shield, int regen, string &&name) :
            _shield(shield), _regen_shield(regen), Unit(life, attack, defense,(string &&) name) { }
};


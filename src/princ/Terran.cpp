//
// Created by Andy on 14/06/2018.
//
#include "../Unit.cpp"

class Terran : Unit{

public:
    Terran(int life, int attack, int defense, string &&name) : Unit(life, attack, defense, name) { }
};
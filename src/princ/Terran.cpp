//
// Created by Andy on 14/06/2018.
//
#include "../Unit.cpp"

class Terran : public Unit{
protected:
    Terran(int life, int attack, int defense, string&& name) :
            Unit(life, attack, defense, (string&&)name) {}
};
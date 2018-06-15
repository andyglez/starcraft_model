//
// Created by Andy on 15/06/2018.
//

#include "Unit.cpp"

class Terran : virtual public Unit{
protected:
    Terran() { }
    Terran(int life, int attack, int defense, string&& name) :
            Unit(life, attack, defense, (string&&)name) {}
};

class Protoss : virtual public Unit{
    int _shield, _regen_shield;
protected:
    Protoss() { }
    Protoss(int life, int attack, int defense, int shield, int regen, string &&name) :
            _shield(shield), _regen_shield(regen), Unit(life, attack, defense,(string &&) name) { }
};

class Zerg : virtual public Unit{
    int _regen_life;
protected:
    Zerg() { }
    Zerg(int life, int attack, int defense, int regen, string &&name) :
            Unit(life, attack, defense, (string &&)name), _regen_life(regen) { }
};

class Infested : public Terran, public Zerg{
public:
    Infested(int life, int attack, int defense, int regen, string &&name) :
            Unit(life, attack, defense, (string &&) name) { }
};

class Hybrid : public Protoss, public Zerg{
public:
    Hybrid(int life, int attack, int defense, int shield, int shield_regen, int life_regen, string &&name) :
            Unit(life, attack, defense, (string &&)name) { }
};
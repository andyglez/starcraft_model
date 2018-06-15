//
// Created by Andy on 15/06/2018.
//
#include "Principal.cpp"

class ManaUnit{
    int _mana, _genManaPerSecond;
protected:
    ManaUnit(int mana, int genManaPerSecond) :
            _mana(mana), _genManaPerSecond(genManaPerSecond) { }
};

class Power {
public:
    virtual ~Power();
    virtual void Cast(ManaUnit manaUnit) = 0;
};

class TerranPower : public Power { };
class ProtossPower : public Power { };
class ZergPower : public Power { };

template <class X = Power, class Y = Power, class Z = Power>
class PowerUnit : public Unit, public ManaUnit{
protected:
    X FirstPower;
    Y SecondPower;
    Z ThirdPower;
    PowerUnit(int life, int attack, int defense, int mana, int genManaPerSecond, string &&name, X first, Y second, Z third) :
         Unit(life, attack, defense, (string &&) name),
         ManaUnit(mana, genManaPerSecond), FirstPower(first), SecondPower(second), ThirdPower(third) { }
};

template <class X = TerranPower, class Y = TerranPower, class Z = TerranPower>
class TerranPowerUnit : virtual public Terran, public PowerUnit<X,Y,Z>{
protected:
    TerranPowerUnit(int life, int attack, int defense, int mana, int genManaPerSecond, string &&name, X first, Y second, Z third) :
            PowerUnit<X,Y,Z>(life, attack, defense, mana, genManaPerSecond, (string &&)name, first, second, third) { }
};

template <class X = ProtossPower, class Y = ProtossPower, class Z = ProtossPower>
class ProtossPowerUnit : public PowerUnit<X,Y,Z>, virtual public Protoss{
protected:
    ProtossPowerUnit(int life, int attack, int defense, int mana, int genManaPerSecond, string &&name, X first, Y second, Z third) :
            PowerUnit<X,Y,Z>(life, attack, defense, mana, genManaPerSecond, (string &&)name, first, second, third) { }
};

template <class X = ZergPower, class Y = ZergPower, class Z = ZergPower>
class ZergPowerUnit : public PowerUnit<X,Y,Z>, virtual public Zerg{
protected:
    ZergPowerUnit(int life, int attack, int defense, int mana, int genManaPerSecond, string &&name, X first, Y second, Z third) :
            PowerUnit<X,Y,Z>(life, attack, defense, mana, genManaPerSecond, (string &&)name, first, second, third) { }
};

template <class X = Power, class Y = Power, class Z = Power>
class HeroeUnit : public PowerUnit<X,Y,Z>{
protected:
    static HeroeUnit* instance;
    HeroeUnit(int life, int attack, int defense, int mana, int genManaPerSecond, string &&name, X first, Y second, Z third) :
            PowerUnit<X,Y,Z>(life, attack, defense, mana, genManaPerSecond, (string &&) name, first, second, third) { }

public:
    virtual HeroeUnit getInstance();
};

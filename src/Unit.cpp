//
// Created by Andy on 14/06/2018.
//

#include <iostream>
using namespace std;

class Unit{
    int _life, _attack, _defense;
    string _name;

protected:
    Unit() { }
    Unit(int life, int attack, int defense, string&& name) :
            _life(life), _attack(attack), _defense(defense), _name(name){}

public:
    void print(){
        cout << _name << endl;
    }
};


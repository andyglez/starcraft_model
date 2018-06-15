## Starcraft class model ##

This project represents C++ introduction to class modeling and inheritance along with some topics inevitable to these
features in the language. For instance:
  * Types of inheritance or access levels.
  * Memory structure of inheritance.


## Types of Inheritance ##

~~~cpp
class Unit{
    int _life, _attack, _defense;
    string _name;

protected:
    Unit(int life, int attack, int defense, string&& name) :
            _life(life), _attack(attack), _defense(defense), _name(name){}
};
~~~

With a straight-forward syntax inheritance is a great tool for extending a class like adding some new functionality.
Inside a class implementation, access levels are marked by sections and with an inheritance declaration are marked before
the name of the base class.

~~~cpp
class Zerg : public Unit{
    int _regen_life;
public:
    Zerg(int life, int attack, int defense, string &&name, int regen) :
            Unit(life, attack, defense, name), _regen_life(regen) { }
};
~~~

There are three access levels in a class implementation just as in inheritance:
  * public
  * protected
  * private

By default everything in C++ is marked private unless another access level is explicit, which means that they will only
be visible from inside the class they belong to.

All member functions or fields that are declared within a class section marked **public** are accessible from everywhere
in code.

Protected means that, only from within the classes that are inheriting from this base class, members or fields declared
in a protected section will be accessible.

> Private members of a base class are inherited by a subclass but are not accessible in subclass code.
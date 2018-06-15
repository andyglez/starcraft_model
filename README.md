## Starcraft class model ##

This project represents C++ introduction to class modeling and inheritance along with some topics inevitable to these
features in the language.


**Access Levels**

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

**Memory structure of inheritance**

C++ supports multiple inheritance which forces to have a well-define structure of the class or there will be ambiguity at
its own concept.

A class is mainly a data container so its size in memory depends on its fields and members.
Inheritance behaves like a wrapper for such data container inside another data container. In other words,
a subclass is defined the same way, but now it contains all data of its parent class and it's own fields and members.

> One way of not containing data from a parent class is what C++ call *virtual inheritance*

With this structure there must be defined some rules for constructing objects:
  * First, the constructor of any virtual base classes is called in the order in which the classes are inherited.
  * Then the constructor for all non-virtual base classes is called in the order in which the classes are inherited.
  * Next, the constructor for all member objects is called in the order in which the member objects appear in the class.
  * Finally, the constructor of the class itself is called.

There is, of course, a better and more complete tool for removing ambiguity when using multiple inheritance that is, referencing
its code path or semantic path, although it isn't the most comfortable one.
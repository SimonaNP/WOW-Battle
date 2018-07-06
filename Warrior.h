#ifndef WARRIOR_H
#define WARRIOR_H
#include "Fighter.h"

class Warrior : virtual public Fighter
{
public:

    Warrior(char* name, double blood, unsigned int damage, int armor, unsigned int speed):Fighter(name,blood,damage,armor,speed){}
    virtual void fight(Fighter& other);

    virtual void print();
};

#endif // WARRIOR_H

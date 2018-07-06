#ifndef DEATHKNIGHT_H_INCLUDED
#define DEATHKNIGHT_H_INCLUDED

#include "Warrior.h"
#include "Warlock.h"

class DeathKnight : public Warrior, public Warlock{
public:
    DeathKnight(char* name, double blood, unsigned int damage, int armor, unsigned int speed,unsigned int X)
    :Fighter(name,blood,damage,armor,speed),Warrior(name,blood,damage,armor,speed), Warlock(name,blood,damage,armor,speed,X)
    {}


    virtual void fight(Fighter& other);

    virtual void print();
};
#endif // DEATHKNIGHT_H_INCLUDED

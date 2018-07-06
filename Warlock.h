#ifndef WARLOCK_H_INCLUDED
#define WARLOCK_H_INCLUDED
#include  "Fighter.h"

class Warlock: virtual public Fighter
{
public:

    Warlock(char* name, double blood, unsigned int damage, int armor, unsigned int speed,unsigned int X):Fighter(name,blood,damage,armor,speed)
    {
        setX(X);
    }

    unsigned int getX() const {return X;}

    void setX(const unsigned int newX) {this->X=newX;}

    virtual void fight(Fighter& other);

    virtual void print();
private:
    unsigned int X;

};

#endif // WARLOCK_H_INCLUDED

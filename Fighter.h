#ifndef FIGHTER_H_INCLUDED
#define FIGHTER_H_INCLUDED
#include<cstring>
#include<iostream>

class Fighter{
public:
    Fighter();
    Fighter(char* name, double blood, unsigned int damage, int armor, unsigned int speed);
    Fighter(const Fighter&);
    Fighter& operator=(const Fighter&);
    virtual ~Fighter();

    const char* getName() const {return name;}
    double getBlood() const {return blood;}
    unsigned int getDamage() const {return damage;}
    int getArmor() const {return armor;}
    unsigned int getSpeed() {return speed;}

    void setBlood(const double newBlood){
        blood=newBlood;
    }

    virtual void fight(Fighter& other);

    bool isDead() {return this->blood<=0;}

    virtual void print();

private:
    char* name;
    double blood;
    unsigned int damage;
    int armor;
    unsigned int speed;

    void copy(const Fighter& other){
    if(other.name==nullptr) this->name="";
    else {
        this->name = new char[strlen(other.name)+1];
        strcpy(this->name, other.name);
        }

    this->blood=other.blood;
    this->damage=other.damage;
    this->armor=other.armor;
    this->speed=other.speed;
    }
    void clear(){
        delete[] name;
    }
};

#endif // FIGHTER_H_INCLUDED

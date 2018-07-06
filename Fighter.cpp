#include "Fighter.h"

Fighter::Fighter(){
    name="player";
    blood=50;
    damage=10;
    armor=0;
    speed=25;
}

Fighter::Fighter(char* name, double blood, unsigned int damage, int armor, unsigned int speed)
    :name(nullptr), blood(blood),damage(damage),armor(armor),speed(speed)
{
    while(this->armor<0 || this->armor>99)
    {
        std::cout<<"The armor should be between 0 and 99. Please input a new one!"<<std::endl;
        std::cin>>this->armor;
    }
    if(name==nullptr) this->name="";
    else {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        }
}


Fighter::Fighter(const Fighter& other){
    copy(other);
}

Fighter& Fighter::operator=(const Fighter& other){
    if(this!=&other){
        clear();
        copy(other);
    }
    return *this;
}

Fighter::~Fighter(){
    clear();
}


void Fighter::fight(Fighter& other){
    if(this!=&other){
    double damageTaken=((double)(100-other.armor)/100)*this->damage;
    other.blood-=damageTaken;
    std::cout<<this->name<<" attacks "<<other.name<<" for "<<damageTaken<<" damage"<<std::endl;
    if(other.blood<=0){
        std::cout<<other.name<<" died"<<std::endl;
    }
    }
    else
        std::cout<<"You cannot fight yourself!"<<std::endl;
}

void Fighter::print(){
    std::cout<<this->name<<" ";
    if(this->isDead()){
        std::cout<<"died"<<std::endl;
    }else
    std::cout<<this->blood<<" "<<this->damage<<" "<<this->armor<<" "<<this->speed<<std::endl;
}

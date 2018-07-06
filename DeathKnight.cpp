#include "DeathKnight.h"

void DeathKnight::fight(Fighter& other){
    if(this!=&other){
   double damageTaken=getDamage();
    other.setBlood(other.getBlood()-damageTaken);
    double healed = (double)this->getX()/100*damageTaken;
    this->setBlood(this->getBlood()+healed);
    std::cout<<getName()<<" attacks "<<other.getName()<<" for "<<damageTaken<<" damage"<<std::endl;
    if(other.getBlood()<=0){
        std::cout<<other.getName()<<" died"<<std::endl;
    }
    std::cout<<getName()<<" healed for "<<healed<<" damage "<<std::endl;

    }
    else
        std::cout<<"You cannot fight yourself!"<<std::endl;

    }

void DeathKnight::print(){
     Fighter::print();
        if(!this->isDead())
            std::cout<<this->getX()<<std::endl;
        }

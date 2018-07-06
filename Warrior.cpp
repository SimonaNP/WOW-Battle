#include "Warrior.h"

void Warrior::fight(Fighter& other){
     if(this!=&other){
   double damageTaken=getDamage();
    other.setBlood(other.getBlood()-damageTaken);
    std::cout<<getName()<<" attacks "<<other.getName()<<" for "<<damageTaken<<" damage"<<std::endl;
    if(other.getBlood()<=0){
        std::cout<<other.getName()<<" died"<<std::endl;
    }
     }

    else
        std::cout<<"You cannot fight yourself!"<<std::endl;

}

void Warrior::print(){
    Fighter::print();
}

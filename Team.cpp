#include "Team.h"
#include <iostream>
#include <algorithm>

void Team::setName(const char* name){
    while(name==nullptr) {
        std::cout<<"Name cannot be empty!"<<std::endl;
    }
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

Team::Team(char* name):name(nullptr){
    setName(name);
}


Team::Team(const Team& other){
    copy(other);
}

Team& Team::operator=(const Team& other){
    if(this!=&other){
        clear();
        copy(other);
    }
    return *this;
}

Team::~Team(){
    clear();
}

void Team::addFighter(Fighter& fighter){
    Fighter* ptr = &fighter;
    team.push_back(ptr);
}

void Team::print(){
    std::cout<<std::endl;
    for(int i=0;i<team.size();i++){
       team[i]->print();
    }
}

Fighter& Team::getFirst() const{
        if(team.size()==0)
            throw "This team is empty!";
        return *team.front();
    }

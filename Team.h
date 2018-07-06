#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED
#include "Fighter.h"
#include <deque>

class Team{
public:
    Team(char* name);
    Team(const Team&);
    Team& operator=(const Team&);
    ~Team();

    const char* getName() const {return  this->name;}
    unsigned int getSize() const {return team.size();}
    std::deque<Fighter*>& getTeam() {return this->team;}

    void setName(const char* name);

    void addFighter(Fighter&);

    Fighter& getFirst() const;

    void print();

private:
    char* name;
    std::deque<Fighter*> team;
    //unsigned int capacity;
    //int size=0;

    void copy(const Team& other){
        setName(other.getName());

        team.clear();
        int i=0;
        while(other.team[i]!=nullptr){
            team.push_back(other.team[i]);
            i++;
        }
        }

    void clear(){
        delete[] name;
        team.clear();
    }
};

#endif // TEAM_H_INCLUDED

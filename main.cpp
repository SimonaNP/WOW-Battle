#include <iostream>
#include "Fighter.h"
#include "Warrior.h"
#include "Warlock.h"
#include "DeathKnight.h"
#include "Team.h"

void battle(Team& t1, Team& t2)
{
    std::cout<<t1.getName()<<" vs. "<<t2.getName()<<std::endl
             <<"-----------------------------------------"<<std::endl;
    int flag=0;
    while(t1.getFirst().isDead())
    {
        t1.getTeam().pop_front();
    }
    while(t2.getFirst().isDead())
    {
        t2.getTeam().pop_front();
    }


    while(!t1.getTeam().empty() && !t2.getTeam().empty())
    {
        if(flag==0)
        {
            if(t1.getFirst().getSpeed()>=t2.getFirst().getSpeed())
            {
                t1.getFirst().fight(t2.getFirst());
                if(t2.getFirst().isDead())
                {
                    t2.getTeam().pop_front();
                    flag=2;
                }
                else
                    flag=1;
            }
            else
            {
                t2.getFirst().fight(t1.getFirst());
                if(t1.getFirst().isDead())
                {
                    t1.getTeam().pop_front();
                    flag=1;
                }
                else
                    flag=2;
            }
        }
        else if(flag==1)
        {
            t2.getFirst().fight(t1.getFirst());
            if(t1.getFirst().isDead())
            {
                t1.getTeam().pop_front();
            }
            else
                flag=2;
        }
        else if(flag==2)
        {
            t1.getFirst().fight(t2.getFirst());
            if(t2.getFirst().isDead())
            {
                t2.getTeam().pop_front();
            }
            else
                flag=1;
        }
    }

    if(!t1.getTeam().empty() && t2.getTeam().empty())
    {
        std::cout<<t1.getName()<<" WON!"<<std::endl;
    }
    if(t1.getTeam().empty() && !t2.getTeam().empty())
    {
        std::cout<<t2.getName()<<" WON!"<<std::endl;
    }
}

int main()
{
    Warrior f1("Gosho",50,15,85,50);
    Fighter f2("Pesho",15,6,20,30);
    Warlock f3("Tosho",75,58,24,66,60);
    DeathKnight f4("Misho",75,32,24,66,20);

    //f3.fight(f2);
    //f1.fight(f1);

    Team t1("Team 1"), t2("Team 2");
    t1.addFighter(f1);
    t2.addFighter(f2);
    t1.addFighter(f3);
    t2.addFighter(f4);
    std::cout<<std::endl;
    t1.print();
    std::cout<<std::endl;
    t2.print();
    std::cout<<"The size of the first team is: "<<t1.getSize()<<std::endl;

    //Fighter ptr = t.getFirst();
    //ptr.print();

    battle(t1,t2);
    //std::deque<Fighter*> que=t1.getTeam();

    //que.pop_front();std::cout<<que.size();
}

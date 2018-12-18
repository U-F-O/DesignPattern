#include "Header.h"



// Prototype Pattern
class Monster{
    
public:
    virtual Monster* clone() = 0;
};

class WellKnownMonster : public Monster{
    
public:
    Monster* clone(){
        cout << "This is well known monster" << endl;
        return (Monster*)this;
    }
};

class DynamicPlayerGeneratedMonster : public Monster{
    
public:
    Monster* clone(){
        cout << "This is dynamic monster" <<endl;
        return (Monster*)this;
    }
};

class MonsterRegister{
    WellKnownMonster wellKnowMonsters;
    DynamicPlayerGeneratedMonster dynamicPlayerGeneratedMonster;
    
public:
    Monster* getMonster(int i){
        
        
        // 1: WellKnownMonster  2:DynamicPlayerGeneratedMonster
        if(i == 0)
            return wellKnowMonsters.clone();
        else if(i == 1)
            return dynamicPlayerGeneratedMonster.clone();
        return NULL;
    }
};

class MonsterMaker{
    
public:
    static void makeRandomMonster(){
        
        int num = rand()%2;
        cout << num << endl;
        MonsterRegister* monsterRegister = new MonsterRegister;
        Monster* monster =monsterRegister->getMonster(num);

    }
    
};


class PrototypeTest{
    
public:
    
    static void test(){
        
        MonsterMaker::makeRandomMonster();
        
    }
};

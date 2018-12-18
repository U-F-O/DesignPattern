#include "Header.h"

// Memento Pattern
class GameMemento{
    
    int xpos;
    int ypos;
    
public:
    
    void savedGameState(int x,int y){
        xpos = x;
        ypos = y;
        cout <<"I'm saving game state" << endl;
    }
    
};


class MasterGameObject{
    
    GameMemento* gameMemento;
    
public:
    void setCurrent(GameMemento* gameMemento){
        this->gameMemento = gameMemento;
    }
    GameMemento* getCurrentState(){
        return gameMemento;
    }
    
    void restoreState(GameMemento* gameMemento){
        this ->gameMemento = gameMemento;
        cout<<"I'm restoring state"<<endl;
    }
    
};

class MementoTest{
    
public:
    
    static void test(){
        
        GameMemento gameMemento;
        gameMemento.savedGameState(1, 1);
        
        MasterGameObject master;
        master.setCurrent(&gameMemento);
        
        
        cout << "I'm playing "<<endl;
        
        
        master.restoreState(&gameMemento);
        
    }
};

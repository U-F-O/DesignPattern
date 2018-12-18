#include "gumballmachine.h"


class StateTest{
    
public:
    
    static void test(){
        
        GumballMachine * gumballMachine = new GumballMachine(5);
        
        gumballMachine->insertQuarter();
        gumballMachine->turnCrank();
        
        gumballMachine->insertQuarter();
        gumballMachine->turnCrank();
        
        gumballMachine->insertQuarter();
        gumballMachine->turnCrank();
        
        delete gumballMachine;
        
    }
};

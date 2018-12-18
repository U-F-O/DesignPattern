#include "gumballmachine.h"

class State {
    
public:
    
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
    virtual ~State(){}
    
};

class NoQuarterState : public State {
    
    GumballMachine* gumballMachine;
    
public:
    
    NoQuarterState(GumballMachine* gumballMachine);
    
    void insertQuarter() ;
    void ejectQuarter() ;
    void turnCrank() ;
    void dispense() ;
};

class HasQuarterState : public State {
    
    GumballMachine* gumballMachine;
    
public:
    
    HasQuarterState(GumballMachine* gumballMachine) ;
    
    void insertQuarter() ;
    void ejectQuarter() ;
    void turnCrank() ;
    void dispense() ;
    
};

class SoldState : public State {
    
    GumballMachine* gumballMachine;
    
public:
    
    SoldState(GumballMachine* gumballMachine) ;
    
    void insertQuarter() ;
    void ejectQuarter() ;
    void turnCrank() ;
    void dispense() ;
    
};

class SoldOutState : public State {
    
    GumballMachine* gumballMachine;
    
public:
    
    SoldOutState(GumballMachine* gumballMachine) ;
    
    void insertQuarter() ;
    void ejectQuarter() ;
    void turnCrank() ;
    void dispense() ;
    
};


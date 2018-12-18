

class State;

class GumballMachine {
    
    State* soldOutState;
    State* noQuarterState;
    State* hasQuarterstate;
    State* soldState;
    State* winnerState;
    
    State* state;
    int count = 0;
    
public:
    GumballMachine(int numberGumballs);
    
    State* getSoldOutState();
    
    State* getNoQuarterState();
    
    State* getHasQuarterState();
    
    State* getSoldState();
    
    State* getWinnerState();
    
    void insertQuarter();
    
    void ejectQuarter();
    
    void turnCrank();
    
    void setState (State* state);
    
    void releaseBall() ;
    
    int getCount();
    
};


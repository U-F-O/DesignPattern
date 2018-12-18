#include "state.h"
#include "Header.h"

GumballMachine::GumballMachine(int numberGumballs){
    
    soldOutState = new SoldOutState(this);
    noQuarterState = new NoQuarterState(this);
    hasQuarterstate = new HasQuarterState(this);
    soldState = new SoldState(this);
    
    this -> count = numberGumballs;
    
    if (numberGumballs > 0)
        state = noQuarterState;
    else
        state = soldOutState;
    
}

State * GumballMachine::getSoldOutState(){
    return soldOutState;
}

State * GumballMachine::getNoQuarterState(){
    return noQuarterState;
}

State * GumballMachine::getHasQuarterState(){
    return hasQuarterstate;
}

State* GumballMachine::getSoldState(){
    return soldState;
}

State* GumballMachine::getWinnerState(){
    return winnerState;
}

void GumballMachine::insertQuarter(){
    state->insertQuarter();
}

void GumballMachine::ejectQuarter() {
    state->ejectQuarter();
}

void GumballMachine::turnCrank() {
    state->turnCrank();
    state->dispense();
}


void GumballMachine::setState (State* state) {
    this->state = state;
}

void GumballMachine::releaseBall() {
    cout << "A gumball comes rolling out the slot..." <<endl;
    if(count!=0)
        --count;
}

int GumballMachine::getCount(){
    return count;
}

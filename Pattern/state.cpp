
#include "state.h"
#include "Header.h"

NoQuarterState::NoQuarterState(GumballMachine* gumballMachine) {
    this->gumballMachine = gumballMachine;
}

void NoQuarterState::insertQuarter() {
    cout << "You inserted a quarter" << endl;
    gumballMachine->setState(gumballMachine->getHasQuarterState());
    
}

void NoQuarterState::ejectQuarter() {
    cout << "You haven't inserted a quarter" << endl;
}

void NoQuarterState::turnCrank() {
    cout << "You turned, but there's no quarter"<< endl;
}

void NoQuarterState::dispense() {
    cout << "You need to pay first" << endl;
}


HasQuarterState::HasQuarterState(GumballMachine* gumballMachine) {
    this->gumballMachine = gumballMachine;
}

void HasQuarterState::insertQuarter() {
    cout << "You can't insert another quarter" << endl;
}

void HasQuarterState::ejectQuarter() {
    cout << "Quarter returned" << endl;
    gumballMachine->setState(gumballMachine->getNoQuarterState());
}

void HasQuarterState::turnCrank() {
    cout << "You turned" << endl;
    gumballMachine->setState(gumballMachine->getSoldState());
}

void HasQuarterState::dispense() {
    cout << "No gumball dispensed" << endl;
}

SoldState::SoldState(GumballMachine* gumballMachine) {
    this->gumballMachine = gumballMachine;
}

void SoldState:: insertQuarter() {
    cout << "Please wait, we're already giving you a gumball" << endl;
}

void SoldState:: ejectQuarter() {
    cout << "Sorry, you already turned the crank" << endl;
}

void SoldState:: turnCrank() {
    cout << "Turnning twice doesn't get you another gumball"<< endl;
}

void SoldState:: dispense() {
    gumballMachine->releaseBall();
    if (gumballMachine->getCount() > 0)
        gumballMachine->setState(gumballMachine->getNoQuarterState());
    else{
        cout << "Oops, out of gumballs!"<<endl;
        gumballMachine -> setState(gumballMachine->getSoldOutState());
    }
}


SoldOutState::SoldOutState(GumballMachine* gumballMachine) {
    this->gumballMachine = gumballMachine;
}

void SoldOutState::insertQuarter() {
    cout << "You can't insert a quarter, the machine is sold out" << endl;
}

void SoldOutState::ejectQuarter() {
    cout << "You can't eject, you haven't inserted a quarter yet" << endl;
}

void SoldOutState::turnCrank() {
    cout << "You turned, but there are no gumballs"<< endl;
}

void SoldOutState::dispense() {
    cout << "No gumball dispensed" << endl;
}

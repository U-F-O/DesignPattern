// DesignPattern.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class MenuItem {
	string name;
	string description;
	bool vegetarian;
	double price;

public:
	MenuItem(){ }
	MenuItem(string name, string description, bool vegetarian, double price)
	{
		this->name = name;
		this->description = description;
		this->vegetarian = vegetarian;
		this->price = price;
	}

	string getName() { return name; }

	string getDescription() { return description; }

	double getPrice() { return price; }

	bool isvegetarian() { return vegetarian; }

};

class PancakeHouseMenu {
	vector<MenuItem> menuItems;
public:

	PancakeHouseMenu() {
		addItem("A_PancakeHouse", "This is A_PancakeHouse", true, 1.99);
		addItem("B_PancakeHouse", "This is B_PancakeHouse", true, 2.00);
		addItem("C_PancakeHouse", "This is C_PancakeHouse", false, 2.99);
		addItem("D_PancakeHouse", "This is D_PancakeHouse", false, 3.00);
	}

	void addItem(string name, string description, bool vegetarian, double price)
	{
		MenuItem menuItem(name, description, vegetarian, price);
		menuItems.push_back(menuItem);
	}

	vector<MenuItem>& getMenuItems()
	{
		return menuItems;
	}
};

class DinerMenu {
	static const int MAX_ITEMS = 6;
	int numberOfItems = 0;
	MenuItem menuItems[MAX_ITEMS];

public:

	DinerMenu()
	{
		addItem("A_DinerMenu", "This is A_DinerMenu", true, 1.99);
		addItem("B_DinerMenu", "This is B_DinerMenu", true, 2.00);
		addItem("C_DinerMenu", "This is C_DinerMenu", false, 2.99);
		addItem("D_DinerMenu", "This is D_DinerMenu", false, 3.00);
	}

	void addItem(string name, string description, bool vegetarian, double price)
	{
		MenuItem menuItem(name, description, vegetarian, price);
		if (numberOfItems >= MAX_ITEMS)
			cout << "Sorry, menu is full!" << endl;
		else
			menuItems[numberOfItems++] = menuItem;
	}

	MenuItem* getMenuItems()
	{
		return menuItems;
	}

};






// proxy pattern



// state pattern

static const int SOLD_OUT = 0;
static const int NO_QUARTER = 0;
static const int HAS_QUARTER = 0;
static const int SOLD = 0;
                                         
int state = SOLD_OUT;

class State {

public:

	virtual void insertQuarter() = 0;
	virtual void ejectQuarter() = 0;
	virtual void turnCrank() = 0;
	virtual void dispense() = 0;

};

class NoQuarterState : public State {
	GumballMachine* gumballMachine;

public:

	NoQuarterState(GumballMachine* gumballMachine) {
		this->gumballMachine = gumballMachine;
	}

	void insertQuarter() {                                                                                                                                                                                             
		cout << "You inserted a quarter" << endl;
		// 
	}

	void ejectQuarter() {
		cout << "You haven't inserted a quarter" << endl;
	}
	
	void turnCrank() {
		cout << "You turned, but there's no quarter"<< endl;
	}

	void dispense() {
		cout << "You need to pay first" << endl;
	}

};

class HasQuarterState : public State {
	GumballMachine* gumballMachine;

public:

	HasQuarterState(GumballMachine* gumballMachine) {
		this->gumballMachine = gumballMachine;
	}

	void insertQuarter() {
		cout << "You can't insert another quarter" << endl;
			}

	void ejectQuarter() {
		cout << "Quarter returned" << endl;
		//
	}

	void turnCrank() {
		cout << "You turned, but there's no quarter") << endl;
		// 
	}

	void dispense() {
		cout << "No gumball dispensed" << endl;
	}

};

class SoldState : public State {
	GumballMachine* gumballMachine;

public:

	SoldState(GumballMachine* gumballMachine) {
		this->gumballMachine = gumballMachine;
	}

	void insertQuarter() {
		cout << "Please wait, we're already giving you a gumball" << endl;
		// 
	}

	void ejectQuarter() {
		cout << "Sorry, you already turned the crank" << endl;
	}

	void turnCrank() {
		cout << "Turnning twice doesn't get you another gumball"<< endl;
	}

	void dispense() {
		
		//
	}
};

class SoldOutState : public State {
	GumballMachine* gumballMachine;

public:

	SoldOutState(GumballMachine* gumballMachine) {
		this->gumballMachine = gumballMachine;
	}

	void insertQuarter() {
		cout << "You can't insert a quarter, the machine is sold out" << endl;
		// 
	}

	void ejectQuarter() {
		cout << "You can't eject, you haven't inserted a quarter yet" << endl;
	}

	void turnCrank() {
		cout << "You turned, but there are no gumballs"<< endl;
	}

	void dispense() {
		cout << "No gumball dispensed" << endl;
	}
};

class GumballMachine {
	
	State* soldOutState;
	State* noQuarterState;
	State* hasQuarterstate;
	State* soldState;
	State* winnerState;

	State* state = soldOutState;

public:

	void insertQuarter(){

	}

	void ejectQuarter() {

	}

	void turnCrank() {

	}

	void setState (State* state) {
		this->state = state; 
	}

	void releaseBall() {

	}

};

int main()
{

	DinerMenu temp;
	MenuItem * tempp =temp.getMenuItems();
	cout << tempp[2].getDescription() << endl;

	system("pause");
    return 0;
}


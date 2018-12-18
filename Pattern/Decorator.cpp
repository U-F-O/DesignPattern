#include "Header.h"

// Decorator Pattern

class Beverage{
    
protected:
    string description = "Unknown Beverage";
    
public:
    
    virtual string getDescription() {
        return description;
    }
    
};


class Espresso :public Beverage{
    
public:
    
    Espresso(){
        description = "Espresso";
    }
    
};

class CondimentDecorator: public Beverage{
    
public:
    virtual string getDescription() = 0;
    
};

class Mocha: public CondimentDecorator{
    
    Beverage* beverage;
    
public:
    
    Mocha(Beverage* beverage){
        this -> beverage = beverage;
    }
    
    string getDescription(){
        return beverage->getDescription()+", Mocha";
    }
    
};

class DecoratorTest{
    
public:
    
    static void test(){
        Beverage* beverage = new Espresso;
        cout << beverage->getDescription() << endl;
        beverage = new Mocha(beverage);
        cout << beverage->getDescription() << endl;
        beverage = new Mocha(beverage);
        cout << beverage->getDescription()<<endl;

    }
    
};


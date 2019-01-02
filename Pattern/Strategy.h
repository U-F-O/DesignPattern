#include "Header.h"

class Quackable {
    
public:
    
    virtual void quack() = 0;
    virtual ~Quackable(){}
    
};

class Quack :public Quackable {
    
    void quack(){
        cout << "        I'm quacking(gugu)" << endl;
    }
    
};

class Squeak :public Quackable {
    
    void quack() {
        cout << "        I'm quacking(zhizhi)" << endl;
    }
    
};

class MuteQuack :public Quackable {
    
    void quack() {
        cout << "        I can't quack!" << endl;
    }
    
};

class Flyable {
    
public:
    
    virtual void fly() = 0;
    virtual ~Flyable(){}
    
};

class FlyWithWings:public Flyable{
    
public:
    
    void fly() {
        cout << "        I'm flying with wings!" << endl;
    }
    
};

class FlyWithNoWing :public Flyable {
    
public:
    
    void fly() {
        cout << "        I can't fly!" << endl;
    }
    
};


class Duck {
    
public:
    
    Flyable *flyable;
    Quackable *quackable;
    
    void setFlyable(Flyable *f) { flyable = f; }
    void setQuackable(Quackable *q) { quackable = q; }
    void swim() { cout << "        I'm swimming!" << endl; }
    void quack() { quackable->quack(); }
    void fly() { flyable->fly(); }
    virtual void display() = 0;
    virtual ~Duck(){}
    
};


class MallardDuck :public Duck{
    
public:
    
    MallardDuck() {
        flyable = new FlyWithWings();
        quackable = new Squeak();
    }
    
    void display() {
        cout << "This is Mallard Duck:" << endl;
    }
    
};

class RedHeadDuck :public Duck  {
    
public:
    
    RedHeadDuck() {
        flyable = new FlyWithWings();
        quackable = new Quack();
    }
    
    void display() {
        cout << "This is Red Head Duck:" << endl;
    }
    
};

class RubberDuck :public Duck {
    
public:
    
    RubberDuck() {
        flyable = new FlyWithNoWing();
        quackable = new MuteQuack();
    }
    
    void display() {
        cout << "This is Rubber Duck:" << endl;
    }
    
};

class StrategyTest{
    
public:
    
    static void test(){
        
        Duck* mallardDuck = new MallardDuck;
        Duck* redheadDuck = new RedHeadDuck;
        Duck* rubberDuck = new RubberDuck;
        
        mallardDuck->display();
        mallardDuck->quack();
        mallardDuck->fly();
        redheadDuck->display();
        redheadDuck->quack();
        redheadDuck->fly();
        rubberDuck->display();
        rubberDuck->quack();
        rubberDuck->fly();
        
        delete mallardDuck;
        delete redheadDuck;
        delete rubberDuck;
        
    }
};

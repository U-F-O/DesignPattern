#include "Header.h"


// adapter pattern

class DuckAda{
    
public:
    
    virtual void quack() = 0 ;
    
    virtual void fly() = 0;
    
};



class MallardDuckAda : public DuckAda{
    
public:
    
    void quack(){
        
        cout << "Mallard Duck quack" << endl;
        
    }
    
    void fly(){
        
        cout << "I'm flying" << endl;
        
    }
    
};



class Turkey{
    
    
public:
    
    void gobble(){
        
        cout << "Gobble gobble" << endl;
        
    }
    
    
    
    void fly(){
        
        cout << "I'm flying a short distance" << endl;
        
    }
    
    
    
};



// object adapter

class TurkeyAdapter: public DuckAda{
    
    Turkey* turkey;
    
public:
    
    
    TurkeyAdapter(Turkey * turkey){
        
        this -> turkey = turkey;
        
    }
    
    void quack(){
        
        turkey->gobble();
        
    }
    
    
    void fly(){
        
        for(int i = 0 ; i < 5; ++i)
            
            turkey->fly();
        
    }
    
};

class AdapterTest{
    
public:
    
    static void test(){
        Turkey * turkey = new Turkey;
        DuckAda* duck = new TurkeyAdapter(turkey);
        
        duck->quack();
        duck->fly();
        
    }
};

// template method pattern
#include "Header.h"

class CaffeineBeverage{
    
public:
    
    virtual void prepareRecipe() final{
        boilWater();
        brew();
        pourInCup();
        addCondiments();
    }
    
    virtual void brew() = 0;
    virtual void addCondiments() = 0;
    
    void boilWater(){
        cout << "Boiliing water" <<endl;
    }
    
    void pourInCup() {
        cout<< "Pouring into Cup" << endl;
    }
    
    virtual ~CaffeineBeverage(){}
    
};

class Tea:public CaffeineBeverage{
    
public:
    
    void brew(){
        cout << "Steeping the tea" <<endl;
    }
    
    void addCondiments(){
        cout <<"Adding Lemon" << endl;
    }
    
};

class Coffee:public CaffeineBeverage{
    
public:
    
    void brew(){
        cout <<"Dripping Coffee through filter" << endl;
    }
    
    void addCondiments(){
        cout <<"Adding Sugar and Milk" << endl;
    }
    
};


class TemplateTest{
    
public:
    
    static void test(){
        
        Tea* tea =  new Tea;
        Coffee* coffee = new Coffee;
        cout << "~~~~~drinking tea~~~~~" << endl;
        tea->prepareRecipe();
        cout << "~~~~~drinking coffee~~~~~" << endl;
        coffee->prepareRecipe();
        
        delete tea;
        delete coffee;
    }
};

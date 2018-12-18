#include "Header.h"

class TV{
    
public:
    
    virtual void on() = 0;
    virtual void off()= 0;
    virtual ~TV(){}
    
};



class RCA : public TV{
    
public:
    
    void on(){cout<<"RCA's on" << endl;}
    void off(){cout<<"RCA's off" <<endl;}
    
};



class Sony : public TV{
    
public:
    
    void on(){cout<<"Sony's on Sony"<<endl;}
    void off(){cout<<"Sony's off Sony" << endl;}
    
};

class RemoteControl_Bridge{
    
protected:
    
    TV * tv;
    
public:
    
    virtual void on() = 0;
    virtual void off() = 0;
    virtual ~RemoteControl_Bridge(){};
    
};



class ConcreteRemote: public RemoteControl_Bridge{
    
public:
    
    ConcreteRemote(TV *tv){
        this -> tv = tv;
    }
    
    void on(){
        tv->on();
    }
    
    void off(){
        tv->off();
    }
    
    void nextChannel(){

        cout << "next channel" << endl;
    
    }
    
    void previousChannel(){

        cout << "previous channel" <<endl;
    }
    
};


class BridgeTest{
    
public:
    
    static void test(){
        
        TV* sony = new Sony;
        TV* rca = new RCA;
        
        ConcreteRemote* remote = new ConcreteRemote(sony);
        remote->on();
        remote->nextChannel();
        remote->previousChannel();
        remote->off();
        
        ConcreteRemote* remote2 = new ConcreteRemote(rca);
        remote2->on();
        remote2->nextChannel();
        remote2->previousChannel();
        remote2->off();
        
        delete sony;
        delete rca;
        delete remote;
        delete remote2;

    }
};

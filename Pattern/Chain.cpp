// Chain of Responsibility Pattern
#include "Header.h"

class Handler{
    
protected:
    
    Handler* successor;
    
public:
    
    virtual void handleRequest() = 0;
    
    virtual void setNext(Handler* next) = 0;
    
    Handler* getNext(){ return successor;}
    
    virtual ~Handler(){}
    
};

class SpamHandler: public Handler{
    
public:
    
    void handleRequest(){
        cout <<"This is handling spam" <<endl;
    }
    
    void setNext(Handler* next){
        this -> successor = next;
    }
};

class FanHandler: public Handler{
    
public:
    
    void handleRequest(){
        cout <<"This is handling fan" <<endl;
    }
    
    void setNext(Handler* next){
        this -> successor = next;
    }
    
    
};

class ComplaintHandler: public Handler{
    
public:
    
    void handleRequest(){
        cout <<"This is handling complaint" <<endl;
    }
    
    void setNext(Handler* next){
        this -> successor = next;
    }
};

class NewLocHandler: public Handler{
    
public:
    
    void handleRequest(){
        cout <<"This is handling new location" <<endl;
    }
    
    void setNext(Handler* next){
        this -> successor = next;
    }
    
};

class ChainTest{
    
public:
    
    static void test(){
        
        Handler* handler = new SpamHandler;
        Handler* handler1 = new FanHandler;
        Handler* handler2 = new ComplaintHandler;
        Handler* handler3 = new NewLocHandler;
        
        handler->setNext(handler1);
        handler1->setNext(handler2);
        handler2->setNext(handler3);
        handler3->setNext(NULL);
        
        while(handler!=NULL){
            handler -> handleRequest();
            handler = handler->getNext();
        }
        
        delete handler;
        delete handler1;
        delete handler2;
        delete handler3;
        
    }
};

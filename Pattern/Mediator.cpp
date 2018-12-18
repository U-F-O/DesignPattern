#include "Header.h"

class Thing{
    
public:
    
    virtual void onEvent() = 0;
    
};

// mediator pattern
class Alarm :public Thing{
    
public:
    void onEvent(){
        cout << "This is alarm" << endl;
    }
};

class Calendar: public Thing{
    
public:
    void onEvent(){
        cout << "This is calendar" << endl;
    }
};

class Sprinkle: public Thing{
    
public:
    void onEvent(){
        cout << "This is sprinkle" << endl;
    }
};



class Mediator{
    
    Alarm* alarm;
    Calendar* calendar;
    Sprinkle* sprinkle;
    
public:
    
    void regist(Thing* thing){
        
        if(typeid(*thing) == typeid(Alarm))
            alarm = (Alarm*)thing;
        else if(typeid(*thing) == typeid(Calendar))
            calendar = (Calendar*)thing;
        else if(typeid(*thing) == typeid(Sprinkle))
            sprinkle=(Sprinkle*)thing;
        
    }
    
    void play(Thing* thing){
        if(typeid(*thing) == typeid(Alarm)){
            alarm->onEvent();
            calendar->onEvent();
            sprinkle->onEvent();
        }
        else if(typeid(*thing) == typeid(Calendar)){
            calendar->onEvent();
            sprinkle->onEvent();
        }
        else if(typeid(*thing) == typeid(Sprinkle))
            sprinkle->onEvent();
    }
    
};


class MediatorTest{
    
public:
    
    static void test(){
        
        Mediator* mediator = new Mediator;
        
        Alarm alarm;
        Calendar calendar;
        Sprinkle sprinkle;
        
        mediator -> regist(&alarm);
        mediator -> regist(&calendar);
        mediator -> regist(&sprinkle);
        
        mediator -> play(&alarm);
        mediator -> play(&calendar);
        mediator -> play(&sprinkle);
    }
};

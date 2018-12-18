#include "Header.h"


class Vacation{
    
    vector<string> steps;
    
public:
    
    void addStep(string step){
        cout << "adding " << step << endl;
        steps.push_back(step);
        
    }
    
};

// builder pattern

class AbstractBuilder{
    
public:
    
    virtual void buildDay() = 0;
    
    virtual void addHotel() = 0;
    
    virtual void addReservation() = 0;
    
    virtual void addSpecialEvent() = 0;
    
    virtual Vacation* getVacationPlanner() = 0;
    
};



class VacationBuilder : public AbstractBuilder{
    
    Vacation* vacation;
    
public:
    
    VacationBuilder(){ vacation = new Vacation;}
    
    
    void buildDay(){
        
        vacation->addStep("build day");
        
    }
    
    void addHotel(){
        
        vacation->addStep("add hotel");
        
    }
    
    void addReservation(){
        
        vacation->addStep("add reservation");
        
    }
    
    void addSpecialEvent(){
        
        vacation->addStep("add speciation event");
        
    }
    
    Vacation* getVacationPlanner() {
        
        return vacation;
        
    }
    
};


class BuilderTest{
    
public:
    
    static void test(){
        
        AbstractBuilder* builder = new VacationBuilder();
        
        builder->addHotel();
        builder->addReservation();
        builder->addSpecialEvent();
        
    }
};


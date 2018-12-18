
#include "Header.h"



class Singleton{
    
private:
    
    Singleton(){}

    static Singleton* uniqueInstance;
    
public:
    
    static Singleton* getInstance(){
        
         if(uniqueInstance == NULL){
         
             cout << "This is the first instance" << endl;
             uniqueInstance = new Singleton;
         
         }
         else
             cout << "This is not the first instance" <<endl;
        
        return uniqueInstance;
    }
    
};

//Singleton* Singleton::uniqueInstance = NULL;

class SingletonTest{
    
public:
    
    static void test(){

        Singleton* test1 = Singleton::getInstance();
        Singleton* test2 = Singleton::getInstance();
        
        if(test2 == test1)
            delete test1;
        else{
            delete test1;
            delete test2;
        }

    }
};


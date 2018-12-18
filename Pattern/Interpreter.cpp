#include "Header.h"
#include <map>


class Context{
    
private:
    map<string, int> mp;
    
public:
    void insert(string str, int num){
        mp.insert(pair<string, int>(str,num));
    }
    
    double getKey(string str){
        return (double)mp[str];
    }
    
};

class Expression{
    
public:
    
    virtual double interpret(Context* context) = 0;
    virtual ~Expression(){}
    
};

class Variable: public Expression{
    
    string key;
    
public:
    
    Variable(string key){
        
        this ->key = key;
        
    }
    double interpret(Context* context){
        
        return context -> getKey(key);
        
    }
    
    string getKey(){
        
        return key;
        
    }
    
};

class FlyCommand: public Expression{
    
    string key;
    
public:
    
    FlyCommand(string key){
        
        this ->key = key;
        
    }
    
    double interpret(Context* context){
        
        return context -> getKey(key);
        
    }
    
};

class AddExpression: public Expression{
    
    Variable* variable1;
    Variable* variable2;
    
public:
    
    AddExpression(Variable* variable1,Variable* variable2){
        this->variable1 = variable1;
        this->variable2 = variable2;
    }
    
    double interpret(Context* context){
        
        double a = variable1->interpret(context);
        double b = variable2->interpret(context);
        
        return a + b;
    }
    
};


class InterpretTest{
    
public:
    
    static void test(){
        
        Context context;
        context.insert("1", 2);
        Variable var1("1");
        Variable var2("1");
        AddExpression addExpression(&var1,&var2);
        
        cout << addExpression.interpret(&context)<<endl;
        
    }
};

#include "Header.h"

// visitor pattern

class ConcreteElement1;
class ConcreteElement2;

class Visitor{
    
public:
    
    virtual void visit(ConcreteElement1* concreteElement1) = 0;
    virtual void visit(ConcreteElement2* concreteElement2) = 0;
    virtual ~Visitor(){};
    
};


class Element{
    
protected:
    
    string what;
    
public:
    
    void display(){ cout << what <<endl;}
    virtual void accept(Visitor* ) = 0;
    virtual~ Element(){}
    
};

class ConcreteElement1:public Element{
    
public:
    
    ConcreteElement1(string str){this -> what = str;}
    
    void accept(Visitor* vs){
        vs->visit(this);
    }
};

class ConcreteElement2:public Element{
    
public:
    
    ConcreteElement2(string str){this -> what = str;}
    
    void accept(Visitor* vs){
        vs->visit(this);
    }
    
};

class ObjectStructure{
    
    vector<Element* >elements;
    
public:
    
    void add(Element* ele){
        elements.push_back(ele);
    }
    
    void search(Visitor* vs){
        for(int i = 0 ; i < elements.size(); ++i){
            elements[i]->accept(vs);
        }
    }
    
};

class Visitor1:public Visitor{
    
public:
    
    void visit(ConcreteElement1* concreteElement1){
        cout << "Vistor 1 , ConcreteElement1: ";
        concreteElement1->display();
    }
    
    void visit(ConcreteElement2* concreteElement2){
        cout << "Vistor 1 , ConcreteElement2: ";
        concreteElement2->display();
    }
    
};

class Visitor2:public Visitor{
    
public:
    
    void visit(ConcreteElement1* concreteElement1){
        cout << "Vistor 2 ,ConcreteElement1: ";
        concreteElement1->display();
    }
    
    void visit(ConcreteElement2* concreteElement2){
        cout << "Vistor 2 ,ConcreteElement2: ";
        concreteElement2->display();
    }
    
};

class VisitorTest{
    
public:
    
    static void test(){
        
        ObjectStructure client;
        ConcreteElement1 conEle1("concrete element 1");
        ConcreteElement2 conEle2("concrete element 2");

        client.add(&conEle1);
        client.add(&conEle2);
        
        Visitor1 vs1;
        Visitor2 vs2;
        
        client.search(&vs1);
        client.search(&vs2);
        
    }
};

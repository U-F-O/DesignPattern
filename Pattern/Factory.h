#include "Header.h"

class Pizza{
    
protected:
    
    string name;
    string dough;
    string sauce;
    vector<string>toppings;
    
public:
    
    virtual void prepare(){
        
        cout << "Preparing " << name<<endl;
        cout << "Tossing dough..."<<endl;
        cout << "Adding sauce..." << endl;
        cout << "Adding toppings: "<<endl;
        
        for(int i = 0 ; i < toppings.size(); ++i){
            cout << toppings[i]<<endl;
        }
        
    }
    
    virtual void bake(){
        cout << "Bake for 25 minutes at 350" << endl;
    }
    
    virtual void cut(){
        cout << "Cutting the pizza into diagonal slices" << endl;
    }
    
    virtual void box(){
        cout << "Place pizza in official PizzaStore box" << endl;
    }
    
    string getName(){
        return name;
    }
    
    virtual ~Pizza(){}
    
};

class NYStyleCheesePizza: public Pizza{
    
public:
    
    NYStyleCheesePizza(){
        
        name = "NY Style Sauce and Cheese Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        
        toppings.push_back("Grated Reggiano Cheese");
    }
    
};

class NYStylepepperoniPizza: public Pizza{
    
public:
    
    NYStylepepperoniPizza(){
        
        name = "NY Style Sauce and pepperoni Pizza";
        dough = "Thin Crust Dough";
        sauce = "Marinara Sauce";
        
        toppings.push_back("Grated Reggiano Cheese");
    }
    
};

class PizzaStore{
    
public:
    
    virtual Pizza* createPizze(string type)=0;
    
    Pizza* orderPizza(string type){
        
        Pizza* pizza = createPizze(type);
        pizza -> prepare();
        pizza -> bake();
        pizza -> cut();
        pizza -> box();
        
        return pizza;
    }
    
    virtual ~PizzaStore(){}
    
};

class NYStylePizzaStore : public PizzaStore{
    
public:
    
    Pizza* createPizze(string type){
        if(type == "cheese")
            return new NYStyleCheesePizza();
        else if (type == "pepperoni")
            return new NYStylepepperoniPizza();
        else
            return NULL;
    }
    
};

class ChicagoStyleCheesePizza:public Pizza{
    
public:
    
    ChicagoStyleCheesePizza(){
        
        name = "Chicago Style Deep Dish Cheese Pizza";
        dough = "Extra Thick Crust Dough";
        sauce = "Plum Tomato Sauce";
        
        toppings.push_back("Shredded Mozzarella Cheese");
    }
    
};

class ChicagoStylepepperoniPizza:public Pizza{
    
public:
    
    ChicagoStylepepperoniPizza(){
        
        name = "Chicago Style Deep Dish pepperoni Cheese Pizza";
        dough = "pepperoni";
        sauce = "Plum Tomato Sauce";
        
        toppings.push_back("Chicago pepperoni Cheese");
    }
    
    void cut(){
        cout << "Cutting the pizza into square slices" <<endl;
    }
    
};

class ChicagoStylePizzaStore : public PizzaStore{
    
public:
    
    Pizza* createPizze(string type){
        if(type == "cheese")
            return new ChicagoStyleCheesePizza();
        else if (type == "pepperoni")
            return new ChicagoStylepepperoniPizza();
        else
            return NULL;
    }
    
};


class FactoryTest{
    
public:
    
    static void test(){
        
        PizzaStore * nyStore = new NYStylePizzaStore;
        PizzaStore * chicagoStore = new ChicagoStylePizzaStore;
        
        Pizza* pizza = nyStore->orderPizza("cheese");
        
        pizza = chicagoStore->orderPizza("pepperoni");
        
        delete nyStore;
        delete chicagoStore;
        delete pizza;
        
    }
};

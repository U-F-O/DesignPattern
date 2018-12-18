#include "Header.h"


class Dough{
    
protected:
    
    string name;
    
};

class ThinCrustDough: public Dough{
    
public:
    ThinCrustDough(){
        name = "I'm thin crust dough";
    }
};

class Sauce{
    
protected:
    string name;
    
};

class MarinaraSauce: public Sauce{
    
public:
    MarinaraSauce(){
        name =  "I'm MarinaraSauce";
    }
};

class Cheese{
    
protected:
    
    string name;
    
};

class ReggianoCheese: public Cheese{
    
public:
    
    ReggianoCheese(){
        name = "I'm ReggianoCheese";
    }
    
};

class  PizzaIngredientFactory{
    
public:
    virtual Dough* createDough() = 0;
    virtual Sauce* createSauce() = 0;
    virtual Cheese* createCheese() = 0;
    
};

class NYPizzaIngredientFactory : public PizzaIngredientFactory{
    
public:
    
    Dough* createDough(){
        return new ThinCrustDough();
    }
    
    Sauce* createSauce(){
        return new MarinaraSauce();
    }
    
    Cheese* createCheese(){
        return new ReggianoCheese();
    }
    
};



class AbstractPizza{
    
protected:
    string name;
    Dough* dough;
    Sauce* sauce;
    Cheese* cheese;
    vector<string>toppings;
    
    
public:
    virtual void prepare()  = 0;
    
    void bake(){
        cout << "Bake for 25 minutes at 350" << endl;
    }
    
    void cut(){
        cout << "Cutting the pizza into diagonal slices" << endl;
    }
    
    void box(){
        cout << "Place pizza in official PizzaStore box" << endl;
    }
    
    string getName(){
        return name;
    }
    
    void setName(string name){
        this -> name = name;
    }
};

class AbstractCheesePizza : public AbstractPizza{
    
    PizzaIngredientFactory * ingredientFactory;
    
public:
    
    AbstractCheesePizza(PizzaIngredientFactory * ingredientFactory){
        name = "AbstractCheesePizza";
        this -> ingredientFactory = ingredientFactory;
    }
    
    void prepare(){
        cout << "Preparing " << name << endl;
        dough = ingredientFactory->createDough();
        sauce = ingredientFactory->createSauce();
        cheese = ingredientFactory->createCheese();
    }
};

class AbstractClamPizza : public AbstractPizza{
    
    PizzaIngredientFactory * ingredientFactory;
    
public:
    
    AbstractClamPizza(PizzaIngredientFactory * ingredientFactory){
        name = "AbstractClamPizza";
        this -> ingredientFactory = ingredientFactory;
    }
    
    void prepare(){
        cout << "Preparing " << name << endl;
        dough = ingredientFactory->createDough();
        sauce = ingredientFactory->createSauce();
        cheese = ingredientFactory->createCheese();
    }
};

class AbstractPizzaStore{
    
public:
    virtual AbstractPizza* createPizze(string type)=0;
    
    AbstractPizza* orderPizza(string type){
        
        AbstractPizza* pizza = createPizze(type);
        pizza -> prepare();
        pizza -> bake();
        pizza -> cut();
        pizza -> box();
        
        return pizza;
    }
};

class AbstractNYStylePizzaStore: public AbstractPizzaStore{
    
public:
    
    AbstractPizza* createPizze(string item){
        
        AbstractPizza * pizza = NULL;
        PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory;
        
        if(item == "cheese")
        {
            pizza = new AbstractCheesePizza(ingredientFactory);
            pizza -> setName("NY Style pizza");
        }
        else if (item == "clam")
        {
            pizza =  new AbstractClamPizza(ingredientFactory);
            pizza -> setName("Clam Style pizza");
        }
        
        return pizza;
        
    }
    
};

class AbstractChicagoStylePizzaStore : public AbstractPizzaStore{
    
public:
    AbstractPizza* createPizze(string type){
        
        AbstractPizza * pizza = NULL;
        PizzaIngredientFactory* ingredientFactory = new NYPizzaIngredientFactory;
        
        if(type == "cheese")
        {
            pizza = new AbstractCheesePizza(ingredientFactory);
            pizza -> setName("Chicago  chees Style pizza");
        }
        else if (type == "clam")
        {
            pizza =  new AbstractClamPizza(ingredientFactory);
            pizza -> setName("Chicago clam Style pizza");
        }
        return pizza;
    }
};





class AbstractFactoryTest{
    
public:
    
    static void test(){
        
        AbstractPizzaStore * nyStore = new AbstractNYStylePizzaStore;
        AbstractPizzaStore * chicagoStore = new AbstractChicagoStylePizzaStore;
        
        AbstractPizza* pizza = nyStore->orderPizza("cheese");
        
        pizza = chicagoStore->orderPizza("clam");
        
    }
};

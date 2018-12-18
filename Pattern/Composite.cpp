
#include "Header.h"

class MenuComponent{
public:
    virtual void add(MenuComponent*){}
   // virtual MenuComponent* getChild(int);
    virtual string getName() = 0;
    virtual void print() = 0;
};

class MenuItemCom: public MenuComponent{
    string name;
public:
    MenuItemCom(string name){this -> name = name;}
    string getName(){return name;}
    void print(){
        cout << name << endl;
    }
};

class MenuCom:public MenuComponent{
    
    vector<MenuComponent*> menuComponents;
    string name;
    
public:
    
    MenuCom(string name){this -> name = name;}
    
    void add(MenuComponent* menucomponent){
        menuComponents.push_back(menucomponent);
    }
    
 //   MenuComponent* getChild(int num){
   //     return menuComponents[num];
    //}
    
    string getName(){return name;}
    
    void print(){
        for(int i = 0 ; i < menuComponents.size(); ++i){   // This can also use iterator here. We can use both/
            menuComponents[i]->print();
        }
    }
};

class WaitressCom{
    MenuComponent* allMenus;
    
public:
    WaitressCom(MenuComponent* menuComponent){
        this -> allMenus = menuComponent;
    }
    
    void printMenu(){
        allMenus -> print();
    }
};

class CompositeTest{
    
public:
    
    static void test(){
        
       MenuComponent* pancake = new MenuItemCom("Pan Cake");
        MenuComponent* dinnerMenu = new MenuItemCom("dinnerMenu");
        MenuComponent* launchMenu = new MenuItemCom("launch");
        
        MenuComponent* allMenu = new MenuCom("All Menus");
        allMenu->add(pancake);
        allMenu->add(dinnerMenu);
        allMenu->add(launchMenu);

        WaitressCom* waitress = new WaitressCom(allMenu);
        waitress -> printMenu();
        
    }
};


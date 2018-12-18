#include "Header.h"


class MenuItem {
    
    string name;
    string description;
    bool vegetarian;
    double price;
    
public:
    
    MenuItem(){ }
    
    MenuItem(string name, string description, bool vegetarian, double price)
    {
        this->name = name;
        this->description = description;
        this->vegetarian = vegetarian;
        this->price = price;
    }
    
    string getName() { return name; }
    
    string getDescription() { return description; }
    
    double getPrice() { return price; }
    
    bool isvegetarian() { return vegetarian; }
    
};

class Iterator{
    
public:
    
    virtual bool hasNext() = 0;
    virtual MenuItem* next() = 0;
    virtual ~Iterator(){};
    
};

class DinerMenuIterator:public Iterator{
    
    MenuItem* menuItems;
    int len;
    int pos;
    
public:
    
    DinerMenuIterator(MenuItem* menuItem,int len){
        menuItems = menuItem;
        this->len = len;
        pos = 0;
    }
    
    MenuItem* next(){
        MenuItem* menuItem = &menuItems[pos++];
        return menuItem;
    }
    
    bool hasNext(){
        return (pos>=len)?false:true;
    }
    
};

class BreakfastMenuIterator:public Iterator{
    
    vector<MenuItem> menuItems;
    int pos;
    
public:
    
    BreakfastMenuIterator(vector<MenuItem>& menuItems){
        pos = 0;
        this->menuItems = menuItems;
    }
    
    MenuItem* next(){
        return &menuItems[pos++];
    }
    
    bool hasNext(){
        return (pos>=menuItems.size())?false:true;
    }
    
};

class PancakeHouseMenu {
    
    vector<MenuItem> menuItems;
    
public:
    
    PancakeHouseMenu() {
        
        addItem("A_PancakeHouse", "This is A_PancakeHouse", true, 1.99);
        addItem("B_PancakeHouse", "This is B_PancakeHouse", true, 2.00);
        addItem("C_PancakeHouse", "This is C_PancakeHouse", false, 2.99);
        addItem("D_PancakeHouse", "This is D_PancakeHouse", false, 3.00);
        
    }
    
    void addItem(string name, string description, bool vegetarian, double price)
    {
        MenuItem menuItem(name, description, vegetarian, price);
        menuItems.push_back(menuItem);
    }
    
    Iterator* createIterator()
    {
        return new BreakfastMenuIterator(menuItems);
    }
};

class DinerMenu {
    
    static const int MAX_ITEMS = 6;
    int numberOfItems = 0;
    MenuItem menuItems[MAX_ITEMS];
    
public:
    
    DinerMenu()
    {
        addItem("A_DinerMenu", "This is A_DinerMenu", true, 1.99);
        addItem("B_DinerMenu", "This is B_DinerMenu", true, 2.00);
        addItem("C_DinerMenu", "This is C_DinerMenu", false, 2.99);
        addItem("D_DinerMenu", "This is D_DinerMenu", false, 3.00);
    }
    
    void addItem(string name, string description, bool vegetarian, double price)
    {
        MenuItem menuItem(name, description, vegetarian, price);
        if (numberOfItems >= MAX_ITEMS)
            cout << "Sorry, menu is full!" << endl;
        else
            menuItems[numberOfItems++] = menuItem;
    }
    
    /* MenuItem* getMenuItems()
     {
     return menuItems;
     }*/
    
    Iterator* createIterator()
    {
        return new DinerMenuIterator(menuItems,MAX_ITEMS);
    }
    
};

class Waitress{
    
    PancakeHouseMenu* pancakeHouseMenu;
    DinerMenu* dinerMenu;
    
public:
    
    Waitress(PancakeHouseMenu* pancakeHouseMenu, DinerMenu* dinerMenu){
        
        this -> pancakeHouseMenu = pancakeHouseMenu;
        this -> dinerMenu = dinerMenu;
        
    }
    
    void printWaitress(){
        
        Iterator* pancakeIterator = pancakeHouseMenu->createIterator();
        Iterator* dinnerIterator = dinerMenu->createIterator();
        
        cout<< " -- breakfast -- "<<endl;
        
        printMenu(pancakeIterator);
        
        cout<< " -- dinner -- "<<endl;
        
        printMenu(dinnerIterator);
        
    }
    
    void printMenu(Iterator* iterator){
        
        while(iterator->hasNext()){
            
            MenuItem* menuitem = (MenuItem*)iterator->next();
            
            cout << menuitem->getName() <<" ";
            
        }
        
        cout << endl;
    }
    
};


class IteratorTest{
    
public:
    
    static void test(){
        
        PancakeHouseMenu* pancakeHouseMenu = new PancakeHouseMenu;
        DinerMenu* dinnerMenu = new DinerMenu;
        
        Waitress* waitress = new Waitress(pancakeHouseMenu,dinnerMenu);
        
        waitress -> printWaitress();
        
        delete pancakeHouseMenu;
        delete dinnerMenu;
        delete waitress;
        
    }
};

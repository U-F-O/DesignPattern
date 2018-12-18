// Flyweight Pattern
#include "Header.h"

class Tree{
    
public:
    
    void display(int x, int y){
        cout <<"("<<x<<","<<y<<")"<<endl;
    }
    
};

class TreeManager{
    
private:
    
    int coordinate_x[50];
    int coordinate_y[50];
    Tree* tree;
    
public:
    
    TreeManager(){
        
        for(int i = 0 ; i< 50; ++i){
            coordinate_x[i] = i+ 1;
            coordinate_y[i] = i+ 2;
        }
        
    }
    
    void displayTrees(){
        
        for(int i = 0 ;i < 50; ++i){
            tree->display(coordinate_x[i], coordinate_y[i]);
        }
        
    }
    
};


class Flyweight{
    
public:
    
    static void test(){
        TreeManager* treeManager = new TreeManager;
        treeManager->displayTrees();
    }
};

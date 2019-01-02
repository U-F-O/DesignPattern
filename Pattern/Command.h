#include "Header.h"


class Command{
    
public:
    
    virtual void execute() = 0;
    virtual ~Command(){};
    
};

class NoCommand:public Command{
    
public:
    
    void execute(){}
    
};



class Light{
    
public:
    
    void on(){cout << "Light is on" << endl;}
    
    void off(){cout << "Light is off" << endl;}
    
};



class LightoffCommand : public Command{
    
    Light * light;
    
public:
    
    LightoffCommand(Light* light){this -> light = light;}
    
    void execute(){ light -> off();}
    
};



class LightOnCommand : public Command{
    
    Light * light;
    
public:
    
    LightOnCommand(Light* light){this -> light = light;}
    
    void execute(){ light -> on();}

};





class Stereo{
    
public:
    
    void on(){ cout << "Stereo is on" << endl; }
    
    void off(){ cout << "Stereo is off" << endl; }
    
    void setCD() { cout << "I'm setting CD" << endl;}
    
    void setVolume(){ cout << "I'm setting volume" <<endl;}
    
};



class StereoOnwithCDCommand : public Command{
    
    Stereo* stereo;
    
public:
    
    StereoOnwithCDCommand(Stereo * stereo){
        
        this -> stereo = stereo;
        
    }
    
    void execute(){
        
        stereo -> on();
        
        stereo -> setCD();
        
        stereo -> setVolume();
        
    }
    
};



class StereoOffwithCDCommand : public Command{
    
    Stereo* stereo;
    
public:
    
    StereoOffwithCDCommand(Stereo* stereo){
        
        this -> stereo = stereo;
        
    }
    
    void execute(){
        
        stereo -> off();
        
    }
    
};





class RemoteControl{
    
    
    vector<Command *> onCommands;
    vector<Command *> offCommands;
    
public:
    
    RemoteControl(){
        
        onCommands.reserve(7);
        
        offCommands.reserve(7);
        
        for(int i = 0; i < 7 ; ++i){
            
            onCommands[i] = new NoCommand;
            offCommands[i] = new NoCommand;
        }
        
    }
    
    void setCommand(int slot, Command* onCommand, Command* offCommand){
        
        onCommands[slot] = onCommand;
        offCommands[slot] = offCommand;
        
    }
    
    void onButtonWasPushed(int slot){
        onCommands[slot]->execute();
    }
    
    
    void offButtonWasPushed(int slot){
        offCommands[slot]->execute();
        
    }
};



// party mode


/*
class MacroCommand : public Command{
    
    vector<Command *> commands;
    
public:
    
    MacroCommand(vector<Command *> & commands){
        
        this -> commands = commands;
        
    }
    
    void execute(){
        
        for(int i = 0 ; i < commands.size(); ++i){
            
            commands[i] -> execute();
            
        }
        
    }
    
};*/

class CommandTest{
    
public:
    
    static void test(){
        
        RemoteControl* remoteControl = new RemoteControl();
        Light* light = new Light();
        Stereo* stereo = new Stereo();
        
        LightOnCommand* lightOn = new LightOnCommand(light);
        LightoffCommand* lightOff = new LightoffCommand(light);
        
        StereoOnwithCDCommand* stereoOnCommand = new StereoOnwithCDCommand(stereo);
        StereoOffwithCDCommand* stereoOffCommand = new StereoOffwithCDCommand(stereo);
        
        remoteControl->setCommand(0, lightOn, lightOff);
        remoteControl->setCommand(1, stereoOnCommand, stereoOffCommand);
        
        remoteControl->onButtonWasPushed(0);
        remoteControl->offButtonWasPushed(0);
        
        remoteControl->onButtonWasPushed(1);
        remoteControl->offButtonWasPushed(1);
        
        delete remoteControl;
        delete light;
        delete stereo;
        delete lightOn;
        delete lightOff;
        delete stereoOnCommand;
        delete stereoOffCommand;
        
    }
};





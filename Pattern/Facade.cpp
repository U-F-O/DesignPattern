//Facade Pattern

#include "Header.h"

#define COMPONENT(name)\
class name{\
public:\
void on(){cout <<#name << ": I'm on" << endl;}\
void off(){cout <<#name <<": I'm off" << endl;}\
};



COMPONENT(Amplifier)
COMPONENT(Tuner)
COMPONENT(DvdPlayer)
COMPONENT(CdPlayer)
COMPONENT(Projector)
COMPONENT(TheaterLights)
COMPONENT(Screen)
COMPONENT(PopcornPopper)

#define INSTANCE(name,a)\
name* a = new name;


class HomeTheaterFacade{
    
    Amplifier* amp;
    Tuner* tuner;
    DvdPlayer* dvd;
    CdPlayer* cd;
    Projector* projector;
    TheaterLights* lights;
    Screen* screen;
    PopcornPopper* popper;
    
public:
    
    HomeTheaterFacade(Amplifier* amp,
                      Tuner* tuner,
                      DvdPlayer* dvd,
                      CdPlayer* cd,
                      Projector* projector,
                      TheaterLights* lights,
                      Screen* screen,
                      PopcornPopper* popper){
        
        this -> amp = amp;

        this -> tuner = tuner;
        
        this -> dvd = dvd;
        
        this -> cd = cd;
        
        this -> projector = projector;
        
        this -> lights = lights;
        
        this -> screen = screen;
        
        this -> popper = popper;
        
    }
    
    
    
    void watchMovie(){
        
        cout << "Start watching movie" << endl;
        
        amp->on();
        
        tuner->on();
        
        dvd->on();
        
        cd->on();
        
        projector->on();
        
        lights->on();
        
        screen->on();
        
        popper->on();
        
    }
    
    void endMovie(){
        
        cout << "Finish Movie" << endl;
        
        amp->off();
        
        tuner->off();
        
        dvd->off();
        
        cd->off();
        
        projector->off();
        
        lights->off();
        
        screen->off();
        
        popper->off();
        
    }
    
};


class FacadeTest{
    
public:
    
    static void test(){
        
        INSTANCE(Amplifier,amp)
        INSTANCE(Tuner,tune)
        INSTANCE(DvdPlayer,dvd)
        INSTANCE(CdPlayer,cd)
        INSTANCE(Projector,projector)
        INSTANCE(TheaterLights,theaterLight)
        INSTANCE(Screen,screen)
        INSTANCE(PopcornPopper,popcorn)
        
        HomeTheaterFacade* homeTheater = new HomeTheaterFacade(amp,tune,dvd,cd,projector,theaterLight,screen,popcorn);
        homeTheater -> watchMovie();
        homeTheater -> endMovie();
        
        delete amp;
        delete tune;
        delete dvd;
        delete cd;
        delete projector;
        delete theaterLight;
        delete screen;
        delete popcorn;
        delete homeTheater;
        
    }
};



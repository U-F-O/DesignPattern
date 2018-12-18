
#include "Header.h"


class Observer;

class Subject{
public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers()=0;
};

class Observer{
    
protected:
    int id;
    
public:
    virtual void update(float temp, float humidity, float pressure) = 0;
    int getID(){return id;}
    
};

class DisplayElement {
    
    virtual void display() = 0;
    
};

class WeatherData : public Subject{
    
private:
    vector<Observer* > observers;
    float temperature;
    float humidity;
    float pressure;
    
public:
    WeatherData(){}
    
    void registerObserver(Observer* o){
        observers.push_back(o);
    }
    
    void removeObserver(Observer* o){
        int index = o->getID();
        int i = 0;
        for(vector<Observer*>:: iterator it;it!=observers.end();++it){
            if(index== i){
                observers.erase(it);
                break;
            }
        }
    }
    
    void notifyObservers(){
        for(int i = 0 ; i < observers.size(); ++i){
            observers[i]->update(temperature, humidity, pressure);
        }
    }
    
    void measurementsChanged(){
        notifyObservers();
    }
    
    void setMeasurements(float temperature, float humidity, float pressure){
        this->temperature=temperature;
        this->humidity=humidity;
        this->pressure=pressure;
        measurementsChanged();
    }
};

class CurrentConditionDisplay :public Observer,public DisplayElement{
private:
    float temperature;
    float humidity;
    Subject* weatherData;
    
public:
    CurrentConditionDisplay(Subject* weatherData,int id){
        this -> id = id;
        this -> weatherData = weatherData;
        weatherData->registerObserver(this);
    }
    
    void update(float temperature, float humidity, float pressure){
        this->temperature = temperature;
        this->humidity=humidity;
    }
    
    void display(){
        cout << "Current conditions: " << temperature << " F degrees and " <<humidity <<"% humidity"<<endl;
    }
};

class StatisticsDisplay :public Observer,public DisplayElement{
private:
    float temperature;
    Subject* weatherData;
    
public:
    StatisticsDisplay(Subject* weatherData,int id){
        this -> weatherData = weatherData;
        this -> id = id;
        weatherData->registerObserver(this);
    }
    
    void update(float temperature, float humidity, float pressure){
        this->temperature = temperature;
    }
    
    void display(){
        cout << "Statistics conditions: " << temperature << " F degrees" << endl;
    }
};

class ForecastDisplay :public Observer,public DisplayElement{
private:
    float pressure;
    Subject* weatherData;
    
public:
    ForecastDisplay(Subject* weatherData,int id){
        this -> id = id;
        this -> weatherData = weatherData;
        weatherData->registerObserver(this);
    }
    
    void update(float temperature, float humidity, float pressure){
        this->pressure=pressure;
    }
    
    void display(){
        cout << "Current pressure: " << pressure << endl;
    }
};

class ObserverTest{
    
public:
    
    static void test(){
        WeatherData* weatherData = new WeatherData;
        
        CurrentConditionDisplay* currentConditionDisplay = new CurrentConditionDisplay(weatherData,1);
        StatisticsDisplay* statisticsDisplay = new StatisticsDisplay(weatherData,1);
        ForecastDisplay* forecastDisplay = new ForecastDisplay(weatherData,1);
        
        weatherData->setMeasurements(11.0, 12.0, 13.0);
        
        currentConditionDisplay->display();
        statisticsDisplay->display();
        forecastDisplay->display();
        
        weatherData->setMeasurements(14.0, 15.0, 16.0);
        
        currentConditionDisplay->display();
        statisticsDisplay->display();
        forecastDisplay->display();
        
        delete weatherData;
        delete currentConditionDisplay;
        delete statisticsDisplay;
        delete forecastDisplay;
        
    }
};

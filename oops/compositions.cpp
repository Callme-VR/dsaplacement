#include <iostream>
using namespace std;

class Engine
{
public:
    void startEngine()
    {
        cout << "Engine started" << endl;
    }
};

class Car
{ 
private:
    Engine engine;

public:
    void startCar()
    {
        cout << "Car started\n"; 
        engine.startEngine();    
    }
};

int main()
{
    Car car;
    car.startCar();
    return 0;
}

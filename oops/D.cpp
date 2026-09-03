// depenedecnies inversion principle

#include <iostream>
#include <memory>
using namespace std;
class IEngine
{
public:
    virtual void start() = 0;
    virtual ~IEngine() = default;
};

class V8Engine : public IEngine
{
public:
    void start() override
    {
        cout << "V8 engine started" << endl;
    }
};

// 3. Concrete Low-level Implementation B (Easy to add now!)

class ElectricEngine : public IEngine
{
public:
    void start() override
    {
        cout << "Electric engine started" << endl;
    }
};

// 4. High-level component depending only on the Abstraction

class Car
{
private:
    // property depends in interface not concrete implementation
    unique_ptr<IEngine> engine;

public:
    Car(unique_ptr<IEngine> eng) : engine(move(eng)) {}
    void drive()
    {
        if (engine)
        {
            engine->start();
            cout << "Car is driving Efficiently" << endl;
        }
    }
};
int main()
{
    // We can seamlessly swap out properties at runtime!
    unique_ptr<IEngine> v8Engine = make_unique<V8Engine>();
    Car car1(move(v8Engine));
    car1.drive(); // Output: V8 engine started
                  //         Car is driving Efficiently

    unique_ptr<IEngine> electricEngine = make_unique<ElectricEngine>();
    Car car2(move(electricEngine));
    car2.drive(); // Output: Electric engine started
                  //         Car is driving Efficiently
}


// good way We invert the dependency by introducing an abstract base class (IEngine). The Car property now depends on a smart pointer to this abstraction. This lets us inject any engine type without changing the code inside the Car class.
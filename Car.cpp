#include <iostream>
#include <string>

using namespace std;

class Engine
{
    int hp_;
    string type_;

public:
    Engine(int hp, string type) : hp_(hp), type_(type)
    {
        cout << "Constructor for Engine called." << endl;
    }
    ~Engine()
    {
        cout << "Destructor for Engine called." << endl;
    }
    void display()
    {
        cout << "Engine: " << type_
             << ", HP: " << hp_ << endl;
    }
};

class Car
{
    Engine engine_; // composition: Car has an Engine
    // direct data members of Car
    //this is not a pointer, so the Engine object is created and destroyed as part of the Car object's lifecycle

    string maker_;
    string model_;
    int doors_;

public:
    Car(string maker, string model, int doors, int hp,
        string type) : engine_(hp, type), maker_(maker),
                       model_(model), doors_(doors)
    {
        cout << "Constructor for Car called." << endl;
        cout << "the concstructor for Engine is called before the constructor for Car.\n" << endl;
    }
    // the constuctor from big to small, it will start wth the smll parts 1st and the big one which consist all


    ~Car()
    {
        cout << "Destructor for Car called." << endl;
    }
    void display()
    {
        cout << "Maker: " << maker_ << ", Model: " << model_
             << ", Number of doors: " << doors_ << endl;
        engine_.display();
    }
};

int main()
{

    Car *corolla = new Car("Toyota", "Corolla", 4, 170, "V4");

    corolla->display();

    delete corolla;

    return 0;
}
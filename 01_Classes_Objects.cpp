#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    int speed;

public:
    // Constructor (string version)
    Car(const string &brand, const string &model)
        : brand(brand), model(model), speed(0) {}

    void accelerate(int increment)
    {
        if (increment > 0)
            speed += increment;
    }

    void displayStatus() const
    {
        cout << brand << " " << model
             << " is running at " << speed << " km/h." << endl;
    }
};

int main()
{
    Car corolla("Toyota", "Corolla");
    
    corolla.accelerate(20);

    corolla.displayStatus();

    return 0;
}
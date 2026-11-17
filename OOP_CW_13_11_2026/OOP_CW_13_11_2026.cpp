#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle
{
public:
    Vehicle(int maxSpeed, int wheels, bool hasEngine,
        string model, string color, int year, double price)
    {
        this->maxSpeed = maxSpeed;
        this->wheels = wheels;
        this->hasEngine = hasEngine;
        this->model = model;
        this->color = color;
        this->year = year;
        this->price = price;
    }

    virtual void move(int percent)
    {
        if (percent > 100 || percent < 0)
        {
            cout << "Invalid percent value!" << endl;
            return;
        }

        speed = (maxSpeed * percent) / 100.0f;
    }
    float getSpeed() {
        return speed;
    }

    virtual void print() = 0;

    virtual ~Vehicle() = default;

protected:
    int maxSpeed;
    float speed = 0;
    int wheels;
    bool hasEngine;
    string model;
    string color;
    int year;
    double price;
};

class Engine
{
public:
    Engine(int power, string type)
    {
        this->power = power;
        this->type = type;
    }

protected:
    int power;
    string type;
};

class Cargo
{
public:
    Cargo(float maxweight, string cargoType)
    {
        this->maxweight = maxweight;
        this->cargoType = cargoType;
    }

protected:
    float maxweight;
    string cargoType;
};

// Trailer
class Trailer : public Cargo, public Vehicle
{
public:
    Trailer(float maxweight, string cargoType,
        int maxSpeed, string model,
        string color, int year, double price)
        : Cargo(maxweight, cargoType),
        Vehicle(maxSpeed, 2, false, model, color, year, price)
    {
    }

    void print() override
    {
        cout << "\n--- Trailer ---" << endl;
        cout << "Model: " << model << endl;
        cout << "Max speed: " << maxSpeed << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Max weight: " << maxweight << endl;
        cout << "Cargo type: " << cargoType << endl;
    }
};

// Bike
class Bike : public Vehicle
{
public:
    Bike(int maxSpeed, string model,
        string color, int year, double price)
        : Vehicle(maxSpeed, 2, false, model, color, year, price)
    {
    }

    void print() override
    {
        cout << "\n--- Bike ---" << endl;
        cout << "Model: " << model << endl;
        cout << "Max speed: " << maxSpeed << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
    }
};

// MotoBike
class MotoBike : public Vehicle, public Engine
{
public:
    MotoBike(int maxSpeed, string model,
        int power, string type,
        string color, int year, double price)
        : Vehicle(maxSpeed, 2, true, model, color, year, price),
        Engine(power, type)
    {
    }

    void print() override
    {
        cout << "\n--- MotoBike ---" << endl;
        cout << "Model: " << model << endl;
        cout << "Max speed: " << maxSpeed << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Engine power: " << power << endl;
        cout << "Engine type: " << type << endl;
    }
};

// Car
class Car : public Vehicle, public Engine
{
public:
    Car(int maxSpeed, string model,
        int power, string type,
        string color, int year, double price)
        : Vehicle(maxSpeed, 4, true, model, color, year, price),
        Engine(power, type)
    {
    }

    void print() override
    {
        cout << "\n--- Car ---" << endl;
        cout << "Model: " << model << endl;
        cout << "Max speed: " << maxSpeed << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Engine power: " << power << endl;
        cout << "Engine type: " << type << endl;
    }
};

// Fourgon
class Fourgon : public Vehicle, public Engine, public Cargo
{
public:
    Fourgon(int maxSpeed, string model,
        int power, string type,
        float maxweight, string cargoType,
        string color, int year, double price)
        : Vehicle(maxSpeed, 4, true, model, color, year, price),
        Engine(power, type),
        Cargo(maxweight, cargoType)
    {
    }

    void print() override
    {
        cout << "\n--- Fourgon ---" << endl;
        cout << "Model: " << model << endl;
        cout << "Max speed: " << maxSpeed << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Engine power: " << power << endl;
        cout << "Engine type: " << type << endl;
        cout << "Max weight: " << maxweight << endl;
        cout << "Cargo type: " << cargoType << endl;
    }
};

// Bus
class Bus : public Vehicle, public Engine, public Cargo
{
public:
    Bus(int maxSpeed, string model,
        int power, string type,
        float maxweight,
        string color, int year, double price)
        : Vehicle(maxSpeed, 4, true, model, color, year, price),
        Engine(power, type),
        Cargo(maxweight, "people")
    {
    }

    void print() override
    {
        cout << "\n--- Bus ---" << endl;
        cout << "Model: " << model << endl;
        cout << "Max speed: " << maxSpeed << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Engine power: " << power << endl;
        cout << "Engine type: " << type << endl;
        cout << "Max weight: " << maxweight << endl;
        cout << "Cargo type: " << cargoType << endl;
    }
};

// Truck
class Truck : public Vehicle, public Engine
{
private:
    Trailer trailer;

public:
    Truck(int maxSpeed, string model,
        int power, string type,
        Trailer trailer,
        string color, int year, double price)
        : Vehicle(maxSpeed, 4, true, model, color, year, price),
        Engine(power, type),
        trailer(trailer)
    {
    }

    void print() override
    {
        cout << "\n--- Truck ---" << endl;
        cout << "Model: " << model << endl;
        cout << "Max speed: " << maxSpeed << endl;
        cout << "Color: " << color << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
        cout << "Engine power: " << power << endl;
        cout << "Engine type: " << type << endl;

        cout << "\nAttached trailer:";
        trailer.print();
    }
};

int main()
{
    // Creating objects
    Trailer trailer(5000, "Construction materials",
        100, "Trailer X",
        "White", 2022, 5000.0);

    Bike bike(80, "Mountain Bike",
        "Black", 2023, 800.0);

    MotoBike moto(220, "Yamaha R1",
        200, "Petrol",
        "Blue", 2024, 15000.0);

    Car car(250, "BMW M5",
        600, "Petrol",
        "Black", 2023, 85000.0);

    Fourgon fourgon(160, "Mercedes Sprinter",
        190, "Diesel",
        3000, "Packages",
        "White", 2022, 40000.0);

    Bus bus(120, "Mercedes Bus",
        300, "Diesel",
        10000,
        "Yellow", 2021, 120000.0);

    Truck truck(130, "Volvo FH",
        500, "Diesel",
        trailer,
        "Red", 2024, 150000.0);

    // Polymorphism test
    vector<Vehicle*> vehicles;

    vehicles.push_back(&trailer);
    vehicles.push_back(&bike);
    vehicles.push_back(&moto);
    vehicles.push_back(&car);
    vehicles.push_back(&fourgon);
    vehicles.push_back(&bus);
    vehicles.push_back(&truck);

    // Print all vehicles
    for (Vehicle* vehicle : vehicles)
    {
        vehicle->print();
    }

    // Move test
    cout << "\n--- Movement test ---" << endl;

    car.move(50);
    cout << "Car speed at 50%: " << car.getSpeed() << endl;

    bike.move(75);
    cout << "Bike speed at 75%: " << bike.getSpeed() << endl;

    car.move(150);

    return 0;
}
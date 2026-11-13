

#include <iostream>
#include <vector>
using namespace std;
class Vehicle
{
public:
    Vehicle(int maxSpeed,
    int wheels,
    bool hasEngine,
    string model) {
        this->maxSpeed = maxSpeed;
        this->wheels = wheels;
        this->hasEngine = hasEngine;
        this->model = model;
    };
    virtual void move(signed int percent) {
		if (percent > 100 || percent < 0) {
			cout << "Invalid percent value!" << endl;
			return;
		}
		speed = (maxSpeed * percent) / 100.0f;
    };
	virtual void print() = 0;
    
protected:
	int maxSpeed;
    float speed=0;
	int wheels;
	bool hasEngine;
    string model;
};

class Engine {
public:
	Engine(int power, string type) {
		this->power = power;
		this->type = type;
	};
protected:
	int power;
	string type;
};

class Cargo
{
public:
    Cargo(float maxweight, string cargoType) {
        this->maxweight = maxweight;
        this->cargoType = cargoType;
    };
protected:
    float maxweight;
    string cargoType;
};
class Trailer : public Cargo, public Vehicle
{
public:
	Trailer(float maxweight, string cargoType, int maxSpeed, string model) : Cargo(maxweight, cargoType), Vehicle(maxSpeed, 2, false, model) {};
	void print() override {
		cout << "Trailer model: " << model << ", max speed: " << maxSpeed << ", wheels: " << wheels << ", has engine: " << hasEngine << endl;
	}
};

class Bike : public Vehicle
{
public:
    Bike(int maxSpeed, string model) : Vehicle(maxSpeed, 2, false, model) {};
	void print() override {
		cout << "Bike model: " << model << ", max speed: " << maxSpeed << ", wheels: " << wheels << ", has engine: " << hasEngine << endl;
	}
};

class MotoBike : public Vehicle, public Engine
{
public:
    MotoBike(int maxSpeed, string model, int power,string type) : Vehicle(maxSpeed, 2, true, model), Engine(power, type) {};
    void print() override {
        cout << "MotoBike model: " << model << ", max speed: " << maxSpeed << ", wheels: " << wheels << ", has engine: " << hasEngine << endl;
    }
};

class Car : public Vehicle, public Engine
{
public:
    Car(int maxSpeed, string model, int power, string type) : Vehicle(maxSpeed, 4, true, model), Engine(power, type) {};
    void print() override {
        cout << "Car model: " << model << ", max speed: " << maxSpeed << ", wheels: " << wheels << ", has engine: " << hasEngine << endl;
    }
};

class Fourgon : public Vehicle, public Engine, public Cargo
{
public:
    Fourgon(int maxSpeed, string model, int power, string type, float maxweight, string cargoType) : Vehicle(maxSpeed, 4, true, model), Engine(power, type), Cargo(maxweight, "light") {};
    void print() override {
        cout << "Fourgon model: " << model << ", max speed: " << maxSpeed << ", wheels: " << wheels << ", has engine: " << hasEngine << endl;
    }
};

class Bus : public Vehicle, public Engine, public Cargo
{
public:
    Bus(int maxSpeed, string model, int power, string type, float maxweight) : Vehicle(maxSpeed, 4, true, model), Engine(power, type), Cargo(maxweight, "people") {};
    void print() override {
        cout << "Bus model: " << model << ", max speed: " << maxSpeed << ", wheels: " << wheels << ", has engine: " << hasEngine << endl;
    }
};

class Truck : public Vehicle, public Engine
{
private:
	Trailer trailer;
public:
    Truck(int maxSpeed, string model, int power, string type, Trailer trailer) : Vehicle(maxSpeed, 4, true, model), Engine(power, type), trailer(trailer){};
    void print() override {
        cout << "Truck model: " << model << ", max speed: " << maxSpeed << ", wheels: " << wheels << ", has engine: " << hasEngine << endl;
    }   
};



int main()
{
//мне лень писать
}

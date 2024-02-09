#include <iostream>
#include <string>

// Абстрактний продукт - автомобіль
class Car 
{
public:
    virtual std::string getName() const = 0;
    virtual double getPrice() const = 0;
};

// Конкретні продукти
class EconomyCar : public Car 
{
public:
    std::string getName() const override 
    {
        return "Economy Car";
    }

    double getPrice() const override 
    {
        return 15000.0;
    }
};

class LuxuryCar : public Car 
{
public:
    std::string getName() const override 
    {
        return "Luxury Car";
    }

    double getPrice() const override 
    {
        return 50000.0;
    }
};

// Абстрактна фабрика
class CarFactory 
{
public:
    virtual Car* createCar() = 0;
};

// Конкретні фабрики
class EconomyCarFactory : public CarFactory 
{
public:
    Car* createCar() override 
    {
        return new EconomyCar();
    }
};

class LuxuryCarFactory : public CarFactory 
{
public:
    Car* createCar() override 
    {
        return new LuxuryCar();
    }
};

// Виведення інформації про автомобіль
void printCarInfo(CarFactory* factory) 
{
    Car* car = factory->createCar();

    std::cout << "Car Type: " << car->getName() << std::endl;
    std::cout << "Price: $" << car->getPrice() << std::endl;

    delete car;
}

int main() 
{
    // Створення екземплярів фабрик та виведення інформації про автомобілі
    CarFactory* economyFactory = new EconomyCarFactory();
    CarFactory* luxuryFactory = new LuxuryCarFactory();

    std::cout << "Economy Car Details:" << std::endl;
    printCarInfo(economyFactory);
    std::cout << std::endl;

    std::cout << "Luxury Car Details:" << std::endl;
    printCarInfo(luxuryFactory);

    delete economyFactory;
    delete luxuryFactory;

    return 0;
}

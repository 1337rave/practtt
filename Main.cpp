#include <iostream>

class Transport {
public:
    virtual double calculateTime(int passengers, int cargo) const = 0;
    virtual double calculateCost(int passengers, int cargo) const = 0;
    virtual ~Transport() {}
};

class Car : public Transport {
public:
    double calculateTime(int passengers, int cargo) const override {
        return passengers + cargo;
    }

    double calculateCost(int passengers, int cargo) const override {
        return passengers * 10 + cargo * 5;
    }
};

class Bicycle : public Transport {
public:
    double calculateTime(int passengers, int cargo) const override {
        return 0.5 * (passengers + cargo);
    }

    double calculateCost(int passengers, int cargo) const override {
        return 0;
    }
};

class Cart : public Transport {
public:

    double calculateTime(int passengers, int cargo) const override {
        return 2 * (passengers + cargo);
    }

    double calculateCost(int passengers, int cargo) const override {
        return passengers * 5 + cargo * 2;
    }
};

int main() {

    Car car;
    Bicycle bicycle;
    Cart cart;

    std::cout << "Car - Time: " << car.calculateTime(5, 200) << " hours, Cost: $" << car.calculateCost(5, 200) << std::endl;
    std::cout << "Bicycle - Time: " << bicycle.calculateTime(2, 50) << " hours, Cost: $" << bicycle.calculateCost(2, 50) << std::endl;
    std::cout << "Cart - Time: " << cart.calculateTime(10, 100) << " hours, Cost: $" << cart.calculateCost(10, 100) << std::endl;

    return 0;
}

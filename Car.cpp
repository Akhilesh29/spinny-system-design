#include "include/Car.h"

Car::Car(int id, int sellerId, const std::string& make, const std::string& model, int year, double price, int mileage, const std::string& location)
    : carId(id), sellerId(sellerId), make(make), model(model), year(year), price(price), mileage(mileage), location(location), status(CarStatus::AVAILABLE) {} 
#pragma once
#include <string>

enum class CarStatus {
    AVAILABLE,
    BOOKED,
    SOLD,
    INSPECTION_PENDING
};

class Car {
private:
    int carId;
    int sellerId;
    std::string make;
    std::string model;
    int year;
    double price;
    int mileage;
    std::string location;
    CarStatus status;

public:
    Car(int id, int sellerId, const std::string& make, const std::string& model,
        int year, double price, int mileage, const std::string& location);

    // Getters
    int getCarId() const { return carId; }
    int getSellerId() const { return sellerId; }
    std::string getMake() const { return make; }
    std::string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return price; }
    int getMileage() const { return mileage; }
    std::string getLocation() const { return location; }
    CarStatus getStatus() const { return status; }

    // Setters
    void setPrice(double newPrice) { price = newPrice; }
    void setMileage(int newMileage) { mileage = newMileage; }
    void setLocation(const std::string& newLocation) { location = newLocation; }
    void setStatus(CarStatus newStatus) { status = newStatus; }

    // Utility methods
    bool isAvailable() const { return status == CarStatus::AVAILABLE; }
    bool isBooked() const { return status == CarStatus::BOOKED; }
    bool isSold() const { return status == CarStatus::SOLD; }
    bool needsInspection() const { return status == CarStatus::INSPECTION_PENDING; }
}; 
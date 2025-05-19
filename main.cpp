#include <iostream>
#include <vector>
#include <chrono>
#include "include/User.h"
#include "include/Car.h"
#include "include/Booking.h"
#include "include/Payment.h"

int main() {
    // Create Users
    User buyer(1, "Akhilsh", "akhilesh@example.com", "1234567890", UserRole::BUYER);
    User seller(2, "parth", "parth@example.com", "0987654321", UserRole::SELLER);
    User admin(3, "nikhil", "nikhil@spinny.com", "1112223333", UserRole::ADMIN);

    // Print Users
    std::cout << "Users:\n";
    std::cout << "Buyer: " << buyer.getName() << ", Email: " << buyer.getEmail() << ", Role: BUYER\n";
    std::cout << "Seller: " << seller.getName() << ", Email: " << seller.getEmail() << ", Role: SELLER\n";
    std::cout << "Admin: " << admin.getName() << ", Email: " << admin.getEmail() << ", Role: ADMIN\n\n";

    // Create Car
    Car car1(101, seller.getUserId(), "Toyota", "Corolla", 2018, 800000, 35000, "Delhi");
    std::cout << "Car Listing:\n";
    std::cout << "Car: " << car1.getMake() << " " << car1.getModel() << ", Year: " << car1.getYear() << ", Price: " << car1.getPrice() << ", Location: " << car1.getLocation() << ", Status: AVAILABLE\n\n";

    // Booking
    auto now = std::chrono::system_clock::now();
    Booking booking1(201, car1.getCarId(), buyer.getUserId(), now);
    std::cout << "Booking:\n";
    std::cout << "Booking ID: " << booking1.getBookingId() << ", Car ID: " << booking1.getCarId() << ", Buyer ID: " << booking1.getBuyerId() << ", Status: PENDING\n\n";

    // Payment
    Payment payment1(301, booking1.getBookingId(), car1.getPrice());
    std::cout << "Payment:\n";
    std::cout << "Payment ID: " << payment1.getPaymentId() << ", Booking ID: " << payment1.getBookingId() << ", Amount: " << payment1.getAmount() << ", Status: PENDING\n\n";

    // Simulate status changes
    car1.setStatus(CarStatus::BOOKED);
    booking1.setStatus(BookingStatus::CONFIRMED);
    payment1.setStatus(PaymentStatus::COMPLETED);

    std::cout << "--- After Status Updates ---\n";
    std::cout << "Car Status: BOOKED\n";
    std::cout << "Booking Status: CONFIRMED\n";
    std::cout << "Payment Status: COMPLETED\n";

    return 0;
} 
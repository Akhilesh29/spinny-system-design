#pragma once
#include <string>
#include <chrono>

enum class BookingStatus {
    PENDING,
    CONFIRMED,
    CANCELLED,
    COMPLETED
};

class Booking {
private:
    int bookingId;
    int carId;
    int buyerId;
    std::chrono::system_clock::time_point inspectionDate;
    BookingStatus status;

public:
    Booking(int id, int carId, int buyerId, 
            const std::chrono::system_clock::time_point& inspectionDate);

    // Getters
    int getBookingId() const { return bookingId; }
    int getCarId() const { return bookingId; }
    int getBuyerId() const { return buyerId; }
    std::chrono::system_clock::time_point getInspectionDate() const { return inspectionDate; }
    BookingStatus getStatus() const { return status; }

    // Setters
    void setInspectionDate(const std::chrono::system_clock::time_point& newDate) { 
        inspectionDate = newDate; 
    }
    void setStatus(BookingStatus newStatus) { status = newStatus; }

    // Utility methods
    bool isPending() const { return status == BookingStatus::PENDING; }
    bool isConfirmed() const { return status == BookingStatus::CONFIRMED; }
    bool isCancelled() const { return status == BookingStatus::CANCELLED; }
    bool isCompleted() const { return status == BookingStatus::COMPLETED; }
}; 
#pragma once
#include <string>

enum class PaymentStatus {
    PENDING,
    COMPLETED,
    FAILED,
    REFUNDED
};

class Payment {
private:
    int paymentId;
    int bookingId;
    double amount;
    PaymentStatus status;

public:
    Payment(int id, int bookingId, double amount);

    // Getters
    int getPaymentId() const { return paymentId; }
    int getBookingId() const { return bookingId; }
    double getAmount() const { return amount; }
    PaymentStatus getStatus() const { return status; }

    // Setters
    void setAmount(double newAmount) { amount = newAmount; }
    void setStatus(PaymentStatus newStatus) { status = newStatus; }

    // Utility methods
    bool isPending() const { return status == PaymentStatus::PENDING; }
    bool isCompleted() const { return status == PaymentStatus::COMPLETED; }
    bool isFailed() const { return status == PaymentStatus::FAILED; }
    bool isRefunded() const { return status == PaymentStatus::REFUNDED; }
}; 
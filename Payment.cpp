#include "include/Payment.h"

Payment::Payment(int id, int bookingId, double amount)
    : paymentId(id), bookingId(bookingId), amount(amount), status(PaymentStatus::PENDING) {} 
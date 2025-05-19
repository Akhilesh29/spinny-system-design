#include "include/Booking.h"

Booking::Booking(int id, int carId, int buyerId, const std::chrono::system_clock::time_point& inspectionDate)
    : bookingId(id), carId(carId), buyerId(buyerId), inspectionDate(inspectionDate), status(BookingStatus::PENDING) {} 
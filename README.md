# Spinny System Design Implementation

## High Level Design (HLD)

### System Components
1. **User Management System**
   - User registration and authentication
   - Profile management
   - Role-based access (Buyer, Seller, Admin)

2. **Car Inventory Management**
   - Car listing and details
   - Search and filtering
   - Inventory tracking

3. **Search and Discovery**
   - Advanced search functionality
   - Filters (price, location, make, model)
   - Sorting options

4. **Booking and Inspection System**
   - Car inspection scheduling
   - Booking management
   - Status tracking

5. **Payment System**
   - Payment processing
   - Transaction history
   - Refund management

### Database Schema
```
Users
- user_id (PK)
- name
- email
- phone
- role
- created_at

Cars
- car_id (PK)
- seller_id (FK)
- make
- model
- year
- price
- mileage
- location
- status
- created_at

Bookings
- booking_id (PK)
- car_id (FK)
- buyer_id (FK)
- inspection_date
- status
- created_at

Payments
- payment_id (PK)
- booking_id (FK)
- amount
- status
- created_at
```

## Low Level Design (LLD)

### Class Structure

1. **User Management**
```cpp
class User {
    int userId;
    string name;
    string email;
    string phone;
    UserRole role;

};

enum class UserRole {
    BUYER,
    SELLER,
    ADMIN
};
```

2. **Car Management**
```cpp
class Car {
    int carId;
    int sellerId;
    string make;
    string model;
    int year;
    double price;
    int mileage;
    string location;
    CarStatus status;
    // Methods for car operations
};

enum class CarStatus {
    AVAILABLE,
    BOOKED,
    SOLD,
    INSPECTION_PENDING
};
```

3. **Booking System**
```cpp
class Booking {
    int bookingId;
    int carId;
    int buyerId;
    DateTime inspectionDate;
    BookingStatus status;
    // Methods for booking operations
};

enum class BookingStatus {
    PENDING,
    CONFIRMED,
    CANCELLED,
    COMPLETED
};
```

4. **Payment System**
```cpp
class Payment {
    int paymentId;
    int bookingId;
    double amount;
    PaymentStatus status;
    // Methods for payment operations
};

enum class PaymentStatus {
    PENDING,
    COMPLETED,
    FAILED,
    REFUNDED
};
```

### Key Features Implementation
1. **Search System**
   - Implemented using filters and sorting
   - Supports multiple criteria
   - Results pagination

2. **Booking System**
   - Real-time availability check
   - Automated confirmation
   - Status updates

3. **Payment Processing**
   - Secure transaction handling
   - Multiple payment methods
   - Transaction history

## How to Run
1. Compile the code:
```bash
g++ -std=c++17 main.cpp -o spinny
```

2. Run the executable:
```bash
./spinny
```

## Output Screenshots

Below is the output from running the Spinny system demo:

```
Users:
Buyer: Alice, Email: alice@example.com, Role: BUYER
Seller: Bob, Email: bob@example.com, Role: SELLER
Admin: Admin, Email: admin@spinny.com, Role: ADMIN

Car Listing:
Car: Toyota Corolla, Year: 2018, Price: 800000, Location: Delhi, Status: AVAILABLE

Booking:
Booking ID: 201, Car ID: 201, Buyer ID: 1, Status: PENDING

Payment:
Payment ID: 301, Booking ID: 201, Amount: 800000, Status: PENDING

--- After Status Updates ---
Car Status: BOOKED
Booking Status: CONFIRMED
Payment Status: COMPLETED
``` 
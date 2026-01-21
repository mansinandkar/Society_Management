# Society Management System

## Project Summary

The **Society Management System** is a C++-based application that simulates the core operational workflows of a residential society.  
It provides modular functionality to manage residents, staff, facilities, billing, event bookings, and access control in a structured, object-oriented manner.

Rather than a simple console application, this project demonstrates real-world software engineering principles through encapsulation, polymorphism, modular design, and data structures.

---

## Motivation & Goals

Managing a residential society involves:
- Resident and household information
- Billing and payments
- Facility reservations
- Staff and visitor tracking

This project was developed to:
- Solve these challenges using **object-oriented programming (OOP)**
- Model real business logic in a maintainable codebase
- Demonstrate use of classes, inheritance, and modular file organization
- Build a system that can extend to database integration or UI later

---

## Features

The application includes the following capabilities:

### 🔹 Resident & User Management
- Store and manage resident profiles
- Track roles (member, secretary, administrator)

### 🔹 Billing & Finance
- Calculate maintenance bills for residents
- Support different billing modes
- Demonstrate basic financial transactions

### 🔹 Facilities & Events
- Simulate clubhouse booking and hall reservations
- Track event participation

### 🔹 Staff & Visitor Modules
- Record staff details
- Track visitors and guest entries

### 🔹 Query & Reporting
- Query member information
- Generate summaries of residents and facilities

---

## Technologies & Skills

This project highlights:

- **Programming Language:** C++  
- **Paradigm:** Object-Oriented Programming (OOP)  
- **Key Concepts:**
  - Classes and objects
  - Inheritance and polymorphism
  - Modular file structure
  - Encapsulation of business logic
- **Design Artifacts:**
  - Class Diagrams
  - Requirement and design documents
  - System presentation

As such, this project is a **strong demonstration of core software engineering skills** suited for SDE roles.

---

## Code Organization

Each `.cpp` file corresponds to a logical subsystem:

| File | Description |
|------|-------------|
| `oop_bill.cpp` | Billing computation logic |
| `oop_clubhouse.cpp` | Clubhouse facility booking |
| `oop_frontgate.cpp` | Entry/exit logic and visitor tracking |
| `oop_hallbooking.cpp` | Hall reservation functionality |
| `oop_query.cpp` | Member and facility query interface |
| `oop_users.cpp` | User credentials and role management |
| `oop_final.cpp` | Main driver and integration logic |

---

## How to Build & Run

This repository contains **C++ source files**. To compile and run:

### Using g++ (Linux / macOS / WSL)

```bash
g++ oop_final.cpp oop_bill.cpp oop_clubhouse.cpp oop_frontgate.cpp oop_hallbooking.cpp oop_query.cpp oop_users.cpp -o society_app
./society_app


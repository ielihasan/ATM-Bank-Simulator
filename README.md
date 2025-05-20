# 💳 ATM Bank Simulator

A C++ based simulation of an ATM banking system, developed as a data structures and algorithms (DSA) academic project. The project supports both user and admin functionalities including account management, balance inquiries, deposits, withdrawals, and data persistence via text files.

## 📜 Description

This project emulates a simplified ATM banking environment where:
- Users can log in, check balances, withdraw/deposit funds, and change passwords.
- Admins can view user data and perform administrative operations.

Built using fundamental C++ concepts and file handling to simulate a backend database using text files.

## 🚀 Features

- Admin and User authentication
- View account details
- Deposit and withdraw funds
- Password management
- Persistent data storage using `.txt` files
- Admin dashboard to manage and view user data

## 🗂️ Project Structure

```
ATM_Bank_Simulator/
    ├── GroupX_DSA_Project.cpp
    ├── *.sln, *.vcxproj, *.filters
    ├── AdminData.txt
    ├── Admin_IdPassword.txt
    ├── UserIdPassword.txt
    ├── UserInfo.txt
    └── Text.txt
```

## 🛠️ How to Run

### Requirements
- C++ compiler (e.g., GCC, or MSVC)
- Visual Studio (for `.sln` build) or any IDE that supports C++

### Steps
1. Open `GroupX_DSA_Project.sln` in Visual Studio.
2. Build the solution.
3. Run the executable or debug using the IDE.

Alternatively, compile manually:
```bash
g++ GroupX_DSA_Project.cpp -o ATM_Bank_Simulator
./ATM_Bank_Simulator
```

## 👨‍💻 Authors / Group Members

- 22021519-076 (Ali Hassan)

## 🧰 Technologies Used

- C++ (File handling, OOP)
- Visual Studio (C++ project)
- Text-based data storage

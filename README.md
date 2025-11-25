# Interest_calculation_system
A C-based console application for calculating simple and compound interest with customer record storage.
# Abstract
The Interest Calculation System is a console-based application developed in C to compute both Simple Interest (SI) and Compound Interest (CI). The program provides a menu-driven interface that allows users to enter customer details, perform interest calculations, and store results in a persistent file. Each customer is assigned a unique ID, enabling efficient record management and search functionality. By integrating core programming concepts such as functions, structures, loops, conditional statements, and file handling, the system demonstrates how C can be applied to solve real-world financial problems. This project highlights the importance of modular design and data persistence, making it a practical tool for basic financial record-keeping and a strong foundation for more advanced applications.
📘 Interest Calculation System (CRUD Enabled)

A menu-driven C program that calculates Simple Interest and Compound Interest, and supports full CRUD operations on customer records.

Records are stored in a records.txt file and loaded automatically when the program starts.

🚀 Features
✔ Interest Calculation

Simple Interest

Compound Interest

✔ CRUD Operations

Create – Add new customer interest records

Read – View saved records

Update – Modify existing records

Delete – Remove incorrect or old records

✔ File Handling

Records automatically saved to records.txt

Supports loading existing data at startup

Uses | as a delimiter for clean parsing

✔ Improved Safety & Code Quality

Supports names with spaces

Input validation

Clear modular functions

Prevents buffer overflow issues

Cleaner UI / menu design

📂 File Structure
project/
│── main.c
│── records.txt   (auto-created)
│── README.md

🛠 How to Compile

Use GCC or any C compiler:

gcc main.c -o interest_system -lm


Run the program:

./interest_system

📋 Program Menu
=== Interest Calculation System (CRUD Enabled) ===
1. Add New Record
2. View Records
3. Update Record
4. Delete Record
5. Exit

🗂 Record Format (in records.txt)

Each record is stored as:

Name|Principal|Rate|Time|InterestType|InterestValue


Example:

John Doe|10000.00|5.00|2.00|Simple|1000.00
Jane Smith|20000.00|7.50|3.00|Compound|4830.50

📌 Functions Included
Interest Calculations

simpleInterest(p, r, t)

compoundInterest(p, r, t)

CRUD Functions

addRecord()

viewRecords()

updateRecord()

deleteRecord()

File Operations

saveToFile()

loadFromFile()

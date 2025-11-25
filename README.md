# Interest_calculation_system
A C-based console application for calculating simple and compound interest with customer record storage.
# Abstract
The Interest Calculation System is a console-based application developed in C to compute both Simple Interest (SI) and Compound Interest (CI). The program provides a menu-driven interface that allows users to enter customer details, perform interest calculations, and store results in a persistent file. Each customer is assigned a unique ID, enabling efficient record management and search functionality. By integrating core programming concepts such as functions, structures, loops, conditional statements, and file handling, the system demonstrates how C can be applied to solve real-world financial problems. This project highlights the importance of modular design and data persistence, making it a practical tool for basic financial record-keeping and a strong foundation for more advanced applications.
# Interest Calculation System (C CLI Program)

This is a simple command-line program written in C that calculates **Simple Interest** and **Compound Interest**, saves results to a file, and allows viewing all saved records.

---

## Features

- Calculate **Simple Interest**
- Calculate **Compound Interest**
- Save customer details and interest results to `records.txt`
- View all saved records
- Easy-to-use text-based menu

---

## Interest Formulas

### Simple Interest
SI = (P × R × T) / 100

shell
Copy code

### Compound Interest
CI = P * (1 + R/100)^T - P

yaml
Copy code

---

## Project Structure

.
├── main.c
└── records.txt (created automatically after first save)

yaml
Copy code

---

## How to Compile and Run

### Compile
```bash
gcc main.c -o interest_calc -lm
Run
bash
Copy code
./interest_calc
Program Menu
markdown
Copy code
##--- Interest Calculation System ---
1. Calculate Simple Interest
2. Calculate Compound Interest
3. View Records
4. Exit
Record Format (stored in records.txt)
Example:

yaml
Copy code
Name: Alex | Principal: 5000.00 | Rate: 5.00 | Time: 2.00 | Simple Interest: 500.00
Functions Used
Function	Description
simpleInterest(float p, float r, float t)	Calculates simple interest
compoundInterest(float p, float r, float t)	Calculates compound interest
saveRecord(Customer c)	Saves results to records.txt

Notes
Names with spaces are not supported (scanf("%s") limitation).

Make sure the program has permission to create/write records.txt.

Records are appended continuously — delete the file manually if needed.

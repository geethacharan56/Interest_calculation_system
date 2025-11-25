# Interest_calculation_system
A C-based console application for calculating simple and compound interest with customer record storage.
# Abstract
The Interest Calculation System is a console-based application developed in C to compute both Simple Interest (SI) and Compound Interest (CI). The program provides a menu-driven interface that allows users to enter customer details, perform interest calculations, and store results in a persistent file. Each customer is assigned a unique ID, enabling efficient record management and search functionality. By integrating core programming concepts such as functions, structures, loops, conditional statements, and file handling, the system demonstrates how C can be applied to solve real-world financial problems. This project highlights the importance of modular design and data persistence, making it a practical tool for basic financial record-keeping and a strong foundation for more advanced applications.
 # Interest Calculation System (C CLI Program)

A simple and efficient command-line application written in C for calculating **Simple Interest** and **Compound Interest**.  
The program allows users to enter customer details, compute interest, save results, and view past records — all through a clean text-based menu.

---

## ✨ Features

- Calculate **Simple Interest**
- Calculate **Compound Interest**
- Automatically save results to `records.txt`
- View all saved customer records
- Lightweight and easy to run on any system with GCC

---

## 📘 Interest Formulae

### Simple Interest
SI = (P × R × T) / 100

shell
Copy code

### Compound Interest
CI = P * (1 + R/100)^T - P

yaml
Copy code

Where:
- **P** = Principal  
- **R** = Rate of interest  
- **T** = Time (years)

---

## 📁 Project Structure

.
├── main.c
└── records.txt (auto-created after first entry)

yaml
Copy code

---

## 🛠️ How to Compile and Run

### Compile the Program
```bash
gcc main.c -o interest_calc -lm
Run the Program
bash
Copy code
./interest_calc
🖥️ Program Menu
markdown
Copy code
--- Interest Calculation System ---
1. Calculate Simple Interest
2. Calculate Compound Interest
3. View Records
4. Exit
🗂️ Saved Record Format
Each calculation is appended to records.txt like this:

yaml
Copy code
Name: Maria | Principal: 10000.00 | Rate: 5.00 | Time: 3.00 | Compound Interest: 1576.25
🔍 Functions Overview
Function	Purpose
simpleInterest()	Computes simple interest
compoundInterest()	Computes compound interest
saveRecord()	Saves customer info + interest to file

⚠️ Notes
Customer names cannot contain spaces due to scanf("%s").

Ensure the program has write permission to create records.txt.

Records are continuously appended — delete the file if you want to reset.

📄 License
This project is free to use, modify, and share for educational purposes.

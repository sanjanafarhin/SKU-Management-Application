# 📦 SKU Management System (C Language)

**SKU Management System** is a simple, file-based inventory management application written in C. This console-based program enables users to manage product stock and authenticate users without relying on a database — using `.txt` files for data storage.

---

## 🚀 Features

### 🧑‍💼 User Authentication
- ✅ **Sign Up:** Register new users with a username and password.
- 🔐 **Login:** Secure access control using saved credentials (`Register.txt`).

### 📦 Product Management
- ➕ **Add Product:** Insert new products with Name, Category, Price, and Quantity.
- 🔍 **Search Product:** Find a product by its name.
- ✏️ **Edit Product:** Modify product price and stock.
- 🗑 **Delete Product:** Remove a product from the inventory.
- 📃 **Display Stock:** View all products in a neatly formatted table.

---

## 🗂 File Structure

SKU-Management/
├── main.c # Source code
├── ProductList.txt # Stores product data
├── Register.txt # Stores user login credentials
└── README.md # Project documentation

---

---

## 🛠 Technologies Used

- **Language:** C  
- **Compiler:** GCC or any standard C compiler  
- **Platform:** Windows *(uses `windows.h` for `Sleep()` and `system()` calls)*

---

## 🧠 Concepts Practiced

- Structured programming using `struct` for Product data
- File handling: `fopen`, `fscanf`, `fprintf`, `remove`, `rename`
- Input safety: `fgets()` with newline trimming
- Basic user authentication system
- Console UI with formatted table output
- Safe buffer usage and validation

---

## 📚 Use Case

This project is ideal for students learning:
- Structured Programming in C
- File handling techniques
- Console-based UI design
- CRUD operations without a database

---

## 👨‍💻 Project Development

> **Course Project:** Structured Programming Language (SPL)  
> **Institution:** United International University (UIU)

**Developed by:**

- **Md. Abu Huraira Rahi**  
  B.Sc. in CSE, UIU

- **Sanjana Farhin Astha**  
  B.Sc. in CSE, UIU

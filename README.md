# 🪙 Cryptocurrency Exchange Platform (C++)

A **console-based Cryptocurrency Exchange Platform** implemented in **C++** using **Object-Oriented Programming (OOP)** principles.  
Simulates core exchange functionalities such as **order books, wallets, CSV-based market data ingestion**, and **time-based trading simulation**.

> 📘 Inspired by real-world crypto exchanges and developed as part of an Object-Oriented Programming specialization course.

---

## ✨ Features

### 📊 Order Book System
- Supports **bid (buy) and ask (sell) orders**
- **Time-based order matching** simulation
- Price statistics: **minimum, maximum, and average**

### 💼 Wallet Management
- Insert and update **currency balances**
- Prevents **invalid or negative transactions**
- **Exception handling** for erroneous inputs

### 📁 CSV Market Data Handling
- Parses historical market data from **CSV files**
- Converts rows into structured **OrderBookEntry** objects
- Maintains **data integrity** by ignoring malformed entries

### ⏱️ Time-Step Simulation
- Market progresses in **discrete timestamps**
- Orders are evaluated per timestamp
- Enables **realistic market simulation**

### 🧠 OOP Design
- Clear **class separation** for modularity
- Encapsulation and **clean header/source file structure**
- Easy to **extend and maintain**

---

## 🗂️ Project Structure

```text
Cryptocurrency-Exchange-Platform/
UI Layer (MerkelMain) 
│ 
├── Business Logic 
│   ├── OrderBook 
│   └── Wallet
│ 
└── Data Layer 
    └── CSVReader
```

- **Orders → OrderBookEntry**  
- **Market → OrderBook**  
- **Storage → Wallet**  
- **Input source → CSVReader**  

---

## 🖥️ Modules & Functionality

### 1️⃣ User Interface & Control Flow (MerkelMain)
- **Menu-driven console interface** to:
  - Navigate the exchange
  - View market statistics
  - Place orders
  - Manage wallet balances
  - Advance market time
- **Input validation** to prevent invalid menu choices
- **Time control:** each menu cycle represents a market tick
- **Purpose:** Coordinates all system components

### 2️⃣ Market Data Handling (CSVReader)
- **CSV parsing:** Reads timestamp, product pair, order type, price, and amount
- Converts raw CSV data into **OrderBookEntry** objects
- Ignores malformed lines to maintain data integrity
- **Purpose:** Simulates historical market feeds

### 3️⃣ Order Representation (OrderBookEntry)
- Stores **price, amount, timestamp, product pair, order type, and username**
- Strongly typed **bid/ask distinction**
- **Purpose:** Provides a reusable data model for orders

### 4️⃣ Order Book Management (OrderBook)
- Stores orders organized by **product, timestamp, and type**
- Checks wallet balances before placing orders
- Prevents **negative currency amounts**
- **Purpose:** Simulates secure market order management

### 5️⃣ Wallet Management (Wallet)
- Adds or updates currency balances
- Prevents negative amounts
- Throws exceptions for invalid operations
- **Purpose:** Simulates a secure crypto wallet

### 6️⃣ Order Placement
- **Bid (Buy) Orders:** Requires sufficient quote currency
- **Ask (Sell) Orders:** Requires sufficient base currency
- Orders are stored but **not auto-matched**
- **Purpose:** Allows user market participation

### 7️⃣ Time Simulation Engine
- Market progresses in **discrete time steps**
- Orders evaluated per timestamp
- Loops back after last timestamp for continuous simulation
- **Purpose:** Mimics real-world market evolution

### 8️⃣ Error Handling & Safety
- **Invalid input protection** to prevent crashes
- **Financial safety:** No negative balances, no invalid trades
- **Purpose:** Ensures system stability and correctness

---

## ⚙️ Usage

1. Compile the project using a C++ compiler (e.g., `g++` or `clang++`)
2. Run the console application
3. Navigate through the menu to:
   - View market stats
   - Manage your wallet
   - Place orders
   - Advance time for simulation

---

## 📝 Notes

- This project is a **simulation** and does not connect to real cryptocurrency markets.
- Designed for **educational purposes** to demonstrate OOP and exchange mechanics.
- Can be extended to include **auto order matching, multi-user support, and real-time market feeds**.

---

## 🏆 Acknowledgements

- Inspired by **real cryptocurrency exchange systems**
- Developed as part of an **Object-Oriented Programming specialization**


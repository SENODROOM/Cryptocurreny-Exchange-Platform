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
│
├── src/
│   ├── MerkelMain.cpp        # Main console interface and control flow
│   ├── OrderBook.cpp         # Order book logic
│   ├── OrderBookEntry.cpp    # Order representation
│   ├── Wallet.cpp            # Wallet management logic
│   └── CSVReader.cpp         # CSV market data parser
│
├── include/
│   ├── OrderBook.h
│   ├── OrderBookEntry.h
│   ├── Wallet.h
│   └── CSVReader.h
│
├── data/
│   └── market_data.csv        # Sample market data CSV
│
└── README.md

- **Orders → OrderBookEntry**  
- **Market → OrderBook**  
- **Storage → Wallet**  
- **Input source → CSVReader**  

---

## 🖥️ Modules & Functionality

### 1️⃣ User Interface & Control Flow (MerkelMain)
- **Menu-driven console interface**:
  - Navigate the exchange
  - View market statistics
  - Place orders
  - Manage wallet balances
  - Advance market time
- **Input validation** prevents invalid menu choices
- Each menu cycle represents a **market tick**
- **Purpose:** Coordinates all system components

### 2️⃣ Market Data Handling (CSVReader)
- Reads CSV rows: `timestamp`, `product pair`, `order type`, `price`, `amount`
- Converts raw CSV data into **OrderBookEntry** objects
- Ignores malformed lines for **data integrity**
- **Purpose:** Simulates historical market feeds

### 3️⃣ Order Representation (OrderBookEntry)
- Stores **price, amount, timestamp, product pair, order type, username**
- Strongly typed **bid/ask distinction**
- **Purpose:** Provides a reusable order data model

### 4️⃣ Order Book Management (OrderBook)
- Stores orders by **product, timestamp, and type**
- Checks wallet balances before placing orders
- Prevents **negative currency amounts**
- **Purpose:** Simulates secure market order management

### 5️⃣ Wallet Management (Wallet)
- Adds or updates currency balances
- Prevents negative amounts
- Throws exceptions for invalid operations
- **Purpose:** Simulates a secure crypto wallet

### 6️⃣ Order Placement
- **Bid (Buy**

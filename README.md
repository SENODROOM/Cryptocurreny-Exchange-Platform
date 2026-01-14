# Cryptocurrency Exchange Platform (C++)

A console-based Cryptocurrency Exchange Platform implemented in **C++ using Object-Oriented Programming (OOP)** principles.  
This project simulates the core functionality of a crypto exchange, including order books, wallets, CSV-based market data, and time-based trading simulation.

> 📘 Inspired by real-world exchange mechanics and developed as part of an Object-Oriented Programming specialization.

---

## 📌 Features

- 📊 **Order Book System**
  - Bid and ask orders
  - Time-based order matching
  - Price statistics (min, max, average)

- 💼 **Wallet Management**
  - Insert and update currency balances
  - Prevents invalid transactions
  - Exception handling for invalid inputs

- 📁 **CSV Market Data Reader**
  - Parses historical market data from CSV files
  - Converts rows into structured order book entries

- ⏱️ **Time-Step Simulation**
  - Market advances over time
  - Orders processed per timestamp

- 🧠 **OOP Design**
  - Clear class separation
  - Encapsulation and modularity
  - Header/source file structure

---

## 🗂️ Project Structure:
UI Layer (MerkelMain)
│
├── Business Logic
│   ├── OrderBook
│   ├── Wallet
│
└── Data Layer
    └── CSVReader
Orders → OrderBookEntry
Market → OrderBook
Storage → Wallet
Input source → CSVReader



1️⃣ USER INTERFACE & CONTROL FLOW (MerkelMain)
🔹 Menu-Driven Console Interface
The system provides a console-based menu allowing the user to:
  • Navigate the exchange
  • View market statistics
  • Place orders
  • Manage wallet balances
  • Advance the market in time

🔹 Input Validation
User input is validated to avoid invalid menu choices
Prevents program crashes due to wrong input

🔹 Time Control
The exchange operates on discrete timestamps
Each menu cycle represents a market tick
User explicitly moves the market forward

📌 Functionality Purpose:
Acts as the controller coordinating all system components.

2️⃣ MARKET DATA HANDLING (CSVReader)
🔹 CSV File Parsing
Reads market data from CSV files
Each row contains:
  • timestamp
  • product pair (e.g., BTC/USDT)
  • order type (bid/ask)
  • price
  • amount

🔹 Data Conversion
Converts raw CSV strings into OrderBookEntry objects
Ensures numeric fields are correctly parsed

🔹 Data Integrity
Ignores malformed lines
Keeps market data consistent

📌 Functionality Purpose:
Provides historical market data ingestion, simulating real exchange feeds.

3️⃣ ORDER REPRESENTATION (OrderBookEntry)
🔹 Order Abstraction
Each order is represented as an object containing:
  • Price
  • Amount
  • Timestamp
  • Product pair
  • Order type (bid or ask)
  • Username (if applicable)

🔹 Strong Typing
Order types are clearly distinguished
Prevents mixing bids and asks

📌 Functionality Purpose:
Creates a clean and reusable data model for all market orders.


4️⃣ ORDER BOOK MANAGEMENT (OrderBook)
🔹 Order Storage
Stores all orders in memory
Organized by:
  • Product
  • Timestamp
  • Order type

🔹 Balance Validation
Prevents insertion of negative currency amounts
Ensures wallet consistency

🔹 Balance Checking
Checks whether the user has sufficient funds
Required before placing orders

🔹 Exception Handling
Throws exceptions for invalid operations
Prevents invalid financial state

📌 Functionality Purpose:
Simulates a secure crypto wallet.


5️⃣ WALLET MANAGEMENT (Wallet)
🔹 Currency Insertion
Adds new currency to wallet if not present
Updates existing currency balances

🔹 Balance Validation
Prevents insertion of negative currency amounts
Ensures wallet consistency

🔹 Balance Checking
Checks whether the user has sufficient funds
Required before placing orders

🔹 Exception Handling
Throws exceptions for invalid operations
Prevents invalid financial state

📌 Functionality Purpose:
Simulates a secure crypto wallet.



6️⃣ ORDER PLACEMENT
🔹 Bid Orders (Buy)
User can place buy orders
Requires sufficient quote currency
Order is added to the order book

🔹 Ask Orders (Sell)
User can place sell orders
Requires sufficient base currency
Order is added to the order book

🔹 Manual Trade Execution
Orders are stored but not auto-matched
Execution logic is separated (future upgrade)

📌 Functionality Purpose:
Allows user participation in the market.



7️⃣ TIME SIMULATION ENGINE
🔹 Discrete Time Steps
Market progresses one timestamp at a time
Orders are evaluated per time step

🔹 Market Loop
After reaching last timestamp, market loops back
Enables continuous simulation

📌 Functionality Purpose:
Simulates how real exchanges evolve over time.

8️⃣ ERROR HANDLING & SAFETY
🔹 Invalid Input Protection
Prevents crashes
Guides user back to valid operations

🔹 Financial Safety
No negative balances
No invalid trades

📌 Functionality Purpose:
Ensures system stability and correctness.
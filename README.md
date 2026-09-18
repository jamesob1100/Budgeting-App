# Budgeting App (C)
A command-line budgeting application that lets users log weekly income and 
expenses, view transaction history, and calculate a weekly budget split 
across savings, disposable income, and necessities (20/30/50 rule).

## Version history
- **V1**: Stored user input directly to a flat text file
- **V2 (current)**: Refactored to use C structs (`Income`, `Expenditure`) for 
  typed data handling, with persistence moved to CSV files for easier 
  parsing and future extensibility

## Features
- Log weekly income, automatically timestamped
- Log individual transactions with category, description, and amount
- View full earnings and expenditure history
- Calculate a weekly budget breakdown (20% savings / 30% disposable / 50% necessities)

## Build & run
gcc budgetApp.c -o budgetApp
./budgetApp

## What I'd improve next
- Bounds-checked input to prevent buffer overflow on category/description fields
- Input validation on the main menu to handle non-numeric input gracefully
- A running total/summary view instead of raw CSV output

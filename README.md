# Supermarket Management System
A console-based Supermarket Management System developed in C++ as a practice project. The project is designed to help supermarket employees manage products, search for products, add items to a cart, check stock availability, and generate bills.
## Features
- View available products
- Search for a product
- Add products to cart
- Enter product quantity
- Check available stock
- Prevent adding more quantity than available stock
- Generate a detailed bill
- Calculate total price for each item
- Calculate the grand total
- Menu-driven interface
## Programming Concepts Used
- Structures (struct)
- Arrays
- Variables
- for loops
- do-while loops
- if-else statements
- switch statements
- Boolean variables
- break statements
- Input and output using cin and cout
- Basic input validation
## Structures Used
### 1. Product
Stores information about products available in the supermarket, including:
- Product name
- Stock quantity
- Price
- Unit
### 2. Cart Item
Stores:
- Selected product name
- Quantity selected by the customer

### 3. Bill Item

Stores:

- Product name
- Quantity
- Price
- Total price

## How the System Works

The program provides a menu with the following options:

1. View Products
2. Search Product
3. Add to Cart
4. Generate Bill
5. Exit
The employee can view the available products, search for a specific product, add products to the customer's cart, check stock availability, and generate the final bill.

## Bill Calculation

The total price of each item is calculated using:
Total = Quantity × Price
The grand total is calculated by adding the total prices of all items in the cart.

## Technology
- Programming Language: C++
-  Code::Blocks

## How to Run

1. Clone or download this repository.
2. Open main.cpp in a C++ IDE such as Code::Blocks.
3. Compile the program.
4. Run the program.
5. Select an option from the menu and follow the instructions.

## Future Improvements
Some possible improvements for future versions include:
- Combining duplicate products in the cart
- Case-insensitive product search
- Adding payment and change calculation
- Adding more products dynamically
- Saving product and transaction data using files
- Adding a more advanced user interface
## Project Purpose
This project was developed to practice and apply fundamental C++ programming concepts in a practical, real-world style application.

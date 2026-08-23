#include <iostream>
#include <string>
using namespace std;

struct product {
    string name;
    int stockquantity;
    int price;
    string unit;
};

struct cartitem {
    string product;
    double quantity;
};

struct billitem {
    string name;
    float quantity;
    int price;
    float total;
};

int main() {

  product product[10] = {
        {"Milk", 30, 250, "kg"},
        {"Sugar", 50, 200, "kg"},
        {"Salt", 20, 100, "kg"},
        {"Biscuit", 40, 50, "packets"},
        {"Lays", 100, 50, "Packets"},
        {"Tea", 60, 70, "Packets"},
        {"Soap", 80, 60, "bars"},
        {"Shampoo", 50, 400, "bottle"},
        {"Vegoil", 50, 360, "kg"},
        {"oliveoil", 70, 700, "bottle"}
    };

    cartitem cartitems[10];
    int cartitemcount = 0;

    billitem item[50];
    int billcount = 0;

    int choice;

    do {
        cout << "\n==== SUPERMARKET MENU ====" << endl;
        cout << "1. View Products" << endl;
        cout << "2. Search Product" << endl;
        cout << "3. Add to Cart" << endl;
        cout << "4. Generate Bill" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1: {
                // --- 1. View Products ---
                cout << "Name\t\tStock\tPrice\tUnit" << endl;
                cout << "--------------------------------------------------" << endl;
                for (int i = 0; i < 10; i++) {
                    cout << product[i].name << "\t\t"
                         << product[i].stockquantity << "\t"
                         << product[i].price << "\t"
                         << product[i].unit << endl;
                }
                break;
            }

            case 2: {
                // --- 2. Search Product ---
                string searchname;
                cout << "Enter the product to be searched: ";
                cin >> searchname;
                bool found = false;

                for (int i = 0; i < 10; i++) {
                    if (searchname == product[i].name) {
                        cout << "\nProduct found!" << endl;
                        cout << "Name: " << product[i].name
                             << " | Stock: " << product[i].stockquantity
                             << " | Price: " << product[i].price
                             << " | Unit: " << product[i].unit << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Product not found." << endl;
                }
                break;
            }

            case 3: {
                // --- 3. Add to Cart ---
                char addMore;
                do {
                    string cartproduct;
                    cout << "Enter product to add to cart: ";
                    cin >> cartproduct;

                    bool cartfound = false;
                    for (int i = 0; i < 10; i++) {
                        if (cartproduct == product[i].name) {
                            cartfound = true;
                            double qty;
                            cout << "Enter quantity: ";
                            cin >> qty;

                            if (product[i].stockquantity < qty) {
                                cout << "NOT enough stock! Available: " << product[i].stockquantity << endl;
                            } else {
                                cartitems[cartitemcount].product = product[i].name;
                                cartitems[cartitemcount].quantity = qty;
                                cartitemcount++;

                                // Reduce stock in product
                                product[i].stockquantity -= qty;
                                cout << "Product added to cart!" << endl;
                            }
                            break;
                        }
                    }

                    if (!cartfound) {
                        cout << "Product NOT found." << endl;
                    }

                    cout << "Do you want to add more items? (y/n): ";
                    cin >> addMore;
                    cout << endl;

                } while ((addMore == 'y' || addMore == 'Y') && cartitemcount < 10);
                break;
            }

            case 4: {
                // --- 4. Generate Bill ---
                if (cartitemcount == 0) {
                    cout << "Your cart is empty! Add items to cart first." << endl;
                    break;
                }

                billcount = 0;
                cout << "================ CART ================" << endl;
                for (int i = 0; i < cartitemcount; i++) {
                    cout << "Product: " << cartitems[i].product
                         << " | Quantity: " << cartitems[i].quantity << endl;

                    // Calculate bill items
                    for (int j = 0; j < 10; j++) {
                        if (product[j].name == cartitems[i].product) {
                            item[billcount].name = cartitems[i].product;
                            item[billcount].quantity = cartitems[i].quantity;
                            item[billcount].price = product[j].price;
                            item[billcount].total = cartitems[i].quantity * product[j].price;
                            billcount++;
                            break;
                        }
                    }
                }

                cout << "\n================ BILL ================" << endl;
                float grandtotal = 0;
                for (int i = 0; i < billcount; i++) {
                    cout << "Name: " << item[i].name
                         << " | Qty: " << item[i].quantity
                         << " | Price: Rs." << item[i].price
                         << " | Total: Rs." << item[i].total << endl;
                    grandtotal += item[i].total;
                }
                cout << "--------------------------------------" << endl;
                cout << "Grandtotal: Rs." << grandtotal << endl;
                break;
            }

            case 5:
                cout << "Thank you for using the Supermarket System!" << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a option from 1 to 5." << endl;
                break;
        }

    } while (choice != 5);

    return 0;
}

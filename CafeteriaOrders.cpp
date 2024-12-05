#include <iostream>
#include <vector>
using namespace std;

// Menu class to define menu items
class MenuItem {
private:
    string itemName;
    int price;
    int itemNumber;

public:
    MenuItem(int itemNum, string name, int itemPrice) {
        itemNumber = itemNum;
        itemName = name;
        price = itemPrice;
    }

    string getItemName() {
        return itemName;
    }

    int getItemNumber() {
        return itemNumber;
    }

    int getPrice() {
        return price;
    }
};

// Cafe class to manage menu items and orders
class Cafe {
private:
    vector<MenuItem> menuItems;

public:
    // Function to add menu items
    void addItem(int itemNum, string itemName, int itemPrice) {
        MenuItem menu(itemNum, itemName, itemPrice);
        menuItems.push_back(menu);
    }

    // Function to display menu
    void displayMenu() {
        cout << "<<<<<<< Cafeteria Menu >>>>>>>" << endl;
        for (int i = 0; i < menuItems.size(); i++) {
            cout << menuItems[i].getItemNumber() << ". " << menuItems[i].getItemName()
                 << " - ₹" << menuItems[i].getPrice() << endl;
        }
    }

    // Function to handle ordering
    void placeOrder() {
        int orderNumber, quantity;
        char anotherOrder;

        // Loop to allow multiple orders
        do {
            cout << "Enter item number to order: ";
            cin >> orderNumber;

            // Validate item number
            bool itemFound = false;
            for (int i = 0; i < menuItems.size(); i++) {
                if (orderNumber == menuItems[i].getItemNumber()) {
                    itemFound = true;
                    cout << "Enter quantity: ";
                    cin >> quantity;

                    // Validate quantity
                    if (quantity <= 0) {
                        cout << "Invalid quantity! Please enter a positive number." << endl;
                        break;
                    }

                    int totalPrice = quantity * menuItems[i].getPrice();
                    cout << "Item ordered: " << menuItems[i].getItemName() 
                         << " | Quantity: " << quantity << " | Total: ₹" << totalPrice << endl;
                    break;
                }
            }

            if (!itemFound) {
                cout << "Invalid item number! Please choose a valid item." << endl;
            }

            cout << "Would you like to order another item? (y/n): ";
            cin >> anotherOrder;

        } while (anotherOrder == 'y' || anotherOrder == 'Y');

        cout << "Thank you for your order!" << endl;
    }
};

// Main function
int main() {
    Cafe cafe;

    // Adding items to the menu
    cafe.addItem(1, "Chicken Burger", 150);
    cafe.addItem(2, "Zinger Burger", 250);
    cafe.addItem(3, "Potato Chips", 50);
    cafe.addItem(4, "Juice", 100);
    cafe.addItem(5, "Samosa", 15);
    cafe.addItem(6, "Spring Rolls", 50);

    // Displaying the menu
    cafe.displayMenu();

    // Taking orders
    cafe.placeOrder();

    return 0;
}

//code by : Aarohi Chadha

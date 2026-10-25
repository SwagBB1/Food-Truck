#include "Product.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

Product::Product()
    : orderNumber(0), name(""), price(0.0), quantity(0) {
}

//FoodTruck class usage and removed MAX_ITEMS
FoodTruck::FoodTruck() {
    numItems = 0;
    nameFoodTruck = "Csi Food Truck";
    cuisine = "Street Food";
    menu = nullptr;
	cartQuantities = nullptr;
}

FoodTruck::FoodTruck(string name, string cuisineType) : nameFoodTruck(name), cuisine(cuisineType), numItems(0) {
    menu = nullptr;
	cartQuantities = nullptr;
}

int FoodTruck::getNumItems() const {
    return numItems;
}

string FoodTruck::getNameFoodTruck() const {
    return nameFoodTruck;
}

string FoodTruck::getCuisine() const {
    return cuisine;
}

void FoodTruck::setNumItems(int count) {
    if (count>= 0) {
		this->numItems = count;
    }
}

void FoodTruck::setNameFoodTruck(const string& name) {
    nameFoodTruck = name;
}
void FoodTruck::setCuisine(const string& cuisine) {
    cuisine = cuisineType;
}
//Functions
void FoodTruck::loadMenu() {
    ifstream file("Product.txt");

    if (!file.is_open()) {
        cout << "Menu is Out of Service :(" << endl;
        cout << "Please inform the Employee" << endl;
        return;
    }

    int orderNumber;
    string name;
    double price;
    int count = 0;

    // Count products in the file
    while (file >> orderNumber >> name >> price) {
        count++;
    }

    // Return to the beginning of the file
    file.clear();
    file.seekg(0);

    // Replace any previously allocated arrays
    delete[] menu;
    delete[] cartQuantities;

    menu = nullptr;
    cartQuantities = nullptr;
    numItems = 0;

    if (count == 0) {
        cout << "The menu is empty." << endl;
        file.close();
        return;
    }

    // Allocate arrays
    menu = new Product[count];
    cartQuantities = new int[count]();

    numItems = count;

    // Store and display products
    for (int i = 0; i < numItems; i++) {
        if (!(file >> orderNumber >> name >> price)) {
            numItems = i;
            break;
        }

        menu[i].setOrderNumber(orderNumber);
        menu[i].setName(name);
        menu[i].SetFoodPrice(price);
        menu[i].SetQuantity(0);

        cout << "Order Number: "
             << menu[i].getOrderNumber()
             << ". " << menu[i].getName()
             << " - $" << fixed << setprecision(2)
             << menu[i].getPrice() << endl;
    }

    file.close();
}


//Jose's Function
void FoodTruck::takeOrder() {
    if (numItems <= 0 || menu= nullptr) {
        return;
    }
    int selections = -1;
    int qty = 0;
	cout << "\nEnter the order number of the item you want to order (or 0 to finish): ";
    while (true) {
        if (!(cin >> selection)) {
            cout << "Invalid input. Please enter a number: ";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (selection == 0) {
            break;
        }

        // Find product using its order number
        int index = -1;

        for (int i = 0; i < numItems; i++) {
            if (menu[i].getOrderNumber() == selection) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Invalid order number. Please try again: ";
            continue;
        }

        cout << "How many "
             << menu[index].getName()
             << "(s) would you like to order? ";

        if (!(cin >> qty) || qty <= 0) {
            cout << "Invalid quantity. Enter a quantity "
                 << "greater than 0: ";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cartQuantities[index] += qty;

        cout << "Added " << qty << " "
             << menu[index].getName()
             << "(s) to your order." << endl;

        cout << "\nEnter another order number "
             << "(or 0 to finish): ";
    }
}

//JeanCarlos's Function:
double FoodTruck::TotalOrderAmount() const {
    double total = 0.0;
	for( int i = 0; i < numItems; i++){
		total += cartQuantities[i] * menu[i].getPrice();
	}
	return total;
}

//Jose's Function
if (numItems <= 0 || menu == nullptr ||
        cartQuantities == nullptr) {
        cout << "No menu is available to print a receipt."
             << endl;
        return;
    }

    bool orderedAnything = false;

    for (int i = 0; i < numItems; i++) {
        if (cartQuantities[i] > 0) {
            orderedAnything = true;
            break;
        }
    }

    if (!orderedAnything) {
        cout << "\nNo items ordered. Please try again."
             << endl;
        return;
    }

	//time and date
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char timeBuffer[80];
    strftime(timeBuffer, sizeof(timeBuffer), "%m/%d/%Y %I:%M %p", ltm);

    for (int i = 0; i < numItems; ++i) {
        if (cartQuantities[i] > 0) {
            subtotal += menu[i].getPrice() * cartQuantities[i];
        }
    }
	double subtotal = TotalOrderAmount();
    double taxAmount = subtotal * 0.08875;
    double grandTotal = subtotal + taxAmount;
    
	double cashGiven = 0.0;
    cout << "\n  Total: $" << fixed << setprecision(2) << grandTotal << endl;
    cout << "Enter cash given: $";
    while (!(cin >> cashGiven) || cashGiven < grandTotal) {
        cout << "Insufficient or invalid cash. "
             << "Please enter at least $."
             << fixed << setprecision(2)
             << grandTotal << ": ";

        cin.clear();
        cin.ignore(10000, '\n');
    }
    double change = cashGiven - grandTotal;
    cout << endl << endl;
    cout << "               " << nameFoodTruck << "               " << endl;
    cout << "               " << cuisine << "               " << endl;
    cout << "            Staten Island, NY 10314          " << endl;
    cout << "                (718) 555-0199               " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "                  RECEIPT                   " << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    for (int i = 0; i < numItems; i++) {
        if (cartQuantities[i] > 0) {
            double lineTotal = menu[i].getPrice() * cartQuantities[i];
            cout << cartQuantities[i] << " x " << menu[i].getName() << " - $" << fixed << setprecision(2) << lineTotal << endl;
        }
    }
    cout << "--------------------------------------------" << endl;
    cout << "SUBTOTAL: $" << fixed << setprecision(2) << subtotal << endl;
    cout << "NYC TAX (8.875%): $" << fixed << setprecision(2) << taxAmount << endl;
    cout << "TOTAL AMOUNT: $" << fixed << setprecision(2) << grandTotal << endl;
    cout << "CASH GIVEN: $" << fixed << setprecision(2) << cashGiven << endl;
    cout << "CHANGE: $" << fixed << setprecision(2) << change << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Date/Time: " << timeBuffer << endl;
    cout << "--------------------------------------------" << endl;
    cout << "                 THANK YOU                  " << endl; // Added missing endl
    cout << "--------------------------------------------" << endl;
    cout << " ||| |||| | || |||||| | ||| | ||| || ||| || " << endl;
    cout << "--------------------------------------------" << endl;
}

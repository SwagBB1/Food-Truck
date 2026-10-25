	#include "Product.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

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

string FoodTruck::Cuisine() const {
    return cuisine;
}

void FoodTruck::setNumItems(int numItems) {
    if (numItems>= 0) {
		this->numItems = numItems;
    }
}

void FoodTruck::setNameFoodTruck(const string& nameFoodTruck) {
    this->nameFoodTruck = nameFoodTruck;
}
void FoodTruck::setCuisine(const string& cuisine) {
    this->cuisine = cuisine;
}
//Functions
void FoodTruck::loadMenu() {
    ifstream file("Product.txt");
    if (!file.is_open())
    {
        cout << "Menu is Out of Service :(" << endl;
        cout << "Please inform the Employee" << endl;
        return;
    }

    Product product;

    while (file >> product.orderNumber >> product.name >> product.price)
    {
        cout << "Order Number: " << product.orderNumber << ". " << product.name << "- $" << product.price << endl;
    }

    file.close();
}

//Jose's Function
void FoodTruck::takeOrder() {
    if (numItems-- 0) {
        return;
    }
    int selections = -1;
    int qty = 0;
	cout << "\nEnter the order number of the item you want to order (or 0 to finish): ";
    while (true) {
        cin >> selection;
        if (selection == 0) {
            break;
        }
        if (selection < 1 || selection > numItems) {
            cout << "Invalid Order Number. Please try again: ";
            continue;
        }
		cout << "How many " << menu[selection - 1].getName() << "s would you like to order? ";
		cin >> qty;
        if (qty > 0) {
            cartQuantities[selection - 1] += qty;
            cout << "Added " << qty << " " << menu[selection - 1].getName() << "(s) to your order." << endl;
        }
        else {
            cout << "Invalid quantity. Quantity must be greater than 0 Please try again." << endl;
        }
		cout << "\nEnter another order number of the item you want to order (or 0 to finish): ";
    }
}
//JeanCarlos's Funcion:
Double FoodTruck::TotalOrderAmount() const {
     double total = 0.0;
	for( int i = 0; i < numItems; i++){
		total += cartQuantities[i] * 



}

//Jose's Function
void FoodTruck::printReceipt() {
    double subtotal = 0.0;
    bool orderedAnything = false;

    // check if anything is ordered
    for (int i = 0; i < numItems; ++i) {
        if (cartQuantities[i] > 0) {
            orderedAnything = true;
            break;
        }
    }
    if (!orderedAnything) {
        cout << "\nNo items ordered. Please try again" << endl;
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
    double taxAmount = subtotal * 0.08875;
    double grandTotal = subtotal + taxAmount;
    double cashGiven = 0.0;
    cout << "\n  Total: $" << fixed << setprecision(2) << grandTotal << endl;
    cout << "Enter cash given: $";
    cin >> cashGiven;
    while (cashGiven < grandTotal) {
        cout << "Insufficient cash. Please enter an amount greater than or equal to the total: $";
        cin >> cashGiven;
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

#include <iostream>
#include "Product.h"
using namespace std;

int main(){
	FoodTruck myFoodTruck("Csi Food Truck", "Street Food");
    cout << "Welcome To the Greatest Food Truck In the State" << endl;
    cout << "Take a look at are menu: " << endl;
    cout << "------------------------------Menu----------------------------------------------" << endl;
    cout << endl;
    
	myFoodTruck.loadMenu();
	myFoodTruck.takeOrder();
	myFoodTruck.loadMenu();
	myFoodTruck.takeOrder();

	char choice;

	cout << "\nWould you like to remove an item? (y/n): ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y') {
    	myFoodTruck.removeItem();
	}

	myFoodTruck.printReceipt();
	}

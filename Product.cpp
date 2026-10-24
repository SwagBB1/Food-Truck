#include "Product.h"
#include <iostream>
#include <iomanip>
using namespace std;

FoodTruck::FoodTruck() {
    numItems = 0;
    nameFoodTruck = "Csi Food Truck";
    cuisine = "Street Food";
}

FoodTruck::FoodTruck(string name, string cuisineType) {
    numItems = 0;
    nameFoodTruck = name;
    cuisine = cuisineType;
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

void FoodTruck::setNumItems(int num) {
    if (num >= 0 && num <= MAX_ITEMS) {
        numItems = num;
    } else {
        cout << "Invalid number of items. It must be between 0 and " << MAX_ITEMS << "." << endl;
	}
    numItems = num;
}

void FoodTruck::setNameFoodTruck(const string& name) {
    nameFoodTruck = name;
}

void FoodTruck::setCuisine(const string& cuisineType) {
    cuisine = cuisineType;
}

void menufile()
{
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

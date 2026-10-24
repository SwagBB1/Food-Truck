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
    nameFoodTruck = name;
    cuisine = cuisineType;
    numItems = 0;
}

int FoodTruck::getNumItems() const {
    return numItems;
}

string FoodTruck::getNameFoodTruck() const {
    return nameFoodTruck;
}

string FoodTruck::Cuisine() const {
    return cuisine;

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

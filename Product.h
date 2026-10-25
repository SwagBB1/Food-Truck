#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product
{
private:
    int orderNumber;
    string CustomerName;
    double price;
    int quantity;

public:
    Product();
    void setOrderNumber(int Number) {
        orderNumber = Number;
    }
    void setName(const string& CustomerNamee) {
        name = CustomerName;
    }
    void SetFoodPrice(double FoodPrice) {
        price = FoodPrice;
    }

    void SetQuantity(int Quantityitems) {
        quantity = Quantityitems;
    }

    int setOrderNumber() const {
      return orderNumber;
    }
    string SetFoodName() const {
          return name;
    }
    double SetFoodPrice() const {
        return price;
   }   
     int SetQuantity() const {
      return quantity;
    }
};

//Jose's Class
class FoodTruck {
private:
    int numItems;
    string nameFoodTruck;
    string cuisine;
    //Dynamic Array of Products
    Product* menu;
    int* cartQuantities;
public:
    FoodTruck();
    FoodTruck(string name, string cuisineType);
    ~FoodTruck();

    // Getters
    int getNumItems() const;
    string getNameFoodTruck() const;
    string getCuisine() const;

    // Setters
    void setNumItems(int count);
    void setNameFoodTruck(const string& name);
    void setCuisine(const string& cuisineType);

    // Functions
    void loadMenu();
    void takeOrder();
    void removeItem();
    double TotalOrderAmount() const;
    void printReceipt();
};

#endif

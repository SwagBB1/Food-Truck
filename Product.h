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
    string name;
    double price;
    int quantity;

public:
    Product();
void setOrderNumber(int Number)
{
Number = orderNumber;
}
   void SetFoodName(string FoodName){
         FoodName = name; }
   
       void SetFoodPrice(double FoodPrice){
   FoodPrice = price; 
}
  void SetQuantity(int Quantityitems){
Quantityitems = quantity;
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

void menufile();

#endif

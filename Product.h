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
void menufile();

#endif

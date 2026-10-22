#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Product
{
    int orderNumber;
    string name;
    double price;
};

void menufile();

#endif

#include "Product.h"

void menufile()
{
    ifstream file("Proudct.txt");

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

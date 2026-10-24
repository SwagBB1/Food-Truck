#include <iostream>
#include "Product.h"
using namespace std;

int main(){
	FoodTruck myFoodTruck("Csi Food Truck", "Street Food");
    cout << "Welcome To the Greatest Food Truck In the State" << endl;
    cout << "Take a look at are menu: " << endl;
    cout << "------------------------------Menu----------------------------------------------" << endl;
    cout << endl;
    menufile();
    return 0;
}

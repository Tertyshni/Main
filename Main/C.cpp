#include "DynamicArray.h"
#include <iostream>
using namespace std;

int main() {
    DynamicArray arr1;
    arr1.add(10);
    arr1.add(20);
    arr1.add(30);
    arr1.print(); 

    arr1.remove(1);
    arr1.print(); 

    std::cout << "arr1[1] = " << arr1[1] << std::endl;

    DynamicArray arr2;
    arr2 += 5;
    arr2 += 15;
    arr2 += 25;

    DynamicArray arr3 = arr1 + arr2;
    arr3.print(); 

    DynamicArray arr4 = arr3; 
    std::cout << (arr3 == arr4 ? "Equal" : "Not equal") << std::endl;

   
    arr1.remove(10);  
    std::cout << arr1.get(-1) << std::endl; 
    std::cout << arr1[-5] << std::endl;     

    return 0;
}

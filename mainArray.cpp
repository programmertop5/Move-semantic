#include <iostream>
#include "DynamicArray.h"
#include "MyString.h"
using namespace std;

int main() {
  
    String a("Microsoft");
    String b("Windows");

    String c = a * b; 
    c.Show();         

    String d = a / b; 
    d.Show();        

    String e = std::move(d);
    e.Show();        
    d.Show();       

    
    DynamicArray arr1;
    arr1 += 1; arr1 += 2; arr1 += 3; arr1 += 4; arr1 += 5;

    DynamicArray arr2;
    arr2 += 3; arr2 += 4; arr2 += 5; arr2 += 6; arr2 += 7;

    DynamicArray arr3 = arr1 * arr2; 
    arr3.print();                    

    DynamicArray arr4 = arr1 / arr2;
    arr4.print();                  

    DynamicArray arr5 = arr1;       
    arr5.print();                  

    DynamicArray arr6 = std::move(arr2); 
    arr6.print();                     
    arr2.print();                       

    return 0;
}

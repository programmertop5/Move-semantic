#include <iostream>
#include "MyString.h"



int main() {
    String s1("Hello");
    String s2("World");

    cout << "s1: ";
    s1.Show();

    cout << "s2: ";
    s2.Show();

    
    s1.push_back('!');
    cout << "s1 after push_back('!'): ";
    s1.Show();

    
    s2.pop_back();
    cout << "s2 after pop_back(): ";
    s2.Show();

    
    s1.append(" C++");
    cout << "s1 after append(\" C++\"): ";
    s1.Show();

    
    String s3 = s1 * s2;
    cout << "s3 (symbols that are present in both places): ";
    s3.Show();

    
    String s4 = s1 / s2;
    cout << "s4 (characters that are not in the second): ";
    s4.Show();

    
    String s5 = std::move(s1);
    cout << "s5 after move s1: ";
    s5.Show();

    cout << "s1 after move: ";
    s1.Show();

    return 0;
}

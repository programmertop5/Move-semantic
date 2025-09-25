#pragma once
#include <iostream>
using namespace std;

class String {
    char* data;
    int length;

public:
    String();                       
    String(const char* str);        
    String(const String& other);
    String& operator=(const String& other);    
    String(String&& other);        
    ~String();


    int size() const;
    bool empty() const;
    const char* c_str() const;
    char at(int index) const;

    void push_back(char c);
    void pop_back();
    void clear();
    void append(const char* str);
    void assign(const char* str);
    int find(char c) const;
    void print();

    String& operator=(const String& other); 
    String& operator=(String&& other);     

    String operator*(const String& other) const; 
    String operator/(const String& other) const; 

    void Show() const;

}

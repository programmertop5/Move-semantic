#pragma once
#include <string>
#include <iostream>

class DynamicArray {
private:
    int* data;
    int n_size;
    int n_capacity;

public:
   
    DynamicArray() { data = nullptr; n_size = 0; n_capacity = 0; }
    DynamicArray(int capacity);
    ~DynamicArray();

    
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);

    
    DynamicArray(DynamicArray&& other);
    DynamicArray& operator=(DynamicArray&& other);

    
    void add(int value);
    void remove(int index);
    int get(int index);
    int size() const;
    int capacity() const;
    void print() const;

    
    int& operator[](int index);
    const int& operator[](int index) const;

    
    DynamicArray operator+(const DynamicArray& other) const;
    DynamicArray& operator+=(int value);
    DynamicArray& operator+=(const DynamicArray& other);

    
    bool operator==(const DynamicArray& other) const;
    DynamicArray operator*(const DynamicArray& other) const; 
    DynamicArray operator/(const DynamicArray& other) const; 

    
    int* getData() { return data; }
    
};

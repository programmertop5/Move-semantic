#include "DynamicArray.h"
#include <iostream>


DynamicArray::DynamicArray(int capacity_) {
    std::cout << "Constructor with parameter!" << std::endl;
    if (capacity_ <= 0) capacity_ = 1;
    n_capacity = capacity_;
    n_size = 0;
    data = new int[n_capacity];
}

DynamicArray::~DynamicArray() {
    std::cout << "Destructor!" << std::endl;
    delete[] data;
}


DynamicArray::DynamicArray(const DynamicArray& other) {
    std::cout << "Copy constructor" << std::endl;
    n_size = other.n_size;
    n_capacity = other.n_capacity;
    data = new int[n_capacity];
    for (int i = 0; i < n_size; i++) {
        data[i] = other.data[i];
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    std::cout << "Operator= copy" << std::endl;
    if (this == &other) return *this;
    if (data != nullptr) delete[] data;

    n_capacity = other.n_capacity;
    n_size = other.n_size;
    data = new int[n_capacity];
    for (int i = 0; i < n_size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

DynamicArray::DynamicArray(DynamicArray&& other) {
    data = other.data;
    n_size = other.n_size;
    n_capacity = other.n_capacity;

    other.data = nullptr;
    other.n_size = 0;
    other.n_capacity = 0;
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;

    data = other.data;
    n_size = other.n_size;
    n_capacity = other.n_capacity;

    other.data = nullptr;
    other.n_size = 0;
    other.n_capacity = 0;

    return *this;
}


void DynamicArray::add(int value) {
    if (n_size == n_capacity) {
        int newCapacity = (n_capacity == 0) ? 1 : n_capacity * 2;
        int* newData = new int[newCapacity];
        for (int i = 0; i < n_size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        n_capacity = newCapacity;
    }
    data[n_size] = value;
    n_size++;
}

void DynamicArray::remove(int index) {
    if (index < 0 || index >= n_size) return;
    for (int i = index; i < n_size - 1; i++) {
        data[i] = data[i + 1];
    }
    n_size--;
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= n_size) return 0;
    return data[index];
}

int DynamicArray::size() const {
    return n_size;
}

int DynamicArray::capacity() const {
    return n_capacity;
}

void DynamicArray::print() const {
    for (int i = 0; i < n_size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int& DynamicArray::operator[](int index) {
    if (index < 0 || index >= n_size) {
        static int dummy = 0;
        return dummy;
    }
    return data[index];
}

const int& DynamicArray::operator[](int index) const {
    if (index < 0 || index >= n_size) {
        static int dummy = 0;
        return dummy;
    }
    return data[index];
}

DynamicArray DynamicArray::operator+(const DynamicArray& other) const {
    DynamicArray result(n_size + other.n_size);
    for (int i = 0; i < n_size; i++) {
        result.add(data[i]);
    }
    for (int i = 0; i < other.n_size; i++) {
        result.add(other.data[i]);
    }
    return result;
}

DynamicArray& DynamicArray::operator+=(int value) {
    add(value);
    return *this;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& other) {
    for (int i = 0; i < other.n_size; i++) {
        add(other.data[i]);
    }
    return *this;
}

bool DynamicArray::operator==(const DynamicArray& other) const {
    if (n_size != other.n_size) return false;
    for (int i = 0; i < n_size; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}


DynamicArray DynamicArray::operator*(const DynamicArray& other) const {
    DynamicArray result;

    for (int i = 0; i < n_size; i++) {
        for (int j = 0; j < other.n_size; j++) {
            if (data[i] == other.data[j]) {
                result.add(data[i]);
                break; 
            }
        }
    }

    return result; 
}

DynamicArray DynamicArray::operator/(const DynamicArray& other) const {
    DynamicArray result;

    for (int i = 0; i < n_size; i++) {
        bool found = false;
        for (int j = 0; j < other.n_size; j++) {
            if (data[i] == other.data[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.add(data[i]);
        }
    }

    return result; 
}




DynamicArray getNewArray(int size) {
    DynamicArray result(size);
    for (int i = 0; i < size; i++) {
        result.add(i * 10);
    }
    return result;
}





  




















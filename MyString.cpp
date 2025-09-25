#include <iostream>
#include <cstring>
#include "MyString.h"
using namespace std;

String::String() {
    length = 0;
    data = new char[1];
    data[0] = '\0';
}

String::String(const char* str) {
    if (str == nullptr) {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }
    else {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }
}

String::String(const String& other) {
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);
}

String& String::operator=(const String& other)
{
    cout << "OPERATOR = " << endl;
    if (this == &other) return *this;
    delete[]data;
    length = other.length;
    data = new char[length + 1];
    strcpy(data, other.data);
    return *this;
    // TODO: insert return statement here
}

String& String::operator=(String&& other)
{
    cout << "Operator= move" << endl;
    if (this == &other) return *this;

    delete[] data;
    data = other.data;
    length = other.length;

    other.data = nullptr;
    other.length = 0;

    return *this;
    // TODO: insert return statement here
}

String String::operator*(const String& other) const
{
    String result;
    for (int i = 0; i < length; i++) {
        if (other.find(data[i]) != -1) { 
            result.push_back(data[i]);   
        }
    }
    return result; 
}


String String::operator/(const String& other) const {
    String result; 
    for (int i = 0; i < length; i++) {
        if (other.find(data[i]) == -1) { 
            result.push_back(data[i]);   
        }
    }
    return result; 
}

String::String(String&& other)
{
    cout << "Move constructor!" << endl;
    data = other.data;
    length = other.length;
    other.data = nullptr;
    other.length = 0;
    
}

String::~String() {
    delete[] data;
}

int String::size() const {
    return length;
}

bool String::empty() const {
    return length == 0;
}

const char* String::c_str() const {
    return data;
}

char String::at(int index) const {
    if (index < 0 || index >= length) {
        cout << "Error\n";
        return '\0';
    }
    return data[index];
}

void String::push_back(char c) {
    char* newData = new char[length + 2];
    strcpy(newData, data);
    newData[length] = c;
    newData[length + 1] = '\0';

    delete[] data;
    data = newData;
    length++;
}

void String::pop_back() {
    if (length == 0) {
        return;
    }

    char* newData = new char[length];
    strncpy(newData, data, length - 1);
    newData[length - 1] = '\0';

    delete[] data;
    data = newData;
    length--;
}


void String::clear() {
    delete[] data;
    length = 0;
    data = new char[1];
    data[0] = '\0';
}

void String::append(const char* str) {
    if (str == nullptr) {
        return;
    }

    int strLen = strlen(str);
    char* newData = new char[length + strLen + 1];

    strcpy(newData, data);
    strcat(newData, str);

    delete[] data;
    data = newData;
    length += strLen;
}

void String::assign(const char* str) {
    delete[] data;
    if (str == nullptr) {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }
    else {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }
}

int String::find(char c) const {
    for (int i = 0; i < length; i++) {
        if (data[i] == c) {
            return i;
        }
    }
    return -1;
}

void String::Show() const {
    cout << data << endl;
}

void String::print() {
    cout << data << " (length: " << length << ")" << endl;
}

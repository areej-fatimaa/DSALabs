// AutoGrowingArray.h
#pragma once
#include <iostream>
using namespace std;

template<typename TemplateClass>
class AutoGrowingArray {
private:
    int size;
    int capacity;
    TemplateClass* DA;

public:
    AutoGrowingArray(int size, int capacity) {
        DA = new TemplateClass[capacity];
        this->size = size;
        this->capacity = capacity;
    }

    ~AutoGrowingArray() {
        delete[] DA;
    }

    void InsertAtTheEnd(int value) {
        if (size == capacity) {
            capacity =capacity*1.5;
            TemplateClass* HA = new TemplateClass[capacity];
            for (int i = 0; i < size; i++) {
                HA[i] = DA[i];
            }
            delete[] DA;
            DA = HA;
        }
        DA[size] = value;
        size++;
    }
    friend ostream& operator<< (ostream& cout, AutoGrowingArray<TemplateClass>& arr);
   
};
template<typename TemplateClass>
 ostream& operator<< (ostream& cout, AutoGrowingArray<TemplateClass>& arr) {
    for (int i = 0; i < arr.size; i++) {
        cout << arr[i] << " ";
    }
    return cout;
} 

#ifndef DynamicArray_hpp
#define DynamicArray_hpp

#include <string>
#include <sstream>
#pragma once
using namespace std;

const string SIZE_LESS_00 = "Size is less than 0";
const string INDEX_OUT_OF_RANGE0 = "Index out of range";

template <typename T>
class DynamicArray {
private:
    T* data = nullptr;
    int size;
public:
    //Contructor
    DynamicArray() {//create empty array
        size = 0;
    };
    DynamicArray(int size) {// create an empty array of the specified length
        if (size < 0) {
            throw length_error(SIZE_LESS_00);
        };
        data = new T[size];
        this->size = size;
    };
    DynamicArray(T* items, int count) { // create an empty array and copy the elements from the given array, obtaining an identical array
        if (count < 0) {
            throw length_error(SIZE_LESS_00);
        };
        data = new T[count];
        size = count;
        for (int i = 0; i < count; i++)
            data[i] = items[i];
    };
    DynamicArray(DynamicArray <T>& dynamicArray) {// creating a copy of the original masive
        data = new T[size];
        size = dynamicArray.size;
        for (int i = 0; i < size; i++) {
            data[i] = dynamicArray.data[i];
        };
    };
    DynamicArray(DynamicArray<T>* dynArr) {
        size = dynArr->size;
        data = dynArr->data;
    }


    //Destructor
    ~DynamicArray() {
        delete[] data;
        size = 0;
    };
    void Delete_DynamicArray() { // deleting an entire array
        delete[] data;
        size = 0;
    }


    string toString(int val)    //int to string
    {
        ostringstream oss;
        oss << val;
        return oss.str();
    }

    //Decomposition
    T Get(int index) {// returns the element by index
        if (index < 0 || index >= size) {
            string msg = INDEX_OUT_OF_RANGE0 + ". Get -> " + toString(index) + " but len -> " + toString(size);
            throw out_of_range(msg);
        };
        return data[index];
    };

    int GetSize() {// returns the size of the array(number of all cells)
        return size;
    }


    //Operations
    void Set(int index, T value) {//create element by index
        if (index < 0 || index >= size) {
            string msg = INDEX_OUT_OF_RANGE0 + ". Get -> " + toString(index) + " but len -> " + toString(size);
            throw out_of_range(msg);
        }
        data[index] = value;
    };
    void Resize(int newSize) {// change the dimension of the array
        if (newSize < 0) {
            throw out_of_range(INDEX_OUT_OF_RANGE0);
        };

        if (newSize == 0) {
            delete[] data;
            data = nullptr;
            size = 0;
            return;
        }// len = 0 => delete

        if (newSize == size) {
            return;
        }

        if (newSize < size) {
            T* new_data = new T[newSize];
            for (int i = 0; i < newSize; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            size = newSize;
            data = new_data;
            return;
        }// shortening array

        if (newSize > 0 && size == 0) {
            T* new_data = new T[newSize];
            delete[] data;
            size = newSize;
            data = new_data;
        }//

        if (newSize > size) {
            T* new_data = new T[newSize];
            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            size = newSize;
            data = new_data;
            return;
        }// increase length of array
    };


    //Operator
    T operator[] (int index) {
        if (index < 0 || index >= this->size) {
            throw out_of_range(INDEX_OUT_OF_RANGE0);
        }
        return this->Get(index);
    };

};
#endif //DynamicArray_hpp 
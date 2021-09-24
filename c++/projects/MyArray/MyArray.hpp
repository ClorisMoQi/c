#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray{
public:
    // constructor with parameter(s)
    MyArray(int capacity){
        cout << "MyArray constructor with parameter(s)" << endl;
        this->capacity = capacity;
        this->size = 0;
        this->address = new T[this->capacity];
    }

    // destructor
    ~MyArray(){
        cout << "MyArray destructor" << endl;
        if (!this->address){
            delete[] this->address;
            this->address = NULL;
        }
    }

    // copy constructor
    MyArray(const MyArray& arr){
        cout << "MyArray copy constructor" << endl;
        this->capacity = arr.capacity;
        this->size = arr.size;
        // prevent shallow copy, allocate a new T to do a deep copy
        this->address = new T[arr.capacity];

        // copy data from arr
        for (int i=0; i<this->size; i++){
            this->address[i] = arr.address[i];
        }
    }

    // overload operator= to prevent shallow copy
    MyArray& operator= (const MyArray &arr){
        cout << "MyArray overload =" << endl; 
        // free the memory if there's data occuping this heap memory
        delete[] this->address;
        this->address = NULL;
        this->capacity = 0;
        this->size = 0;

        // deep copy
        this->capacity = arr.capacity;
        this->size = arr.size;
        this->address = new T[arr.capacity];
        for(int i=0; i<this->size; i++){
            this->address[i] = arr.address[i];
        }
        return *this;
    }
    
    // add a new element to the last
    void pushBack(const T &val){
        cout << "push back " << endl;
        if (this->capacity == this->size){
            return;
        }
        this->address[this->size] = val;
        this->size++;
    }

    // delete the last element
    void popBack(){
        
        if(this->size == 0){
            return;
        }
        this->size--;
    }

    // get elements by index
    T& operator[](int index){
        return this->address[index];
    }

    int getSize(){
        return this->size;
    }

    int getCapacity(){
        return this->capacity;
    }

private:
    T* address; // an address point to the heap
    int capacity;
    int size;
};
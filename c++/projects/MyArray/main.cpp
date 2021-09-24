#include <iostream>
#include <string>
#include "MyArray.hpp"

using namespace std;

class Person{
public:
    Person(){};

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }

// private:
    string name;
    int age;
};

void printIntArray(MyArray<int>& arr){
    for (int i=0; i<arr.getSize(); i++){
        cout << arr[i] << endl;
    }
}

void printPersonArray(MyArray<Person>& arr){
    for(int i=0; i<arr.getSize(); i++){
        cout << arr[i].name << " : " << arr[i].age << endl;
    }
}

int main(int argc, char const *argv[])
{
    // MyArray<int> arr1(5);
    
    // cout << arr1.getCapacity() << " " << arr1.getSize() << endl;
    // for (int i=0; i<5; i++){
    //     arr1.pushBack(i);
    // }

    // cout << "arr1: " << endl;

    // printIntArray(arr1);

    // cout << "arr2: " << endl;
    // MyArray<int> arr2(arr1);
    // printIntArray(arr2);

    // arr2.popBack();

    // printIntArray(arr2);


    MyArray<Person> arr(10);
    Person p1("Cloris", 16);
    Person p2("Cloris", 17);
    Person p3("Cloris", 18);
    Person p4("Cloris", 19);
    Person p5("Cloris", 20);
    
    arr.pushBack(p1);
    arr.pushBack(p2);
    arr.pushBack(p3);
    arr.pushBack(p4);
    arr.pushBack(p5);


    printPersonArray(arr);

    arr.popBack();

    printPersonArray(arr);

    return 0;
}



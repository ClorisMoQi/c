#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;


// class Person{
// public:
//     Person(){};

//     Person(string name, int age){
//         this->name = name;
//         this->age = age;
//     }

// // private:
//     string name;
//     int age;
// };


// void myPrint(Person *val){
//     cout << val->name << " : " << val->age << endl;
// }

// int main(int argc, char const *argv[])
// {
//     vector<Person *> p;
//     Person p1("Cloris", 16);
//     Person p2("Cloris", 17);
//     Person p3("Cloris", 18);
//     Person p4("Cloris", 19);
//     Person p5("Cloris", 20);

//     p.push_back(&p1);
//     p.push_back(&p2);
//     p.push_back(&p3);

//     for(vector<Person *>::iterator it=p.begin(); it!=p.end(); it++){
//         // cout << (*it).name << " : " << (*it).age << endl;
//         cout << (*it)->name << " : " << (*it)->age << endl;

//     }

//     for_each(p.begin(), p.end(), myPrint);
//     return 0;
// }


void printVector(vector<int> &v){
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int num = 0;
    int * p = NULL;
    vector<int> v;
    // v.reserve(100000);
    for(int i=0; i<100000; i++){
        v.push_back(i);
        if(p != &v[0]){
            p = &v[0];
            num++;
        }
    }

    
    cout << num << endl;
    return 0;
}

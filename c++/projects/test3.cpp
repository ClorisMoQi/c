#include <iostream>
#include <string>

using namespace std;



template <class T1, class T2>
class Person;

template <class T1, class T2>
void printPerson2(Person<T1, T2> &p){
    cout << "person2: \nName: " << p.name << "\nAge: " << p.age << endl;
}

template <class T1, class T2>
class Person{
    friend void printPerson(Person<T1, T2> &p){
        cout << "Name: " << p.name << "\nAge: " << p.age << endl;
    }
    
    friend void printPerson2<>(Person<T1, T2> &p);
    public:
    Person(T1 name, T2 age){
        this->name = name;
        this->age = age;
    }

    
    private:
    T1 name;
    T2 age;
};





void test3(){
    Person<string, int> p("Alice", 21);
    printPerson2(p);
}

int main(int argc, char const *argv[])
{

    test3();

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

template <class T1, class T2>
class Person {
    public:
    Person(T1 name, T2 age){
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson(){
        cout << "Name: " << this->m_Name << endl << "Age: " << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};


void printPerson1(Person<string, int> &p){
    p.showPerson();
}

void test1(){
    Person<string, int> p("Tom", 12);
    printPerson1(p);
}

template<class T1, class T2>
void printPerson2(Person<T1, T2> &p){
    p.showPerson();
    cout << "Type of T1: " << typeid(T1).name() << endl;
    cout << "Type of T2: " << typeid(T2).name() << endl;

}

void test2(){
    Person<string, int> p("Lily", 10);
    printPerson2(p);
}

template <class T>
void printPerson3(T &p){
    cout << "Type of T: " << typeid(T).name() << endl;
    p.showPerson();
    
}
void test3(){
    Person<string, int> p("Cole", 23);
    p.showPerson();
}

int main(int argc, char const *argv[])
{
    test1();

    test2();

    test3();
    return 0;
}

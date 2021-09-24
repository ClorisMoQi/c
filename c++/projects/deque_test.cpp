#include <iostream>
#include <deque>

using namespace std;

void printDeque(const deque<int> &d){
    for(deque<int>::const_iterator it=d.begin(); it!=d.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    deque<int> d1;
    for (int i=0; i<10; i++){
        d1.push_back(i);
    }
    printDeque(d1);

    d1.insert(d1.begin()+1, 2, 10000);
    printDeque(d1);

    d1.erase(d1.begin()+2);
    printDeque(d1);


    return 0;
}

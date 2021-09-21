#include <iostream>

using namespace std;

class Year{
private:
    int y;
public:
    static int const Inity;
    Year(){
        y = Inity;
    }  
};
int const Year::Inity=1997; // 静态变量的赋值方法，注意必须放在类外定义

int main(){
    Year y;
    cout << Year::Inity << endl; //注意调用方式，这里是用类名调用的
    return 0;
}
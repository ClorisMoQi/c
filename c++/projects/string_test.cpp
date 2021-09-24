#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string s1;
    s1 = "hello word";
    cout << "s1 = " << s1 << endl;

    string s2;
    s2 = s1;
    cout << "s2 = " << s2 << endl;

    string s3;
    s3 = 'a';
    cout << "s3 = " << s3 << endl;

    string s4;
    s4.assign("hello C++");
    cout << "s4 = " << s4 << endl;

    string s5;
    s5.assign("hello C++", 5);
    cout << "s5 = " << s5 << endl;

    string s6;
    s6.assign(s5);
    cout << "s6 = " << s6 << endl;

    string s7;
    s7.assign(10, 'w');
    cout << "s7 = " << s7 << endl;

    string s8 = "a";
    s8 += 'w';
    cout << "s8 = " << s8 << endl;

    string s9 = "Wolf: ";
    cout << "s9 = " << s9.append(s8) << endl;

    string s10 = "I love ";
    cout << "s10 = " << s10.append(s4, 6, 8) << endl;

    cout << s10.find("C++") << endl;
    cout << s10.rfind("C++") << endl;

    string email = "1847115521@qq.com";
    int pos = email.find("@");

    cout << pos << endl;
    string username = email.substr(0,pos);
    cout << username << endl;

    cout << username.length() << endl;
    cout << username.size() << endl;
    cout << sizeof(email) << endl;

    return 0;
}

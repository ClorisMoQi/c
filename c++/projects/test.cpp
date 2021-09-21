#include <iostream>

using namespace std;

template<typename T> 
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<class T> 
void mySort(T arr[], int len) {
    for (int i=0; i<len; i++){
        int min = i;
        for (int j=i; j < len; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        if (min != i){
            mySwap<T>(arr[min], arr[i]);
        }
    }

}

template<class T> 
void printArray(T arr[], int len){
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

template<typename T>
T myAdd(T a, T b){
    return a+b;
}

void test00(){
    int a = 10;
    int b = 20;
    // mySwap(a, b);
    mySwap<int>(a, b);

    cout << a << " " << b << endl;

    // test char array
    char charArr[] = "badcef";
    int num = sizeof(charArr) / sizeof(char);
    mySort(charArr, num);
    printArray(charArr, num);

    // test int array
    int intArr[] = {2, 3, 4, 1, 5, 2,3,59,4,6};
    int len = sizeof(intArr) / sizeof(int);
    mySort(intArr, len);
    printArray(intArr, len);
}


void test01(){
    int a = 10;
    int b = 20;
    char c = 'c';

    cout << myAdd(a, b) << endl;
    int res = myAdd<int>(a, c); 
    cout << myAdd<int>(a, c) << endl;

}



int main(){
    
    test01();
    return 0;
}

//普通函数
// int myAdd01(int a, int b)
// {
// 	return a + b;
// }

// //函数模板
// template<class T>
// T myAdd02(T a, T b)  
// {
// 	return a + b;
// }

// //使用函数模板时，如果用自动类型推导，不会发生自动类型转换,即隐式类型转换
// void test01()
// {
// 	int a = 10;
// 	int b = 20;
// 	char c = 'c';
	
// 	cout << myAdd01(a, c) << endl; //正确，将char类型的'c'隐式转换为int类型  'c' 对应 ASCII码 99

// 	//myAdd02(a, c); // 报错，使用自动类型推导时，不会发生隐式类型转换

// 	myAdd02<int>(a, c); //正确，如果用显示指定类型，可以发生隐式类型转换
// }

// int main() {

// 	test01();

// 	system("pause");

// 	return 0;
// }

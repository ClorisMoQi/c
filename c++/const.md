## const

### const修饰基本数据类型

##### 1. const修饰一般常量及数组

- 对于类似这些基本数据类型，修饰符const可以用在类型说明符前，也可以用在类型说明符后，其结果是一样的。在使用这些常量的时候，只要不改变这些常量的值便好。 

```c++
const int a=10;               /*等价的书写方式：*/     int const a=10;
const int arr[3]={1,2,3};     /*等价的书写方式：*/	   int const arr[3]={1,2,3};
```

##### 2. const修饰指针变量*及引用变量&

- &用于返回变量的实际地址，*用于返回地址所指向的变量，他们应当互为逆运算。
- 在定义变量的引用的时候，&只是个定义引用的标志，不代表取地址。

###### 2.1 const 修饰指针

修饰指针有三种情况

1. const修饰指针   --- 常量指针

   - 指针的指向可以改，指针指向的值不可以改

     ```c++
     const int* p1 = &a;
     p1 = &b; //正确
     *p1 = 100;  报错
     ```

2. const修饰常量   --- 指针常量

   - 指针的指向不可以改，指针指向的值可以改

     ```c++
     int* const p2 = &a;
     p2 = &b; //错误
     *p2 = 100; //正确
     ```

3. const即修饰指针，又修饰常量

   - 指针的指向，指针指向的值都不可以改

     ```c++
     const int* const p3 = &a;
     p3 = &b; //错误
     *p3 = 100; //错误
     ```

###### 2.2 const修饰引用

```c++
int const &a = x;
const int &a = x;
int &const a = x; // 这种方式定义是C、C++编译器未定义，虽然不会报错，但是该句效果和int &a一样。int &a = b; 的意思就是给b这个变量所指向的值再加一个引用a引到这个值上
```



### const应用到函数中

##### 1. 作为形参的const修饰符

##### 2. const修饰函数返回值

- 这样声明了返回值后，const按照"修饰原则"进行修饰，起到相应的保护作用

  ```c++
  const int func();
  ```

- 返回值用const修饰可以防止允许这样的操作发生:

  ```c++
  Rational a,b;
  Radional c;
  (a*b) = c;
  ```

  一般用const修饰返回值为对象本身（非引用和指针）的情况多用于二目操作符重载函数并产生新对象的时候。

##### 3. const放在函数末尾

- 类成员函数：`A fun4() const;` 其意义上是不能修改所在类的的任何变量。

### const在类中的用法 - 类中定义常量

##### 1. 枚举 enum

```c++
class test{
    enum {SIZE1 = 10, SIZE2 = 20};
    int array1[SIZE1];
    int array2[SIZE2];
};
```

##### 2. 使用const

- 不能在类声明中初始化const数据成员，一下用法是错误的，因为类的对象未被创建时，编译器不知道SIZE的值是什么。

```c++
class test{
    const int SIZE = 100; //错误，企图在类声明中初始化const数据成员
    int array[SIZE]; // 错误，未知的SIZE
};
```

- 正确的使用const实现方法为：const数据成员的初始化只能在类构造函数的初始化表中进行。

```c++
class A {
    A(int SIZE); // 构造函数
    const int SIZE;
};

A::A(int size):SIZE(size){}

// 错误：赋值的方式是不行的
A::A(int size){
    SIZE = size;
}

void main(){
	A a(100); // 对象a的SIZE值为100
    A b(200); // 对象b的SIZE值为200
}
```

注意：对const成员变量的初始化，不能在变量声明的地方，必须在类的构造函数的初始化列表中完成，即使是在构造函数内部赋值也是不行的。

##### 3. 使用static const

```c++
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

void main(){
    cout << Year::Inity << endl; //注意调用方式，这里是用类名调用的
}
```



### const修饰类对象，定义常量对象

- 常量对象只能调用常量函数，别的成员函数都不能调用。

```c++
class test {
public: 
    test():x(1){
        y = 2;
    }
    ~test(){}
    
    void set(int yy){
        y = yy;
    }
    int getx() const {
        return x;
    }
private:
    const int x;
    int y;
}

void main(){
    const test t;
    t.set(33); // error
    t.getx();
}
```



### const 和 define 的区别

**作用**：用于记录程序中不可更改的数据

C++定义常量两种方式

1. **\#define** 宏常量： `#define 常量名 常量值`
   * ==通常在文件上方定义==，表示一个常量
   * 注意：\#define 指令行的末尾没有分号。


2. **const**修饰的变量 `const 数据类型 常量名 = 常量值`
   * ==通常在变量定义前加关键字const==，修饰该变量为常量，不可修改

C语言中，符号常量名通常用大写字母拼写，这样可以很容易与用小写字母拼写的变量名相区别。

**示例：**

```C++
//1、宏常量
#define DAY 7

int main() {

	cout << "一周里总共有 " << DAY << " 天" << endl;
	//day = 8;  //报错，宏常量不可以修改

	//2、const修饰变量
	const int MONTH = 12;
	cout << "一年里总共有 " << MONTH << " 个月份" << endl;
	//month = 24; //报错，常量是不可以修改的
	
	
	system("pause");

	return 0;
}
```


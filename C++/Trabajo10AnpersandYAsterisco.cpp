/*#include <iostream>
using namespace std;

void modify(int& ref) { // ref 是 a 的引用
    ref = 20;           // 修改引用会改变原始变量 a 的值
}

int main() {
    int a = 10; // 初始值为 10
    modify(a);  // 调用 modify 函数，修改 a 的值
    cout << "a: " << a << endl; // 输出 a: 20
    return 0;
}

这里的ref因为&的原因指向的是一个地址，而这个地址的居民是a，
所以当我modify（a）的时候，因为我在之前已经修改了ref的值为20了(c++先运行main 最后运行modify)， 

Before modify: 10
After modify: 20

所以这a变成了20*/


/*
int a = 10;         // 声明一个整数变量 a
int* b = &a;     // 声明一个指针 ptr，并将 a 的地址赋给它

int* ptr 表示 b 是一个指向整数的指针。
&a 获取变量 a 的地址，并将其存储在 ptr 中。


*/

#include <iostream>
using namespace std;


int main(){
    int a;
    int *p;

    p = &a;
    *p = 10;

    cout << a;
}
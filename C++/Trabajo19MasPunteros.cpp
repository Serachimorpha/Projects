#include <iostream>
using namespace std;

int main(){
    int valor1 = 5;
    int valor2 = 15;

    cout << "Los valores son "<< valor1 << " y " << valor2 << "\n";

    int *p; //当你写 *p 时，你实际上是在说：“我要访问 p 所指向的内存地址中存储的值
    int *q;
    p = &valor1;// 将 p 指向 valor1 的地址
    q = &valor2;// 将 q 指向 valor2 的地址

    /*指针必须指向有效的地址:
        int valor = 5;
        int *p = &valor; // p 现在指向变量 valor 的地址
        *p = 10;         // 通过指针修改 valor 的值
        指针可以为空： 在一些情况下，指针可以指向空地址（nullptr），这表示它不指向任何有效的内存。

        int *p = nullptr; // p 目前不指向任何地址
        // *p = 10;      // 这样操作会崩溃，因为 p 指向的是空地址*/

    *p = 10; // 通过指针 p 修改 valor1 的值为 10
    *q = 20;// 通过指针 q 修改 valor2 的值为 20
    
    cout << "Operando " << "\n";
    cout << "Ahora los valores son " << valor1 << " y " << valor2 << "\n";
}
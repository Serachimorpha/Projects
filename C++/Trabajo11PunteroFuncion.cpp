/*指针 (&)：想象您在电脑内存中有一块地，这块地代表一个变量。
在您的比喻中，“用鼠标画了一块地”就类似于 & 操作符，它帮助我们 找到并标记 这块地的位置（即该变量的内存地址）。
指针就是用来存储这块地的位置，告诉我们“这块地在哪儿”。

解引用 (*)：然后，当您想要知道这块地里面有什么内容时，您只需要将鼠标指向这块地。
我们就像是通过指针 * 来 访问 这块地上的数据，也就是“读取它的值”。
也可以理解为您看到地上浮现出一个数字（即该变量的值）。这一步类似于解引用，通过指针访问并获取存储在内存中的数据。

比喻总结：
&（取地址操作符）：画了一块地，标记了它的位置（内存地址）。
*（解引用操作符）：将鼠标移到这块地上，查看这块地中的内容（变量的值）。*/


#include <iostream>
using namespace std;

// 加法函数：接收两个整数参数 a 和 b，返回它们的和
int addition (int a, int b) {
    return (a + b);
}

// 减法函数：接收两个整数参数 a 和 b，返回它们的差
int subtraction (int a, int b) {
    return (a - b);
}

// operation 函数：接收两个整数 x 和 y，及一个函数指针 functocall
// 函数指针指向的函数接收两个 int 参数并返回 int 类型结果
// 在函数中，调用 functocall 函数指针，并返回结果
int operation (int x, int y, int (*functocall)(int,int)) {
    int g;
    g = (*functocall)(x, y);  // 使用传入的函数指针计算 x 和 y
    return (g);               // 返回计算结果
}

int main() {
    int m, n;
    
    // 调用 operation 函数，传入 addition 函数指针，计算 7 + 5
    // 结果为 12，并赋值给 m
    m = operation(7, 5, addition);
    
    // 调用 operation 函数，传入 subtraction 函数指针，计算 20 - 12
    // 结果为 8，并赋值给 n
    n = operation(20, m, subtraction);
    
    // 输出 n 的值，结果为 8
    cout << n;

    return 0;
}

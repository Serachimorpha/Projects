#include <iostream>
using namespace std;

int main() {
    int numbers[5]; // 声明一个大小为 5 的整数数组
    int *p;        // 声明一个指向整数的指针 p

    p = numbers;    // 让指针 p 指向数组的第一个元素，即 numbers[0]
    *p = 10;        // 解引用指针 p，将第一个元素 numbers[0] 赋值为 10

    p++;            // 将指针 p 移动到数组的下一个元素，p 现在指向 numbers[1]
    *p = 20;        // 将 numbers[1] 赋值为 20

    p = &numbers[2]; // 让指针 p 指向数组的第三个元素 numbers[2]
    *p = 30;         // 将 numbers[2] 赋值为 30

    p = numbers + 3; // 让指针 p 指向数组的第四个元素 numbers[3] (numbers+3)
    *p = 40;         // 将 numbers[3] 赋值为 40

    p = numbers;     // 让指针 p 再次指向数组的第一个元素 numbers[0]
    *(p + 4) = 50;   // 使用指针偏移，将第五个元素 numbers[4] 赋值为 50

    // 使用 for 循环输出数组中的每个元素
    for (int n = 0; n < 5; n++)
        cout << numbers[n] << ", ";  // 输出数组的每个元素，以逗号分隔

    return 0; // 程序成功结束
}

#include <iostream>
using namespace std;

// 定义一个函数 prevnext，用于计算给定整数 x 的前一个和下一个值
// 参数 x 是输入值，prev 和 next 是引用参数，用于返回结果
void prevnext(int x, int& prev, int& next)
{/*引用是一个变量的别名，声明为 int& 意味着该引用会关联到一个 int 类型的变量。
    对引用的任何操作都会直接影响它所引用的变量。*/
    prev = x - 1;
    next = x + 1;
}

int main ()
{
    // 声明整数变量 x 并初始化为 100，y 和 z 用于存储前后值
    int x = 100, y, z;
    // 调用 prevnext 函数，将 x、y 和 z 作为参数
    prevnext(x, y, z);
    // 输出 y 和 z 的值，即 x 的前一个值和下一个值
    cout << "Previous=" << y << ", Next=" << z;
    return 0;
}

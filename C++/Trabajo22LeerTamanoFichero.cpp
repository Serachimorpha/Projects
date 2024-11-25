#include <iostream>  // 引入用于控制台输入输出的标准库
#include <fstream>   // 引入用于文件流操作的标准库

using namespace std;

int main () {
    long begin, end;  // 定义变量用于存储文件开头和结尾的指针位置

    // 打开名为 "example.txt" 的文件用于读取
    ifstream myfile ("example.txt");

    // 获取当前文件指针的位置（文件刚打开，指针在文件的开头）
    begin = myfile.tellg();

    // 将文件指针移动到文件末尾
    myfile.seekg(0, ios::end);

    // 获取文件末尾的指针位置（也就是文件的大小）
    end = myfile.tellg();

    // 关闭文件
    myfile.close();

    // 输出文件的大小，计算方式为末尾指针减去开头指针
    cout << "size is: " << (end - begin) << " bytes.\n";

    return 0;  // 返回 0 表示程序正常执行
}

#include <iostream>  // 用于控制台输入输出
#include <fstream>   // 用于文件流操作

using namespace std;

ifstream::pos_type size;  // 定义一个变量用于存储文件大小
char *memblock;           // 指针，用于存储读取的文件内容

int main () {
    // 打开一个名为 "example.bin" 的文件，以二进制模式读取，并将文件指针移动到文件末尾（ios::ate）
    ifstream file("example.bin", ios::in | ios::binary | ios::ate);

    // 检查文件是否成功打开
    if (file.is_open()) {
        // 获取文件大小（文件指针已经在文件末尾）
        size = file.tellg();

        // 动态分配一块内存来存储文件的内容，大小为文件的字节数
        memblock = new char[size];

        // 将文件指针重新定位到文件的开头
        file.seekg(0, ios::beg);

        // 读取整个文件的内容到 memblock 缓冲区
        file.read(memblock, size);

        // 关闭文件
        file.close();

        // 输出提示信息，表示文件已完全读入内存
        cout << "The complete file content is in memory" << endl;

        // 释放分配的内存
        delete[] memblock;
    }
    else {
        // 如果文件无法打开，输出错误信息
        cout << "Unable to open file" << endl;
    }

    return 0;  // 返回 0 表示程序正常执行
}

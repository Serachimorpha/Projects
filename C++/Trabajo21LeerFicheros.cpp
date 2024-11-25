#include <iostream>
#include <fstream>  // 包含文件处理库
#include <string>

using namespace std;

int main() {
    ifstream file("../example.txt");  // 这里的 "example.txt" 是文件的路径

    string line;  // 用于存储每行的文本
    // 使用循环逐行读取文件内容
    for (int i = 0; getline(file, line); i++) {
        cout << "Line " << i + 1 <<  ": " << line  << endl;  // 输出行号和内容
    }

    file.close();

    return 0;  // 程序正常结束
}

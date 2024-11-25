#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ofstream myfile; /*创建一个 ofstream 类型的对象 myfile，用于输出文件流。*/
    myfile.open ("example.txt");
    myfile << "Writing this to a file.\n";
    myfile.close();
    return 0;
}
#include <iostream>
using  namespace std;

int main(){

int numero;

cout<<"Ingrese un numero:"<< "\n";
cin>> numero;
cout<<"El numero ingresado es: "<<numero<<"\n";

for(int i=numero; i>=0;i--){

cout<<i<<"\n";

if(i == 0){
    cout<<"FIRE!!";
}
}
}

/*#include <iostream>
#include <fstream> // 包含文件流库
#include <string>  // 包含字符串库

using namespace std;

int main() {
    string contenido; // 用于存储用户输入的文本
    ofstream Escritura("output.txt"); // 创建一个输出文件流对象

    if (!Escritura) { // 检查文件是否成功打开
        cerr << "无法打开文件!" << endl;
        return 1; // 返回错误代码
    }

    cout << "请输入一行文本: ";
    getline(cin, contenido); // 从标准输入读取一整行文本

    Escritura << contenido; // 将输入的文本写入文件

    cout << "已将输入的文本写入到 output.txt 文件中。" << endl;

    Escritura.close(); // 关闭文件流
    return 0; // 程序成功结束
}
*/
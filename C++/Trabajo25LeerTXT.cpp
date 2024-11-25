#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void compressFile(const string &inputFile, const string &outputFile) {
    ifstream inFile(inputFile);
    ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        for (char &c : line) {//char &c 是一个引用，c 将会引用 line 中的每一个字符。使用引用是为了避免在每次迭代时复制字符，提高效率。
            if (c != ' ') {  // Remove spaces
                outFile << c;
            }
        }
        outFile << endl;
    }

    inFile.close();
    outFile.close();
    cout << "File compressed successfully!" << endl;
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "compressed.txt";

    compressFile(inputFile, outputFile);

    return 0;
}
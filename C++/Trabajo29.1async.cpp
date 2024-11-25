/*While computeSquare is running, the main thread prints "Doing other work...". 
This simulates the ability to perform other tasks while the computation is happening asynchronously.*/

#include <iostream>
#include <future>
#include <chrono>

using namespace std;

int computeSquare(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return x * x;
}

int otherTask(int x) {
    return x * x * x;
}

int main() {
    int result1 = otherTask(10);

    std::future<int> result2 = std::async(std::launch::async, computeSquare, 5);
    cout << "Doing other work..." << endl;


    int value2 = result2.get();
    /*The main thread then calls result.get(), which blocks until the result of computeSquare is available. 
    While waiting, it is effectively paused for 2 seconds 
    (as that's how long computeSquare takes to complete due to std::this_thread::sleep_for).*/

    cout << "Result of otherTask(10): " << result1 << endl;
    cout << "Square of 5 is: " << value2 << endl;

    return 0;
}
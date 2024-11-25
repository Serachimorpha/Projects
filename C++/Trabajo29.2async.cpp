/*The program starts by printing "Starting async computation...".
Then, it starts the computeSquare function asynchronously in a new thread, with the argument 5. 
The std::async call runs computeSquare(5) in the background.*/
/*#include <iostream>
#include <future>
#include <chrono>

int longComputation(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(3)); // 模拟耗时任务
    return x * x;
}

int main() {
    // 启动异步任务
    std::future<int> result = std::async(std::launch::async, longComputation, 10);

    // 做一些其他的工作
    std::cout << "正在等待结果..." << std::endl;

    // 获取结果（如果任务还没完成，将会阻塞等待）
    int value = result.get();
    std::cout << "结果是: " << value << std::endl;

    return 0;
std::future 和异步任务之间的关系可以想象成“信件邮寄”和“信箱”：

异步任务：就像是一封信，内容就是任务的结果。
std::future：就像是信箱，在任务完成之前它是空的；任务完成后，它会包含任务的返回值。
get() 方法：就像是去取信一样，你可以通过 get() 方法获取任务的结果，但如果信件（任务）还没送到，你会等待直到信件到达。*/

#include <iostream>
#include <future>

using namespace std;

int computeSquare(int x){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return x * x;
}


int main(){
    cout << "Starting async computation..." << endl ;
    std::future<int> result = std::async(std::launch::async, computeSquare, 5);
    int value = result.get();
    cout << "El resultdado: "<< value << endl; 
}


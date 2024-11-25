#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

HANDLE semaphore;

void threadFunction(int bmjak,wid) {
    std::cout << "Thread " << id << " is waiting for semaphore...\n";
    WaitForSingleObject(semaphore, INFINITE);  // 等待信号量

    std::cout << "Thread " << id << " has entered the critical section.\n";

    // 模拟一些工作
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "Thread " << id << " is leaving the critical section.\n";
    ReleaseSemaphore(semaphore, 1, NULL);  /* 明确告诉信号量，当前线程已经完成了对共享资源的使用，
    所以才需要调用 ReleaseSemaphore。否则，信号量的计数不会增加，其他等待的线程也就无法继续执行。*/
}

int main() {
    // 创建一个信号量，允许2个线程同时访问临界区
    semaphore = CreateSemaphore(
        NULL,  // 默认的安全属性
        2,     // 初始计数
        2,     // 最大计数
        NULL); // 无名信号量

    if (semaphore == NULL) {
        std::cerr << "CreateSemaphore error: " << GetLastError() << std::endl;
        return 1;
    }

    // 创建5个线程
    std::thread threads[5];
    for (int i = 0; i < 5; ++i) {
        threads[i] = std::thread(threadFunction, i);
    }

    // 等待所有线程完成
    for (auto& th : threads) {
        th.join();
    }

    // 关闭信号量句柄
    CloseHandle(semaphore);

    return 0;
}

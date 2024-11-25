#include <iostream>
#include <windows.h>
#include <thread>

HANDLE semaphore;

void accessResource(int id) {
    // 等待信号量
    WaitForSingleObject(semaphore, INFINITE);

    // 线程进入临界区
    std::cout << "Thread " << id << " is accessing the resource.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟资源使用
    std::cout << "Thread " << id << " has finished.\n";

    // 释放信号量
    ReleaseSemaphore(semaphore, 1, NULL);
}

int main() {
    // 创建信号量，初始计数为2，最大计数为2
    semaphore = CreateSemaphore(
        NULL,           // Default security attributes
        2,              // Initial count
        2,              // Maximum count
        NULL);          // Unnamed semaphore

    if (semaphore == NULL) {
        std::cerr << "CreateSemaphore error: " << GetLastError() << std::endl;
        return 1;
    }

    // 创建多个线程访问资源
    std::thread threads[5];
    for (int i = 0; i < 5; ++i) {
        threads[i] = std::thread(accessResource, i);
    }

    // 等待所有线程完成
    for (auto& th : threads) {
        th.join();
    }

    // 关闭信号量句柄
    CloseHandle(semaphore);

    return 0;
}

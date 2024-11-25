#include <iostream>
#include <thread>
#include <condition_variable>
#include <atomic>
#include <chrono>

std::atomic<bool> pauseTask(false);  // 原子布尔变量，控制线程是否暂停
std::condition_variable cv;  // 条件变量
std::mutex mtx;  // 互斥量

void taskWithPauseResume() {
    int iteration = 0;
    while (iteration < 10) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !pauseTask; }); // 等待，直到 pauseTask 为 false
        std::cout << "Task running, iteration: " << ++iteration << std::endl;
        lock.unlock();  // 释放锁，允许其他线程使用
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 模拟工作
    }
    std::cout << "Task completed." << std::endl;
}

int main() {
    // 创建线程
    std::thread th(taskWithPauseResume);

    // 主线程运行2秒
    std::this_thread::sleep_for(std::chrono::seconds(2));

    // 暂停线程
    pauseTask = true;  // 设置暂停标志
    std::cout << "Thread has been paused." << std::endl;

    // 主线程暂停3秒，模拟一些工作
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // 恢复线程
    pauseTask = false;  // 取消暂停标志
    cv.notify_all();  // 通知等待的线程
    std::cout << "Thread has been resumed." << std::endl;

    th.join();  // 等待线程结束
    return 0;
}

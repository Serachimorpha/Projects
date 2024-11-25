#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

using namespace std;

const int numThreads = 3;
HANDLE semaphore; 

void threadFunction(int id){
    cout << "ID " << id << "is waiting for semaphore" << endl;
    WaitForSingleObject(semaphore, INFINITE);
    /*DWORD WaitForSingleObject(
    HANDLE hHandle,  // 要等待的对象句柄（信号量、互斥量、事件等）
    DWORD dwMilliseconds // 等待的时间，单位为毫秒*/
    cout << "ID " << id << "has entered into critical section" << endl;
    /*在多线程编程中，临界区（Critical Section） 是指程序中那些会被多个线程同时访问并可能造成数据竞争（Race Condition）或资源冲突的代码块。
    为了避免这些问题，需要对临界区进行保护，这就是为什么要使用同步机制（如信号量、互斥量等）。

    为什么需要临界区？
    当多个线程同时访问共享资源（例如变量、文件或数据库）时，如果不加控制，可能会出现以下问题：

    数据竞争
    两个或更多线程同时对共享变量读写，导致数据不一致。
    例如：

    线程 A 读取变量 x=10，然后修改为 x=15。
    线程 B 同时读取变量 x=10，然后也试图修改它。
    结果：线程 A 的修改可能被线程 B 覆盖，导致最终值错误。
    资源冲突
    两个线程试图同时操作同一资源（如文件或硬件设备），可能导致资源的状态混乱。

    临界区的作用
    临界区保护的目标是确保一个时间点只能有一个线程访问共享资源，从而避免上述问题。*/
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout << "ID " << id << "has finished the task" << endl;
    ReleaseSemaphore(semaphore, 1, NULL);
    }

    int main(){
        HANDLE semarphore = CreateSemaphore(NULL, 2, 2, NULL);
        /*Semaphore 的作用是创建车道（定义最多允许几个线程同时进入临界区）。

        它就像一个交通信号控制系统，设置了车道的数量（CreateSemaphore 的最大计数值）。
        比如 CreateSemaphore(NULL, 2, 2, NULL) 意思是：最多允许两个线程并发执行。
        WaitForSingleObject 的作用是控制红绿灯，决定是否放行线程。

        每个线程在进入临界区之前都会调用 WaitForSingleObject。
        如果信号量还有空位（计数值 > 0），红灯变绿灯，允许线程通过，计数值减 1。
        如果信号量已满（计数值 = 0），线程就会被阻塞，等待资源释放。*/
        if (semarphore == NULL){
            cout << "Error" << endl;
            return 1;
        }

        std::vector<std::thread> threads;
        for (int i=1; i<=numThreads; i++){
            threads.emplace_back(threadFunction, i);
        }

        for (auto& mithreads: threads){
            mithreads.join();
        }

        CloseHandle(semaphore);

        return 0;
    }

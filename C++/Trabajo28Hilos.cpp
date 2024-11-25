/*DWORD 在 Windows API 中用来表示无符号的 32 位整数，尤其适合处理和返回较大数值的数据。因为它的范围较大（0 到 4,294,967,295），
DWORD 非常适合存储像计数、文件大小、时间戳等需要较大数值的场景。

典型场景总结
错误码：许多 API 返回 DWORD 类型的错误码（如 GetLastError()）。
计时与时间戳：例如，用 GetTickCount() 获取系统启动后的毫秒数。
文件大小：GetFileSize() 返回文件大小时，使用 DWORD 表示字节数。
系统资源 ID：很多 API 会返回资源的唯一 ID（如线程 ID、进程 ID）。*/
#include <iostream>
#include <windows.h>
#include <string>
 
using namespace std;

// Thread function
DWORD WINAPI ThreadFunction(LPVOID lpParam) {
    /*DWORD：这是线程函数的返回类型，代表一个 32 位的无符号整数。
    在 Windows API 中，很多函数（包括线程函数）都使用 DWORD 来表示返回的状态码，或者表示线程的退出码。
    在这里，DWORD 表示 ThreadFunction 函数执行后的返回值。
    
    WINAPI：这是一个调用约定（Calling Convention）。
    调用约定指定了函数如何与调用者之间传递参数以及如何清理调用栈。
    在 Windows API 中，WINAPI 是一个常见的约定，它规定了函数参数如何在栈上排列，以及函数调用后栈的清理方式。
    对于 Windows API 的线程函数，WINAPI 确保线程的创建和执行遵循操作系统约定。
    
    为什么要使用 WINAPI？ WINAPI 告诉编译器该函数是为 Windows API 使用的，它将采用特定的堆栈布局以及错误处理和返回方式。
    这个约定是 Windows 环境中线程函数的一部分。
    
    ThreadFunction：这是线程的函数名，表示当线程创建时，操作系统将执行这个函数。
    你在调用 CreateThread 或其他线程创建 API 时，操作系统会启动这个函数，并开始在线程中执行它的内容。
    
    LPVOID lpParam (Long Pointer to Void)：这个参数是传递给线程函数的输入参数。
    LPVOID 是一个指向任意类型数据的指针，即它是一个 通用指针，可以指向任何类型的数据。
    在这里，它的作用是允许你将任何类型的参数传递给线程函数。
    它可以指向整数、结构体、数组等类型的数据。由于它是通用指针，因此需要在函数内部将它转换为实际的数据类型，才能使用。*/
    int threadID = *reinterpret_cast<int*>(lpParam);    
    /*reinterpret_cast<int*>(lpParam)：
    reinterpret_cast 是 C++ 中的一种类型转换方式，用于将指针从一种类型转换为另一种类型。
    它是一种低级的转换方式，适用于需要强制将一种指针类型转换为另一种指针类型的情况。
    在这里，lpParam 是一个 LPVOID 类型的参数，它是一个指向未知类型数据的指针。
    reinterpret_cast<int*>(lpParam) 将这个指针转换为 int* 类型，表示它指向一个 int 类型的数据。
    
    *reinterpret_cast<int*>(lpParam)：
    * 是解引用操作符，用于获取指针指向的值。
    * 这里，reinterpret_cast<int*>(lpParam) 得到的是一个指向 int 的指针，
    * *reinterpret_cast<int*>(lpParam) 则获取该 int 的值。*/
    cout << "Hello from thread " << threadID << ", " <<endl;
    return 0;
}

int main()
{
    HANDLE threads[2];
    DWORD threadIDs[2];
    int threadParams[2] = {1, 2};

for(int i = 0; i < 2; ++i) {
    threads[i] = CreateThread(
        nullptr,              // 默认安全性属性
        0,                    // 默认堆栈大小
        ThreadFunction,       // 线程执行的函数
        &threadParams[i],     // 传递给线程的参数（线程 ID）
        0,                    // 默认创建标志
        &threadIDs[i]         // 保存线程的 ID
    );
}

    WaitForMultipleObjects(2, threads, true, INFINITE);

    bool CloseHandle(HANDLE threads);

    return 0;
}
#include <windows.h>
#include <iostream>

// Thread function
DWORD WINAPI ThreadFunction(LPVOID lpParam) {
    int threadID = *reinterpret_cast<int*>(lpParam);
    return 0;
}

int main() {
    HANDLE threads[2];
    DWORD threadIDs[2];
    int threadParams[2] = {1, 2};

    for (int i = 0; i < 2; ++i) {
        threads[i] = CreateThread(
            nullptr,                 // default security attributes
            0,                       // default stack size
            ThreadFunction,          // thread function
            &threadParams[i],        // argument to thread function
            0,                       // default creation flags
            &threadIDs[i]            // thread ID
        );
        if (threads[i] == nullptr) {
            std::cerr << "Error creating thread: " << GetLastError() << std::endl;
            return 1;
        }
    }

    // Wait for all threads to complete
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);

    // Close thread handles
    for (int i = 1; i >= 0; --i) {
        CloseHandle(threads[i]);
        std::cout << "Adiós hilo " << threadParams[i] << std::endl;
    }

    return 0;
}
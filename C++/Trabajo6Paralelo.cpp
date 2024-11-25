#include <iostream>
#include <thread>
#include <vector>
#include <numeric>  // std::accumulate

// 函数用于计算范围内的和
void sum_range(int start, int end, int& result) {
    result = 0;
    for (int i = start; i <= end; ++i) {
        result += i;
    }
}

int main() {
    const int num_threads = 10;
    const int range = 100;

    // 用于存储每个线程的结果
    std::vector<int> results(num_threads, 0);
    
    // 线程向量
    std::vector<std::thread> threads;

    // 创建线程，每个线程计算不同的范围
    for (int i = 0; i < num_threads; ++i) {
        int start = i * range + 1;
        int end = (i + 1) * range;
        threads.push_back(std::thread(sum_range, start, end, std::ref(results[i])));
    }

    // 等待所有线程完成
    for (auto& t : threads) {
        t.join();
    }

    // 计算所有线程的结果总和
    int total_sum = std::accumulate(results.begin(), results.end(), 0);

    // 输出最终结果
    std::cout << "Total sum from 1 to 1000 is: " << total_sum << std::endl;

    return 0;
}

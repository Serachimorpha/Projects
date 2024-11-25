#include <iostream>
#include <cstdlib>      // For system command execution
#include <filesystem>   // For directory creation

namespace fs = std::filesystem;

int main() {
    // 创建目录
    std::string dirPath = "new_directory";
    try {
        if (fs::create_directory(dirPath)) {
            std::cout << "目录创建成功: " << dirPath << std::endl;
        } else {
            std::cout << "创建目录失败或目录已存在。" << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << "创建目录时出错: " << e.what() << std::endl;
        return 1; // 出现错误时退出
    }

    // 执行 ping 操作
    std::string ipAddress;
    std::cout << "请输入要 ping 的 IP 地址或域名: ";
    std::cin >> ipAddress;

    std::string command = "ping -n 4 " + ipAddress;  // 生成 ping 命令（适用于 Windows）
   
    int result = system(command.c_str());  // 执行系统 ping 命令

    if (result == 0) {
        std::cout << "Ping 成功！" << std::endl;
    } else {
        std::cout << "Ping 失败。" << std::endl;
    }

    return 0;
}

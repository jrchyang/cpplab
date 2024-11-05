#include <iostream>
#include <execinfo.h>
#include <cxxabi.h>
#include <cstdlib>
#include <cstring>

class CallStack {
public:
    void printStack() const {
        // 获取调用栈
        void* callstack[128];
        int frames = backtrace(callstack, sizeof(callstack) / sizeof(void*));

        // 打印调用栈
        char** symbols = backtrace_symbols(callstack, frames);
        std::cout << "Call Stack:\n";

        for (int i = 0; i < frames; ++i) {
            // 解码符号
            char* demangled = demangle(symbols[i]);
            std::cout << "  " << demangled << std::endl;
            free(demangled); // 释放解码后的内存
        }

        free(symbols); // 释放符号数组
    }

private:
    char* demangle(const char* mangled_name) const {
        // 查找 '(' 和 '+' 以定位函数名
        const char* begin = strchr(mangled_name, '(');
        const char* end = strchr(mangled_name, '+');
        if (begin && end) {
            size_t length = end - begin;
            char* name = (char*)malloc(length + 1);
            strncpy(name, begin + 1, length - 1);
            name[length - 1] = '\0'; // 添加字符串结束符

            int status;
            char* demangled = abi::__cxa_demangle(name, nullptr, nullptr, &status);
            free(name); // 释放临时存储的名称

            if (status == 0) {
                return demangled; // 返回解码后的名称
            } else {
                return strdup(mangled_name); // 返回原始名称
            }
        }
        return strdup(mangled_name); // 返回原始名称
    }
};

// 示例函数
void exampleFunction() {
    CallStack cs;
    cs.printStack(); // 打印调用栈
}

// 主函数
int main() {
    exampleFunction(); // 调用示例函数
    return 0;
}
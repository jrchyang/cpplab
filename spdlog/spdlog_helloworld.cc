#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO
#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"

#undef MODULE_PREFIX
#define MODULE_PREFIX "bdev"
#define debug_info(fmt, ...) \
  auto __logger = spdlog::get("baseLogger"); \
  __logger->info("{}: " fmt, MODULE_PREFIX, ##__VA_ARGS__)

void writeLog(int n) {
    for (int i = 0; i < n; ++i) {
        // 获取 logger 后输出日志
        auto myLogger = spdlog::get("baseLogger");
        myLogger->info("{}: Hello, {}!", i + 1, "World");
        myLogger->info("Welcome to spdlog!");
        myLogger->error("Some error message with arg: {}", 1);

        // 带文件名与行号的日志输出
        SPDLOG_LOGGER_INFO(myLogger, "Support for floats {:03.2f}", 1.23456);
        SPDLOG_LOGGER_WARN(myLogger, "Easy padding in numbers like {:08d}", 12);

        // 输出到默认日志中
        spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
        spdlog::error("Some error message with arg: {}", 1);
        spdlog::warn("Easy padding in numbers like {:08d}", 12);
        spdlog::info("Support for floats {:03.2f}", 1.23456);

	debug_info("hello {}", "bdev");
    }
}

void testSPDLog() {
    // 设定日志最大 100k，且最多保留 10 个
    auto myLogger = spdlog::rotating_logger_mt("baseLogger", "/home/jrchyang/projects/cpplab/build/out/logs/basic.log", 1024 * 100, 10);
    spdlog::set_default_logger(myLogger);
    myLogger->set_pattern("[%Y-%m-%d %H:%M:%S.%e][%l](%@): %v"); // 非通过宏输出的日志%@输出为空
    myLogger->set_level(spdlog::level::info);

    myLogger->info("Hello, {}!", "World");

    writeLog(10);
}

int main()
{
    spdlog::info("{:<30}", "left aligned");    
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::error("Some error message with arg: {}", 1);    
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");    
    
    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
    
    // Compile time log levels
    // define SPDLOG_ACTIVE_LEVEL to desired level
    SPDLOG_TRACE("Some trace message with param {}", 42);
    SPDLOG_DEBUG("Some debug message");

    testSPDLog();
}
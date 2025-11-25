#include "logger.h"
#include <fstream>

void cashew::debug::Logger::Log(const char *message, LogLevel level)
{
    std::ofstream logFile;
    logFile.open("C:\\Programming\\Github\\Cashew\\error\\log.txt", std::ios_base::app);
    logFile << "[" << LogLevelToString(level) << "] " << message << std::endl;
    logFile.close();
}

const char *cashew::debug::Logger::LogLevelToString(LogLevel level)
{
    switch (level) {
    case INFO:
        return "INFO";
    case WARNING:
        return "WARNING";
    case ERROR:
        return "ERROR";
    default:
        return "UNKNOWN";
    }
}

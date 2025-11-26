#include "debug.h"

#include <string>
#include <fstream>

cashew::debug::Logger::Logger()
{
}

cashew::debug::Logger::~Logger()
{
}

void cashew::debug::Logger::Log(const char *msg, LogType type, const char *filename, int line)
{
    if (type == LogType::INFO) LogInfo(msg, type, filename, line);
    else if (type == LogType::WARNING) LogWarning(msg, type, filename, line);
    else if (type == LogType::ERROR) LogError(msg, type, filename, line);
    else return;
}

const char *cashew::debug::Logger::ConvertEnumToCharPTR(LogType type)
{
    switch (type) {
    case LogType::INFO: return "INFO";
    case LogType::WARNING: return "WARNING";
    case LogType::ERROR: return "ERROR";
    default: return "UNKNOWN";
    }
}

void cashew::debug::Logger::LogInfo(const char *msg, LogType type, const char *filename, int line)
{
    std::string fp = std::string(FilePath) + InfoFile;
    std::fstream file(fp, std::ios::app);
    file << "[" << ConvertEnumToCharPTR(type) << "] " << msg << " - " << filename << ":" << line << "\n";
    file.close();
}

void cashew::debug::Logger::LogWarning(const char *msg, LogType type, const char *filename, int line)
{
    std::string fp = std::string(FilePath) + WarningFile;
    std::fstream file(fp, std::ios::app);
    file << "[" << ConvertEnumToCharPTR(type) << "] " << msg << " - " << filename << ":" << line << "\n";
    file.close();
}

void cashew::debug::Logger::LogError(const char *msg, LogType type, const char *filename, int line)
{
    std::string fp = std::string(FilePath) + ErrorFile;
    std::fstream file(fp, std::ios::app);
    file << "[" << ConvertEnumToCharPTR(type) << "] " << msg << " - " << filename << ":" << line << "\n";
    file.close();
}

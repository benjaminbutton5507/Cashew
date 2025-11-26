#ifndef __CASHEW_DEBUG_H__
#define __CASHEW_DEBUG_H__

namespace cashew {

    namespace debug {

        constexpr const char* FilePath = "C:\\Programming\\Github\\Cashew\\src\\messages\\";

        constexpr const char* InfoFile = "Info.txt";
        constexpr const char* WarningFile = "Warning.txt";
        constexpr const char* ErrorFile = "Error.txt";

        enum LogType {

            INFO,
            WARNING,
            ERROR

        };

        class Logger {

        public:
            Logger();
            ~Logger();

            void Log(const char* msg, LogType type, const char* filename, int line);

        private:
            const char* ConvertEnumToCharPTR(LogType type);
            void LogInfo(const char* msg, LogType type, const char* filename, int line);
            void LogWarning(const char* msg, LogType type, const char* filename, int line);
            void LogError(const char* msg, LogType type, const char* filename, int line);

        };

    }

}

#endif
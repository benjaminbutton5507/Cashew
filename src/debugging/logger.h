#ifndef __CASHEW_LOGGER_H__
#define __CASHEW_LOGGER_H__

namespace cashew {

    namespace debug {

        enum LogLevel {
            INFO,
            WARNING,
            ERROR
        };
    
        class Logger {

        public:
            Logger() {}
            ~Logger() {}

            static void Log(const char* message, LogLevel level);
        
        private:
            static const char* LogLevelToString(LogLevel level);

        };

    }

}

#endif
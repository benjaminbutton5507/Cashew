#include "CashewAPI.h"
#include <iostream>


int main() {

    cashew::debug::Logger LogObject;

    std::cout << "Hello, World!\n";
    LogObject.Log("Printed \"Hello, World!\"", cashew::debug::LogType::INFO, __FILE__, 9);

    return 0;

}
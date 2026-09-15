#include "log.hpp"

void log(const std::string& message)
{
    std::cout << "const super info: " << message << "\n";
}

void log(std::string& message)
{
    std::cout << "info: " << message << "\n";
}

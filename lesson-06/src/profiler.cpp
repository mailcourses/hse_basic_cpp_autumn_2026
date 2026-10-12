#include <iostream>
#include <chrono>
#include <source_location>

struct Profiler
{
    Profiler(const std::string& func_name) : func_name_(func_name)
    {
        start_ = std::chrono::system_clock::now();
    }

    Profiler(const std::source_location& location = std::source_location::current()) : func_name_(location.function_name())
    {
        start_ = std::chrono::system_clock::now();
        location_ = location;
    }

    ~Profiler()
    {
        auto end_ = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count();
        std::cout << "Time of execution of function '" << location_.function_name() << "' is " << duration << " ms." << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::system_clock> start_;
    const std::string &func_name_;
    std::source_location location_;
};

void foo()
{
    Profiler prf;
    for(size_t i = 0; i < 10000000; ++i);
}

void boo()
{
    Profiler prf;
    for(size_t i = 0; i < 50000000; ++i);
}


int main()
{
    foo();
    boo();
    return 0;
}

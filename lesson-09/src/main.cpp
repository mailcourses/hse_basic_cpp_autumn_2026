#include <iostream>
#include "vector.hpp"

int main()
{
    {
        my::vector<int32_t> arr(10);
        arr.push_back(42);
    }
    {
        my::vector<std::string> arr(10);
        arr.push_back("hello");
    }
}

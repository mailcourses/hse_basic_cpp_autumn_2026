#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <thread>

size_t plain(size_t num)
{
    return num;
}

size_t tolog(size_t num)
{
    return std::log10(num);
}

size_t tozero(size_t num)
{
    return 0;
}

using transform = size_t(*)(size_t);

transform initializer(const std::string& func)
{
    if (func == "plain")
    {
        return plain;
    }    
    else if(func == "log")
    {
        return tolog;
    }
    else if(func == "zero")
    {
        return tozero;
    }
    return plain;
}

int main()
{
    {
        size_t num;
        std::string func;
        std::cin >> func;
        auto function = initializer(func);
        while (std::cin >> num)
        {
            std::cout << num << " -> " << function(num) << std::endl;
        }
    }

    {
        std::map<std::string, size_t> cache;
        cache.insert({"duck", 4});
        cache.insert({"cat", 3});
        cache.insert({"dog", 3});

        std::vector<std::string> arr = {"cat", "dog", "duck", "fox"};
        auto comp = [&cache](const std::string& animal) -> bool {
            auto it = cache.find(animal);
            if (it != cache.end())
            {
                return it->second;
            }

            //....
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if (animal.size() == 4)
            {
                return true;
            }
            return false;
        };
        auto res = std::find_if(std::begin(arr), std::end(arr), comp);
        std::cout << "animal = " << *res << std::endl;
    }
    return 0;
}

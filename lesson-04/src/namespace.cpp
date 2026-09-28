#include <iostream>
#include <chrono>
#include <unordered_map>
#include <vector>

#include <cmath>

//using namespace std;
using namespace std::chrono;
//using time = std::chrono;

namespace fast
{
    double cos(double x)
    {
        return ::cos(x); // cos из cmath
    }
    namespace math
    {
        double fastcos(double x)
        {
            return cos(x); // fast::cos
        }
    }
}

/* В стиле C
typedef std::pair<std::string, uint8_t> person_t;
typedef std::unordered_map<std::string, std::vector<person_t>> map_t;
typedef double(*cos_t)(double);
*/

using cos_t = double(*)(double);
template<class K>
using person_t = std::pair<K, uint8_t>;
using map_t = std::unordered_map<std::string, std::vector<person_t<std::string>>>;

int main()
{
    double x = 10.0;
    fast::math::fastcos(x);
    cos(x); // вызов из math.h
    ::cos(x);
    //std::unordered_map<std::string, std::vector<std::pair<std::string, uint8_t>>> cache;
    map_t cache;
    std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
   
    for (auto elem : cache)
    {
    }
    std::chrono::time_point<std::chrono::system_clock> end = start + std::chrono::milliseconds(100);
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "duration is " << milliseconds << std::endl;
    return 0;
}

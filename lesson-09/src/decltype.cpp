#include <vector>

template<class Container, class Index>
auto authAndAccess(const Container& c, Index i) -> decltype(c[i])
{
    // проверяем доступ к контейнеру c
    return c[i];
}

int main()
{
    std::vector<char> arr;
    authAndAccess(arr, 0);
}

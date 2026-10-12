#include <iostream>

struct A
{
    A(int)
    {
        std::cout << "A()" << std::endl;
    }
};

struct B
{
    B(const A& a)
    {
        std::cout << "B()" << std::endl;
    }
};

class MyVector
{
public:
    MyVector(size_t size): b(a), size_(size), data_(new int[size_])
    {
    }
public:
    int* data_;
    size_t size_;
    B b;
    A a;
};

int main()
{
    MyVector vec{10};
    std::cout << vec.data_[9] << std::endl;
}

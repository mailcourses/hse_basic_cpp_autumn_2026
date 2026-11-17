#include <iostream>

struct A
{
    A() : ptr_(new int[1024])
    {
        std::cout << "A::ctr" << std::endl;
        try
        {
            throw 1;
        } catch (int ex)
        {
            std::cout << "ctr exception caught" << std::endl;
        }
    }
    ~A()
    {
        std::cout << "A::dctr" << std::endl;
        delete[] ptr_;
        try {
            throw 1;
        } catch (int ex)
        {
            std::cout << "dctr exception caught" << std::endl;
        }
    }
    int *ptr_;
};

int main()
{
    try {
        A a;
    } catch (int ex)
    {
        std::cout << "main exception caught" << std::endl;
    }
}

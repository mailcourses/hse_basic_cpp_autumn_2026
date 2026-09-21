#include <iostream>
#include <memory>

void foo(std::unique_ptr<int> ptr)
{
}

void foo(std::shared_ptr<int> ptr)
{
    std::cout << ptr.use_count() << std::endl;
}

int main()
{
    int* i1 = new int[10];

    std::unique_ptr<int> uptr1(new int{100500});
    std::unique_ptr<int> uptr2(i1);
    std::unique_ptr<int> uptr3 = std::move(uptr1);
    //foo(uptr3);

    std::shared_ptr<int> sptr1(new int{100500});
    {
        std::shared_ptr<int> sptr2 = sptr1;
        std::cout << sptr1.use_count() << std::endl;
        *sptr2 -= 100;
        foo(sptr2);
        std::cout << *sptr1 << std::endl;
    }
    std::cout << sptr1.use_count() << std::endl;
    foo(sptr1);
    //delete[] i1;
}

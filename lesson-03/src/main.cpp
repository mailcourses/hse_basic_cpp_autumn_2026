#include <iostream>
#include <cstdlib>

static float pi = 3.1415f;

bool foo()
{
    static uint32_t radius_km = 6371;
    std::cout << "foo::j = " << radius_km << std::endl;
    ++radius_km;
    // долго что-то считает
    return true;
}

struct Tmp
{
    int32_t num1;
    int32_t num2;
    double d;
};

struct Human
{
    Human()
    {
        std::cout << "Human ctr" << std::endl;
    }

    ~Human()
    {
        std::cout << "Human dctr" << std::endl;
    }
};

void boo(int)
{
    std::cout << "boo(int)" << std::endl;
}

void boo(char *)
{
    std::cout << "boo(int*)" << std::endl;
}

int main()
{
    //int32_t arr[1000000000];
    //arr[0] = 10;
    std::cout << "sizeof(Tmp): " << sizeof(Tmp) << std::endl;
    for (size_t i = 0; i < 100; ++i)
    {
        //foo();
    
        char* str = (char*)malloc(5); // массив пяти символов  
        Tmp* tmps = (Tmp*)malloc(5 * sizeof(Tmp)); // массив пяти Tmp
        free(str);
        free(tmps);
    }

    Human *human1 = static_cast<Human*>(malloc(sizeof(Human)));
    human1 = new(human1) Human; // placement new
    human1->~Human();
    free(human1);

    std::string* str1 = static_cast<std::string*>(malloc(sizeof(std::string)));
    str1 = new(str1) std::string;
    str1->push_back('c');

    Human *human2 = new Human;
    delete human2;

    char* ptr1 = NULL;
    char* ptr2 = nullptr; // c++11

    //boo(NULL);
    boo(nullptr);

    int a = 10;
    int* a1 = &a;
    int** a2 = &a1;
    int*** a3 = &a2;
    char* ch1 = new char;
    std::cout << sizeof(ch1) << " vs. " << sizeof(a2) << " vs. " << sizeof(str1) << std::endl;

    [[likely]]
    if (foo())
    {
        return 0;
    }
    else
    {
        return 1;
    }
 
    return 0;
}

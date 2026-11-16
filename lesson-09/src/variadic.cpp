#include <iostream>

template <class T>
void print(T&& val)
{
    std::cout << val << '\n';
}

template <class T, class... Args>
void print(T&& val, Args&&... args)
{
    std::cout << val << '\n';
    print(std::forward<Args>(args)...);
}

template<class T>
struct AddNewLine
{
public:
    AddNewLine(const T& obj) : ref(obj) {}
    friend std::ostream& operator<<(std::ostream& os, const AddNewLine<T>& rhs)
    {
        os << rhs.ref << std::endl;
        return os;
    }
private:
    const T& ref;
};

template<class... Args>
void printFE(Args&&... args)
{
    (std::cout << ... << AddNewLine(args)); // (((std::cout << arg1) << arg2) << ... << arg_n);
}

int main()
{
    print(1, "abc", 2.5);
    print(2.5, "abc", 1);

    printFE(1, "abc", 2.5);
    return 0;
}

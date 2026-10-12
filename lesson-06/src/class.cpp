#include <map>
#include <vector>
#include <iostream>

class A
{
//private:
public:
    //! Конструктор по-умолчанию
    A(/* A* this */)
    {
        this->x_ = new int{100};
        std::cout << "A::ctr #1" << std::endl;
    }

    //! Пользовательский конструктор
    A(int num)
    {
        x_ = new int{100};
        std::cout << "A::ctr #2" << std::endl;
    }

    //! Пользовательский конструктор
    A(const std::string& str)
    {
        std::cout << "A::ctr #3" << std::endl;
        x_ = new int{std::stoi(str)};
    }

    //! Конструктор копирования
    A(const A& rhs) // lvalue-ссылка
    {
        std::cout << "A::ctr #4" << std::endl;
        x_ = new int{*rhs.x_};
    }

    A& operator=(const A& rhs) = default; // lvalue-ссылка

    //! Конструктор перемещеная
    A(A&& rhs ) // rvalue-ссылка
    {
        std::cout << "A::ctr #5" << std::endl;
        x_ = rhs.x_;
        rhs.x_ = 0;
    }

    static int get()
    {
        return 5;
        //return *(this->x_);
    }

    int get_2(/*const A* const this*/) const
    {
        std::cout << array.size() << std::endl;
        if (auto it = array.find(10); it == array.end())
        {
            x_ = new int{10};
        }
        std::cout << array.size() << std::endl;
        return *x_;
    }


    ~A()
    {
        std::cout << "A::dtcr" << std::endl;
    }

public:
    mutable int* x_ = nullptr;
    std::map<int, std::vector<int>> array;
};

struct B
{
    B() = default;

    B(int num)
    {
        x_ = new int{num};
    }

    B(const B& rhs)
    {
        x_ = new int{*(rhs.x_)};  
    }

    B& operator=(const B& rhs) = default;
    /*
      x_ = rhs.x_;
    */

    ~B()
    {
        delete x_;
    }
    
//public:
    int *x_ = nullptr;
};

int main()
{
    {
        A a1{"100500"};
        B b1{-1};
        std::cout << a1.get() + A::get()  << std::endl; 
        std::cout << *(b1.x_) << std::endl; 

        A a2 = a1; // конструктор копирования
        const A a3 = std::move(a2); // конструктор перемещения
        a3.get_2(); // 
    }

    {
        A* a4 = new A{42};
        //A* a4 = static_cast<A*>(malloc(sizeof(A))); <-- не вызывается конструктор
        delete a4;
    }

    {
        B b1{100};
        // Конструктор копирования
        B b2 = b1;
        // Оператор копирования
        b2 = b1;
    }
}

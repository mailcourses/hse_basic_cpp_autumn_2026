//#include <iostream>

#include "a.hpp"
#include "b.hpp"

#define MAGIC 100500
#define MAX(x, y) ( x > y ? x : y )

int main()
{
    int i = 0;
    return MAGIC + MAX(i++, 12) + foo();
}

#include <stdio.h>
#include <stdint.h>

struct Foo
{
    int a;
    double b;
};

struct Point
{
    int x;
    int y;
};

int main()
{
    struct Foo foo;
    foo.a = 10;
    foo.b = 20.0;
    printf("%d\t%f\n", foo.a, foo.b);
    uint64_t c; // 0...2**64 - 1
    int64_t d; // [бит под знак][...] -2**63 ... 2**63-1
    printf("Size of int is %d\n", sizeof(long long int));
    printf("Size of variable c is %d\n", sizeof(c));
}

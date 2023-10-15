#include <iostream>

int main(int argc, char * argv[])
{
    int a = 10;
    int b = 25;

    std::cout << &a << ' ' << a << ' ' << sizeof(a) << '\n';
    std::cout << &b << ' ' << b << ' ' << sizeof(b) << '\n';

    return 0;
}
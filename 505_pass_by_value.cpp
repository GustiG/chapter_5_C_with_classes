// Pass By Value -- default behavior in C++
#include <iostream>

void tennify(int a) { a = 10; }     // local value to it's function

int main()
{
    int i = 12;                     
    tennify(i);
    std::cout << i << '\n';         // won't change because PBV makes a copy first before changing it

    return 0;
}

// pass std::shared_ptr<T> by value
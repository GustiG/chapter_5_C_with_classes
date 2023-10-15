//Pass By Pointer
#include <iostream>

void tennify(int * a) { *a = 10; } // could crash if 'a' is an invalid memory, not pointing to an int, etc.

int main()
{
    int i = 12;
    tennify(&i);                // we pass a copy of the address 
    std::cout << i << '\n';

    return 0;
}


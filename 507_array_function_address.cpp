#include <iostream>

void pp(int & i)
{
    std::cout << &i << ' ' << i << ' ' << sizeof(i) << '\n';
}

int main(int argc, char * argv[])
{
    int arr[10] = {};              // stack allocated array
    int * harr  = new int[10] {};  // heap array

    for (size_t i = 0; i < 10; ++i)
    {
        pp(arr[i]);     // each address is 4 bytes different from the next one -- proving the stack is contiguous
    }

    for (size_t i = 0; i < 10; ++i)
    {
        pp(harr[i]);    // the heap allocated memory is in a different part of the memory than the stack
    }

    return 0;
}
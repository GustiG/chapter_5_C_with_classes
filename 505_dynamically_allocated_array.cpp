#include <iostream>

int main()
{
    int * arr = new int[3]; // allocate an array with 3 integers
    arr[0] = 5;             // give value to the array
    arr[1] = 10;
    *(arr+2) = 20;          // instead of arr[2] = 20, we add 2 to the array pointer
                            // (adding 2 to the memory address giving us the 3rd allocated memory address), 
                            // dereference it and set the value to 20
    // arr[n] = *(arr+n)    // all are equivalent
    // n[arr] = *(n+arr)
    // (arr+n) = &(arr[n]) 

/*
use pointers to:
    1. inheritance
    Base * ptr = new Derived();

    2. pass by value vs pass by reference: modifying variable passed into function
    3. Pointing to large data: large data can't live on the stack
*/ 
}
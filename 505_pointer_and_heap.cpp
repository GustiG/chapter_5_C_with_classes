/*
Create a heap with:
    Type * var_name = new Type
the OS finds a contiguous chunk of memory an returns a pointer to it (very expensive)

synthax to create a stack:        (FAST & LIMITED)
    int i = 6;

synthax to create a heap:        (SLOW & LARGER)
    Pointer* p = new Pointer(5, 4);

both 5 & 4 are added to certain contiguous addresses and allocated to the heap, while the pointer is allocated to the stack!
any locally declared variables in a scope are being de-allocated in reverse order (LIFO from the stack)
also the pointer allocated to the stack is removed while the data (5, 4) from the heap remains there unless deleted!!

C++ Pointers:
    stores a memory address
    the pointer variable is just a memory address that points to a data somewhere
    to modify the value of the data in memory that points to, we deference
    'raw' pointers are very unsafe (allows to modify everything everytime)
*/ 

#include <iostream>

int main()
{
    int i = 6;   // local int var
    int * p;     // pointer to int (undefined - whatever is in memory there) ALWAYS GIVE A VALUE!
    p = &i;      // & = 'address of' (a pointer to an integer) - unary operator, operates on one class, gets the address of the variable
    *p = 7;      // * = 'dereference' to change the int

    return 0;
}
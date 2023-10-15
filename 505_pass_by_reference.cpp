// Pass By Reference
#include <iostream>

void tennify(int & a) { a = 10; }   // pass a reference to a number (will always be valid)

int main()
{
    int i = 12;
    tennify(i);                     // call the function on a variable that exists in memory
    std::cout << i << '\n';

    return 0;
}

/*
Pass by const reference:
    whenever we pass a variable to a function that we dont want to be modified
    const declares that the variable cannot be modified inside the called function
    pass by const whenever the data type is larger than an int (do not use with primitive data types,
        because referencing has an extra 'dereference' step which is slower when using primitives)
*/
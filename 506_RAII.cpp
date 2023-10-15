/*
RAII :
    Resource Aquisition is Initialization
    Binds the life cycle of a resource that must be acquired before use to the lifetime of an object
    Automatically manages memory/resources within an object
RAII Implementation:
    Encapsulate each resource into a class
    the class constructor acquires the resource and initializes it accordingly
    the destructor releases the resource
    the class itself should be instantiated such that it has either automatic storage duration, or in anotherr RAII object
RAII Class Example:
*/
#include <iostream>

class Int_array
{
    int * array;    // private variable: the pointer itself
public:
    Int_array(size_t size) { array = new int[size]; } // the constructor is acquiring the resource, asking for the memory of the heap
    ~Int_array() { delete [] array; }                 // the destructor releases the resource, deletes the array
    int & operator [] (size_t i) { return array[i]; } // overload the operator to access the data
};

int main()
{
    Int_array arr(10); // memory allocated (we don't need pointers, because it's all done inside the class)
    arr[5] = 21;

    return 0;
}                      // leaving the scope: arr destructs, memory deallocated

// basically you make a class that stores both constructor and destructor, making the latter being used automatically.
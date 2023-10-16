/*
SMART POINTER (pointer wrapped inside a class)
* Shared Pointer  
std::shared_ptr<T>  -- it's templated (uses generics)
Handles RAII for a given pointer / type
    "Reference Counted Pointer" (keeps track of how many things are using it)
    Internal counter set to 1 in constructor
    Every time the shared_ptr is copied, the counter increases by 1
synthax:
    #include <memory>
    void func(std::shared_ptr(My_class> p) // c++ (c = 2)
    {
        p->do_something();
    } // c- (c = 1)

    int main()
    {
    auto p = std::make_shared<My_class>(args); // c = 1
    some_other_things()
    }  // c = 0, dealocate

________________________________________________________________________________________________

C++ INHERITANCE
    Member variable types:
    Public:     Seen by all
    Private:    Seen by none
    Protected:  Seen by derived

    Class Derived : Public Base
    Public:     Nothing changes
    Protected:  Base Public > Protected
    Private:    Base all > Private
    99% of the time, use ': public Base'  -- inherits from the base class

_______________________________________________________________________________________________

How to allocate / pass data?
1. If possible, use the stack
    small, local variables
    pass variables by const reference if size > 8 bytes
2. If you need heap memory, use smart ptr
    std::shared_ptr<T> my_big_data;
    std::shared_ptr<Base> = std::make_shared<Derived>();
3. Only when ABSOLUTELY NECESSARY use raw pointers / new
*/ 

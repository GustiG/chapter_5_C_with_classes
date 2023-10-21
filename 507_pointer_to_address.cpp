#include <iostream>

void pp(int & i)
{
    std::cout << &i << ' ' << i << ' ' << sizeof(i) << '\n';
}

int main(int argc, char * argv[])
{
    int   a = 10;
    int   b = 25;
    int* pa = &a;
    int* pb = &b;

    *pa   = 17;       // change whatever is at the 'a' address to 17
    *(&a) = 17;       // same as above
   
    *(pb-1) = 17;     // subract the number of bytes from the memory address of b and change a
   
    pp(a);
    pp(b);


    return 0;
}
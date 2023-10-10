#include <iostream>
#include <vector>

int main(int argc, char * argv[])
{
    std::vector<int> vec;
    vec.push_back(42);
    vec.push_back(10);

    for (size_t i = 0; i < vec.size(); ++i) 
    {
        std::cout << vec[i] << '\n';
    }   

    for (auto& a : vec)           // for everything in the vector assign it the name of a | auto: type inference | &: reference
    {
        std::cout << a << '\n';
    }
    return 0;
}
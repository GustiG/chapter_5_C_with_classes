#include <iostream>
#include <vector>

int main(int argc, char * argv[]) 
{
    std::vector<int> vec;
    vec.push_back(42);
    vec.push_back(10);
    vec.push_back(11);

    // first iteration with a normal 'for loop'
    for (size_t i=0; i<vec.size(); i++)
    {
        std::cout << vec[i] << '\n';
    }

    // second iteration using a 'ranged for loop'
    for (int a : vec)
    {
        std::cout << a << '\n';
    }

    return 0;

}
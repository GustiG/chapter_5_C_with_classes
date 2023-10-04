#include <iostream>
#include <vector>

int main(int argc, char * argv[])
{
    std::vector<float> vec;
    vec.push_back(42.2f);
    vec.push_back(10.1f);
    vec.push_back(11.3f);

    for (auto &a : vec) // pass it by refference so it wont copy the whole data
    {
        std::cout << a << '\n';
    }

    return 0;
}
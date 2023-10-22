#include <iostream>

void pp(int & i)
{
    std::cout << &i << ' ' << i << ' ' << sizeof(i) << '\n';
}

class IntArray
{
    size_t m_size;
    int *  m_arr;    // points to the first element of the array

public:
    IntArray(size_t size)
    : m_size (size)
    , m_arr  (new int[size])
    {
        std::cout << "Array Constructor\n";
    }
    ~IntArray()
    {
        delete [] m_arr;    // free the allocated memory
        std::cout << "Array Destructor" << '\n';
    }
    int get(size_t index) const
    {
        return m_arr[index];
    } 
    void set(size_t index, int val)
    {
        m_arr[index] = val;
    }
    void print() const
    {
        for (size_t i = 0; i < m_size; ++i)
        {
            std::cout << i << ' ' << m_arr[i] << '\n';
        }
    }    

};

int main(int argc, char * atgv[])
{
    IntArray my_array(10);

    my_array.set(4, 7);     // index 4 has the value of 7
    my_array.set(5, 9);
    my_array.print();

    return 0;
}
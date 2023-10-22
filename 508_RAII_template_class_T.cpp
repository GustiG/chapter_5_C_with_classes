#include <iostream>

template <class T>      // or template <typename T> // generics // to use either int or float
class DynamicArray      // no longer just integers
{
    size_t m_size;
    T *    m_arr;

public:
    DynamicArray(size_t size)
        : m_size (size)
        , m_arr  (new T[size])
    {
        std::cout << "Array Constructor\n";
    }

    ~DynamicArray()
    {
        delete [] m_arr;
        std::cout << "Array Destructed.\n";
    }

    T get(size_t index) const
    {
        return m_arr[index];
    }

    void set(size_t index, T val)
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


int main(int argc, char * argv[])
{
    DynamicArray<float> my_array(10);

    my_array.set(1, 5.5);
    my_array.set(2, 10.1);
    my_array.set(3, 15.3);

    my_array.print();

    return 0;
}
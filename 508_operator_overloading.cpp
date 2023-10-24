#include <iostream>

template <typename T>

class Dynamic_arr
{
    size_t m_size;
    T *    m_arr;

public:
    Dynamic_arr () {}
    Dynamic_arr (size_t size)
    : m_size (size)
    , m_arr  (new T[size])
    {
        std::cout << "Array Constructor:\n";
    }

    ~Dynamic_arr ()
    {
        delete [] m_arr;
        std::cout << "Array destructor.\n";
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

    // best practice is to use two versions (one const and one simple):
    T & operator [] (size_t index)  // create a [] operator for this class to assign an index // return a reference to a T
    {
        return m_arr[index];
    }
};

int main()
{
    Dynamic_arr<float> my_arr(5);   // if we want the data to not be changed we use a const both here and on the operator above

    my_arr.set(0, 11.1);    // function no longer needed 
    // or
    my_arr[3] = 3.1415;    // because we assigned a [] operator, and since it returns a reference it changes what is in the array
    
    my_arr.print();

    return 0;
}
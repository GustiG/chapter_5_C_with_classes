#include <iostream>

class Student
{
    std::string m_first = "First";
    std::string m_last  = "Last";
    int         m_id    = 0;
    float       m_avg   = 0;

public:

    Student() {}     //default constructor

    Student(std::string first, std::string last, int id, float avg)
        : m_first   (first)
        , m_last    (last)
        , m_id      (id)
        , m_avg     (avg)
    {
    }

    int get_avg()
    {
        return m_avg;
    }

    int get_id()
    {
        return m_id;
    }

    std::string get_first()
    {
        return m_first;
    }

    std::string get_last()
    {
        return m_last;
    }

};


int main(int argc, char * argv[])
{
    Student s1;
    Student s2("Dave", "Churchill", 1, 3.14);
    Student s3("Jane", "Doe", 202200001, 99.9);

    std::cout << s3.get_last() << '\n';

    return 0;
}
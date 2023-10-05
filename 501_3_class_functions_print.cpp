#include <iostream>

class Student
{
    std::string m_first = "First";
    std::string m_last  = "Last";
    int         m_id    = 0;
    float       m_avg   = 0;

public:

    Student() {};

    Student(std::string first, std::string last, int id, float avg)
        : m_first   (first)
        , m_last    (last)
        , m_id      (id)
        , m_avg     (avg)

    {
    }

    std::string get_first()
    {
        return m_first;
    }

    std::string get_last()
    {
        return m_last;
    }

    int get_id()
    {
        return m_id;
    }

    float get_avg()
    {
        return m_avg;
    }

    void print() const
    {
        std::cout << m_first << " " << m_last << ". " << "ID: " << m_id << ", score: " << m_avg << '\n';
    }
};


int main(int argc, char * argv[])
{
    Student s1("Dave", "Churchill", 8427, 9.99);
    Student s2("Ghita", "Contra", 7413, 6.97);
    Student s3("Jean", "Dela", 8531, 8.33);

    s1.print();

    return 0;
}
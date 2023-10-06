#include <iostream>

class Student
{
private:
    std::string m_first = "First";
    std::string m_last  = "Last";
    int m_id            = 0;
    float m_avg         = 0;

public:
    Student() {};
    Student(std::string first, std::string last, int id, float avg):
        m_first (first),
        m_last  (last),
        m_id    (id),
        m_avg   (avg)
    {
    }
    std::string get_first() const
    {
        return m_first;
    }
    std::string get_last() const
    {
        return m_last;
    }
    int get_id() const
    {
        return m_id;
    }
    float get_avg() const
    {
        return m_avg;
    }
    void print() const
    {
        std::cout << m_first << " " << m_last << " " << m_id << " " << m_avg << '\n';
    }

};

int main(int argc, char * argv[])
{
    const Student s1("Jakarica", "SRL", 991, 4.04);
    const Student s2("Gusti", "Vrabie", 556, 9.09);

    //s1.print();
    std::cout << s2.get_first();

    return 0;
}

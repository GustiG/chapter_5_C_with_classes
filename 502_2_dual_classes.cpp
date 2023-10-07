#include <iostream>
#include <vector>

class Student
{
    std::string m_first = "First";
    std::string m_last  = "Last";
    int         m_id    = 0;
    float       m_avg   = 0;

public:
    Student() {} //default constructor
    Student(std::string first, std::string last, int id, float avg)
        : m_first   (first)
        , m_last    (last)
        , m_id      (id)
        , m_avg     (avg)
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

class Course
{
    std::string m_name = "Course";
    std::vector<Student> m_students;

public:
    Course () {} //default constructor
    Course(const std::string& name)
        :m_name (name)
    {
    }
    void add_student(const Student& s)
    {
        m_students.push_back(s);
    }
    const std::vector<Student>& get_students() const    // what we return can't be changed & this function will not change the class
    {
        return m_students;
    }
    void print() const
    {
        for (const auto& s : m_students)
        {
            s.print();
        }
    }
};

int main(int argc, char * argv[])
{
    Student s1("Dave", "Churchill", 1, 3.14);
    Student s2("Jane", "Doe", 20220001, 99.9);

    Course comp4300("COMP 4300");
    comp4300.add_student(Student("Gusti", "Aug", 20230001, 8.88));
    comp4300.add_student(s1);
    comp4300.add_student(s2);

    comp4300.print();
    std::cout << s1.get_avg();

    return 0;
}
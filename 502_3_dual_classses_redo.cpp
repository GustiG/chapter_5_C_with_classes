#include <iostream>
#include <vector>
#include <fstream>

class Student
{
private:
    std::string m_first = "First";
    std::string m_last  = "Last";
    int         m_id    = 0;
    float       m_avg   = 0;

public:
    Student() {}
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
        std::cout << m_first << ' ' << m_last << ' ';
        std::cout << m_id << ' ' << m_avg << '\n';
    }
};

class Course
{
    std::string m_name = "course_name";
    std::vector<Student> m_students;

public:
    Course() {}
    Course(const std::string& name) : m_name (name)
    {
    }
    void add_student(const Student& s)
    {
        m_students.push_back(s);
    }
    const std::vector<Student>& get_students () const
    {
        return m_students;
    }
    void print()
    {
        for (const auto& s : m_students)
        {
            s.print();
        }
    }
    void loading(const std::string& filename)
    {
        std::ifstream fin(filename);
        std::string first, last;
        int id;
        float avg;

        while (fin >> first)
        {
            fin >> last >> id >> avg;
            add_student(Student(first, last, id, avg));
        }
    }
};

int main()
{
    Course c("COMP 4300");
    c.loading("student_list.txt");
    c.print();

    return 0;
}
#include <iostream>
#include <vector>
#include <fstream>

class Student
{
    std::string m_first = "First";
    std::string m_last  = "Last";
    int         m_id    = 0;
    float       m_avg   = 0;

public:
    Student () {}
    Student (std::string first, std::string last, int id, float avg)
        : m_first   (first)
        , m_last    (last)
        , m_id      (id)
        , m_avg     (avg)
    {
    }
    void print() const
    {
        std::cout << m_first << ' ' << m_last << ": ID ";
        std::cout << m_id << ' ' << "score " << m_avg << '\n';
    }
};

class Course
{
    std::string m_name = "Course";
    std::vector<Student> m_students;

public:
    Course () {}
    Course (const std::string& name) : m_name (name)
    {
    }
    void add (const Student s)
    {
        m_students.push_back(s);
    }
    void print () const
    {
        for (const auto& s : m_students)
        {
                s.print();
        }
    }
    void load_students (const std::string filename)
    {
        std::ifstream fin(filename);
        std::string   first;
        std::string   last;
        int           id;
        float         avg;

        while (fin >> first)
        {
            fin >> last >> id >> avg;
            add(Student(first, last, id, avg));
        }
    }
};

int main (int argc, char * argv[])
{
    Student s1("Primul", "Student", 002, 10.01);

    Course c1("Logica");

    // c1.add(s1);

    // s1.print();
    // c1.print();
    
    c1.load_students("student_list.txt");
    c1.print();

    return 0;
}
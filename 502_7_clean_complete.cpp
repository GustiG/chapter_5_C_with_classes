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
        std::cout << m_first << ' ' << m_last << ": ID ";
        std::cout << m_id << ", score " << m_avg << '\n';
    }

};

class Course
{
    std::string m_name = "Course";
    std::vector<Student> m_students;

public:
    Course () {}
    Course (const std::string& name)
        : m_name    (name)
        {
        }
    void add (const Student s)
    {
        m_students.push_back(s);
    }
    void print() const
    {
        for (const Student& s : m_students)
        {
            s.print();
        }
    }
    void load_list (const std::string& filename)
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

int main(int argc, char * argv[])
{
    Student s1("Ion", "Pokemon", 909, 4.5);
    //s1.print();
    //std::cout << s1.get_id();
    // std::cout << s1.get_last();
    Course c1("Gala");
    c1.add(s1);
    c1.add(Student("Ghe", "Network", 910, 4.1));
    c1.print();
    Course c2("Dezmat");
    c2.load_list("student_list.txt");
    c2.print();

    return 0;
}

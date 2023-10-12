#include <iostream>
#include <vector>
#include <fstream>

class Student
{
    std::string m_first = "First";
    std::string m_last  = "Last";
    int         m_id      = 0;
    float       m_avg     = 0;

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
        std::cout <<  m_id << ", score " << m_avg << '\n';
    }
};

class Course
{
    std::string          m_name = "Course";
    std::vector<Student> m_students;

public:

    Course () {}
    Course (const std::string& name) : m_name (name) {}

    void add (const Student s)
    {
        m_students.push_back(s);
    }

    void print() const
    {
        for (const Student s : m_students)
        {
            s.print();
        }
    }

    void load (const std::string& filename)
    {
        std::ifstream fin (filename);
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

    void search_first (const std::string& first_name) const
    {
        bool found = false;
        for (const Student& s : m_students)
        {
            if (s.get_first() == first_name)
            {
                s.print();
                found = true;
            }
        }
        if (!found)
            std::cout << first_name << " not found.\n";
    }

    void search_last (const std::string& last_name) const
    {
        bool found = false;
        for (const Student& s : m_students)
        {
            if (s.get_last() == last_name)
            {
                s.print();
                found = true;
            }
        }
        if (!found)
            std::cout << last_name << " not found.\n";
    }

    void search_id (const int find_id) const
    {
        bool found = false;
        for (const Student& s : m_students)
        {
            if (s.get_id() == find_id)
            {
                s.print();
                found = true;
            }
        }
        if (!found)
            std::cout << find_id << " not found.\n";
    }

    void search_score (const float find_avg) const
    {
        bool found = false;
        for (const Student& s : m_students)
        {
            if (s.get_avg() == find_avg)
            {
                s.print();
                found = true;
            }
        }
        if (!found)
            std::cout << find_avg << " not found.\n";
    }


};

int main ()
{

    return 0;
}
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
    
    std::string get_last() const
    {
        return m_last;
    }

    void print () const
    {
        std::cout << m_first << ' ' << m_last << ": ID " << m_id << ", score " << m_avg << '\n';
    }
};

class Course
{
    std::string m_name = "Course_name";
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

    void print () const
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

    void search_last (const std::string& search_last_name) const
    {
        bool found = false;
        for (const Student& s : m_students)
        {
            if (s.get_last() == search_last_name)
            {
                s.print();
                found = true;
            }
        }
        if (!found)
        {
            std::cout << search_last_name << " not found.\n";
        }
    }
};

int main (int argc, char * argv[])
{
    Course c ("Catching Pokemons 101");
    c.load("student_list.txt");
    std::string searching;
    std::cout << "Search for a student's last name:\n";
    std::cin >> searching;
    c.search_last(searching);

    return 0;
}


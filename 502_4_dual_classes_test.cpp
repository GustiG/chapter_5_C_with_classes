// make a Student class & a Course class
// a student contains: first name, last name, id, & score
// make functions to get any element of a student, a print function, & add student
// the Course class will contain the name for the course and students will be atributed to it
// read from an external file with the student's details. Add the data from the file to the Student class.

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
    Student () {} // default constructor
    Student (std::string first, std::string last, int id, float avg)
        : m_first   (first)
        , m_last    (last)
        , m_id      (id)
        , m_avg     (avg)
    {
    }
    // public functions
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
    // make the print function
    void print() const
    {
        std::cout << m_first << ' ' << m_last << " : ID " << m_id << ", score " << m_avg << '\n'; 
    }

};

class Course
{
    std::string m_name = "Course";
    std::vector<Student> m_students;

public:
    Course () {} // default constructor
    Course (const std::string& name) // pass by reference so it wont make a new copy of the whole string, also const so it wont change
        : m_name (name)
    {
    }
    void add_student(const Student s) // this function is not const, because we want to add students
    {
        m_students.push_back(s);
    }
    const std::vector<Student>& get_students() const // & to return a reference, const so it wont change (both function & return)
    {
        return m_students;
    }
    // second print function
    void print() const
    {
        for (const auto& s : m_students)
        {
            s.print();
        }
    }
    // load from file function
    void loading (const std::string& filename)
    {
        std::ifstream fin(filename); // calling the variable fin from "file in"
        std::string first, last; 
        int         id; 
        float       avg;

        while (fin >> first) // while there is a first name read the next tokens
        {
            fin >> last >> id >> avg; // load everything from the file

            add_student(Student(first, last, id, avg)); // store the data in the Student class
        } 
    }
};

int main (int argc, char * argv[])
{
    Student s1("Gigi", "Becali", 55, 4.0);
    std::cout << s1.get_first();
    std::cout << std::endl;
    std::cout << s1.get_avg();
    std::cout << std::endl;
    s1.print();

    Course comp4300("COMP 4300"); // create a course named "COMP 4300"
    comp4300.add_student(s1); // add a student to the course
    comp4300.add_student(Student("Ion", "Ionici", 44, 8.01)); // add a student "from scratch" using the Student class

    comp4300.print(); // prints all the students atributed to the course

    comp4300.loading("student_list.txt"); // call the load from file function
    comp4300.print(); // print the loaded list

    return 0;
}
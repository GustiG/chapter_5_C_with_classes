#include <iostream>
#include<vector>
#include <fstream>

class Student
{
    std::string m_first = "First";
    std::string m_last  = "Last";
    int           m_id  = 0;
    float        m_avg  = 0;

    public:

        Student() {}

        Student(std::string first, std::string last, int id, float avg)
            : m_first   (first)
            , m_last    (last)
            , m_id      (id)
            , m_avg     (avg)
        {
        }

        int getAvg() const
        {
            return m_avg;
        }

        int getID() const
        {
            return m_id;
        }

        std::string getFirst() const
        {
            return m_first;
        }

        std::string getLast() const
        {
            return m_last;
        }

        void print() const
        {
            std::cout << m_first << " " << m_last << " ";
            std::cout << m_id << " " << m_avg << '\n';
        }
};


class Course
{
    std::string m_name = "Course";
    std::vector<Student> m_students;

    public:

        Course() {}

        Course(const std::string& name)
            : m_name(name)
        {
        }

        void addStudent(const Student& s)
        {
            m_students.push_back(s);
        }

        const std::vector<Student>& getStudents() const     // 1st const: whatever we return can not be changed. 2nd const this function will not change the class
        {
            return m_students;
        } 

        void LoadFromFile(const std::string& filename)
        {
            std::ifstream fin(filename);    //ifstream = input file stream; fin = file in
            std::string first, last;
            int id;
            float avg;

            while (fin >> first)
            {
                fin >> last >> id >> avg;

                addStudent(Student(first, last, id, avg));        
            }
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
    Course c("COMP 4300");
    c.LoadFromFile("student_list.txt");
    c.print();
    
    return 0;
}
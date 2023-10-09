// make a Student class & a Course class
// a student contains: first name, last name, id, & score
// make functions to get any element of a student, a print function, & add student
// the Course class will contain the name for the course and students will be atributed to it
// read from an external file with the student's details. Add the data from the file to the Student class.

#include <iostream>     // the input/output library to read an write
#include <vector>       // the vector data structure
#include <fstream>      // filestream library to read external files

class Student                             // create the first class named Student
{                                         // declaring the private parts of the class :)
    std::string m_first = "First";        // what the Student class will contain
    std::string m_last  = "Last";
    int         m_id    = 0;
    float       m_avg   = 0;

public:                                   // create the public constructors and functions of the Student class
    Student () {}                         // default constructor if Student is passed with no arguments
    Student (std::string first, std::string last, int id, float avg)    // how the Student class is composed
        : m_first   (first)
        , m_last    (last)
        , m_id      (id)
        , m_avg     (avg)
    {
    }
    std::string get_first() const       // the first function used to get the first name from the Student class
    {
        return m_first;                 // the return value (only shows if it is printed to the screen)
    }
    std::string get_last() const        // all functions are const, they can't change the elements of the class
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
    void print() const                  // the print function shows how class elements are printed to the screen 
    {
        std::cout << m_first << ' ' << m_last << ": " << "ID " << m_id << ", score " << m_avg << '\n';
    }
};                                      // the synthax for the end of the first class

class Course                            // creating a second class called Course
{
    std::string m_name = "Course";      // accept a string with the course's name, default value set to "Course"
    std::vector<Student> m_students;    // add a Student vector to use later for adding students to specific courses

public:
    Course () {}                        // default constructor, good practice for when the class is called with no argument
    Course (const std::string& name)    // an element containing a reference to the course's name
           : m_name (name)              // declaring the private variable for the course's name to be used as a reference in public
    {
    }
    void add (const Student s)    // function to add a student to the student vector: Course_name.add(Student("First", "Last", id, avg));
    {
        m_students.push_back(s);  // ading students to the vector using push.back()
    }
    const std::vector<Student> get_students() const // provides read-only access to the vector of students without allowing modifications
    {
        return m_students;
    }
    void print () const                      // print function to use for the student's vector
    {
        for (const auto& s : m_students)    // ranged for loop to iterate over the vector
        {
            s.print();                      // calling the first print function and using its format
        }
    }
    void load_file (const std::string& filename)    // load from an external file with a reference (not making a copy of the file)
    {
        std::ifstream call(filename);               // declaring a call variable to be used with the external file name
        std::string first;                          // separating the tokens from the filename, putting them each in its own category
        std::string last;
        int         id;
        float       avg;

        while (call >> first)                       // while there is a first token in the list...
        {
            call >> last >> id >> avg;              // ...call all the other tokens following
            add(Student(first, last, id, avg));     // add the students from the list to the Student class (not const)
        }                                           // end of the while loop
    }                                               // end of the load_file function
};                                                  // end of the Course class

int main (int argc, char * argv[])                       // starting the main function of the program
{
    Student s1 ("Inout", "Gambari", 20230055, 68.2);     // adding a first student
    s1.print();                                          // print the first student

    Course c("CS50");                                    // add the first course called "CS50"
    c.add(s1);                                           // add the first student to the first course
    c.add(Student("Jean", "Martiann", 20230011, 76.4));  // add another student to the same course
    c.print();                                           // print all the students in the course so far
    std::cout << s1.get_id();                            // print just the id of the first student
    std::cout << std::endl;                              // print an empty line
    
    Course compSci("Computer Science");                  // create a second course called "Computer Science" 

    compSci.add(Student("Alice", "Smith", 1, 90.5));     // add students to the new course
    compSci.add(Student("Bob", "Johnson", 2, 88.0));
    compSci.add(Student("Charlie", "Brown", 3, 75.3));

    // Accessing students using get_students
    const std::vector<Student>& students = compSci.get_students();

    // Print the information of each student
    for (const auto& student : students)
    {
        student.print();
    }

    c.load_file("student_list.txt");                    // load the students from the external file and moving them to the first course
    c.print();                                          // print all the students in the first course

    return 0;                                           // return 0 if the program runs with no errors (main function is of int type)
}                                                       // end of the program
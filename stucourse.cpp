#include <iostream>
#include <string>

using namespace std;

class Course; // forward declaration  ----> chicken and egg problem

class Student
{
    string name_;
    Course *courses_[5]; // both have the address of each other
    int courseCount_;

public:
    Student(const string &name) : name_(name), courseCount_(0) {}

    const string &name() const { return name_; } // why const at the front? -- because this function does not modify the object's state

    void addCourse(Course *course)
    {
        if (courseCount_ < 5)
        {
            courses_[courseCount_++] = course;
        }
    }

    void printCourses() const;
};

class Course
{
    string name_;
    string code_;
    Student *students_[10];  // a smll restriction for num 
    int studentCount_;

public:
    Course(const string &name, const string &code)
        : name_(name), code_(code), studentCount_(0) {}

    const string &name() const
    {
        return name_;
    }

    const string &code() const
    {
        return code_;
    }

    void addStudent(Student *student)
    {
        if (studentCount_ < 10)
        {
            students_[studentCount_++] = student;
        }
    }

    void printStudents() const
    {
        cout << code_ << ": " << name_ << " roster: ";
        for (int i = 0; i < studentCount_; i++)
        {
            cout << students_[i]->name();
            if (i + 1 < studentCount_)
                cout << ", ";
        }
        cout << endl;
    }
};

void Student::printCourses() const
{
    cout << name_ << " is taking: ";
    for (int i = 0; i < courseCount_; i++)
    {
        cout << courses_[i]->code()
             << ": " << courses_[i]->name();
        if (i + 1 < courseCount_)
            cout << ", ";
    }
    cout << endl;
}

void enroll(Student &student, Course &course)
{
    course.addStudent(&student);
    student.addCourse(&course);
}

int main()
{
    Student alice("Alice"), bob("Bob"),
        john("John"), kevin("Kevin");
    Course sep200("Object Oriented Programming", "SEP200"),
        sem305("Discrete Mathematics", "SEM305");

    enroll(alice, sep200);
    enroll(alice, sem305);
    enroll(bob, sep200);
    enroll(john, sep200);
    enroll(kevin, sem305);

    sep200.printStudents();
    sem305.printStudents();

    alice.printCourses();

    return 0;
}
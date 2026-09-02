#include <iostream>
using namespace std;

class Teacher
{
public:
    void Teach()
    {
        cout << "Teacher is Teaching" << endl;
    }
};

class Student
{
public:
    void learn(Teacher &teacher)
    {
        teacher.Teach();
        cout << "Student is learning" << endl;
    }
};
int main()
{
    Teacher teacher;
    Student student;
    student.learn(teacher);
    return 0;
}
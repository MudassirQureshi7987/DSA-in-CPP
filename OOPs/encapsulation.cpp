/*The process of grouping data members and corresponding methods into a single
 unit is known as Encapsulation. It is an important part of object-oriented programming. 
 We can create a fully encapsulated class by making all the data members private. 
 If the data members are private, it can only be accessible within the class; no other
 class can access that class’s data members. 

 */
#include <iostream>
using namespace std;
class Student {
    // private data members
    private:
    string studentName;
    int studentRollno;
    int studentAge;
    // get method for student name to access  
    // private variable studentName
    public:
        string getStudentName() {
            return studentName;
        }
    // set method for student name to set 
    // the value in private variable studentName
    void setStudentName(string studentName) {
        this -> studentName = studentName;
    }
    // get method for student rollno to access  
    // private variable studentRollno
    int getStudentRollno() {
        return studentRollno;
    }
    // set method for student rollno to set 
    // the value in private variable studentRollno
    void setStudentRollno(int studentRollno) {
        this -> studentRollno = studentRollno;
    }
    // get method for student age to access  
    // private variable studentAge
    int getStudentAge() {
        return studentAge;
    }
    // set method for student age to set 
    // the value in private variable studentAge
    void setStudentAge(int studentAge) {
        this -> studentAge = studentAge;
    }
};
int main() {
    Student obj;
    // setting the values of the variables
    obj.setStudentName("Rahul");
    obj.setStudentRollno(101);
    obj.setStudentAge(22);
    // printing the values of the variables
    cout << "Student Name : " << obj.getStudentName() << endl;
    cout << "Student Rollno : " << obj.getStudentRollno() << endl;
    cout << "Student Age : " << obj.getStudentAge();
}

/*Advantages of encapsulation

    Encapsulation is a way to achieve data hiding because other classes will not be able to access the data through the private data members.
    In Encapsulation, we can hide the data’s internal information, which is better for security concerns.
    By encapsulation, we can make the class read-only. The code reusability is also an advantage of encapsulation.
    Encapsulated code is better for unit testing.
    */
#include <iostream>
using namespace std;

// Create a base class Person with attributes name and age. Derive a class Student from Person and add an additional attribute studentID. Implement a method display StudentInfo() in the Student class to display all details.
class Person{ 
protected:
    string name;
    int age;
public:
    Person(string n, int a){
        name = n;
        age = a;
    }
};
class Student : public Person{
private:
    int studentID;
public:
    Student(string n, int a, int id) : Person(n, a){
        studentID = id;
    }
    void displayStudentinfo(){
        cout << "Name: " << this->name << endl;
        cout << "Age: " << this->age << endl;
        cout << "Student ID: " << this->studentID << endl;
    }
};

int main(){
    Student student("bavleen", 18, 234578);
    student.displayStudentinfo();
    return 0;
}
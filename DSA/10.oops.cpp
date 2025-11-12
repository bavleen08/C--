#include <iostream>
using namespace std;

class Student{
    // Properties
    private:
    string name;

    public:
    float cgpa;

    // Methods
    void getPercentage(){
        cout << (10*cgpa)<<"%"<< endl;
    }

    // Setters
    void setName(string nameval){
        name = nameval;
    }

    // Getters
    string getName(){
        return name;
    }
};

class Car{
    public:
    string name;
    string color;
    int *mileage;
    Car(){
        cout << "constructor without parameters..\n";
    }
    Car(string name, string color){
        cout << "constructor with parameters..\n";
        this->name = name;
        this->color = color;
        mileage = new int;
        *mileage = 12;
    }

    // Custom Copy Constructor
    Car(Car &original){
        cout << "copying..\n";
        name = original.name;
        color = original.color;

        // shallow copy
        //mileage = original.mileage;

        // deep copy
        mileage = new int;
        *mileage = *original.mileage;
    }
    // desructor
    ~Car(){
        cout << "deleting..\n";
        if(mileage != NULL){
            delete mileage;
            mileage = NULL;
        }
    }
};

// Function Overloading
class Print{
public:
    void show(int x){
        cout << "int: " << x;
    }
    void show(string str){
        cout << "string: " << str;
    }
};

// Operator Overloading
class Complex{
    int real;
    int img;
public:
    Complex(int r, int i){
        real = r;
        img = i;
    }

    void showNum(){
        cout << real << "+" << img << "i" << endl;
    }

    Complex operator +(Complex &c2){
        int resreal = this->real + c2.real;
        int resimg = this->img + c2.img;
        Complex c3(resreal, resimg);
        return c3;
    }
};

// Virtual functions
class Parent{
public:
    virtual void hello(){
        cout << "Parent class\n";
    }
};
class Children : public Parent{
    void hello(){
        cout << "child class\n";
    }
};

// Abstraction and pure virtual function
class Shape{
public:
    virtual void draw() = 0; // abstract fn / pure virtual fn
};

class Circle : public Shape {
public:
    void draw(){
        cout << "draw circle\n";
    }
};
class Square : public Shape {
public:
    void draw(){
        cout << "draw Square\n";
    }
};

// Static Variables
class Exam{
public:
    static int x;
};
int Exam :: x;

// Static Objects
class Example{
public:
    Example(){
        cout << "constructor...\n";
    }
    ~Example(){
        cout << "distructor...\n";
    }
};

class BB{
public:
    BB(){
        cout << "base constructor"<< endl;
    }
    virtual ~BB(){
        cout << "base destructor"<< endl;
    }
};
class DD : public BB{
public:
    DD(){
        cout << "derived constructor"<< endl;
    }
    ~DD(){
        cout << "derived destructor"<< endl;
    }  
};


int main(){
    // Student s1; // object
    // cout << sizeof(s1)<< endl;
    // s1.cgpa = 9.2;
    // s1.getPercentage();
    // s1.setName("Bavleen");
    // cout << s1.getName();

    // Car c1;
    // Car c2("maruti", "black");
    // cout << c2.getName();
    // return 0;

    /*Car c1("maruti", "blue");
    Car c2(c1); // another constructor will be created by compiler and then copy 
    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << *c2.mileage << endl;*/

    /*Complex c1(3,4);
    Complex c2(2,3);
    c1.showNum();
    c2.showNum();
    Complex c3 = c1 + c2;
    c3.showNum();*/

    /*Children child1;
    Parent *ptr;

    ptr = &child1; // Run time binding
    ptr->hello(); // Virtual function*/

    /*Circle c1;
    c1.draw();
    Square s1;
    s1.draw();*/

    /*Exam e1;
    Exam e2;
    Exam e3;
    cout << e1.x++ << endl;
    cout << e2.x++ << endl;
    cout << e3.x++ << endl;*/

    /*int x = 0;
    if(x==0){
        static Example eg1;
    }
    cout << "code ending...\n";*/

    BB *b = new DD();
    delete b;
    return 0;
}
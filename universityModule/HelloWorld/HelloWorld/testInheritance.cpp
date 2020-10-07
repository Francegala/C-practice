//
//  testInheritance.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 06/10/2020.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
// Base class
class MyClass {
protected: // Protected access specifier
    int salary;
  public:
    void myFunction() {
      cout << "Some content in parent class." <<endl<<endl;
    }
};

// Another base class
class MyOtherClass {
  public:
    void myOtherFunction() {
      cout << "Some content in another parent class." <<endl<<endl;
    }
};

// Derived class
class MyChildClass : public MyClass, public MyOtherClass {
public:
    void getSalary(){
        cout << "I know the salary: " << salary <<endl<<endl;

    }
    MyChildClass(int firstInt, int secondInt){
        salary = firstInt+secondInt;
    }
};

void inhTest() {
  MyChildClass myObj(5,3);
  myObj.myFunction();
    myObj.getSalary();
  myObj.myOtherFunction();
}

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
  
};

// Another base class
class MyOtherClass :  public MyClass{
  public:
    void myOtherFunction(int a) {
        salary = a;
    }
};

// Derived class
class MyChildClass : public MyOtherClass {
public:
  void myFunction() {
      cout << "I know the salary: " << salary <<endl<<endl;
  }    void getSalary(int &myCreditCard){// se levi & non cambia il valore
        
        myCreditCard += salary;
        salary = 0;

    }
    MyChildClass(int firstInt, int secondInt);
    /*
     MyChildClass(int firstInt, int secondInt){
        salary = firstInt+secondInt;
    }
    */
};

MyChildClass :: MyChildClass(int firstInt, int secondInt){
    salary = firstInt+secondInt;
}

void inhTest() {
    int creditCard = 0;
  MyChildClass myObj(5,3);
  myObj.myFunction();
    cout << "my bank account: " << creditCard <<endl<<endl;
    myObj.getSalary(creditCard);
    myObj.myFunction();
    cout << "my bank account: " << creditCard <<endl<<endl;
  myObj.myOtherFunction(100);
    myObj.myFunction();
    cout << "my bank account: " << creditCard <<endl<<endl;
    myObj.getSalary(creditCard);
    myObj.myFunction();
    cout << "my bank account: " << creditCard <<endl<<endl;


}

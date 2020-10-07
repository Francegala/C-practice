//
//  provaClass.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 06/10/2020.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class myClass{
public:
    int myInt;
    string myString;
    int myOutsideMethod(int parameter);
    void myInsideMethod() {  // Method/function defined inside the class
        cout << "Method/function defined inside the class!"<<endl<<endl;
    }
    myClass();
};

// Method/function definition outside the class
int myClass::myOutsideMethod(int displayNumber) {
    cout << "Method/function definition outside the class!"<<endl;
    return displayNumber;
}
myClass:: myClass(){
    cout<< "un nuovo oggetto creato col constructor wooow"<<endl;

}

void newMethod(){
    myClass firstObj;
    firstObj.myInt = 5;
    firstObj.myString = "LaaaalLLALallal";
    
    myClass secondObj;
//    secondObj.myString = "eccollooo";
    
    secondObj.myInsideMethod();  // Call the method
    cout << secondObj.myOutsideMethod(500) <<endl<<endl; // Call the method with an argument

    cout<< firstObj.myInt<<endl;
    cout<< firstObj.myString<<endl<<endl;
    cout<< secondObj.myInt<<endl;
    cout<< secondObj.myString<<endl;

}

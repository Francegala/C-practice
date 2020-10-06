//
//  Log.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 02/10/2020.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void Log (const char* t_message){
    cout << "Chi e' la mia cucciolina? " << t_message << endl << endl;
}

void proviamoString(string t_name, string t_secondname) {
    string firstName = t_name;
    string lastName = t_secondname;
    string fullName = firstName + " " + lastName;
    string fullName2 = firstName.append(lastName);

    cout << endl << "Hello, " << fullName << "!  " << endl;
    cout << "Hello, " << fullName2 << "!  " << endl << endl;
    cout << "The length of the fullName string is: " << fullName.length()<< endl;
    cout << "The size of the fullName string is: " << fullName.size()<< endl;
    cout << "The length of the fullName2 string is: " << fullName2.length()<< endl;
    cout << "The size of the fullName2 string is: " << fullName2.size()<< endl<< endl;

}

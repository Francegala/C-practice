//
//  Maths.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 03/10/2020.
//

#include <stdio.h>
#include <iostream>

using namespace std;

void sum(){
    int x = 5, y = 4;
    int valore, somma;
    cout << "Type a value to add to 4 and 5: ";
    cin >> valore;
    somma = x + y + valore;
    bool yayornay = false;
    cout << "The sum is: "<< ++somma  << endl << "that it is the same of "<< x + y + valore << endl << "is it? " << yayornay << endl<< endl;
}

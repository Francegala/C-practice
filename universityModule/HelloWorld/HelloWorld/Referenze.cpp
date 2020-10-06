//
//  Referenze.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 04/10/2020.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


void impariamo(){
    string food = "Pizza";
    string &meal = food;
    string* add = &food;
    
    cout << "food  "  << food <<endl;
    cout << "&food  "  << &food <<endl;
    cout << endl;
    cout << "meal  "  << meal <<endl;
    cout << "&meal  "  << &meal <<endl;
    cout << endl;
    cout << "add  " << add <<endl;
    cout << "*add  " << *add <<endl;
    cout << "&add  " << &add <<endl;

}

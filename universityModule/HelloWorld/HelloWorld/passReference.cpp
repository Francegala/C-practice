//
//  passReference.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 06/10/2020.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;



void swapNums(int &x, int &y) {
    int d = x;
    
    int* z = &x;
    int** s = &z;
    /*cout << z<< endl;
    cout << x<< endl;
    cout << y<< endl;
    cout << &z<< endl;
    cout << &x<< endl;
    cout << &y<< endl;
    
  x = y;
  y = *z; // diventerebbero uguale quindi non puoi usare il *

    cout << endl;
    cout << &x<< endl;
    cout << &z<< endl;
    cout << &y<< endl;
    cout << endl;*/
    
    cout << endl;
    cout << endl;
    cout<< z<< endl;
    cout<< &z<< endl;
    cout<< *z<< endl;
    cout<< s<< endl;
    cout<< &s<< endl;
    cout<< *s<< endl;
    cout << endl;
    cout << endl;
    x = y;
    y = d;


    
}

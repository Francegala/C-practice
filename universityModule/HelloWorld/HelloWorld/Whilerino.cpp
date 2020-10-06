//
//  Whilerino.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 04/10/2020.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void memeWhilerino(){
    cout << "  " << endl ;
    cout << " DO WHILE " << endl ;
    cout << "  " << endl ;
    int i = 1;
    do {
      cout << &i << "\n";
      i++;
    }
    while (i < 1);

    cout << "  " << endl ;
    cout << " ORA SOLO WHILE " << endl ;
    cout << "  " << endl ;

    int z = 1;
    while (z < 1) {
      cout << &z << "\n";
        z++;
    }
    
    cout << "  " << endl ;
    cout << "  " << endl ;
    
    cout << "  " << endl ;
    cout << " DO WHILE " << endl ;
    cout << "  " << endl ;

    int a = 0;
    do {
      cout << &a << "\n";
      a++;
    }
    while (a < 5);

    cout << "  " << endl ;
    cout << " ORA SOLO WHILE " << endl ;
    cout << "  " << endl ;

    int b = 0;
    while (b < 5) {
      cout << &b << "\n";
        b++;
    }
    
}

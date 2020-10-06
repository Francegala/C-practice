//
//  Sub.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 03/10/2020.
//

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

void cipolla(string me, int position, int length){
    string subMe = me.substr(position, length);
    if(!subMe.empty()){
        cout << "substring: "<< subMe <<endl;
    }
    cout << "size of substring "<< subMe.length() <<endl;
}



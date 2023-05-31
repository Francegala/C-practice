//
//  main.cpp
//  Lesson 6
//
//  Created by Francesco Galassi on 28/10/2020.
//

#include <iostream>

using namespace std;

namespace some_namespace
{
int some_function(){
    int a = 400;
    char letter = 'b';
    return a;
}
}

namespace some_namespace_name
{
int some_function(){
    int a = 400;
    char letter = 'b';
    return a;
}
}


int global_variable = 50;

int main() {
    
    cout << "global variable contains the value " << global_variable << "\n"<<endl;
    
    int a = 100;
    int * b ;
    
    {
        int a = 200;
        cout << "the value in a is "<< a << "\n";
        int * local_ptr = new int (300);
        b = local_ptr;
    }
    {
        int a = 100000;
        cout << "the value in a is "<< a << "\n";

    }
    cout << "the value in a is "<< a << "\n";
    cout << "the value pointed to by b is "<< *b <<"\n";
    delete b;
    b = NULL;
    
    cout <<"\n";
    std::cout <<"value of function some_namespace "<< some_namespace::some_function() <<endl;
    std::cout <<"value of function some_namespace_name "<< some_namespace_name::some_function() <<endl;
    cout <<"\n";

    
    return 0;
}

//
//  main.cpp
//  Lesson 5
//
//  Created by Francesco Galassi on 20/10/2020.
//

#include <iostream>

using namespace std;

int main() {
    
    
    int a ; // Stack variables are sometimes referred to as “local variables” because they          only exist within a certain scope (more on scope later).
    int * b;
    a = 100;
    b = new int;
    
    cout<< "the pointer b points to the memory address " << b <<" located on the heap \n";
    cout << "the value in memory location b is "<<*b<<endl;
    
    *b = a;
    
    cout<< "the value of stack variable a is "<<a<<endl;
    cout <<"the 'heap' memory pointed to by b contains "<<*b <<"\n"<<endl;

    delete b;
    b = NULL;

    char characterOnStack = 'S';
    cout<<characterOnStack<<endl;

    char * charOnHeap = new char ('S');
    cout<<*charOnHeap<<endl;
    cout<<charOnHeap<<endl;
    delete charOnHeap;
    charOnHeap = NULL;
    string stringOnStack = "string on stack";
    cout<<stringOnStack<<endl;

    string* stringOnHeap = new string("string on heap");
    cout<<*stringOnHeap<<endl;
    delete stringOnHeap;
    stringOnHeap = NULL;
    return 0;
    
    int * arrayOfInts = new int[10];
    delete [] arrayOfInts;
    
}

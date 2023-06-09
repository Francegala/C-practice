//
//  main.cpp
//  Lesson4
//
//  Created by Francesco Galassi on 13/10/2020.
//

#include <iostream>

using namespace std;
void swap (int *x, int *y){
    //cout<< x<<"  "<<y<<"  "<< *x<< "  "<< *y<<endl;
    int  z = *x;
    //cout<< x<<"  "<<z<<"  "<<y<<"  "<< *x<< "  "<< *y<<endl;
    *x = *y;
    //cout<< x<<"  "<<z<<"  "<<y<<"  "<< *x<<"   "<< *y<<endl;

    *y=z;
}
void acc(int *y){
    if(*y%2==0) cout <<*y<<endl<<endl;
}
int main() {
    /*
    int a = 100;
    int b = 200;
    cout<< a<< "  "<< b<<endl;
    int *p = &a ;
    int *q = &b ;
    swap(p,q);
    cout<< a<< "  "<< b<<endl;
    */
    
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    int * point = &arr[0];
    for(int a=0; a< 10 ;a++) acc(point+a);

    /*
     int a = 100 ;
    cout << "Value in memory location a is "<<a<<endl;
    cout << "Address of (the reference to) memory location is " << &a<<endl<<endl;
    
    int *b = &a;
    cout << "Value in memory location pointed to by b is " << *b<<endl<<endl;
    
    cout << "Value in memory location b is "<<b<<endl;
    cout << b << " should be the same as the memory location for a " << &a<<endl;
    cout << "b is actually at the memory location " << &b <<endl<<endl;
    
    cout<<b<<"  "<<b+1<<endl;
     
     */
    
/*
    int ** c;
    c = &b;

    cout << "c is now pointing to what b points to: " << **c <<endl;
    cout << "una sola stella c points to: " << *c <<endl;
    cout << "c normale c holds the value:" << c <<endl;
    cout << c <<" is the same value as b's memory location: " << &b<<endl;
    cout << "indirizzo di c is at the memory location: " << &c <<endl;

    cout<< "c is eventually retrieving what is in memory location " << **&c <<endl;
    cout << "the value of a is in memory location "<< &a <<endl;
*/
    return 0;
}

//
//  main.cpp
//  Lesson2
//
//  Created by Francesco Galassi on 12/10/2020.
//

#include <iostream>

using namespace std;

int add (int x, int y) {
    return x+y;
}

int meno (int x, int y);
void product (int a, int b);
double quotient (double a, int b);

int main(){
    int a, b, exit;
    char c;
    
    cout << "Please type in a number" << "\n";
    cin >> a ;
    cout << "Please type in another number"<<"\n";
    cin >> b ;
    cout << "Please type in the operator"<<"\n";
    cin >> c ;
    
    switch(c){
        case '+':
            cout << a << '+' << b << '=' << add(a,b) << "\n";
            break;
        case '-':
            if(a>b)cout << a << '-' << b << '=' << meno(a,b) << "\n";
            else cout << b << '-' << a << '=' << meno(b,a) << "\n";
            break;
        case '*':
            product(a,b);
            break;
        case '/':
            cout << a << '/' << b << '=' << quotient(a,b) << "\n";
            break;
    }
   
    cout << "enter another number to exit" << "\n";
    
    cin >> exit;
    return 0;
}

int meno (int x, int y){
    return  x-y;
}

void product (int x, int y){
    cout << x << '*' << y << '=' << x*y << "\n";
}

double quotient (double x, int y){
    double result = x/y;
    return result;
}

//
//  main.cpp
//  Lesson1
//
//  Created by Francesco Galassi on 12/10/2020.
//

#include <iostream> // allows use cout

using namespace std; // all standard libraries must be used within the std namespace is way of grouping

int main() { // function to start with, returns an integer
    std::cout << "What is your name? " << "\n";
    string name;
    cin >> name;
    cout<<endl;
    cout <<  "Hello " <<name<<"! \n"; // object of class ostream to print to standard output (screen, file, network, anything send data to
    int integer;
    cout<<"integer: ";
    cin >> integer;
    cout<<endl;
    int integer2;
    cout<<"integer2: ";
    cin >> integer2;
    cout<<endl;
    std::cout << integer+integer2<< "\n"<<endl;
    char character = 'a';
    std::cout <<character << "\n";
    bool boolean = true;
    std::cout << boolean << "\n";
    float x = 12489.48593;
    std::cout << std::fixed;//senno arrotonda
    std::cout << x << "\n";
    return 0;//(0-255)
}

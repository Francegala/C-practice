//
//  main.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 02/10/2020.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

void swap(int i, int j){
    int tmp = i;
      cout<< "i "<<i<<endl;
      cout<<"tmp "<<tmp<<endl;
    i = j;
      cout<<"j "<<j<<endl;
      cout<<"i "<<i<<endl;

    j = tmp;
      cout<<"tmp "<<tmp<<endl;
      cout<<"j "<<j<<endl;
    cout<<endl<<"temp RESULT no ref"<<endl;
      cout<<"i "<<i<<" j "<<j<<endl;
}

void swapRef(int &i, int &j){
  int tmp = i;
    cout<< "i "<<i<<endl;
    cout<<"tmp "<<tmp<<endl;
  i = j;
    cout<<"j "<<j<<endl;
    cout<<"i "<<i<<endl;

  j = tmp;
    cout<<"tmp "<<tmp<<endl;
    cout<<"j "<<j<<endl;
    cout<<endl<<"temp RESULT with ref"<<endl;
    cout<<"i "<<i<<" j "<<j<<endl;
}

void Log(const char* t_message);
void proviamoString(string t_name, string t_secondname);
void sum();
void stampa();
void cipolla(string me, int position, int length);
void memeWhilerino();
void impariamo();
int swapNums(int &x, int &y);
void newMethod();
void inhTest();
int poliTest() ;
void fileTest() ;


int main()
{
  /*int x=5, y=6;
    cout<<endl<<"before doing the swap WITHOUT reference "<<endl;
    cout<<"x "<<x<<" y "<<y<<endl<<endl;
  swap(x,y);
    cout<<endl<<"after the swap WITHOUT reference "<<endl;
    cout<<"x "<<x<<" y "<<y<<endl<<endl;
    swapRef(x,y);
    cout<<endl<<"after the swap WITH reference "<<endl;
    cout<<"x "<<x<<" y "<<y<<endl<<endl;

    */
    // Log("Elena");

   /*
    cout << "What is your First Name? ";
    string first;
    cin >> first;
    cout << "What is your Second Name? ";
    string second;
    cin >> second;
    proviamoString(first, second);
    */
     
    // sum();
    // stampa();
    
    /*
    string inputOne;
    cout << "Type the string: ";
    getline(cin,inputOne);
    int inputTwo;
    cout << "Type the position: ";
    cin >> inputTwo;
    int inputThree;
    cout << "Type the length: ";
    cin >> inputThree;
    cipolla(inputOne,inputTwo,inputThree);
    memeWhilerino();
     */
    
   // impariamo();
    /*
    int firstNum = 10;
    int secondNum = 20;

    cout<< firstNum<< endl;
    cout << secondNum<< endl;
    cout << &firstNum<< endl;
    cout << &secondNum<< endl;
    cout << endl;

    // Call the function, which will change the values of firstNum and secondNum
     swapNums(firstNum, secondNum);
     cout << endl;

     cout<< firstNum<< endl;
     cout << secondNum<< endl;
     cout << &firstNum<< endl;
     cout << &secondNum<< endl;
     */
    
    // newMethod();
    // inhTest();
     poliTest() ;
    // fileTest();
    // std::cin.get();

}

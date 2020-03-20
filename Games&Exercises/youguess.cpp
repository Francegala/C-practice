#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;
int main()
{
    int a,b;
    cout << "I'm thinking a number between 1 and 1000 !" << endl;
    srand(time(0));
    a=1+rand()%1000;
    //cout << a<< endl; //uncomment for reading the number
    for(int c=10;c>0;c--){
        cout << "Guess the number: " << endl;
        cin >>b;
        if(a>b){cout <<"The number is bigger "<< endl;}
        if(a<b){cout <<"The number is lower "<< endl;}
        if(a==b){cout<<"That's the right one! You won! "<< endl;
        return 0;}
         }
    cout<<"Sorry you lost! "<< endl;
    return 0;
}

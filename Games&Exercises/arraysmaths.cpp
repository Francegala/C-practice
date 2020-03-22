#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int main()
{
    int a, b = 0;
    int c = 10;
    int d = 20;
    cout << "Let's generate automatically an array of numbers and counts how many numbers are repeated "<<endl;
    cout << "You can choose the lower limit of the number generated, between your number and 10 e.g. generate number between 5 and 10 "<<endl;
    cout << "lower limit: ";
    cin >> b;
    cout << "upper limit: "<<c<<endl;
    while (b < 1 && c <= b) {
        cout << "the number must be greater than 0 and lower than"<< c<<endl;
        cin >> b;
    }

    cout << "let's create an array of 20 elements: "<<endl;

    int V[10]{};
    int T[20];
    for (int j = 0; j <c; j++) {
        V[j] = 0;
    }

    srand(time(0));

    for (int i = 0; i < 20; i++) {
        T[i] = b + rand() % (c - b + 1);
        cout << "Number " << i << "generated:  " << T[i] << endl;
            }

    int asdax = 0;
    for (int i = 0; i < 20; i++) {
        asdax = 0;
        for (int lolz = b; lolz <= c; lolz++) {
            if (T[i] == lolz) { V[asdax] += 1; }
            asdax += 1;
        }
    }

    cout << '\n'<<" How many times each number is repeated? "<< endl;
    int use = b;
    for (int var = 0; var <=10-b; var++) {
        cout << "Number "<< use++<< " is reapeted "   << V[var] << " times" << endl;
    }
    return 0;
}

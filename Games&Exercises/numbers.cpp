#include <iostream>
using namespace std;

int main()
{
    int v[10], r = 0, a = 0, b;
    cout << "Please write 10 numbers. The program tells you the sum of all of them, the average and what is the biggest and smallest number: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Write a number" << endl;
        cin >> v[i];
        r = r + v[i];
    }
    cout << "The Sum is: " << r << endl;
    cout << "The average: " << r / 10 << endl;
    for (int i = 0; i < 10; i++) {
        while (a < v[i]) { a = v[i]; }
    }
    cout << "The greatest number is: " << a << endl;

    for (int i = 0; i < 10; i++) {
        b = v[0];
        while (b > v[i]) { b = v[i]; }
    }
    cout << "The lowest numer: " << b << endl;

    return 0;
}

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int a, b, prod;
    cout << "Program calculates the product of two numbers summing them recursiverly " << endl;
    cout << "first number: : ";
    cin >> a;
    cout << "second number : ";
    cin >> b;
    prod = 0;
    while (b>0)
        {
        prod += a;
        b --;
        };
    cout << "result : " << prod << endl << endl;
    system ("pause");
    return 0;
}

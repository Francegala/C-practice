#include <iostream>

using namespace std;

int main()
{
    cout << "Let's create some parallelograms " << endl;
    int a, b, z;
    cout << "write the size of the greatest side  " << endl;
    cin >> a;
    cout << "write the size of the smaller size" << endl;
    cin >> b;
    cout << endl << endl;

    while (b<a) {
        cout << "the second side can't be greater than the first one" << endl;
        cin >> b;
    }

    for (int i = 0; i < a; i++) {
        for (int n = i; n >= 0; n--) {
            cout << " ";
        }
        for (int m = 1; m <= b; m++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << endl << endl;
    cout << endl << "A new one " << endl;
    cout << endl << endl;

    for (int i = 0; i < b; i++) {
        z = 0;
        for (int x = 0; x < a - 1 - i; x++) {
            cout << " ";
            z++;
        }
        for (int m = 1; m <= a - z; m++) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < a; i++) {
        z = 0;
        for (int x = 0; x < a - 1 - i; x++) {
            cout << "*";
            z++;
        }
        for (int m = 1; m <= a - z; m++) {
            cout << " ";
        }
        cout << endl;
    }
    

        cout << endl << endl << endl;
    cout << endl << "A new one " << endl << endl;
    cout << endl << endl << endl;

    for (int i = 0; i < b; i++) {
        for (int n = i; n >= 0; n--) {
            cout << " ";
        }
        for (int m = 1; m <= a; m++) {
            cout << "*";
        }
        cout << endl;
    }
    
        return 0;
}

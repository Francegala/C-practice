#include <iostream>
#include <math.h>
#include  <time.h>
#include <stdlib.h>
using namespace std;

int main() {
    int max = 1000, min = 1, n;
    for (int i = 1; i <= 10; i++) {
        cout << " Think about a number between 1 and 1000: "<< endl;
        cout << " I've 10 tentatives for guessing the number: "<< endl;
        cout << " ready? "<< endl;
        n = (min + max) / 2;
        char risposta;
        cout << " I'm going to guess a number" << endl;
        cout << " Type 'Y' if it is correct" << endl;
        cout << " Type 'G' if your number is greater" << endl;
        cout << " Type another letter (press a random key) if your number is lower" << endl;
        cout << "your number is: " << n << endl;
        cin >> risposta;
        if (risposta == 'y') {
            cout << "I won yee" << endl;
            return 0;
        }
        if (risposta == 'g') min = n;
        else max = n;
    }
    cout << "Nooo you won!" << endl;
}

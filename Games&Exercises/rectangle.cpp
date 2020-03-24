#include <iostream>

using namespace std;

void draw(int b, int h) {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= b; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
int area(int b, int h) {
    int bph;
    bph = b * h;
    cout << bph << endl;
    return bph;
}
int perimeter(int b, int h) {
    int bmh;
    bmh = (b + h) * 2;
    cout << bmh << endl;
    return bmh;

}
int main() {
    int base, height;
    cout << "Plese write the lenght of the base!" << endl;
    cin >> base;
    cout << "now the height!" << endl;
    cin >> height;
    cout << "This is your rectangle!" << endl;
    draw(base, height);
    cout << "area!" << endl;
    area(base, height);
    cout << "perimetre!" << endl;
    perimeter(base, height);
    return 0;
}
//
//  main.cpp
//  Lesson3
//
//  Created by Francesco Galassi on 12/10/2020.
//

#include <iostream>

using namespace std;

int add(int x, int y){
    return x+y;
}

int fac(int x) {
    if(x>1)return x  * (fac(x-1));
    else return 1;
}
bool check(int num){
    return num >=0 ? true : false;
}

int main(){
    int x = 0;
     int total = 0;
    cout << " Enter numbers, will finish if sum of factorials exceeds 2000 \n";
    while (total <= 2000){
        cin>>x;
        if (x> 16){
            cout<<"please insert a smaller value, my machine is not powerful \n";
            return 0;
        }
        if (check(x)) total = add(fac(x),total);
        else {
            while(check(x) != 1){
                cout << " Enter numbers until positive is inserted \n";
                cin >> x;
            }
        }
    }
    cout <<"The total is: " <<total<<endl;
    if (total >3000) cout<< "you overshot by a lot!"<<endl;
    else{
        cout << "you just went over"<<endl;
        cout << "Only over by " << total -2000<<endl;
    }
    return 0;
}

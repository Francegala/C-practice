//
//  main.cpp
//  Lesson 7
//
//  Created by Francesco Galassi on 28/10/2020.
//

#include <iostream>

using namespace std;

int nums [10] = {7,3,5,2,1,4,6,9,10,8};

//int * swap(int x, int y){
void swapA(int x, int y){
    int temp = x;
    x = y;
    y = temp;
    //return &x;
}

void swap(int * x, int * y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void swap_ref(int & x, int & y){
    int temp = x;
    x = y;
    y = temp;
}


int main() {
    /*
    int x;
    int y;
    
    
    cout<<"please insert a value "<<endl;
    cin >> x;
    
    cout<<"please insert a value "<<endl;
    cin >> y;
    
    
    int * ptr_x = &x;
    int * ptr_y = &y;
    
    //int * ptr = swap(x, y);
    //cout<< *ptr<<" "<<endl;
    
    int & x_ref = x; // 1
    int & y_ref = y; // 9
    
    cout<<endl;

    swap(x,y); // it still says the same
    
    swap(&x, &y); // changed one time now 9 1
    swap(ptr_x, ptr_y); // changed second time now 1 9
    
    swap_ref(x, y); // changed third time 9 1
    swap_ref(x_ref, y_ref); // chaned fourth time 1 9

    cout<<x<<" "<<y<<endl;
    
     
    */
    /*
    int  x = 2,y = 8;
    int & x_ref = x;
    cout<<x_ref<<endl;

    x_ref = y;
    
    cout<<x_ref<<endl;
    */
    
    /*
    int * value = new int(0);
    while (*value >0){
        cin>> * value;
    }
    */
    for(int a = 0 ; a< 10; a++){
        cout<< nums[a];
    }

    cout<< endl;

    for(int a = 0 ; a< 9; a++){
        for(int b = a+1; b<10; b++){
           while(nums[b]<nums[a])swap_ref(nums[a], nums[b]);
        }
    }
    
    for(int a = 0 ; a< 10; a++){
        cout<< nums[a];
    }
    return 0;
}

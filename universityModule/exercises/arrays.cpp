//
//  main.cpp
//  Lesson 8
//
//  Created by Francesco Galassi on 29/10/2020.
//

#include <iostream>

using namespace std;

float calc_avg (const int * arr, const int val);

int main(void) {

    const int CONST_VALUE = 3;
    const int CONST_VALUE_S = 8;

    
    float ave;
    
    // stack based 1-d arrays
    int array_nums[CONST_VALUE] = {2,4,5};
    char array_chars[CONST_VALUE_S] = {'F','r','a',' ','G','a','l','a'};
    /*
    //print the fist element
    cout << "value at index 0 is" << array_nums[0]<<endl;
    
    //stack based 2d arays
    char naughts_n_xs [3] [3];
    
    //set the middle square to x
    naughts_n_xs [1] [1] = 'X';
    
    // arrays on the heap 1d
    int * sum = new int [CONST_VALUE];
    
    for (int i =0; i<CONST_VALUE;i++){
        cout<< "enter a value..."<<endl;
        cin>> sum[i];
        
    }
    
    ave= calc_avg(sum, CONST_VALUE);
    cout<<"average is "<<ave<<endl;
    
    delete [] sum;
     
     */
    
    
    char * first = new char [3];
    char * last = new char [4];

    for (int i =0; i<3;i++){
        first[i] = array_chars[i];
    }
    
    for (int i =0; i<CONST_VALUE_S;i++){
           cout<< first[i];
       }
 
    for (int i =0; i<4;i++){
        last[i] = array_chars[i+4];
    }
    cout<< "\n";

    
    for (int i =0; i<CONST_VALUE_S;i++){
           cout<< last[i];
       }
    cout<< "\n";

    
    
    return 0;
}

float calc_avg (const int * arr, const int val){
    int sum =0;
    for(int i = 0; i< val;i++){
        sum += arr[i];
    }
    return (sum/(float)val);
}

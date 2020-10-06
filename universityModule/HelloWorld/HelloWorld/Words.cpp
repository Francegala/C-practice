//
//  Words.cpp
//  HelloWorld
//
//  Created by Francesco Galassi on 03/10/2020.
//

#include <stdio.h>
#include <iostream>
#include <string.h>


using namespace std;


void stampa(){
    
    string nome = "Francesco";

    cout << nome << endl;
    cout << "0 "<< nome[0] << endl;
    cout << "3 "<< nome[3] << endl;
    cout << "8 "<< nome[8] << endl;
    cout << "9 "<< nome[9] << endl;
    cout << "10 "<< nome[10] << endl;

    nome[8] = 'a';
    cout << nome << endl;
    cout << "0 "<< nome[0] << endl;
    cout << "3 "<< nome[3] << endl;
    cout << "8 "<< nome[8] << endl;
    cout << "9 "<< nome[9] << endl;
    cout << "10 "<< nome[10] << endl;

}

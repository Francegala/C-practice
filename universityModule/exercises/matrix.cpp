//
//  main.cpp
//  Lesson 11
//
//  Created by Francesco Galassi on 14/11/2020.
//

#include <iostream>
using namespace std;

template <typename T>
class Matrix{
public:
    static const int default_x = 3;
    static const int default_y = 3;
    Matrix(int x = default_x, int y = default_y);
    ~Matrix();
    int get_x_size() const {return x_size;}
    int get_y_size() const {return y_size;}
    T get_element(int x, int y)const;
    void set_element(int x, int y, int elem);

protected:
    T ** cells;
    int x_size;
    int y_size;
};

template <typename T>
Matrix <T>:: Matrix(int x, int y):
x_size(x), y_size(y){
    cells = new T *[x_size];
    for(int i =0; i<x_size;i++){
        cells [i] = new T[y_size];
        memset(cells[i],0,(y_size*sizeof(T)));
    }
}

template <typename T>
Matrix <T>::~Matrix(){
    for(int i =0; i<x_size;i++){
        delete [] cells[i];
    }
    delete [] cells;
}

template <typename T>
T Matrix <T>::get_element(int x, int y) const{
    return (cells[x][y]);
}

template <typename T>
void Matrix <T>::set_element(int x, int y, int elem){
    cells[x][y] = elem;
}

int main(){
    Matrix <int> m_int;
    m_int.set_element(1, 1, 4);
    cout << "Element at 1,1 is "<< m_int.get_element(1, 1)<< "\n";
    
    Matrix <double> m_doub;
    m_doub.set_element(2, 2, 8.421);
    cout << "Element at 2,2 is "<< m_doub.get_element(2, 2)<< "\n";
    
    Matrix <char> m_char;
    m_char.set_element(2, 2, 'e');
    cout << "Element at 2,2 is "<< m_char.get_element(2, 2)<< "\n";
}

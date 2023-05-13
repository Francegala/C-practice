//
//  main.cpp
//  Binary Search Tree
//
//  Created by Francesco Galassi on 13/11/2020.
//

#include <iostream>
using namespace::std;
struct node{
    int value;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

// implement the functions described by these headers
void insert_integer(struct node** tree, int value){
    if(root == NULL){
        root = *tree;}
    
        if(value > root ->value){

        }
    
};
void print_tree(struct node* tree){
    cout << tree->value <<endl;
};

void terminate_tree(struct node* tree){
    delete tree;
    tree=NULL;
};


int main() {

    
    // call your implemented functions here to test the binary search tree
    struct node* first = new node();
    first->value=5;
    
    insert_integer(&first,6);
    
    
    print_tree(first);
    
    

    return 0;
    
    
}

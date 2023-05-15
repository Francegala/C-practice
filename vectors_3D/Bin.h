/*
* CSC3221: Project 1
* Student No 170492959
* Bin Class: Bin.h
*/

#pragma once
#include "Vector3D.h"
#include <iostream>
using namespace std;

class Bin
{
public:
	
	// Contructor (creats and manages Bin of Vector3D object)
	// Like in the Vector3D constructor I am giving a default value (1) for the size of the array.
	// The parameter is initialised to 1 because otherwise an error will be thrown (null terminator error, space neededs).
	// The array needs a null terminator even if it is not holding any element, so at least size of array = 1;
	Bin(int sizeOfArray = 1);

	// Optimisation: Exactly like in Vector3D class I am  using a constant to avoid changes calling it by reference to avoid excessive memory usage.
	// Both Copy Constructor and = operator can use the function to copy the bins transferring the array and all the elements.
	Bin(const Bin& bin);
	Bin& operator=(const Bin& bin);

	// Destructor:
	// This time the destructor destroys the array and dereference the pointer
	~Bin();

	// Getters to return values to safely access fields
	// Mainly for testing purpose, but it's always safer to access fields using getters rather than directly
	// Optimisation: for a future optimisation, those might be private or protected
	int getNumberOfVectors() const;
	int getArraySize() const;
	Vector3D& getVectorAtPos(int i) const; // This getter is very important for printing a bin since I want to show every vector
											// I need to access every single element of the array
											// Optimisation: for safety it might be private or protected

	//getX, getY, getZ: Accepts an int a, return x,y,z values of the a'th Vector3D in the bin
	float getX(int position) const; // Optimisation: return all values as constants, so no unwanted changes
	float getY(int position) const; // Methods getX, getY, getZ
	float getZ(int position) const; // Accepts an int a, returns the coordinates of the a'th Vector3D in the bin

	// Add
	// Accepts floats x,y,z add new element with those values to the bin at the end
	// Extending the allocated memory
	void add(float x, float y, float z);

	// Remove
	// Accepts an int b, deletes the b'th element of the bin. 
	// Shunts all the subsequent elements to fill the gap
	// Optimisation: Since not only speed is important, I am considering resizing the array if it is too big
	// to reduce the size to save memory space, the function calls a new method reduceSize()
	void remove(int b); // It gets a position, removes the element from there

private:

	// Copy Constructor and Assignment Operator Overloading sharing a funtion to reduce repetition of code
	// This function copy is more complex than the Vector3D one because this time we have to make a copy of the content of the array
	// first I will check that there actually is a Bin with an array inside
	// then if the array I am copying inside the bin calling the function has a different size,
	// I need to delete the array and change the values of the array
	// then after creating a new array, i need to copy over every element
	// Optimisation: if the two arrays have the same size just transfer the vectors.
	void copy(const Bin& bin); // like in Vector3D, a function to make an exact copy

	// The function to find the successive power of 2 given the actual size of the array
	// it is used to allocate the memory for the array since I want to reduce cpu calls
	// allowing the bin to have more space than the number of vectors inside so to add a new vector
	// it only has to insert it into the array and not changing the size every time.
	// Optimisation: increasing or decreasing size of the array happens 
	// in order to have the right balance between cpu and memory usage.
	// e.g if it is too small and we want to add a new array,
	// size is increased, it uses more memory reducing CPU calls since the following time for adding
	// will not increase the size again and transfer vectors (also transfering consumes memory to have a temporary address).
	// While if it is too large it will reduce the size, using CPU but less memory (the opposite).
	int nextPowerOfTwo(int sizeOfArray); //returns a number power of 2 greater than the actual size of the array taken as parameter

	// Before adding an element to the array with the add funcion,
	// if the size of the array is not big enough to contain a new vector + null terminator
	// this function creates a new array of increased size and insert it in the bin.
	void increaseSize();

	// This method is called internally after deleting an element.
	// If the current size of the array after the deletion is greater than the size needed,
	// this method reduces the size to free memory,
	// always considering the null terminator and the power of two to reduce operations when adding new vectors.
	void  reduceSize();

	int arraySize; // Total size of the array (how many space in memory)
	int elements; // Counter for elements in the array: how many vectors in the array
				 // It will always be smaller than the size of the array because a null terminator needs to be stored
				// C++ stores it automatically but if there is not enough space it throws an error!
	Vector3D* arrayOfVectors;

};

// This time I am not overriding the input operator but only output
// I will show how many elements are in the bin and every vector in it
ostream& operator<<(ostream& outStream, const Bin& bin);


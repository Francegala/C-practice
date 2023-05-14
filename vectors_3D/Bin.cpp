/*
* CSC3221: Project 1
* Student No 170492959
* Bin Class: Bin.cpp
*/

#include "Bin.h"
#include <iostream>

using namespace std;

// Optimisation: I noticed that when adding a new Vector3D into the bin, I always had to perform the same actions:
// to create a bigger array I needed to create a new array and store it in a temporary pointer,
// copy the previous array then delete the old array and then change the old variable pointing to the new created.
// Researching online I found a nice solution to reduce memory usage and CPU calculations.
// https://www.embedded.com/improving-performance-for-dynamic-memory-allocation-2/
// https://stackoverflow.com/questions/9515482/performance-advantages-of-powers-of-2-sized-data
// Rather than creating a new array with the same of old+1, let's create a bigger array have a logarithmic performarce.
// If I create the array of the size of the power of 2 next to the number of elements I put in the array (plus null terminator)
// I will reduce number of CPU calculations and even the memory will not be wasted
// because if I copy the array every time I need two times the size of the array because of a temporary array.
// If I directly create a bigger array I will have a slightly increased usage of the memory.
Bin::Bin(int sizeOfArray)
{
	elements = 0;
	this->arraySize = nextPowerOfTwo(sizeOfArray);
	arrayOfVectors = new Vector3D[arraySize]; // Optimisation: array with the size a power of 2 (null terminator included)
											//the compiler automatically put a null terminator chat at the last memory address but there must be the space free otherwise error
}

// Optimisation: Declaring the size of the array a power of 2 optimises performances since it only takes a single CPU instruction
// and then the program will only add data to the already created array (another CPU action without all the copy and paste).
// Adding Vectors will only require to put the data in the array, creating a new Array will be required only when the array is full
// and then this function will resize it to a power of 2, in the worst case it will only occupy twice the memory used. 
// Becuase of the null terminator (like 8 vectors inside the bin but size of the array 16 (8*2)) so free only 6,
// but then when we will need to add a new vector will fill the 9th space and so on without the need to resize it up to the next power of 2
// The multiplication using a power of 2 because memory already uses power of 2 for its datatypes.
int Bin::nextPowerOfTwo(int sizeOfArray)
{
	if (sizeOfArray <= 0) return 2; // Safe: if the user select the bin to contain 0 vector or negative, I will get it ready to add vectors to avoid errors
	int powerOfTwo = 1;
	while (powerOfTwo <= sizeOfArray) { // equal because we need the null terminator, so if we want to put 8 elements (and 8 is a power of 2), at least 9 spaces are required
		powerOfTwo *= 2;
	}
	return powerOfTwo;
}

void Bin::copy(const Bin& bin)
{
	// check that it actual exists
	if (&bin != NULL || arrayOfVectors[0] != NULL) {// Check that I am not copying null values
		if (this->getArraySize() != bin.getArraySize()) { // if they have different size
			delete[] arrayOfVectors;//destroy what is inside the the old array
			arraySize = bin.getArraySize(); // make it of the same size of the one we want to copy
			arrayOfVectors = new Vector3D[arraySize]; //create the new array, now they have the same size
		}
		elements = bin.getNumberOfVectors(); // fill it with the same number of elements
		for (int i = 0; i < elements; i++) {
			arrayOfVectors[i] = bin.arrayOfVectors[i]; //copy every single element
		}
	}
	else {
		cout << "Error: You are trying to copy a NULL value"<<endl;
	}
}

Bin::Bin(const Bin& bin) // copy constructor will just call the copy function 
{
	this->copy(bin);
}

Bin& Bin::operator=(const Bin& bin) // Assignment operator will call the function like the copy contructor but also return a pointer to the first element of the assignment
{
	// prevents copying itself, save memory and CPU computations (Optimisation!)
	if (this == &bin) {
		return *this;
	}

	this->copy(bin);
	return *this;
}

Bin::~Bin()
{
	//cout << "Bin Destructor called";
	delete[] arrayOfVectors; // delete the whole array
	arrayOfVectors = NULL; // set the pointer to nullptr
}

int Bin::getNumberOfVectors() const // this method return how many elements (vectors) are inside the bin
{
	return this->elements;
}

int Bin::getArraySize() const // return as constant the integer representing te size of the array
{
	return this->arraySize;
}

// Optimisation: this method since it is not required, it might be private or protected
// first element in the arryay is 0, second is 1, third is 2 and so on so the a'th position in the array is the value -1
Vector3D& Bin::getVectorAtPos(int p) const // given a position p, it returns the Vector at that position
{
	if (p <= this->getNumberOfVectors() && p > 0) { 
		return this->arrayOfVectors[p-1]; 
	}
	else { // if out of bounds
		cout << "Error: You selected an element outside the array boundaries"<<endl;
		Vector3D err = Vector3D();
		return err;
	}
}

// Optimisation: extra safety, I am returning the vector using the getVectorAtPos so checking for boudaries
// the Vector3D has returned as contant I am safely accessing to its coordinates as constant
float Bin::getX(int position) const
{
	if (position <= this->getNumberOfVectors() && position > 0) {
		return this->getVectorAtPos(position).get_x_coord();
	}
	else {
		cout << "Error: You selected an element outside the array boundaries, will return 0 (NULL) ";
		return NULL;
	}

}

float Bin::getY(int position) const
{
	if (position <= this->getNumberOfVectors() && position > 0) {
		return this->getVectorAtPos(position).get_y_coord();
	}
	else {
		cout << "Error: You selected an element outside the array boundaries, will return 0 (NULL) ";
		return NULL;
	}
}

float Bin::getZ(int position) const
{
	if (position <= this->getNumberOfVectors() && position > 0) {
		return this->getVectorAtPos(position).get_z_coord();
	}
	else {
		cout << "Error: You selected an element outside the array boundaries, will return 0 (NULL) ";
		return NULL;
	}
}

// To add a new element first, check if there is enough space.
// then when the array is ready, add the new Vector
void Bin::add(float x, float y, float z)
{
	// If the number of Vectors in the array +1 (the new element) is greater then or equal ( because of the null terminator ) the size of the array
	// we need to inrease the size of the array (copying over the old arrays)
	if (this->getNumberOfVectors() + 1 >= this->getArraySize()) { this->increaseSize(); }

	// Then let's add the new array to the next in order element (element +1)
	// That it is not necessary the last position of the array
	// Optimisation: Since I am increasing the array exponentially (power of 2) 
	// and not linearly +1 every time it reduces number of operations
	arrayOfVectors[getNumberOfVectors()] = Vector3D(x, y, z); // I am not using elemnts +1 but elements because arrays start from 0
	elements++; // increase the number of elements
}

void Bin::remove(int bth)// the b'th element means that in the array we need to search bth-1 so like 1st means position 0 in array
{
	// if the user tried to remove an element in a negative position or it goes after the last element
	if (bth < 1 || bth > elements) { cout << "Error: You selected an element outside the array boundaries"<<endl; } // return a warning
	else {
		bth--; // first element in the arryay is 0, second is 1, third is 2 and so on
		for (int i = bth + 1; i < elements; i++) { //start from the element after the one we removed to the end of the array
			arrayOfVectors[i - 1] = arrayOfVectors[i]; // transfer every element in the previous space to fill the gap
														// so the vector after the one removed copied to the space of the one removed and so on
		}
		elements--; // decrease the counter of elements in the array
		reduceSize(); // check if the array is too big and using too much memory
	}

}

// This method runs if the bin needs to add a new element in the array but the array doesn't have enough space
// Optimisation: Calling it costs memory but saves CPU
void Bin::increaseSize()
{
	this->arraySize *= 2; // first: get the array space double the size
	Vector3D* temporary = new  Vector3D[arraySize]; // Create a temporary array to hold all the values already in the vector that is in the bin
	for (int i = 0; i < elements; i++) {
		temporary[i] = this->arrayOfVectors[i]; // It transfers all the elements one by one
												// Optimisation: it is still worth transferring all the elements because this process
												// is done only once in a while and every time the array has increased in size
												// the size doubles so it will require always less calls to this method the following times
												// and only elements will be added without transferring vectors.
	}
	delete[] arrayOfVectors;// Delete the content of old array to free memory
	this->arrayOfVectors = temporary; // Substitute the pointer reference to the old array with the one with the one to the new array
}

// Optimisation: This is called only if the array is way to big.
// Calling it costs CPU but saves memory
void Bin::reduceSize()
{
	int sizeNeeded = nextPowerOfTwo(elements + 1); //find the right power of two for the number of elements in the array plus null terminator
	// if we deleted elements and the arrays is to big and the power of two right for the array is smaller than the size of the array at the moment
	// we need to shrink the array
	if (sizeNeeded < getArraySize()) {
		this->arraySize = sizeNeeded;
		Vector3D* temporary = new  Vector3D[arraySize]; // Create a temporary array to hold all the values already in the vector that is in the bin
		// Similar operation than when adding an element
		for (int i = 0; i < elements; i++) {
			temporary[i] = this->arrayOfVectors[i];
		}
		delete[] arrayOfVectors;// Delete the content of old array to free memory
		this->arrayOfVectors = temporary; // Substitute the pointer reference to the old array with the one with the one to the new array
	}

}

// This method prints all the elements
ostream& operator<<(ostream& outStream, const Bin& bin)
{
	outStream << "Bin containing " << bin.getNumberOfVectors() << " Vector3D: \n";
	for (int i = 1; i <= bin.getNumberOfVectors(); i++) {
		outStream << bin.getVectorAtPos(i);
	}
	return outStream;
}

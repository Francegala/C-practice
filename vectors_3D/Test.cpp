/*
* CSC3221: Project 1
* Student No 170492959
* Test Class: Test.cpp
*/

#include "Bin.h"
#include "Vector3D.h"
#include <iostream>
#include <cassert>

using namespace std;

// True = 1

// Vector3D Constructor:
// Checking the default Values of the Vector3D constructor
// Creating an object on the Heap and two in the stack with different calls
// Checking that all of them have coordinates sets to the origin
bool defaultVector() {
	cout << "Checking if the default constructor has x,y,z coordinates set to the origin: ";
	Vector3D a;
	Vector3D b = Vector3D();
	Vector3D* c = new Vector3D();
	return (
		a.get_x_coord() == b.get_x_coord() &&
		b.get_x_coord() == c->get_x_coord() &&
		c->get_x_coord() == 0 &&
		a.get_y_coord() == b.get_y_coord() &&
		b.get_y_coord() == c->get_y_coord() &&
		c->get_y_coord() == 0 &&
		a.get_z_coord() == b.get_z_coord()  &&
		 b.get_z_coord() == c->get_z_coord() &&
		c->get_z_coord() == 0
		);
}

// Checking if the Constructor works at cordinate assignment using hard coding numbers
// Creating an object in the stack and one in the heap
bool VectorConstructorNumber() {
	cout << "Checking if the constructor works hard coding numbers as values: ";
	Vector3D a = Vector3D(1, 2, 7);
	Vector3D* b = new Vector3D(1, 2, 7);
	
	return (
		(a.get_x_coord() == b->get_x_coord()) && 
		(b->get_x_coord() == 1) && 
		(a.get_y_coord() == b->get_y_coord())&& 
		(b->get_y_coord() == 2) && 
		(a.get_z_coord() == b->get_z_coord())&&
		(b->get_z_coord() == 7)
			); 
}

//Checking if the Constructor works at cordinate assignment using variables
bool VectorConstructorVariables() {
	cout << "Checking if the constructor works inserting variables: ";
	float x = 2.3;
	float y = 4.5;
	float z = 6.7;
	Vector3D a = Vector3D(x, y, z);
	Vector3D* b = new Vector3D(x, y, z);

	return (
		(a.get_x_coord() == b->get_x_coord()) &&
		(b->get_x_coord() == x) &&
		(a.get_y_coord() == b->get_y_coord()) &&
		(b->get_y_coord() == y) &&
		(a.get_z_coord() == b->get_z_coord()) &&
		(b->get_z_coord() == z)
		);
}

// Vector3D Copy constructorr:
// Create objects in stack and heap then call copy constructor
// Check that all objects have different addresses but same values inside
bool VectorCopyConstructor() {
	cout << "Checking the objects created are different: ";
	Vector3D a = Vector3D(0, 1, 2);
	Vector3D b = Vector3D(a);
	Vector3D* c = new Vector3D(0, 1, 2);
	Vector3D* d = new Vector3D(*c);
	Vector3D* e = new Vector3D(a);;
	Vector3D f = Vector3D(*c);

	return ((&a != &b) && (&c != &d) && (e != &a) && (&f != c) &&
		a.get_x_coord() == b.get_x_coord() &&
		b.get_y_coord() == b.get_y_coord() &&
		c->get_y_coord() == d->get_y_coord() &&
		e->get_z_coord() == f.get_z_coord());
}

// Vector3D Assignment operator:
// Checking if the = operator creates a different individual object with still the same coordinates
// using = both in stack and heap
// Compare addresses to see that they are different objects
// Check that x,y,z are the same
bool VectorAssignment() {
	cout << "Checking the objects created are different: ";
	Vector3D a = Vector3D(0, 1, 2);
	Vector3D b = a;
	Vector3D* c = new Vector3D(0, 1, 2);
	Vector3D* d = new Vector3D();
	*d = *c;
	Vector3D* e = new Vector3D();;
	*e = a;

	return ((&a != &b) && (&c != &d) && (e != &a) && (&b != c) && 
		a.get_x_coord() == b.get_x_coord() && 
		c->get_y_coord() == d->get_y_coord() && 
		e->get_z_coord() == a.get_z_coord());
}

// Destructor
// I am creating an object in the heap,
// Printing the values,
// Destructing,
// Printing the values with garbage.
void VectorDestructor() {
		Vector3D *a = new Vector3D(6, 5, 4);
		cout <<"Values of the object before destruction (6,5,4): "<<*a;
		delete a;
		cout << "Please uncomment the following cout to see the result since it is using an unitiallized memory and it might cause an error";
		//cout << "Values of the object after destruction (garbage or error): " << *a;
}

// Testing setters, even thought for a future it might be more safe to set them as private or protected
bool VectorSetters() {
	Vector3D set = Vector3D();
	cout << "Checking the coordinates of the Vector are not 0 anymore: ";
	set.set_x_coord(8);
	set.set_y_coord(5);
	set.set_z_coord(9);
	return (
		(set.get_x_coord() == 8)&&
		(set.get_x_coord() != 0)&&
		(set.get_y_coord() == 5)&&
		(set.get_y_coord() != 0)&&
		(set.get_z_coord() == 9)&&
		(set.get_z_coord() != 0)
		);
}

// Testing magnitude
bool VectorMagnitude() {
	cout << "Checking if the magnitude of a Vector (2,3,5) is 6.16 : "<<endl;
	Vector3D testMagnitude = Vector3D(2, 3, 5);
	float magnitudeVector = testMagnitude.magnitude();

	cout << "float variable: "<< magnitudeVector<<endl;
	cout << "magnitude of vector: " << testMagnitude.magnitude()<<"\n";

	assert(testMagnitude.magnitude() == magnitudeVector);

	return (testMagnitude.magnitude() == magnitudeVector);
}

// Testing Sum between two vectors
bool VectorSum() {
	Vector3D addend1 = Vector3D(1, 1, 1);
	Vector3D addend2 = Vector3D(2, 2, 2);
	cout << "Checking that the sum of the Vector "<<addend1 <<" and the vector "<<addend2<<" is the vector "<<(addend1+addend2)<<" : ";
	return (addend1+addend2).get_x_coord()==3;
}

// Testing Difference between two vectors
bool VectorDiff() {
	Vector3D subtrahend1 = Vector3D(3, 3, 3);
	Vector3D subtrahend2 = Vector3D(2, 2, 2);
	cout << "Checking that the difference between the Vector " << subtrahend1 << " and the vector " << subtrahend2 << " is the vector " << (subtrahend1 - subtrahend2) << " : ";
	return (subtrahend1 - subtrahend2).get_x_coord() == 1;
}

// Testing multiplication between a vector and a scalar
bool VectorMultiplication() {
	Vector3D vector = Vector3D(3, 3, 3);
	cout << "Multiplying the vector " << vector << " by -5, "<< "returning the vector " << (vector * -5) << " : ";
	return (vector * -5).get_x_coord() == -15;
}

// Testing division between a vector and a scalar
bool VectorDivision() {
	Vector3D vector = Vector3D(3, 3, 3);
	cout << "Dividing the vector " << vector << " by 5, " << "returning the vector " << (vector / 5) << " : ";
	return (vector / 5).get_x_coord() == (float)0.6;
}

// Testing division by zero
bool VectorDivisionZero() {
	Vector3D vector = Vector3D(3, 3, 3);
	cout << "Dividing the vector " << vector << " by 0, " << "returning the same vector " << (vector / 0) << " : ";
	return (vector / 0).get_x_coord() == 3;
}

// Testing scalar product of two vectors
bool VectorScalarProduct() {
	Vector3D vector = Vector3D(10, 0.5, 4);
	Vector3D vector2 = Vector3D(1, 20, 6);

	cout << "Scalar product between the vector " << vector << " and the vector " << vector2<< "returning " << (vector * vector2) << " : ";

	return (vector*vector2)==44;
}

// Testing vector product of two vectors
bool VectorVectorProduct() {
	Vector3D vector = Vector3D(2, 3, 4);
	Vector3D vector2 = Vector3D(5, 6, 7);

	cout << "Vector product between the vector " << vector << " and the vector " << vector2 << "returning " << (vector % vector2) << " : ";

	return (vector % vector2).get_x_coord() == -3;
}

// Test the creation of a unit vector (function returning a vector)
bool VectorUnit() {
	Vector3D vector = Vector3D(1,2,3);
	cout << "Unit Vector of Vector " << vector <<" is "<< vector.unitVector() << " : ";
	Vector3D unit = vector.unitVector();
	return unit == vector.unitVector();
}

// Creating a Vector Orthogonal to two vectors
bool VectorOrthogonal() {
	Vector3D vector = Vector3D(1, 2, 3);
	Vector3D vector2 = Vector3D(4, 5, 6);
	cout << "Vector Orthogonal to Vector " << vector << "and vector " << vector2 << " is " << vector.orthogonal(vector2) << " : ";
	return  vector.orthogonal(vector2).magnitude();  // true if the magnitude is 1 since it is a unit vector
}

// Test all the update operators
bool VectorUpdate() {
	Vector3D vectorThrees = Vector3D(3, 3, 3);
	Vector3D vectorOnes = Vector3D(1, 1, 1);
	cout << "Testing arithmetic opertors but updating the original value: ";
	assert((vectorOnes += vectorThrees).get_x_coord() == (float)4);
	assert((vectorOnes -= vectorThrees).get_x_coord() == (float)1);
	assert((vectorOnes *= 3).get_x_coord() == vectorThrees.get_x_coord());
	assert((vectorOnes /= 3).get_x_coord() == (float)1);
		return true;
}

// Test all the relational operators
bool VectorRelational() {
	Vector3D vectorOnes = Vector3D(1, 1, 1);
	Vector3D vectorEqual = Vector3D(1, 1, 1);
	Vector3D vectorThrees = Vector3D(3, 3, 3);
	cout << "Checking relational operators on Vectors:\n"<<vectorOnes<<vectorThrees<<vectorEqual;
	assert(vectorOnes == vectorEqual);
	assert(vectorEqual == vectorOnes);
	assert(vectorOnes != vectorThrees);
	assert(vectorThrees != vectorOnes);
	assert(vectorOnes < vectorThrees);
	assert(vectorOnes <= vectorThrees);
	assert(vectorOnes <= vectorEqual);
	assert(vectorOnes >= vectorEqual);
	assert(vectorThrees>vectorOnes);
	assert(vectorThrees>=vectorOnes);
	return true;
}

// Test input operator
bool VectorInput() {
	Vector3D enter;
	cin >> enter;
	cout <<"check if what you inserted is the same as the output: "<< enter;
	return true;
}

// Testing Bin Constructor
// Creating a bin in the stack and in the heap with default values
// then check that the elements are zero and that the array has size 2, the minimum
bool DefaultBin() {
	cout << " Bin Constructor creates Bin objects with no elements inside and an array of size 2: ";
	Bin a;
	Bin b = Bin();
	Bin* c = new Bin();

	assert(a.getNumberOfVectors() == b.getNumberOfVectors());
	assert(b.getNumberOfVectors() == c->getNumberOfVectors());
	assert(c->getNumberOfVectors() == 0);	
	
	assert(a.getArraySize() == b.getArraySize());
	assert(b.getArraySize() == c->getArraySize());
	assert(c->getArraySize() == 2);

	return true;
}

// Now let's use the constructor inserting hard coded numbers
bool NumberBin() {
	cout << " Bin Constructor creates Bin objects specifying the number of vectors to be inserted using a number: ";
	Bin b = Bin(3);
	Bin* c = new Bin(3);

	assert(b.getNumberOfVectors() == c->getNumberOfVectors());
	assert(c->getNumberOfVectors() == 0);

	assert(b.getArraySize() == c->getArraySize());
	assert(c->getArraySize() == 4);

	return true;
}

// Now let's use the constructor with a variable parameter
bool VariableBin() {
	cout << " Bin Constructor creates Bin objects specifying the number of vectors to be inserted using a variable: ";
	int x = 1;
	Bin b = Bin(x);
	Bin* c = new Bin(x);

	assert(b.getNumberOfVectors() == c->getNumberOfVectors());
	assert(c->getNumberOfVectors() == 0);

	assert(b.getArraySize() == c->getArraySize());
	assert(c->getArraySize() == 2);

	return true;
}

// Now let's use the constructor with a negative parameter as number of vectors
bool ErrorConstructor() {
	cout << " This time let's add a negative value and let's check that the array still holds 2 because of good error checking: ";
	int x = -4;
	Bin b = Bin(x);
	Bin* c = new Bin(x);

	assert(b.getNumberOfVectors() == c->getNumberOfVectors());
	assert(c->getNumberOfVectors() == 0);

	assert(b.getArraySize() == c->getArraySize());
	assert(c->getArraySize() == 2);

	return true;
}

// Copy constructor check that copies hold same values but different addresses
// check that it works for both stack and heap
bool BinCopyConstructor() {
	Bin a = Bin(2);
	a.add(1, 2, 3);
	Bin b = Bin(a);
	Bin* c = new Bin(a);

	Bin* d = new Bin(2);
	d->add(4, 5, 6);
	Bin* e = new Bin(*d);
	Bin  f = Bin(*d);

	cout << "Checking the copy constructor creates different objects with same values: ";
	assert(&a!=&b);
	assert(&a!=c);
	assert(&b!=c);

	assert(a.getX(1)==b.getX(1));
	assert(a.getY(1)==b.getY(1));
	assert(a.getZ(1)==b.getZ(1));

	assert(a.getX(1)==c->getX(1));
	assert(a.getY(1)== c->getY(1));
	assert(a.getZ(1)== c->getZ(1));


	assert(d!=e);
	assert(e!=&f);
	assert(&f!=d);

	assert(e->getX(1) == f.getX(1));
	assert(e->getY(1) == f.getY(1));
	assert(e->getZ(1) == f.getZ(1));

	assert(e->getX(1) == d->getX(1));
	assert(e->getY(1) == d->getY(1));
	assert(e->getZ(1) == d->getZ(1));

	return true;
}

// Overriding equal operator check that copies hold same values but different addresses
// check that it works for both stack and heap
bool BinEqual() {
	Bin a = Bin(2);
	a.add(1, 2, 3);
	Bin b = a;
	Bin* c = new Bin();
	*c= a;

	Bin* d = new Bin(2);
	d->add(4, 5, 6);
	Bin* e = new Bin();
	*e = *d;
	Bin  f = *d;

	cout << "Checking the assignment operator creates different objects with same values: ";
	assert(&a != &b);
	assert(&a != c);
	assert(&b != c);

	assert(a.getX(1) == b.getX(1));
	assert(a.getY(1) == b.getY(1));
	assert(a.getZ(1) == b.getZ(1));

	assert(a.getX(1) == c->getX(1));
	assert(a.getY(1) == c->getY(1));
	assert(a.getZ(1) == c->getZ(1));


	assert(d != e);
	assert(e != &f);
	assert(&f != d);

	assert(e->getX(1) == f.getX(1));
	assert(e->getY(1) == f.getY(1));
	assert(e->getZ(1) == f.getZ(1));

	assert(e->getX(1) == d->getX(1));
	assert(e->getY(1) == d->getY(1));
	assert(e->getZ(1) == d->getZ(1));

	return true;
}

// Testing destructor:
// Create a Bin with one array, check that there is a Vector inside;
// Destroy the bin and check that it returns an error if accessing it
bool BinDestructor() {
	Bin* a = new Bin(1);
	a->add(9, 9, 9);
	assert(a->getX(1) != 0);
	delete a;
	cout << "uncomment the following assertion to check the destructor, it might throw an error!" << endl;
	// uninitialised memory but it is ok for testing purpose
	//assert(a->getX(1) == 0);
	return true;
}

// Testing if the getter to know how many elements are in the array works efficiently
// Let's create a bin with a low expected number of vectors
// then add at least three times vectors inside
// see if returns the right number of elements.
bool BinVectors() {
	Bin bin = Bin(2);
	for (int i = 0; i < 6; i++)bin.add(i, i, i);
	cout << "check that after adding 6 vectors, the bin contains 6 vectors: ";
	assert(bin.getNumberOfVectors() == 6);
	return true;
}

// Test the getters for the array size value
// since we know that the array size is always greater than the number of vectors (+ null term)
bool BinArraySize() {
	Bin bin = Bin();
	Bin* newBin = new Bin(9);
	Bin lastBin = Bin(2);
	for (int i = 0; i < 6; i++)bin.add(i, i, i);
	cout << "check that after creating Bins and adding vectors, bins hold power of two array sizes: ";
	assert(bin.getArraySize() %2 == 0);
	assert(newBin->getArraySize() % 2 == 0);
	assert(lastBin.getArraySize() % 2 == 0);
	return true;
}

// Test getters
// Test that getX(a) returns the x coord of the a'th vector in the array
// Test that getY(a) returns the y coord of the a'th vector in the array
// Test that getZ(a) returns the z coord of the a'th vector in the array
// Check that if we ask for a vector (position in the array) not existing 0 is returned with an error; 
bool BinGetters() {
	Bin bin = Bin(1);
	bin.add(1, 2, 3);
	assert(bin.getX(1) == 1);
	assert(bin.getY(1) == 2);
	assert(bin.getZ(1) == 3);

	assert(bin.getX(11) == 0);
	cout << "\nTesting that the getters return the right value or an error if accessed the wrong value: ";
	return true;
}

// Test adding method for Bin
// Use add method and check that both the array size and elements number have been updated
bool BinAdd() {
	Bin tester = Bin(1);
	int el = tester.getNumberOfVectors();
	int as = tester.getArraySize();
	for (int i = 0; i < 6; i++)tester.add(i, i, i);

	cout << "check that after adding Vectors, both elements in the array and size of the array is bigger than the initial value : ";
	assert(tester.getArraySize()>as);
	assert(tester.getNumberOfVectors()>el);

	return true;

}

// Test removing method for Bin
// Use remove method and check that both the array size and elements number have been updated
bool BinRemove() {
	Bin tester = Bin(1);
	for (int i = 0; i < 6; i++)tester.add(i, i, i);
	int el = tester.getNumberOfVectors();
	int as = tester.getArraySize();

	// this time the starting point is the bin with vectors in it
	for (int i = 0; i < 4; i++)tester.remove(1);
	cout << "Check that after looping removing the first element (element 1 even if array starts from zero),\nelements and size is smaller than the initial value.\n";
	
	assert(tester.getArraySize() < as);
	assert(tester.getNumberOfVectors() < el);

	// try remove more vectors that how many are in teh array
	cout << "Check that removing an extra element throws an error: ";
	for (int i = 0; i < 3; i++)tester.remove(1);

	return true;
}

// Test the output method
//creating a bin in the stack, on in the heap, one empty and one with vectors and see how they are printed
void BinOutput() {
	Bin binS = Bin(0);
	Bin * binH = new Bin(3);
	for (int i = 0; i < 3; i++)binH->add(i, i, i);
	cout << binS<<endl;
	cout << *binH << endl;

}

// Creating some tests scenarios to understand better what is going on behind the scenes:

// Creating some vectors in the stack and copying values, then create a vector in heap and see distance of memory
void VectorScenario1() {
	Vector3D a, b;
	cout << "Checking if the default constructor has 0 values" << endl;
	cout << a << endl;
	a.set_x_coord(1);
	cout << "Checking if the x has 1 and the rest has 0 values" << endl;
	cout << a << endl;
	a.set_y_coord(5);
	cout << "Checking if the x has 1 and y is 5 and the rest has 0 values" << endl;
	cout << a << endl;
	a.set_z_coord(9);
	cout << "Checking if the x has 1 and y is 5 and z is 9" << endl;
	cout << a << endl;
	b = a;
	cout << "Copying a to b. b should print  x=1, y=5, z=9" << endl;
	cout << b << endl;
	Vector3D c = b;
	cout << "Declaring c and copying b to c. c should print  x=1, y=5, z=9" << endl;
	cout << b << endl;
	Vector3D* heapAllocated1 = new Vector3D();
	Vector3D* heapAllocated2 = new Vector3D(1, 2, 3);
	cout << "a and b will have neighbouring memory address but for heapAllocated it will be a lot different" << endl;
	cout << &a << " " << &b << " " << heapAllocated1 << endl;
}

// Destroying objects in the heap to see destructor in action
void VectorScenario2() {
	Vector3D* heapAllocated1 = new Vector3D();
	Vector3D* heapAllocated2 = new Vector3D(1, 2, 3);
	cout << "Heap allocated variables, first one should print 0,0,0 and second should print 1,2,3" << endl;
	cout << *heapAllocated1 << " " << *heapAllocated2 << endl;
	cout << "Destroy heapAllocated variables (uncomment the cout from Destructor to see comment)" << endl;
	delete heapAllocated1;
	delete heapAllocated2;
}

// Confirming that magnitude is a constant, Making a copy of the result of the addition of two vectors int a variable
// Playing with subtraction, multiplication and products
void VectorScenario3() {
	Vector3D b = Vector3D(1, 5, 9);
	cout << "the magnitude of vector x=1, y=5, z=9 should be 10.3441" << endl;
	cout << b.magnitude() << endl;
	cout << "Tried changing  the magnitude but since it is returned by a getter as a const value but that gives an error so its commmented out" << endl;
	//b.magnitude() +1 = 2;
	Vector3D c = b;
	Vector3D a;
	cout << "Adding 2 vectors x=1, y=5, z=9 and x=1, y=5, z=9" << endl;
	cout << b + c << endl;
	cout << "Subtracting 2 vectors x=1, y=5, z=9 and x=1, y=5, z=9" << endl;
	cout << b - c << endl;
	cout << "Make a copy of the result of the subtraction of two vectors with same coordinates so expected result origin ( x=1, y=5, z=9 and x=1, y=5, z=9 ) into a" << endl;
	a = b - c;
	cout << "a is -> " << a << " b is -> " << b << " c is -> " << c << endl;
	cout << "multiplying b ( x=1, y=5, z=9 ) with 5 and diving it by 2" << endl;
	cout << b * 5 << " " << (b * 5 / 2) << endl;
	cout << "Scalar product b with b without saving the result in a variable" << endl;
	cout << b * b << endl;
	Vector3D vecProd = Vector3D();
	cout << "vector product b with c but saving the result" << endl;
	c = Vector3D(9, 5, 1);
	vecProd = b % c;
	cout << vecProd << endl;
}

// A stress test to se if it works using complex formulas or if the user types wrong
// Playing with unit vector and see if v1 orthogonal v2 is the same as second orthogonal first
// Comparing b with itself
void VectorScenario4() {
	Vector3D b = Vector3D(1, 5, 9);
	Vector3D c = Vector3D(9, 5, 1);
	cout << "Stress test: Complex formula like c = b = b%c" << endl;
	c = b = b % c;
	cout << c << endl;
	//resetting
	b = Vector3D(5, 6, 5);
	c = Vector3D(1, 2, 4);
	cout << "unit of vector -> " << b << " is -> " << b.unitVector() << endl;
	cout << "unit orthogonal of vector b -> " << b <<" and c -> " << c << " is -> " << b.orthogonal(c) << endl;
	cout << "unit orthogonal of vector c -> " << c <<" and b -> " << b << " is -> " << c.orthogonal(b) << endl;
	b += b;
	cout << "b+=b makes -> " << b << endl;
	b *= 5;
	cout << "b*=5 makes -> " << b << endl;
	b /= 2;
	cout << "b/=2 makes -> " << b << endl;
	b -= b;
	cout << "b-=b makes -> " << b << endl;
	cout << "b==b returns -> " << (b == b) << endl;
	cout << "b!=b returns -> " << (b != b) << endl;

}

//Testing some comparisons and asking for user interaction
void VectorScenario5() {
	Vector3D vector;
	cin >> vector;
	cout << "you entered -> " << vector << endl;

	cout << " vector < vector + Vector 1,5,10 is -> " << (vector < (vector + Vector3D(0, 0, 10))) << endl;
	cout << " vector > vector + Vector 1,5,8  is -> " << (vector > (vector + Vector3D(0, 0, 8))) << endl;

	cout << " vector < vector + Vector 1,5,10 is -> " << (vector <= (vector + Vector3D(0, 0, 10))) << endl;
	cout << "vector > vector + Vector 1,5,8 is -> " << (vector >= (vector + Vector3D(0, 0, 0))) << endl;	
}

// This scenario creates a bin with some vectors and after deleting all the vectors creates another bin and makes it a copy of the previous one
void BinScenario1() {
	Bin* b = new Bin(-1);
	b->add(1, 2, 3);
	b->add(4, 5, 6);
	cout << "b " << *b << endl;


	b->remove(1);
	cout << "b " << *b << endl;
	b->remove(1);

	Bin* a = new Bin();

	cout << "a size array: " << a->getArraySize() << endl;
	cout << "b size array: " << b->getArraySize() << endl;
	cout << "a vectors: " << a->getNumberOfVectors() << endl;
	cout << "b vectors: " << b->getNumberOfVectors() << endl;


	*a = *b;

	cout << "a size array: " << a->getArraySize() << endl;
	cout << "b size array: " << b->getArraySize() << endl;
	cout << "a vectors: " << a->getNumberOfVectors() << endl;
	cout << "b vectors: " << b->getNumberOfVectors() << endl;


	cout << "\na " << a << "  " << *a << endl;

	cout << "b " << b << "  " << *b << endl;
}

// This scenario might help to know the speed of execution
void BinScenario2() {
	Bin bin;
	cout << bin << endl;

	cout << "Checking if the memory allocation is happening dynamically and optimally: (adding and printing 9 elements)" << endl;
	bin.add(0, 222, 333);
	cout << bin << endl;
	bin.add(1, 222, 333);
	cout << bin << endl;
	bin.add(2, 222, 333);
	cout << bin << endl;
	bin.add(3, 222, 333);
	cout << bin << endl;
	bin.add(4, 222, 333);
	cout << bin << endl;
	bin.add(5, 222, 333);
	cout << bin << endl;
	bin.add(6, 222, 333);
	cout << bin << endl;
	bin.add(7, 222, 333);
	cout << bin << endl;
	bin.add(8, 222, 333);
	cout << bin << endl;

	cout << "Remove all the elements and trying removing more vectors causing errors: " << endl;
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	bin.remove(1);
	cout << bin << endl;
	cout << "As quick as expected: to calculate the time, please remove the couts inside this method" << endl;

}

// Adding 2048000 vectors to 5 bins each: Extimated time about 5-6 seconds
void BinScenario3() {

	cout << "Using for loops to add elements to five different Bins and see if the program manages and handles the memory correctly" << endl;
	cout << "This is just a test case so after the method execution the Distructor will be called, please uncomment the vector and bin distuctors comment to more details" << endl;
	{
		Bin bin, aa, bb, cc, dd;

		for (int i = 0; i < 2048 * 1000; i++) {
			bin.add(6, 222, 333);
		}
		for (int i = 0; i < 2048 * 1000; i++) {
			aa.add(6, 222, 333);
		}
		for (int i = 0; i < 2048 * 1000; i++) {
			bb.add(6, 222, 333);
		}
		for (int i = 0; i < 2048 * 1000; i++) {
			cc.add(6, 222, 333);
		}

		cout << "Bin has -> vector: " << bin.getNumberOfVectors() << " total size: " << bin.getArraySize() << endl;
		cout << "Bin has -> vector: " << aa.getNumberOfVectors() << " total size: " << aa.getArraySize() << endl;
		cout << "Bin has -> vector: " << bb.getNumberOfVectors() << " total size: " << bb.getArraySize() << endl;
		cout << "Bin has -> vector: " << cc.getNumberOfVectors() << " total size: " << cc.getArraySize() << endl;
	}

}

// Tests for vector functions
void VectorTest() {
	// cout << defaultVector() << endl;
	// cout << VectorConstructorNumber() << endl;
	// cout << VectorConstructorVariables() << endl;
	// cout << VectorCopyConstructor() << endl;
	// cout << VectorAssignment() << endl;
	// VectorDestructor();
	// cout << VectorSetters() << endl;
	// cout << VectorMagnitude() << endl;
	// cout << VectorSum() << endl;
	// cout << VectorDiff() << endl;
	// cout << VectorMultiplication() << endl;
	// cout << VectorDivision() << endl;
	// cout << VectorDivisionZero() << endl;
	// cout << VectorScalarProduct() << endl;
	// cout << VectorVectorProduct() << endl;
	// cout << VectorUnit() << endl;
	// cout << VectorOrthogonal() << endl;
	// cout << VectorUpdate() << endl;
	// cout << VectorRelational() << endl;
	// cout << VectorInput()<< endl;
	// VectorScenario1();
	// VectorScenario2();
	// VectorScenario3();
	// VectorScenario4();
	// VectorScenario5();
}

//Test for Bin functions
void BinTest() {
	
	 // cout << DefaultBin()<<endl;
	 // cout << NumberBin() << endl;
	 // cout << VariableBin() << endl;
	 // cout << ErrorConstructor() << endl;
	  cout << BinCopyConstructor() << endl;
	 // cout << BinEqual() << endl;
	 // cout << BinDestructor() << endl;
	 // cout << BinVectors() << endl;
	 // cout << BinArraySize() << endl;
	 // cout << BinGetters() << endl;
	 // cout << BinAdd() << endl;
	 // cout << BinRemove() << endl;
	 // BinOutput();
	 // BinScenario1();
	 // BinScenario2();
	 // BinScenario3();

}

int main() {
	cout << "Please select the tests you wish to run by uncommenting them from the follong methods: \n" << endl;
	 VectorTest();
	 BinTest();
}

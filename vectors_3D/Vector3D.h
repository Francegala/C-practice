/*
* CSC3221: Project 1
* Student No 170492959
* Vector3D Class: Vector3D.h
*/

#pragma once
#include <iostream>
using namespace std;

class Vector3D
{
public:

	// Constructor:
	// I decided to add only a single construtor because an empty one is not necessary.
	// I am using standard values in case the user leaves the fields empty.
	// Safety is important so if not specified, the Vector is created with coordinates at the origin.
	// However I will add setters in case there is the necessity to change values afterwards.
	Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);

	// According to the rule of 3,
	// if I am adding a Constructor I will need a Destructor and a CopyConstructor.
	// In the copy constructor, the Vector passed as parameter is called as constant
	// so it won't be changed by mistake.
	// To optimise: I am passing/returning objects by reference so it will avoid the creation of a copy of the object.
	Vector3D(const Vector3D& vector);

	// Assignent operator overloading, which basically copyes the coordinates.
	Vector3D operator= (const Vector3D& vector); // here we can see the first operator overloading
												// Optimisation: I am also using a Vector declared as constant to the field to avoid changes
												// and it is called using the address so a copy won't be made.

	// Destructor is not needed: we could use the one provided since we don't have to destroy anything internal created on the heap
	// I added it to insert a print statement to know where it is called.
	~Vector3D();

	// Setters: assignnment operator to set coordinates in the vector
	// For safety purpose in the constructor I am using setters so we are sure that the user don't access to intern fields by accident
	// Optimisation: for the future we could make setters private or protected for even more security since at the moment they are called only by constructor
	// It depends if we want to give the possibility to change a Vector3D coordinates or not
	void set_x_coord(float x);
	void set_y_coord(float y);
	void set_z_coord(float z);

	// Getters:
	// Return a x,y,x component of a vector
	// Optimisation: for efficiency, using float rather than double
	// I am using the const keyword to avoid changes to the element:
	// e.g. if the user mistakely insert in a if (a+b=c rather than a+b==c)
	float get_x_coord() const;
	float get_y_coord() const;
	float get_z_coord() const;

	// Compute the magnitude of a vector: square root of the sum of each component multiplied by itself (squared)
	// Optimisation: I researched that using the math library to do the square of a number is more expensive than multiplying the number by itself:
	// https://baptiste-wicht.com/posts/2017/09/cpp11-performance-tip-when-to-use-std-pow.html
	// To calculate the square root since I am using floats as components,
	// I am using sqrtf rather than sqrt to calculate the square root of a float type variable with precision
	float magnitude() const; 	// square root (x^2+y^2+z^2)


	// Optimisation: passing the vector parameters by reference
	// otherwise inside the function a copy of the object has made.
	// It saves both memory and CPU

	// Arithmetic Operators
	// Operators to add and subtract vectors
	Vector3D operator+ (const Vector3D& rhs); //sum between *this and right hand side (addend)
	Vector3D operator- (const Vector3D& rhs); // subrtraction between *this and righthandside (subtrahend) 
	// Operators to multiply and divide a vector by a scalar
	Vector3D operator* (const float scalar);
	Vector3D operator/ (const float scalar);
	// Calculate the scalar and vector product of two vectors
	float operator* (const Vector3D& rhs) const; // declaring it as constant since it won't change
	Vector3D operator% (const Vector3D& rhs);

	// Unit vector (of magnitude 1) pointing in same direction as given vector
	Vector3D unitVector();
	// Return a Unit Vector orthogonal to two given vectors
	Vector3D orthogonal(const Vector3D& rhs);

	// Overload update Operators
	Vector3D& operator+= (const Vector3D& rhs);
	Vector3D& operator-= (const Vector3D& rhs);
	Vector3D& operator*= (const float rhs);
	Vector3D& operator/= (const float rhs);

	// Overload Relational Operators
	bool operator== (const Vector3D& rhs);
	bool operator!= (const Vector3D& rhs);
	bool operator< (const Vector3D& rhs);
	bool operator<= (const Vector3D& rhs);
	bool operator> (const Vector3D& rhs);
	bool operator>= (const Vector3D& rhs);

private:
	// Since the copy constructor and the assignemnt operator overloading are basically doing operations very similar.
	// I am creating a function that copies the values of a vector inside another vector,
	// then, the copy constructor will be used to create an object
	// while the assignment operator returns a reference to the object calling the function.
	// This function reduces repetition of code.
	void copyCoordinates(const Vector3D& vector);

	// Implement a class Vector3D to Store x,y,z coordinates
	// Optimisation: Use the Stack to save fields
	// Optimisation: Use the smallest primitive types possible
	// floats to reduce the memory consuption
	float x_coordinate;
	float y_coordinate;
	float z_coordinate;
};

// Overriding methods for input and output outside the class because they are not part of the class but the std library
istream& operator>>(istream& inStream, Vector3D& vector);
ostream& operator<< (ostream& outStream, const Vector3D& vector);
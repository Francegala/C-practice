/*
* CSC3221: Project 1
* Student No 170492959
* Vector3D Class: Vector3D.cpp
*/

#include "Vector3D.h"
#include <iostream>
#include <cmath>

using namespace std;

// Constructor, all the components are set to zero when dafault constructor is called (Vector3D()) 
// Standard values are specified to avoid errors
// Setters are called because security is important
Vector3D::Vector3D(float x, float y, float z)
{
	//cout << "Calling constructor"<<endl;
	set_x_coord(x);
	set_y_coord(y);
	set_z_coord(z);
}

// this-> is the correct way to use both * for a pointer and . to call a function respecting priorities
Vector3D::Vector3D(const Vector3D& vector)
{
	//cout<<"Calling copy constructor"<<endl;
	this->copyCoordinates(vector);
}

void Vector3D::copyCoordinates(const Vector3D& vector)
{
	// using both setters to assign value to private fields
	// and getters to retrieve safely the valus of the parameters
	this->set_x_coord(vector.get_x_coord());
	this->set_y_coord(vector.get_y_coord());
	this->set_z_coord(vector.get_z_coord());
}

// Security first:
// prevents copying itself, save memory and CPU computations (Optimisation!)
Vector3D Vector3D::operator=(const Vector3D& vector)
{
	//cout << "Calling = operator" << endl;
	if (this == &vector) { 
		return *this; 
	}

	this->copyCoordinates(vector);
	return *this;
}

// Optimisation Commented out to save memory and CPU printing every destruction
// uncomment it to know where the distructors runs
// comment it to speed everything up
Vector3D::~Vector3D()
{
	// cout<<"Deleting the vector: "<<*this<<endl;
}

void Vector3D::set_x_coord(float x)
{
	x_coordinate = x;
}

void Vector3D::set_y_coord(float y)
{
	y_coordinate = y;
}

void Vector3D::set_z_coord(float z)
{
	z_coordinate = z;
}

float Vector3D::get_x_coord() const
{
	return x_coordinate;
}

float Vector3D::get_y_coord() const
{
	return y_coordinate;
}

float Vector3D::get_z_coord() const
{
	return z_coordinate;
}

// Optimisation: Magnitude not even using any other library (like for using pow) only std::sqrtf
float Vector3D::magnitude() const
{
	// I am directly returning the value rather than creating variables to host temporary values
	// to decrease both memory and CPU usage.
	return sqrtf( // sqrtf is exclusive for float values and avoids precision errors.
		(get_x_coord() * get_x_coord())
		+ (get_y_coord() * get_y_coord())
		+ (get_z_coord() * get_z_coord())
	);
}

Vector3D Vector3D::operator+(const Vector3D& rhs) //addend
{
	return Vector3D(
		get_x_coord() + rhs.get_x_coord(),
		get_y_coord() + rhs.get_y_coord(),
		get_z_coord() + rhs.get_z_coord()
	);
}

Vector3D Vector3D::operator-(const Vector3D& rhs) //subtrahend
{
	return Vector3D(
		get_x_coord() - rhs.get_x_coord(),
		get_y_coord() - rhs.get_y_coord(),
		get_z_coord() - rhs.get_z_coord()
	);
}

Vector3D Vector3D::operator*(const float scalar)
{
	return Vector3D(
		get_x_coord() * scalar,
		get_y_coord() * scalar,
		get_z_coord() * scalar
	);
}

Vector3D Vector3D::operator/(const float scalar)
{
	//Safety: prevent division by zero:
	if (scalar == 0) {
		cout << "Error: impossible division by zero, returning the initial Vector ";
		return *this; // I decided to return the vector calling this function if not allowed;
	}else return Vector3D(
		get_x_coord() / scalar,
		get_y_coord() / scalar,
		get_z_coord() / scalar
	);
}

float Vector3D::operator*(const Vector3D& rhs) const
{
	return (
		(get_x_coord() * rhs.get_x_coord())
		+ (get_y_coord() * rhs.get_y_coord())
		+ (get_z_coord() * rhs.get_z_coord())
		);
}

Vector3D Vector3D::operator%(const Vector3D& rhs)
{
	return Vector3D(
		(get_y_coord() * rhs.get_z_coord()) - (get_z_coord() * rhs.get_y_coord()),
		(get_z_coord() * rhs.get_x_coord()) - (get_x_coord() * rhs.get_z_coord()),
		(get_x_coord() * rhs.get_y_coord()) - (get_y_coord() * rhs.get_x_coord())
	);
}

Vector3D Vector3D::unitVector()
{
	// Optimisation: first since I didn't want to create temporary variables like for the operations above,
	// I was just returning the object with all the operations inside as coordinates.
	// Then I saw that for every component I was calculating the magnitude calling the function and it was a CPU waste.
	// so to optimise the number of calls, I am creating a variable to store the value and always call the same value rather than calling the function
	// For future optimisation: find a better alternative to save both memory and CPU
	float tempMagnitude = this->magnitude();

	return Vector3D(
		(this->get_x_coord() / tempMagnitude),
		(this->get_y_coord() / tempMagnitude),
		(this->get_z_coord() / tempMagnitude)
	);
}

// Vector product between two vectors, then returning its unit vector
Vector3D Vector3D::orthogonal(const Vector3D& rhs)
{
	return (*this % rhs ).unitVector();
}

Vector3D& Vector3D::operator+=(const Vector3D& rhs)
{
	this->set_x_coord(this->get_x_coord() + rhs.get_x_coord());
	this->set_y_coord(this->get_y_coord() + rhs.get_y_coord());
	this->set_z_coord(this->get_z_coord() + rhs.get_z_coord());

	return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& rhs)
{
	this->set_x_coord(this->get_x_coord() - rhs.get_x_coord());
	this->set_y_coord(this->get_y_coord() - rhs.get_y_coord());
	this->set_z_coord(this->get_z_coord() - rhs.get_z_coord());

	return *this;
}

Vector3D& Vector3D::operator*=(const float rhs)
{
	this->set_x_coord(this->get_x_coord() * rhs);
	this->set_y_coord(this->get_y_coord() * rhs);
	this->set_z_coord(this->get_z_coord() * rhs);

	return *this;
}

Vector3D& Vector3D::operator/=(const float rhs)
{
	if (rhs == 0) {
		cout << "Error: impossible division by zero, returning the initial Vector ";
		return *this; // I decided to return the vector calling this function if not allowed;
	}
	else {
		this->set_x_coord(this->get_x_coord() / rhs);
		this->set_y_coord(this->get_y_coord() / rhs);
		this->set_z_coord(this->get_z_coord() / rhs);

		return *this;
	}
}

// I used to calculate pow (10^-10) then I emailed the lecturer since I was receiving an error (Arithmetic overflow).
// To compare the difference between the two magnitudes with a small number I receive a conversion warning saying
// the small number is an 8-byte value while the float is 4 bytes.
// I received the suggestion that it ought to be easy to convert a double to float and it would be better to use a const than evaluating pow every comparison.
const float smallValue = 10e-10;

// I need to use the absolute value since I am using the difference between the magnitudes
// and since we need to stay safe that the user might be 1==3 and the function will do 1-3 so negative number 
// using  the absolute value a==b is the same than b==a
bool Vector3D::operator==(const Vector3D& rhs)
{
	if ((abs(magnitude() - rhs.magnitude())) < smallValue) return true;
	else return false;
}

bool Vector3D::operator!=(const Vector3D& rhs)
{
	if ((abs(magnitude() - rhs.magnitude())) < smallValue) return false;
	else return true;
}

// To compare vectors I am using the magnitude 
bool Vector3D::operator<(const Vector3D& rhs)
{
	if (magnitude() < rhs.magnitude()) return true;
	else return false;
}

bool Vector3D::operator<=(const Vector3D& rhs)
{
	if (magnitude() <= rhs.magnitude()) return true;
	else return false;
}

bool Vector3D::operator>(const  Vector3D& rhs)
{
	if (magnitude() > rhs.magnitude()) return true;
	else return false;
}

bool Vector3D::operator>=(const Vector3D& rhs)
{
	if (magnitude() >= rhs.magnitude()) return true;
	else return false;
}

// This method is for inserting data to a Vector e.g cin
istream& operator>>(istream& inStream, Vector3D& vector)
{
	// I am adding this sentence to avoid user errors in case they add commas, brackets or other symbols
	// Optimisation: it costs memory so it might be omitted
	cout << "\nPlease type coordinate one next to the other followed by a whitespace o pressing enter!\n";
	float x_coordinate;
	float y_coordinate;
	float z_coordinate;
	inStream >> x_coordinate >> y_coordinate >> z_coordinate;

	vector = Vector3D(x_coordinate, y_coordinate, z_coordinate);
	return inStream;

}

// This method prints the vector in the form x: coord y: coord z: coord
ostream& operator<<(ostream& outStream, const Vector3D& vector)
{
	outStream << "x: " << vector.get_x_coord() << " y: " << vector.get_y_coord() << " z: " << vector.get_z_coord() <<"\n";
	return outStream;
}
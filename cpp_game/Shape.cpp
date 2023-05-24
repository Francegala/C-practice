//
//  Shape.cpp
//  csc3221cousework2
//
//  Created by Francesco Galassi on 21/01/2021.
//

#include "Shape.hpp"
#include <iostream>
using namespace std;

/*
* This class has pure virtual functions and is abstrac so can't be instantiated.
* The constructor creates a shape and saves the position of the origin.
* Origin's point is the private member used from other memeber functios of this class
*/
Shape::Shape(int x, int y)
{
    this->origin=Point(x, y);
}


void Shape::setX(int x)
{
    this->origin.setX(x);
}

void Shape::setY(int y)
{
    this->origin.setY(y);
}

int Shape::getX()
{
    return this->origin.getX();
}

int Shape::getY()
{
    return this->origin.getY();
}

/*
* Circles and Squares needs to get specific values related to their objects
*/
Shape::Type Shape::getType()
{
    return this->type;
}

/*
* Overloading operator<< to print origin of the shape
*/
ostream& operator<<(ostream& outStream, Shape* shape)
{
    outStream <<"\t\tOrigin: x=" << shape->getX() << ", y=" << shape->getY() << std::endl;
    return outStream;
}

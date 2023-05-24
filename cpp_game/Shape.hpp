//
//  Shape.hpp
//  csc3221cousework2
//
//  Created by Francesco Galassi on 21/01/2021.
//

#ifndef Shape_hpp
#define Shape_hpp

#include <stdio.h>
#include <iostream>
#include "Point.hpp"
class Square;
class Circle;

using namespace std;
/*
    Abstract class Shape to represent the moving objects in the game.
    Enumeration to represent the two types of shape Cycle and Squares so to know what is overlapping with what.
    The class provides the method move(x,y) to move the position of the shape by a given amount, and a virtual destructor.
    I added the friend ostream function to print details of the shape when needed:
    ostream operator<< overwritten to print the position of the shape which will be calling cout<< method.
    checkCollision functions use as variable a shape to check if there is a collision.

    To extend the program to work in 3 dimensions with spheres and cubes, add them to the Types.

    For the coordinates I am using another class Point similar to the vector for coursework 1 to store and return the positions on a flat 2D surface.
*/
class Shape
{
public:
    enum class Type {
        Circle,
        Square // add any other type if adding new shapes
    };

    Shape(int x=0, int y=0);

    void setX(int x);
    void setY(int y);

    int getX();
    int getY();

    Type getType();

    // Method to move the shape and two methods to check collision between the shape calling the method and the one passed as variable, both virtual since this class is abstract (virtual destructor too)
    virtual void move(int dx, int dy) = 0;
    virtual ~Shape() { }

    virtual bool checkCollision(Circle* s1) = 0;
    virtual bool checkCollision(Square* s2) = 0;

    // print in the screen information from the origin point
    friend ostream& operator<< (ostream& outStream, Shape* shape);

protected:

    // To store the coordinates of the origin of the shape I will use a class like a Vector2D similar to what done for coursework 1
    Point origin;

    // Type of the shape if circle or square
    Type type;

};

#endif /* Shape_hpp */

//
//  Square.hpp
//  csc3221cousework2
//
//  Created by Francesco Galassi on 21/01/2021.
//

#ifndef Square_hpp
#define Square_hpp

#include <stdio.h>
#include <iostream>
#include "Shape.hpp"
#include "Circle.hpp"
using namespace std;
/*
    The Square class derives from the Shape Class (class Square : public Shape)
    When creating a Square not only the origin of the shape which is the bottom left edge gets saved but also all the other vertices.
    I have an array of vertices that stores all the 4 points

    I dealing with a Cube, there will be the need to save all 8 vertices,
    starting from the origin it is similar like having two squares parallel which differentiate only in the z values
    since all the x and y of the 4 points would be the same.

    When moving the Square the origin along with all the vertices must move.
*/
class Square : public Shape
{
public:
    /*
    * If called Square() the edge is the minimum 1 and origin is the origin of the axis
    */
    Square(int x=0, int y=0, int size=1);
    int getSize();
    Point* getVertices();

    virtual bool checkCollision(Circle* s1) override;
    virtual bool checkCollision(Square* s2) override;

    virtual void move(int moveX, int moveY) override;
    friend ostream& operator<< (ostream& outStream, Square* square);
    virtual ~Square() override;

protected:
    // size of the edge of the square
    int size;
    // all the 4 vertices of the square, will use them to see if they are inside another shape and collide
    Point vertices[4]; // The origin will be the point at the bottom left corner

};

#endif /* Square_hpp */

//
//  Circle.hpp
//  csc3221cousework2
//
//  Created by Francesco Galassi on 21/01/2021.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include <string>
#include "Shape.hpp"
#include <iostream>
class Square;
using namespace std;
/*
    This Circle class derives from the class Shape and stores three important informations:
    The origin so the center of the circle, the type from the shape class and the radius.

    To move and display the circle two functions are provided which override the function provided:
    the operator<< has added as friend function so it can print both values from circle and from shape.
    The destruction overrides the one from Shape too.

    There also is a function to check collision with each other shape.
*/
class Circle : public Shape
{
public:
    /*
    * If called Circle() the radius is the minimum 1 and centre is the origin of the axis
    */
    Circle(int x = 0, int y = 0, float radius = 1);
    float getRadius();

    virtual bool checkCollision(Circle* s2) override;
    virtual bool checkCollision(Square* s2) override;

    virtual void move(int moveX, int moveY) override;
    friend ostream& operator<< (ostream& outStream, Circle* circle);
    virtual ~Circle() override;

protected:
    // The origin is the centre of the circle and the size is the radius
    float radius;

};


#endif /* Circle_hpp */

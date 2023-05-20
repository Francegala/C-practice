//
//  Point.cpp
//  csc3221cousework2
//
//  Created by Francesco Galassi on 21/01/2021.
//

#include "Point.hpp"
/*
* Default constructor if calling Point() has the origin of the axes 0,0
* It saves the coordinates using calling the setCoords function
*/
Point::Point(int x, int y)
{
    this->setCoords(x,y);

}

/*
* The following methods saves the x and y coordinates (for 3D shapes add the z coord)
*/
void Point::setCoords(int x, int y)
{
    this->setX(x);
    this->setY(y);
}

void Point::setX(int x)
{
    this->xCoord = x;

}

void Point::setY(int y)
{
    this->yCoord = y;

}

/*
* The following methods returns the x and y coordinates
*/
int Point::getX()
{
    return this->xCoord;
}

int Point::getY()
{
    return this->yCoord;
}

/*
* This method asks as parameters two integers that are the amount of which the two coordinates will be moved,
* they are independent so the x can move of an amount and the y of a different number.
* The final position is saved as the old position + the change from the variable (change might be positive or negative).
*/
void Point::movePoint(int moveX, int moveY)
{
    setCoords(this->getX() + moveX, this->getY() + moveY);
}

//
//  Circle.cpp
//  csc3221cousework2
//
//  Created by Francesco Galassi on 21/01/2021.
//

#include "Circle.hpp"
#include "Square.hpp"
#include <iostream>
using namespace std;

/*
* Contructor calls first the parent construtor and saves the origin of the circle which is the centre.
* Then is saves the radius and the type of the shape
* If no value gets specified it has some default value which are origin and unit radius
*/
Circle::Circle(int x, int y, float radius) : Shape(x, y)
{
    this->radius = radius;
    this->type = Shape::Type::Circle;
}

float Circle::getRadius()
{
    return radius;
}

/*
* Two circles collides if the distance between their centers
* is smaller or equal than the sum of their radiuses
* d <= R1 + R2
* The formula of distance between two points P1(x1, y1) and P2(x2, y2) is given by square root of(x2 ñ x1) * (x2 ñ x1) + (y2 ñ y1) * (y2 ñ y1)
* square root is expensive that's why I am squaring them
* d * d <= R1 * R1 + R2 * R2 + 2 * R1 * R2
* In case we will have a spehere the idea is the same but with 3 dimentions so(x, y, z):
* two spheres collide if the distance between the two centes is less or equal than
* the distance of the two radiuses.
* square root of(x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1) <= R1 + R2
*/
bool Circle::checkCollision(Circle* s2)
{
    // Coordinates and radius for the first circle
    int x1 = this->getX();
    int y1 = this->getY();
    int r1 = this->getRadius();
    // Coordinates and radius for the second circle
    int x2 = s2->getX();
    int y2 = s2->getY();
    int r2 = s2->getRadius();

    // We are checking if the distance between the
    // two centers is less than (or equal to) the sum of the radiuses.
    if ((((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))) <= ((r1 * r1) + (r2 * r2) + 2 * r1 * r2)) {
        return true;
    }
    return false;
}

/*
    A circle and a square collide if:
    1) the square is completely or a little bit inside the circle: the distance between the edge of the square and the centre of the circle is lower or equal than the radius of the circle
    2) the circle is inside the square: the centre of the circle is inside the square
    3) the circle is inside the square but the centre is outside and the square has no corner inside the circle: check distance between them lower than the radius plus half the size (radius, whole size like diameter), considering the square like a circle

    In case of a cube and a spheres I would do pratically the same but in a 3D environment:
    so first check if the vertex of a corner of the cube is inside the sphere checking the distance with the center of the sphere
    then check if the center of the sphere is inside the cube
    last consider the cube like a sphere with the diameter of the same size of the edge of the cube and compare the distance between them and the sum or the readiuses
*/
bool Circle::checkCollision(Square* s2)
{
    // vertices for the square.
    Point* vertices = s2->getVertices();

    // We have to check that the distance between any corner and
    // the center of the circle is less than (or equal to) the radius
    int x1, y1;
    for (int i = 0; i < 4; i++) {
        x1 = vertices[i].getX();
        y1 = vertices[i].getY();
        if ((((x1 - this->getX()) * (x1 - this->getX())) + ((y1 - this->getY()) * (y1 - this->getY()))) <= (((this->getRadius()) * (this->getRadius())))) {
            return true;
        }
    }

    // Let's check if the center of the circle is between the bounds of the square.
    // Checking if the x coordinate is between [x, x + edge].
    if (this->getX() >= vertices[0].getX() && this->getX() <= vertices[3].getX()) {
        // Checking if the y coordinate is between [y, y + edge].
        if (this->getY() >= vertices[0].getY() && this->getY() <= vertices[3].getY()) {
            return true;
        }
    }

    // In this case, we will be treating the square as a circle.
    if (this->checkCollision(new Circle((vertices[3].getX() + vertices[0].getX()) / 2, (vertices[3].getY() + vertices[0].getY()) / 2, ((float)s2->getSize()) / 2)))
        return true;

    return false;
}

/*
* When this shape is moved calling the function move(x,y),
* it calles the function in the Point class to save the new values summing the old position plus the "movement"
*/
void Circle::move(int moveX, int moveY)
{
    this->origin.movePoint(moveX, moveY);
}

/*
* When the circle gets deleted, show information about the circle itself (type) and radius.
* Then prints also the information about its position at that time since they move.
*/
Circle::~Circle()
{
    cout << (Circle*)this;
}

/*
* This function is called to display the values of the circle when two shapes collide
*/
ostream& operator<<(ostream& outStream, Circle* circle)
{
    outStream << "\tCircle : " << endl;
    outStream << "\t\tRadius : " << circle->getRadius() << endl;
    outStream << (Shape*)circle << endl;
    return outStream;
}

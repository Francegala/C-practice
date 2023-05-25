//
//  Square.cpp
//  csc3221cousework2
//
//  Created by Francesco Galassi on 21/01/2021.
//

#include "Square.hpp"
#include "Circle.hpp"
#include <iostream>
using namespace std;
/*
* This constructor saves the lenght of the Square edge and the type
* Base constructor always called first so origin is always initialised (bottom left vertex).
* Then it saves the position of all the vertices in an array,
* since to see if a square collides with another shape I see if any of the vertex is inside the other shape.
*/
Square::Square(int x, int y, int size) : Shape(x, y)
{
    this->size = size;
    this->type = Shape::Type::Square;

    // all four vertices from bottom left to up so the y axes plus the size and same with the x axis plus the size
    vertices[0] = Point(origin.getX(), origin.getY());
    vertices[1] = Point(origin.getX() + size, origin.getY());
    vertices[2] = Point(origin.getX(), origin.getY() + size);
    vertices[3] = Point(origin.getX() + size, origin.getY() + size);

}

/*
    A circle and a square collide if:
    1) the square is completely or a little bit inside the circle: the distance between the edge of the square and the centre of the circle is lower or equal than the radius of the circle
    2) the circle is inside the square: the centre of the circle is inside the square
    3) the circle is inside the square but the centre is outside and the square has no corner inside the circle: check if the distance between them is lower or equal than the radius plus half the size, considering the square like a circle

    In case of a cube and a spheres I would do pratically the same but in a 3D environment:
    so first check if the vertex of a corner of the cube is inside the sphere checking the distance with the center of the sphere
    then check if the center of the sphere is inside the cube
    last consider the cube like a sphere with the diameter of the same size of the edge of the cube and compare the distance between them and the sum or the readiuses
*/
bool Square::checkCollision(Circle* s1)
{
    // vertices for the square.
    Point* vertices = this->getVertices();

    // We have to check that the distance between any corner and
    // the center of the circle is less than (or equal to) the radius
    int x1, y1;
    for (int i = 0; i < 4; i++) {
        x1 = vertices[i].getX();
        y1 = vertices[i].getY();
        if ((((x1 - s1->getX()) * (x1 - s1->getX())) + ((y1 - s1->getY()) * (y1 - s1->getY()))) <= (((s1->getRadius()) * (s1->getRadius())))) {
            return true;
        }
    }

    // Let's check if the center of the circle is between the bounds of the square.
    // Checking if the x coordinate is between [x, x + edge].
    if (s1->getX() >= vertices[0].getX() && s1->getX() <= vertices[3].getX()) {
        // Checking if the y coordinate is between [y, y + edge].
        if (s1->getY() >= vertices[0].getY() && s1->getY() <= vertices[3].getY()) {
            return true;
        }
    }

    // In this case, we will be treating the square as a circle.
    if (s1->checkCollision(new Circle((vertices[3].getX() + vertices[0].getX()) / 2, (vertices[3].getY() + vertices[0].getY()) / 2, ((float)this->getSize()) / 2)))
        return true;

    return false;
}

/*
    Two squares collide in two occasions:
    1) if at least one of the corner of a square is inside the other square
    2) if one square is completely inside the other square

    I check if the coordinates of the edge are inside the shape,
    it's true if the x coordinate of the vertex (of first shape) is greater or equal than the x of the origin of the other square (bottom left vertex)
    but lower then the x coordinate of the bottom right hand side vertex (origin + lenght)
    Same for the y if the y of the vertex is greater or equal than the origin vertex of the second square but lower than y origin + size of square


    In case of two cubes colliding we should check the 3D vertex (x,y,z)
    if the point (point class also chenged to 3D) is inside the cube
    so anywhere with x,y,z coordinates greater or equal (it can also be in a face of the cube) of the origin so bottom left
    but this time lower or equal then three points: point origin x + edge , origin z + edge and oring x,z + edge; same for the y

    There are new checks because now the new point must be inside all the 6 faces.
    so to collide the vertex must have coordinates greater than the face facing down of the cube but smaller of the plane facing up,
    same with the other faces of the cube, considering them as parallel planes.

*/
bool Square::checkCollision(Square* s2)
{
    // Vertices for the first square.
    Point* vertices = this->getVertices();

    for (int i = 0; i < 4; i++) {
        // Checking if the x coordinate is between [x, x + size].
        if (vertices[i].getX() >= s2->getX() && vertices[i].getX() <= s2->getX() + s2->getSize()) {
            // Checking if the y coordinate is between [y, y + size].
            if (vertices[i].getY() >= s2->getY() && vertices[i].getY() <= s2->getY() + s2->getSize()) {
                return true;
            }
        }
    }
    return false;
}

/*
* Move the origin and all the vertices, moving the points one by one.
*/
void Square::move(int moveX, int moveY)
{
    origin.movePoint(moveX, moveY);
    vertices[0].movePoint(moveX, moveY);
    vertices[1].movePoint(moveX, moveY);
    vertices[2].movePoint(moveX, moveY);
    vertices[3].movePoint(moveX, moveY);
}

int Square::getSize()
{
    return size;
}

Point* Square::getVertices()
{
    return this->vertices;
}

/*
* Destructor overrides the shape destructor and it prints all the information about the square
*/
Square::~Square()
{
    cout << (Square*)this;

}

/*
* This function is called to display the values of the circle when two shapes collide
* When the square touches another shape,
* this function outputs the details of the shape.
*/
ostream& operator<<(ostream& outStream, Square* square)
{
    outStream << "\tSquare : " << "\n";
    outStream << "\t\tSize : " << square->getSize() << "\n";
    outStream << (Shape*)square << endl;
    return outStream;
}

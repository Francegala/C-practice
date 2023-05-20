//
//  Point.hpp
//  csc3221cousework2
//
//  Created by Francesco Galassi on 21/01/2021.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
/*
    This class helped me to handle the coordinates of the points.
    To do every check from when creating or moving a shape if it is inside the game board or if two shapes collide, I uses x and y coordinates.
    Whith this class I consider the point (vertex or center) as an object easing every operation
    rather than for example storing them in two different variables of the object or inside an array or 2D array
    like for the square which needs to store x and y for every vertex (every edge).
    To move a coordinate I simply add the increment of the x to the x position and same for the y.

    To implement Cubes and Spheres add a third dimention x,y,z
*/
class Point
{
public:
    Point(int x=0,int y=0);
    
    void setCoords(int x = 0, int y = 0);
    void setX(int x);
    void setY(int y);
    
    int getX();
    int getY();

    void movePoint(int moveX, int moveY);

protected:
    // Like the vector in the first coursework, save x and y coordinates in the space.
    int xCoord;
    int yCoord;

};


#endif /* Point_hpp */

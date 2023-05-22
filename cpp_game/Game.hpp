//
//  Game.hpp
//  csc3221cousework2
//
//  Created by Francesco Galassi on 21/01/2021.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include "Point.hpp"
#include "Shape.hpp"
#include "Circle.hpp"
#include "Square.hpp"
/*
    This Game class stores and provides method to manage a board for the game.
    To start a game the maximum width and height must be specified,
    along with the minimum and maximum size of the shapes since it stores the shapes created inside its vector of shapes.
    Then there is a method to detect when two shapes overlap, it deals with the overlap of 2 circles, 2 squares and a circle and a square.
    I am attaching a document explaining how I imagined the collisions between them.

    The method generateShapes creates several shapes and stores them in a vector.
    The function moveShapes then iterates through the data, move each shape by a small random amount,
    and it checks using checkSquareOrigin and checkCircleOrigin fucntions both square and circle origin to keep them inside the game board.
    The function checkCollision checks to see if there are any shapes overlapping,
    if there are, it removes them from the vector and it calls the descructor that prints all the details about the overlapping shapes.
    The function play checks if there is any shape left to continue the game until at most one shape remains.
*/
class Game
{
public:
    Game(int width = 10, int height = 10, int minSize = 1, int maxSize = 4, int numOfShapes = 3);

    // Generate shapes givng random size and origin
    void generateShapes();
    //checks if there still are shapes in the game
    bool play();
    // move shapes by random number
    void moveShapes();

private:
    // the game board can have shapes in the space from 0 to width-1 and from 0 to height-1
    int width;
    int height;

    int minSize;
    int maxSize;
    int numOfShapes;

    std::vector<Shape*> vectorOfShapes;

    bool checkCircleOrigin(int x, int y, float radius);
    bool checkSquareOrigin(int x, int y, int edge);

    bool checkCollision(Shape* s1, Shape* s2);
};


#endif /* Game_hpp */

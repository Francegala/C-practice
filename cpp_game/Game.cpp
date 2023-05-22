//
//  Game.cpp
//  csc3221cousework2
//
//  Created by Francesco Galassi on 21/01/2021.
//

#include "Game.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

/*
* I created this Game object to be like a board where all the shapes are created.
* To initialise a Game board, the user needs to specify the maximum width and height (from 0);
* to create Shapes the user needs to pick a minumum and a maximum radius/edge for the shapes;
* and finally how many shapes to initialise.
*
* If Game() gets called there are some default values: width = 10,  height = 10,  minSize = 1,  maxSize = 4,  numOfShapes = 3,
* that are a good example of a short game.
*
* I put no constrains but I decided to leave the values empty since there are no limits for generating shapes or for the boards;
* all the checks to have a balanced game like not too many shapes if the game board is small are handled in the main function.
*/
Game::Game(int width, int height, int minSize, int maxSize, int numOfShapes)
{
    // getting values from main class
    this->width = width;
    this->height = height;
    this->minSize = minSize;
    this->maxSize = maxSize;
    this->numOfShapes = numOfShapes;
}

/*
* This method uses the number of shapes variable to add shapes to the vector created to hold them.
* Using a for loop it "flips a coin", it gets a random value from 0 to 1
* if it is 0 it intantiates a Circle, if 1 it instantiates a Square.
* A Square will have its edge calculated randomly considering the minumum and the maximum size.
* A Circle to calculate its radius uses the same formula but divided by two so it's like if the edge of the square would be considered as a diameter.
* The x and y location is based on a random value less than the boundaries from the game board
*
* Before generating the shapes, this function checks using the appropriate function if the location of the shapes is within boundaries.
*/
void Game::generateShapes()
{
    std::cout << "Initializing shapes:\n";
    for (int i = 0; i < numOfShapes; i++) {

        int xPosition, yPosition;
        
        int chooseShape = rand() % 2;
        switch (chooseShape) {
            case 0: // circle
            {
                float radius = ((rand() % (maxSize - minSize)) + minSize + 2) / 2; // random might be 0, minimum might be 0 for any reason so +2 to avoid a number less then 2 to be divided by 2 and return int 0
                do {
                    xPosition = rand() % width;
                    yPosition = rand() % height;
                } while (
                    !checkCircleOrigin(xPosition, yPosition, radius)
                    );
                vectorOfShapes.push_back(new Circle(xPosition, yPosition, radius));
                cout << "Circle, Radius: " << radius << " x: " << xPosition << " y: " << yPosition << "\n";
                break;
            }
            case 1: // square
            {
                int size = rand() % (maxSize - minSize) + minSize + 1; // +1 to avoid being 0 from rand and min size
                    do {
                    xPosition = rand() % width;
                    yPosition = rand() % height;
                    } while (
                        !checkSquareOrigin(xPosition, yPosition, size)
                        );
                vectorOfShapes.push_back(new Square(xPosition, yPosition, size));
                cout << "Square, Size: " << size << " x: " << xPosition << " y: " << yPosition << "\n";
                break;
            }
        }
    }
}

/*
* This function checks if there are shapes remaining in the vector containing shapes of the game and returns true/false.
* Every time is called, it iterates through the shapes in the Game vector to see if they are colliding,
* if so it removes and deletes the shapes printing their values.
*
* Check collision is called not caring of what shapes they are since the differentiation gets done afterwards.
*/
bool Game::play()
{
    cout <<" "<<this->numOfShapes<<" shapes remaining   ---------------------------New turn\n";
    for (int i = 0; i < vectorOfShapes.size(); i++) {
        if (vectorOfShapes[i] != NULL) {
            for (int j = 0; j < vectorOfShapes.size(); j++) {
                if (i != j && vectorOfShapes[j] != NULL) {
                    if (checkCollision(vectorOfShapes[i], vectorOfShapes[j])) {
                        cout << "Collision: " << endl;
                        delete vectorOfShapes[i];
                        delete vectorOfShapes[j];
                        vectorOfShapes[i] = vectorOfShapes[j] = NULL;
                        this->numOfShapes -= 2;
                            break;
                    }
                }
            }
        }
    }
    return this->numOfShapes > 1;
}

/*
* This function is similar to the one to create the shapes,
* it iterates through shapes in the vector and generating random x and y values it checks if the new location in the board would be ok.
* If the actual position of the shape + the movement is still within boudaries it gets saved otherwise a new value gets generated.
*/
void Game::moveShapes()
{
    for (int i = 0; i < vectorOfShapes.size(); i++) {
        if (vectorOfShapes[i] != NULL) {
            int moveX, moveY;
            if (vectorOfShapes[i]->getType() == Shape::Type::Circle) {
                do {

                    int signX = rand() % 2;
                    int signY = rand() % 2;
                    moveX = (rand() % width + 1) * (signX * -1);
                    moveY = (rand() % height + 1) * (signY * -1);
                } while (
                    !checkCircleOrigin( //check for correctness of result if false so outside the map do again the operation
                        vectorOfShapes[i]->getX() + moveX,
                        vectorOfShapes[i]->getY() + moveY,
                        ((Circle*)vectorOfShapes[i])->getRadius()
                    )
                    );
                vectorOfShapes[i]->move(moveX, moveY);
            }
        else if (vectorOfShapes[i]->getType()== Shape::Type::Square) {
                do {
                       
                    int signX = rand() % 2;
                    int signY = rand() % 2;
                    moveX = (rand() % width + 1) * (signX * -1);
                    moveY = (rand() % height + 1) * (signY * -1);

                } while (
                    !checkSquareOrigin(
                        vectorOfShapes[i]->getX() + moveX,
                        vectorOfShapes[i]->getY() + moveY,
                        ((Square*)vectorOfShapes[i])->getSize()
                    )
                    );
                vectorOfShapes[i]->move(moveX, moveY);
            }
        }
    }
}

/*
* Is the origin inside the "map"? if no, false (so outside) recalculate the result.
* it checks if the most left point of the circle is outside (x, so the center minus the radius so move it to the left)
* same for the right point if exceeds the boundary and up and down
*/
bool Game::checkCircleOrigin(int x, int y, float radius) {
    if (x - radius < 0 ||
        x + radius > width - 1 ||
        y - radius < 0 ||
        y + radius > height - 1) {
        return false;
    }
    return true;
}

/*
* Square is easier than the circle because the point we are checking is the the bottom left vertex and must be positive (both x and y values) so inside the board,
* same for the bottom right vertex (x + edge) and one of the two up vertices (y+size).
*/
bool Game::checkSquareOrigin(int x, int y, int size) {
    if (x < 0 ||
        x + size > width - 1 ||
        y < 0 ||
        y + size > height - 1) {
        return false;
    }
    return true;
}

/*
* Ths function receives two Shapes and checking their types calls the appropriate function returning the correct value;
*/
bool Game::checkCollision(Shape* s1, Shape* s2)
{
    if (s1->getType() == Shape::Type::Circle && s2->getType() == Shape::Type::Circle) {
        // Collision between two circles.
        return ((Circle*)s1)->checkCollision((Circle*)s2);
    }

    else if (s1->getType() == Shape::Type::Square && s2->getType() == Shape::Type::Square) {
        // Collision between two squares, must be tested twice because it might happen that one square is inside the other one or viceversa.
        return ((Square*)s1)->checkCollision((Square*)s2) || ((Square*)s2)->checkCollision((Square*)s1);
    }

    else if (s1->getType() == Shape::Type::Circle && s2->getType() == Shape::Type::Square) {
        // Collision between a circle and a square.
        return ((Circle*)s1)->checkCollision((Square*)s2);
    }
    else if (s1->getType() == Shape::Type::Square && s2->getType() == Shape::Type::Circle) {
        // Collision between a square and a circle.
        return ((Square*)s1)->checkCollision((Circle*)s2);
    }

    return false;
}

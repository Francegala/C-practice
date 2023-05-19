//
//  main.cpp
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
* Method to simulate a game, a match.
* The user can select an already created match or can set the values themselves.
*/
int main() {
    // Setting a random seed each time the program starts.
    srand((unsigned int)time(0));

    // variables for game board + shapes size and for number of shapes
    int selection, xMaxBoard, yMaxBoard, minSizeShape, maxSizeShape, numShapes;
    cout << "Welcome to my program! (Student No 170492959)\n";
    Game gm;
    cout << "\nSelect 0 to run an example or 1 to select custom values!\n";
    cin >> selection;
    switch (selection) {
        case 0:
        {
            gm = Game(300, 300, 1, 50, 99);
            break;
        }
        case 1:
        {
            do {
                cout << "\nSelect the range of the board on the x axes! (at least 10)\n";
                cin >> xMaxBoard;
            } while (xMaxBoard < 10);
            do {
                cout << "\n Select the range of the board on the y axes!  (at least 10)\n";
                cin >> yMaxBoard;
            } while (yMaxBoard < 10);
            do {
                cout << "\n Select the minimum edge/radius/size of a Shape !\n";
                cin >> minSizeShape;
            } while (minSizeShape < 1 || minSizeShape >= xMaxBoard || minSizeShape >= yMaxBoard);
            do {
                cout << "\n Select the maximum edge/radius/size of a Shape !\n";
                cin >> maxSizeShape;
            } while (maxSizeShape <= minSizeShape || maxSizeShape >= xMaxBoard - 1 || maxSizeShape >= yMaxBoard - 1);
            do {
                cout << "\n How many shapes do you want to play with? (at least 2 and not too many in relation to the board size)\n";
                cin >> numShapes;
            } while (numShapes < 2 || numShapes >= xMaxBoard / 2 || numShapes >= yMaxBoard / 2);
            //passing above values to Gameboard class
            gm = Game(xMaxBoard, yMaxBoard, minSizeShape, maxSizeShape, numShapes);
            break;
        }
        default:
        {
            gm = Game(); // default values
            break;
        }
    }

    //creating object using create shape method of Gameboard class
    gm.generateShapes();

    //unitil we have at least two shapes let's play
    while (gm.play()) {
        gm.moveShapes();
    }
    cout << "\nEnd of the Game\n";

}


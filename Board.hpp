/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: header file for Board class
 ********************/

#ifndef Board_hpp
#define Board_hpp

#include "Space.hpp"
#include <array>


class Board
{
private:

    Space* board[8][8]; // create dynamic board
    
    // XY coordinates for locations on map
    int farmX;
    int farmY;
    int castleX;
    int castleY;
    
    //Item locations
    
    int swordLocationX;
    int swordLocationY;
    
    int shieldLocationX;
    int shieldLocationY;
    
    int armorLocationX;
    int armorLocationY;
    
    int numNormSpaces;

    Space* now;  // to hold the space that the player is on currently 
    
    bool gameOver;
    bool bundleFound;
    
    void makeBoard();

public:
    
    Board();
    ~Board();
    
    void createRandoms(); // generate random values for locations
    
    void showBoard();
    Space* getNowSpace();
    void updateSpace(Space*);
    bool isOver();

    void foundBundle();
};



#endif /* Board_hpp */

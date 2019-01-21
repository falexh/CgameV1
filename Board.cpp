/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: function implementations for Board class
 ********************/

#include "Board.hpp"

#include "CastleSpace.hpp"
#include "JungleSpace.hpp"
#include "LandSpace.hpp"
#include "FarmSpace.hpp"

#include <cstdlib>
#include <iostream>


Board::Board()
{
    numNormSpaces = 0;
    bundleFound = false;
    gameOver = false;
    makeBoard();
    now = board[farmX][farmY];  // starts the llama at the farm
}

Board::~Board()
{
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            delete board[i][j];
        }
    }
}

/* createRandoms Implementation: Creates randomized spaces for map locations */

void Board::createRandoms()
{
    //create a random location for the farm
    farmX = rand() % 8;
    farmY = rand() % 8;
    
    
    do  // generates another random number if land = farm values
    {
        castleX = rand() % 8;
        castleY = rand() % 8;
        
    }while(castleY == farmY && castleX == farmX);
}

/* makeBoard Implementation: Creates an 8x8 2D array */

void Board::makeBoard() // creates an 8x8 dynamic array 
{
    createRandoms();
    
    //make spaces for board
    
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (j == farmX && i == farmY)
            {
                board[i][j] = new FarmSpace;
            }
            else if (j == castleX && i == castleY)
            {
                board[i][j] = new CastleSpace;
            }
            else
            {
                int rand_ = rand() % 80 + 1;
                
                if (rand_ <= 45)
                {
                    board[i][j] = new LandSpace();
                    numNormSpaces++;
                }
                else
                {
                    board[i][j] = new JungleSpace();
                }
            }
        }
    }
    
    //linkage of squares
    for (int i =0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (i == 0)  // first space
            {
                board[i][j]->setUp(nullptr);
                board[i][j]->setDown(board[i+1][j]);
            }
            else if (i == 7) // last space
            {
                board[i][j]->setUp(board[i-1][j]);
                board[i][j]->setDown(nullptr);
            }
            else
            {
                board[i][j]->setUp(board[i-1][j]);
                board[i][j]->setDown(board[i+1][j]);
            }
            
            if (j == 0)
            {
                board[i][j]->setRight(board[i][j+1]);
                board[i][j]->setLeft(nullptr);
            }
            else if (j == 7)
            {
                board[i][j]->setRight(nullptr);
                board[i][j]->setLeft(board[i][j-1]);
            }
            else
            {
                board[i][j]->setRight(board[i][j+1]);
                board[i][j]->setLeft(board[i][j-1]);
            }
        }
    }
    
}


/* showBoard Implementation: Display characters for each entity   */

void Board::showBoard()
{
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            //if space is taken:
            if (board[i][j]->isActive() == true)
            {
                std::cout << " *";  // * indicates the player
            }

            else if (board[i][j]->getSpace().compare("Land") == 0)
            {
                std::cout << " ~";
            }
            else if (board[i][j]->getSpace().compare("Jungle") == 0)
            {
                std::cout << " ∆";
            }
            else if (board[i][j]->getSpace().compare("Farm") == 0)
            {
                std::cout << " F";
            }
            else if (board[i][j]->getSpace().compare("Castle") == 0)
            {
                std::cout << " C";
            }
            
            if (j==7)
            {
                std::cout << '\n';
            }
        }
    }
    std::cout << '\n';
}

/* getNowSpace Implementation: Returns a pointer to a Space object that the player is currently on.  */
 
Space* Board::getNowSpace()
{
    return now;
}

/* updateSpace Implementation: Sets player location to a new space.   */

void Board::updateSpace(Space* ns)
{
    now = ns;

}

void Board::foundBundle()  // if llama already beat the lizard king and has the bundle
{
    bundleFound = true;
}


bool Board::isOver()  // if the game is beaten, or the llama runs out of health!
{
    return gameOver;
}

/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: header file for Player class
 ********************/

#ifndef Player_hpp
#define Player_hpp

#include "Board.hpp"
#include <string>


class Player
{
private:
    
    std::string bag[4] = {""};  // the llama bag holds the sword, shield, and armor
    Board* board;
    int llamaHealth;
    bool gameOver;
    bool hasBundle;
    
public:
    Player(Board* );
    ~Player();
    
    void inspect();
    void move(char);
    
    bool isGameOver();
    void showBag();
    void displayHealth();
};

#endif /* Player_hpp */

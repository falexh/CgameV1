/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: function implementation for Player Class
 ********************/

#include "Player.hpp"
#include "Space.hpp"

#include <iostream>
#include <string>

Player::Player(Board* board)
{
    this->board = board;
    gameOver = false;
    hasBundle = false;
    llamaHealth = 15;
}

Player::~Player(){}

bool Player::isGameOver()
{
    return gameOver;
}

void Player::showBag() // shows what is in the llama's bag
{
    std::cout << "Your bag contains: " << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (bag[i].compare("") != 0)
        {
            std::cout << bag[i] << std::endl;
        }
    }
}


void Player::inspect()
{
    Space* area = board->getNowSpace();
    
    if(hasBundle == false) // if the llama doesnt have the bundle of hay, so inspectBefore
    {
        if (area->getSpace().compare("Castle")== 0)
        {
            bool isSword = false;
            bool isShield = false;
            bool isArmor = false;
            
            for (int i=0; i<4; i++)
            {
                if(bag[i].compare("Sword")== 0)
                {
                    isSword = true;
                }
                
                if(bag[i].compare("Shield")== 0)
                {
                    isShield = true;
                }
                
                if(bag[i].compare("Armor")== 0)
                {
                    isArmor = true;
                }
            }
            
            //all items are found
            if (isSword && isShield && isArmor)
            {
                bag[3] = area->inspectBefore();
                hasBundle = true;
                board->foundBundle();
            }
            else
            {
                std::cout << "You don't have all the items!" << std::endl;
            }
        }
        else if (area->getSpace().compare("Farm")== 0 || area->getSpace().compare("Jungle") == 0)  //the llama farm restores llama's health and so does the Jungle...the llama finds blueberries there.
        {
            area->inspectBefore();
            llamaHealth = 10; // restores 10 health points back to the llama
        }
        else if (area->getSpace().compare("Land")== 0 )
        {
            std::string val = area->inspectBefore();
            
            if(val.compare("Sword")== 0)
            {
                bag[0] = val;
            }
            else if (val.compare("Shield")== 0)
            {
                bag[1] = val;
            }
            else if (val.compare("Armor")== 0)
            {
                bag[2] = val;
            }
        }
    }
    else  // inspection if llama already has the bundle of hay, so inspectAfter
    {
        std::string num = area->inspectAfter();
        
        if(num.compare("Vanished")== 0)
        {
            std::cout << "There is nothing here!" << std::endl;
        }
        else if (num.compare("Llamified")== 0) // farm replenishes the llama's health
        {
            llamaHealth = 10;
        }
    }
}

void Player::move(char dir)  // for the llama's movement, each move reduces the llama's health by 1
{
    Space* area = board->getNowSpace();
    
    if (toupper(dir) == 'W') // MOVE UP
    {
        //displays error if theres no space upwards
        if (area->getUp() == nullptr)
        {
            std::cout << "Error: Cant go any further! Bad llama!" << std::endl;
        }
        else
        {
            area->setActiveStatus(false);
            (area->getUp())->setActiveStatus(true);
            board->updateSpace(area->getUp());
            llamaHealth--;  // for each move decrease llama health 
        }
    }
    else if (toupper(dir) == 'S') // MOVE DOWN
    {
        if (area->getDown() == nullptr)
        {
            std::cout << "Error: Cant go any futher! Bad llama!" << std::endl;
        }
        else
        {
            area->setActiveStatus(false);
            (area->getDown())->setActiveStatus(true);
            board->updateSpace(area->getDown());
            llamaHealth--;
        }
    }
    else if (toupper(dir) == 'D') // MOVE RIGHT
    {
        if (area->getRight() == nullptr)
        {
            std::cout << "Error: Cant go any further! Bad llama!" << std::endl;
        }
        else
        {
            area->setActiveStatus(false);
            (area->getRight())->setActiveStatus(true);
            board->updateSpace(area->getRight());
            llamaHealth--;
        }
    }
    else if (toupper(dir) == 'A') // MOVE LEFT
    {
        if (area->getLeft() == nullptr)
        {
            std::cout << "Error: Cant go any futher! Bad llama!" << std::endl;
        }
        else
        {
            area->setActiveStatus(false);
            (area->getLeft())->setActiveStatus(true);
            board->updateSpace(area->getLeft());
            llamaHealth--;
        }
    }
   
    // now check what space the player is on
    area = board->getNowSpace();
}

void Player::displayHealth()
{
    std::cout << "Your current health is: " << llamaHealth <<std::endl;
}


/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: function implementations for Space class
 ********************/

#include "Space.hpp"
#include <iostream>

Space::Space(){}

Space::~Space(){}

void Space::setUp(Space* s)
{
    up =  s;
}

Space* Space::getUp()
{
    return up;
}

void Space::setDown(Space* s)
{
    down = s;
}

Space* Space::getDown()
{
    return down;
}

void Space::setRight(Space* s)
{
    right = s;
}

Space* Space::getRight()
{
    return right;
}

void Space::setLeft(Space* s)
{
    left = s;
}

Space* Space::getLeft()
{
    return left; 
}

std::string Space::getSpace()  // returns the name of the space
{
    return space;
}

void Space::setItem(std::string i) // sets item name!
{
    item = i;
}

void Space::setActiveStatus(bool present)  // sets the player status
{
    playerOnSpace = present;
}

bool Space::isActive()  // returns if the player is on space or not
{
    return playerOnSpace;
}

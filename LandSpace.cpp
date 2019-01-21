/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: function implementation for LandSpace class
 ********************/

#include "LandSpace.hpp"
#include <iostream>
#include <string>

LandSpace::LandSpace()
{
    space = "Land";    //occupies most of the map ~
    playerOnSpace = false;

}

LandSpace::~LandSpace(){}

std::string LandSpace::inspectBefore()  // land spaces contain shield and armor
{
    std::cout << "Looking around.." << std::endl;
    
    if(item.compare("Shield")== 0)
    {
        std::cout << "You found the shield!" << std::endl;
        return "Shield";
    }
    else if (item.compare("Armor")== 0)
    {
        std::cout << "You found the armor!" << std::endl;
        return "Armor";
    }
    else
    {
        std::cout << "No items found!" << std::endl;
        return "";
    }
}

std::string LandSpace::inspectAfter()
{
    {
        std::cout << "Nothing is here!" << std::endl;
       
        std::cout << "No lizards are present in this area.." << std::endl;
        return "Vanished";
    }
}

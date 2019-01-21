/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: function implementation for JungleSpace class
 ********************/

#include "JungleSpace.hpp"
#include <iostream>
#include <string>

JungleSpace::JungleSpace()
{
    space = "Jungle";
    playerOnSpace = false;
}

JungleSpace::~JungleSpace(){}

std::string JungleSpace::inspectBefore()
{
    std::cout << "You see a blueberry plant and gain 10 health points!" << std::endl;
    
    std::cout << "Investigating the bushes..." << std::endl;
    
    if (item.compare("Sword") == 0)
    {
        std::cout << "You Found the Great Llama Sword!" << std::endl;
        return "Sword";
    }
    else
    {
        std::cout << "Nothing found!" << std::endl;
        return "";
    }
}

std::string JungleSpace::inspectAfter()
{
    std::cout << "You already found the item in this location. Llama must keep moving!" << std::endl;
    std::cout << "but you still gain 10 health points!" << std::endl;
    return "";
}



/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: function implementation for CastleSpace class
 ********************/

#include "CastleSpace.hpp"
#include <iostream> 

CastleSpace::CastleSpace()
{
    space = "Castle";
    playerOnSpace = false;

}

CastleSpace::~CastleSpace(){}

std::string CastleSpace::inspectBefore()
{
    std::cout << "It looks like you have the tools to defeat the Lizard King!" << std::endl;
    
    std::cout << "........." << std::endl;
    
    std::cout << "You have defeated the Lizard King!" << std::endl;
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "the Lizard King dropped a bundle of hay!" << std::endl; 
    
    return "bundle";
}

std::string CastleSpace::inspectAfter()
{
    std::cout << "You already have the bundle of hay! Bring it back to the farm! " << std::endl;
    return "";
}

/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: function implementation for FarmSpace class
 ********************/

#include "FarmSpace.hpp"
#include <iostream>

FarmSpace::FarmSpace()
{
    space = "Farm";
    playerOnSpace = true;  // llama starts at the farm

}

FarmSpace::~FarmSpace(){}

std::string FarmSpace::inspectBefore()
{
    std::cout << "Gaining llama points...." << std::endl;
    std::cout << "Llama points achieved!" << std::endl;
    
    return "Llamified";
}

std::string FarmSpace::inspectAfter()
{
    std::cout << "Gaining llama points...." << std::endl;
    std::cout << "Llama points achieved!" << std::endl;
    
    return "Llamified";
}

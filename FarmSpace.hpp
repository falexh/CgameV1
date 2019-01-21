/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: header file for FarmSpace class
 ********************/

#ifndef FarmSpace_hpp
#define FarmSpace_hpp

#include "Space.hpp"


class FarmSpace: public Space
{
public:
    
    FarmSpace();
    ~FarmSpace();
    
    std::string inspectBefore();
    std::string inspectAfter();
};



#endif /* FarmSpace_hpp */

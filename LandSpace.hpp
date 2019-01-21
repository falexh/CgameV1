/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: header file for LandSpace class
 ********************/

#ifndef LandSpace_hpp
#define LandSpace_hpp

#include "Space.hpp"


class LandSpace : public Space
{
public:
    
    LandSpace();
    ~LandSpace();
    
    std::string inspectBefore();
    std::string inspectAfter();
};


#endif /* LandSpace_hpp */

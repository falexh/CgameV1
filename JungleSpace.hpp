/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: header file for JungleSpace class
 ********************/

#ifndef JungleSpace_hpp
#define JungleSpace_hpp

#include "Space.hpp"
#include <string> 

class JungleSpace : public Space
{
public:
    JungleSpace();
    ~JungleSpace();
    
    std::string inspectBefore();
    std::string inspectAfter();
    
    
};


#endif /* JungleSpace_hpp */

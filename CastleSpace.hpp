/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: header file for CastleSpace class
 ********************/

#ifndef CastleSpace_hpp
#define CastleSpace_hpp

#include "Space.hpp"
#include <string>

class CastleSpace : public Space
{
public:
    
    CastleSpace();
    ~CastleSpace();
    
    std::string inspectBefore();
    std::string inspectAfter();
};


#endif /* CastleSpace_hpp */

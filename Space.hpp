/****************
 *Author: Forrest Hellard
 *Date: 6/08/2018
 *Description: header file for Space class
 ********************/

#ifndef Space_hpp
#define Space_hpp

#include <string>

// abstract class  with pure virtual functions

class Space
{
protected:
    
    std::string space;
    std::string item;
    bool playerOnSpace;
    Space* up;
    Space* down;
    Space* left;
    Space* right; 
 
    
public:
    
    Space();
    virtual ~Space();
    
    //access,mutator functions for spaces
    void setUp(Space*);
    Space* getUp();
    
    void setDown(Space*);
    Space* getDown();
    
    void setRight(Space*);
    Space* getRight();
    
    void setLeft(Space*);
    Space* getLeft();
    
    
    std::string getSpace();
    
    void setItem(std::string);
    
    bool isActive();
    void setActiveStatus(bool);
    
    virtual std::string inspectBefore()= 0;
    virtual std::string inspectAfter()= 0;
};
#endif /* Space_hpp */

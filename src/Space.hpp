/*******************************************************************************
 * 
 * File:	Space.hpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the specification file for the Space class. 
 * 
 ******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>

#include "utilityFunctions.hpp"
#include "Player.hpp"

class Space 
{
    public:
        Space();
        Space(std::string, int, int);
        virtual ~Space();

        virtual void interact(Player*, 
            const std::vector<std::vector<Space*>> &) = 0;

        void setUp(Space *up);
        void setDown(Space *down);
        void setLeft(Space *left);
        void setRight(Space *right);

        Space* getUp();
        Space* getDown();
        Space* getLeft();
        Space* getRight();
        std::string getName();
        int getXCoord();
        int getYCoord();
        
    protected:
        Space *up;
        Space *down;
        Space *left;
        Space *right;
        std::string name;
        int xCoord;
        int yCoord;

    private:
        std::string translateName(Space*);

};

#endif // SPACE_HPP
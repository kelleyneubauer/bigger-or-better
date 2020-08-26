/*******************************************************************************
 * 
 * File:	Space.cpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the implementation file for the Space class. It contains 
 *      code for the parent class Space. 
 * 
 ******************************************************************************/
#include <iostream>

#include "Space.hpp"

/**
 * 
 * Space::Space()
 * 
 * Summary: 
 * 		This is the default constructor for the Space class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This default constructor sets Space default values
 * 
 **/
Space::Space()
{
	up = down = left = right = nullptr;
    xCoord = 0;
	yCoord = 0;
}

/**
 * 
 * Space::Space()
 * 
 * Summary: 
 * 		This is the default constructor for the Space class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This default constructor sets Space default values
 * 
 **/
Space::Space(std::string name, int xCoord, int yCoord)
{
	up = down = left = right = nullptr;
    this->name = name;
    this->xCoord = xCoord;
    this->yCoord = yCoord;
    // this->graphicsXCoord = graphicsXCoord;
	// this->graphicsYCoord = graphicsYCoord;
}

/**
 * 
 * Space::~Space()
 * 
 * Summary: 
 * 		This is the destructor for the Space class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Destructor
 * 
 **/
Space::~Space()
{

}


/**
 * 
 * void Space::interact(Player* player, 
 *   const std::vector<std::vector<Space*>> &gameMap)
 * 
 * Summary: 
 * 		This is a pure virtual function for the space class.
 * 
 * Parameters:	a pointer to a Player object
 *              a const reference to a 2D vector of pointers to Space objects
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This function outputs the names of the locations to the north, east,
 *      south, and west of player current location
 * 
 **/
void Space::interact(Player* player, 
    const std::vector<std::vector<Space*>> &gameMap)
{
    std::string north, south, east, west;
    north = translateName(
        gameMap[player->getXCoord()][player->getYCoord()]->getUp());
    south = translateName(
        gameMap[player->getXCoord()][player->getYCoord()]->getDown());
    east = translateName(
        gameMap[player->getXCoord()][player->getYCoord()]->getRight());
    west = translateName(
        gameMap[player->getXCoord()][player->getYCoord()]->getLeft());

    std::cout << north << " to the north" << std::endl;
    std::cout << south << " to the south" << std::endl;
    std::cout << east << " to the east" << std::endl;
    std::cout << west << " to the west" << std::endl;
    std::cout << std::endl;
}


/**
 * 
 * std::string Space::translateName(Space* location)
 * 
 * Summary: 
 * 		This function returns the name of the location passed as parameter
 * 
 * Parameters:	a pointer to a Space object
 * 
 * Returns:	    a string for the name of the location
 * 
 * Description:
 * 		This function returns the name of an object. If there is no space in
 *      that location (nullptr) it returns "Nothing"
 * 
 **/
std::string Space::translateName(Space* location)
{
    if(location == nullptr)
    {
        return "Nothing";
    }
    else
    {
        return location->getName();
    }
}


/**
 * 
 * Set functions
 * 
 **/
void Space::setUp(Space *up)
    {
        this->up = up;
    }
void Space::setDown(Space *down)
    {
        this->down = down;
    }
void Space::setLeft(Space *left)
    {
        this->left = left;
    }
void Space::setRight(Space *right)
    {
        this->right = right;
    }

/**
 * 
 * Get functions
 * 
 **/
Space* Space::getUp()
{
	return this->up;
}
Space* Space::getDown()
{
	return this->down;
}
Space* Space::getLeft()
{
	return this->left;
}
Space* Space::getRight()
{
	return this->right;
}

std::string Space::getName()
{
    return name;
}

int Space::getXCoord()
{
    return xCoord;
}
int Space::getYCoord()
{
    return yCoord;
}
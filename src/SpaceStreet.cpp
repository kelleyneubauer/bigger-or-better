/*******************************************************************************
 * 
 * File:	SpaceStreet.cpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the implementation file for the SpaceStreet class. 
 *      This class is derived from the Space class.
 * 
 ******************************************************************************/
#include <iostream>

#include "SpaceStreet.hpp"

/**
 * 
 * SpaceStreet::SpaceStreet()
 * 
 * Summary: 
 * 		This is a constructor for the SpaceStreet class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This derived constructor sets default values 
 * 
 **/
SpaceStreet::SpaceStreet() // : Space()
{
	
}

/**
 * 
 * SpaceStreet::SpaceStreet()
 * 
 * Summary: 
 * 		This is an overload constructor for the SpaceStreet class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This derived constructor sets default values 
 * 
 **/
SpaceStreet::SpaceStreet(std::string name, int xCoord, int yCoord) 
    : Space(name, xCoord, yCoord)
{	

}

/**
 * 
 * SpaceStreet::~SpaceStreet()
 * 
 * Summary: 
 * 		This is the destructor for the SpaceStreet class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Destructor
 * 
 **/
SpaceStreet::~SpaceStreet()
{
	
}


/**
 * 
 * void SpaceStreet::interact(Player* player, 
 *   const std::vector<std::vector<Space*>> &gameMap)
 * 
 * Summary: 
 * 		This is a virtual function override
 * 
 * Parameters:	a pointer to a Player object
 *              a const reference to a 2D vector of pointers to Space objects
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This function calls the default interact and outputs what type of
 *      space is in each direction
 * 
 **/
void SpaceStreet::interact(Player* player, 
    const std::vector<std::vector<Space*>> &gameMap)

{
    Space::interact(player, gameMap);
}
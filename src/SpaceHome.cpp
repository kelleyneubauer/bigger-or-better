/*******************************************************************************
 * 
 * File:	SpaceHome.cpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the implementation file for the SpaceHome class. 
 *      This class is derived from the Space class.
 * 
 ******************************************************************************/
#include <iostream>

#include "SpaceHome.hpp"

/**
 * 
 * SpaceHome::SpaceHome()
 * 
 * Summary: 
 * 		This is a constructor for the SpaceHome class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This derived constructor sets default values 
 * 
 **/
SpaceHome::SpaceHome() // : Space()
{
	
}


/**
 * 
 * SpaceHome::SpaceHome(std::string name, int xCoord, int yCoord, 
 *   std::string itemName) 
 *   : Space(name, xCoord, yCoord)
 * 
 * Summary: 
 * 		This is an overload constructor for the SpaceHome class 
 * 
 * Parameters:	a string for the name of the space
 *              an int for the x coord
 *              an int for the y coord
 *              a string for the item name at this space
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This overload constructor sets initial values
 * 
 **/
SpaceHome::SpaceHome(std::string name, int xCoord, int yCoord, 
    std::string itemName) 
    : Space(name, xCoord, yCoord)
{
    this->itemName = itemName;
}


/**
 * 
 * SpaceHome::~SpaceHome()
 * 
 * Summary: 
 * 		This is the destructor for the SpaceHome class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Destructor
 * 
 **/
SpaceHome::~SpaceHome()
{
	
}


/**
 * 
 * void SpaceHome::interact(Player* player, 
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
 * 		This function outputs a different message whether or not the player
 *      has won the game or still needs to trade for additional items.
 * 
 **/
void SpaceHome::interact(Player* player, 
    const std::vector<std::vector<Space*>> &gameMap)
{
    if (player->hasItem(itemName))
    {
        std::cout << "You made it back with a bike" 
            <<" before dinner at 6:00 PM!" << std::endl;
    }
    else
    {
        std::cout << "Trade up to a bike and make it home"
            << " by dinner at 6:00!" << std::endl;       
    }
    std::cout << std::endl;
}
/*******************************************************************************
 * 
 * File:	SpaceHouse.cpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the implementation file for the SpaceHouse class. 
 *      This class is derived from the Space class.
 * 
 ******************************************************************************/
#include <iostream>

#include "SpaceHouse.hpp"
#include "Menu.hpp"

/**
 * 
 * SpaceHouse::SpaceHouse()
 * 
 * Summary: 
 * 		This is a constructor for the SpaceHouse class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This derived constructor sets default values 
 * 
 **/
SpaceHouse::SpaceHouse() // : Space()
{

}


/**
 * 
 * SpaceHouse::SpaceHouse(std::string name, int xCoord, int yCoord, 
 *   std::string itemName, std::string itemTrade) 
 *   : Space(name, xCoord, yCoord)
 * 
 * Summary: 
 * 		This is an overload constructor for the SpaceHouse class 
 * 
 * Parameters:	a string for the name of the space
 *              an int for the x coord
 *              an int for the y coord
 *              a string for the item name at this space
 *              a string for the item required to make trade
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This overload constructor sets initial values
 * 
 **/
SpaceHouse::SpaceHouse(std::string name, int xCoord, int yCoord, 
    std::string itemName, std::string itemTrade) 
    : Space(name, xCoord, yCoord)
{
    this->itemName = itemName;
    this->itemTrade = itemTrade;
}


/**
 * 
 * SpaceHouse::~SpaceHouse()
 * 
 * Summary: 
 * 		This is the destructor for the SpaceHouse class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Destructor
 * 
 **/
SpaceHouse::~SpaceHouse()
{
	
}


/**
 * 
 * void SpaceHouse::interact(Player* player, 
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
 * 		This function gives the player an option to trade for an item if they
 *      have already obtained a prerequisite item
 * 
 **/
void SpaceHouse::interact(Player* player, 
    const std::vector<std::vector<Space*>> &gameMap)
{
    if(player->hasItem(itemTrade))
    {
        Menu itemMenu(std::vector<std::string>{
            "Yes","No"});

        std::cout << "You have a " << itemTrade << "!" << std::endl;
        std::cout << "Do you want to trade for a " << itemName << "?";
        
        if (itemMenu.getChoice("\n",">") == 1)
        {
            player->removeItem(itemTrade);
            player->addItem(itemName);
        }
        else
        {
            std::cout << "OK, no trade" << std::endl;
            std::cout << std::endl;
        }
        player->printItems();
    }
    else
    {
        std::cout << "You have nothing to trade here" << std::endl;
        std::cout << std::endl;
    }
}


/**
 * 
 * Get functions
 * 
 **/
std::string SpaceHouse::getItemName()
{
    return itemName;
}
std::string SpaceHouse::getItemTrade()
{
    return itemTrade;
}
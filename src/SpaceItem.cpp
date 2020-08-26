/*******************************************************************************
 * 
 * File:	SpaceItem.cpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the implementation file for the SpaceItem class. 
 *      This class is derived from the Space class.
 * 
 ******************************************************************************/
#include <iostream>

#include "SpaceItem.hpp"
#include "Menu.hpp"

/**
 * 
 * SpaceItem::SpaceItem()
 * 
 * Summary: 
 * 		This is a constructor for the SpaceItem class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This derived constructor sets default values 
 * 
 **/
SpaceItem::SpaceItem() // : Space()
{
	
}


/**
 * 
 * SpaceItem::SpaceItem(std::string name, int xCoord, int yCoord, 
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
SpaceItem::SpaceItem(std::string name, int xCoord, int yCoord, 
    std::string itemName) 
    : Space(name, xCoord, yCoord)
{
    this->itemName = itemName;
}

/**
 * 
 * SpaceItem::~SpaceItem()
 * 
 * Summary: 
 * 		This is the destructor for the SpaceItem class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Destructor
 * 
 **/
SpaceItem::~SpaceItem()
{
	
}


/**
 * 
 * void SpaceItem::interact(Player* player, 
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
 * 		This function allows the user to pick up an item
 * 
 **/
void SpaceItem::interact(Player* player, 
    const std::vector<std::vector<Space*>> &gameMap)
{
    Menu itemMenu(std::vector<std::string>{
        "Yes","No"});

    std::cout << "You found a " << itemName << "!" << std::endl;

    if (itemMenu.getChoice("Pick it up?\n", ">") == 1)
    {
        player->addItem(itemName);
    }
    else
    {
        std::cout << itemName << " not added" << std::endl;
        std::cout << std::endl;
    }
    player->printItems();
}
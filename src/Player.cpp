/*******************************************************************************
 * 
 * File:	Player.cpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the implementation file for the Player class. It contains code
 * 		to add and remove items, check for particular items, print the item
 * 		list, set location, and get x and y coordinates
 * 
 * -----------------------------------------------------------------------------
 *  Elements of this code have been adapted from:
 * 
 *  -   Title: How to Find and Erase Item from Vector C++
 *      Author: P0W
 *      Date: 12/26/2014
 *      Availability: https://stackoverflow.com/questions/27659478/
 * 
 ******************************************************************************/
#include <iostream>
#include <algorithm>

#include "Player.hpp"

/**
 * 
 * Player::Player()
 * 
 * Summary: 
 * 		This is the default constructor for the Player class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This default constructor sets Player default values
 * 
 **/
Player::Player()
{
	xCoord = 2;
	yCoord = 2;
	itemsCapacity = 2;
}


/**
 * 
 * Player::~Player()
 * 
 * Summary: 
 * 		This is the destructor for the Player class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Destructor
 * 
 **/
Player::~Player()
{

}


/**
 * 
 * void Player::addItem(std::string itemName)
 * 
 * Summary: 
 * 		This function adds an item to the player's item list
 * 
 * Parameters:	a string for the item name
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This function allows the user to pick up an item
 * 
 **/
void Player::addItem(std::string itemName)
{
	if (static_cast<int>(items.size()) < itemsCapacity)
	{
		items.push_back(itemName);
	}
	else
	{
		std::cout << "No room for additional items" << std::endl;
		std::cout << std::endl;
	}
}

/**
 * 
 * void Player::removeItem()
 * 
 * Summary: 
 * 		This function removes the item at the back of the player list
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This pops the back item
 * 
 **/
void Player::removeItem()
{
	if (items.size() != 0)
	{
		items.pop_back();
	}
}

/*
 *  Adapted code:
 * 
 *  -   Title: How to Find and Erase Item from Vector C++
 *      Author: P0W
 */
/**
 * 
 * void Player::removeItem(std::string itemName)
 * 
 * Summary: 
 * 		This function removes a specific item
 * 
 * Parameters:	a string for the item name
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This searches for a specific item and removes if it exists
 * 
 **/
void Player::removeItem(std::string itemName)
{
	std::vector<std::string>::iterator element;
	element = find(items.begin(), items.end(), itemName);
	if (element != items.end())
	{
		items.erase(element);
	}
}

/**
 * 
 * bool Player::hasItem(std::string itemName)
 * 
 * Summary: 
 * 		This function searches a specific item
 * 
 * Parameters:	a string for the item name
 * 
 * Returns:	    a bool
 * 
 * Description:
 * 		This searches for a specific item and returns true if it exists
 * 
 **/
bool Player::hasItem(std::string itemName)
{
	std::vector<std::string>::iterator element;
	element = find(items.begin(), items.end(), itemName);
	if (element != items.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
 * End adapted code
 */


/**
 * 
 * void Player::printItems()
 * 
 * Summary: 
 * 		This function prints the player item list
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This function prints all current items that player has
 * 
 **/
void Player::printItems()
{
	std::cout << "You have:" << std::endl;
	if (items.size() == 0)
	{
		std::cout << "nothing" << std::endl;
	}
	else
	{
		for (unsigned int i=0; i<items.size(); i++)
		{
			std::cout << "- " << items[i] << std::endl;
		}
		std::cout << std::endl;
	}
}


/**
 * 
 * Set functions
 * 
 **/
void Player::setLocation (int xCoord, int yCoord)
{
	this->xCoord = xCoord;
	this->yCoord = yCoord;
}

/**
 * 
 * Get functions
 * 
 **/
int Player::getXCoord()
{
	return xCoord;
}
int Player::getYCoord()
{
	return yCoord;
}
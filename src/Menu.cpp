/*******************************************************************************
 * 
 * File:	Menu.cpp
 * Author:	Kelley Neubauer
 * Date:	10/9/2019
 * 
 * Description: 
 *      This is the implementation file for the Menu class. It stores the list
 *      of items in the Menu and the total number of items in the Menu.
 *      It contains code that creates Menu objects based on the parameters 
 *      passed in. It has a function that will return user input for a 
 *      Menu choice.
 * 
 ******************************************************************************/

#include"Menu.hpp"
#include"inputValidation.hpp"  // For getInt() function

#include<iostream>
#include<string>

/**
 * 
 * Menu::Menu()
 * 
 * Summary: 
 * 		This is the default constructor for the Menu class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This default constructor sets the min and max values to 0
 * 
 **/
Menu::Menu()
{
   
}
/**
 * 
 * Menu::Menu()
 * 
 * Summary: 
 * 		This is the default constructor for the Menu class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This default constructor sets the min and max values to 0
 * 
 **/
Menu::Menu(std::vector<std::string> inputs)
{
   for (unsigned int i = 0; i<inputs.size(); i++)
   {
	   menu.push_back(inputs[i]);
   }
}



// Destructor
Menu::~Menu()
{
    menu.clear();
}




void Menu::add(std::string inputs)
{
	menu.push_back(inputs);
}

void Menu::remove()
{
	if (!menu.empty())
	{
		menu.pop_back();
	}
}

/**
 * 
 * int Menu::getChoice()
 * 
 * Summary: 
 * 		This function prints a title, the Menu, and a prompt for the user
 *      to make an input. It uses default title and instruction prompt.
 * 
 * Parameters:	none
 * 
 * Returns:	    an int for the choice of the user
 * 
 * Description:
 * 		This function uses a loop to print each of the items in the Menu list.
 * 
 * Example output for - getChoice():
 * 
 *      Select from the following
 *      1. Item 1
 *      2. Item 2
 *      Enter a number for your choice:   
 * 
 **/
int Menu::getChoice()
{
	int choice;
	if (menu.empty())
	{
		std::cout << "Menu is empty" << std::endl;

		choice = -1;
	}
	else
	{
		std::cout << "Select from the following" << std::endl;

		for (unsigned int i = 0; i < menu.size(); i++)
		{
			std::cout << i+1 << ". " << menu[i] << std::endl;
		}

		std::cout << "Enter a number for your choice:" << std::endl;

		choice = getInt(1, menu.size());

	}
	
	return choice;
    
}




/**
 * 
 * int Menu::getChoice(std::string title)
 * 
 * Summary: 
 * 		This function prints a title, the Menu, and a prompt for the user
 *      to make an input. It uses custom title and default instruction prompt.
 * 
 * Parameters:	a string for the custom title
 * 
 * Returns:	    an int for the choice of the user
 * 
 * Description:
 * 		This function uses a loop to print each of the items in the Menu list.
 * 
 * Example output for - getChoice():
 * 
 *      Custom Menu title goes here
 *      1. Item 1
 *      2. Item 2
 *      Enter a number for your choice:   
 * 
 **/
int Menu::getChoice(std::string title)
{
	int choice;
	if (menu.empty())
	{
		std::cout << "Menu is empty" << std::endl;
		choice = -1;
	}
	else
	{
		std::cout << title;

		for (unsigned int i = 0; i < menu.size(); i++)
		{
			std::cout << i+1 << ". " << menu[i] << std::endl;
		}

		std::cout << "Enter a number for your choice:" << std::endl;

		choice = getInt(1, menu.size());
	}
	
    return choice;
}


/**
 * 
 * int Menu::getChoice(std::string title, std::string instruction)
 * 
 * Summary: 
 * 		This function prints a title, the Menu, and a prompt for the user
 *      to make an input. It uses custom title and custom instruction prompt.
 * 
 * Parameters:	a string for the custom title
 *              a string for the custom instruction prompt
 * 
 * Returns:	    an int for the choice of the user
 * 
 * Description:
 * 		This function uses a loop to print each of the items in the Menu list.
 * 
 * Example output for - getChoice():
 * 
 *      Custom Menu title goes here
 *      1. Item 1
 *      2. Item 2
 *      Custom instruction prompt goes here   
 * 
 **/
int Menu::getChoice(std::string title, std::string instruction)
{
	int choice;
	if (menu.empty())
	{
		std::cout << "Menu is empty" << std::endl;
		choice = -1;
	}
	else
	{
		std::cout << title;

		for (unsigned int i = 0; i < menu.size(); i++)
		{
			std::cout << i+1 << ". " << menu[i] << std::endl;
		}

		std::cout << instruction;

		choice = getInt(1, menu.size());
	}

	return choice;
	
    
}


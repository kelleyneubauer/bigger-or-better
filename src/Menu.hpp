/*******************************************************************************
 * 
 * File:	Menu.hpp
 * Author:	Kelley Neubauer
 * Date:	10/9/2019
 * 
 * Description: 
 *      This is the specification file for the Menu class.
 * 
 ******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include<vector>


class Menu
{
    public:

		// Default constructor
		Menu();

		Menu(std::vector<std::string>);

		// Destructor
		~Menu();

		void add(std::string);
		void remove();

		// Get user input with default title and instruction
		int getChoice();

		// Get user input with custom title
		int getChoice(std::string title);

		// Get user input with custom title and instrution
		int getChoice(std::string title, std::string instruction);





	private:

		std::vector<std::string> menu;



};


#endif
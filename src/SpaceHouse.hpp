/*******************************************************************************
 * 
 * File:	SpaceHouse.hpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the specification file for the SpaceHouse class. 
 *      It is derived from the Space class.
 * 
 ******************************************************************************/
#ifndef SPACE_HOUSE_HPP
#define SPACE_HOUSE_HPP

#include "Space.hpp"

class SpaceHouse : public Space
{
	public:
		SpaceHouse();
		SpaceHouse(std::string, int, int, std::string, std::string);
		~SpaceHouse();

		// Virtual
		void interact(Player*, const std::vector<std::vector<Space*>> &);

	private:
		std::string itemName;
		std::string itemTrade;
		
		std::string getItemName();
		std::string getItemTrade();};

#endif // SPACE_HOUSE_HPP

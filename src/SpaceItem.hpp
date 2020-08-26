/*******************************************************************************
 * 
 * File:	SpaceItem.hpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the specification file for the SpaceItem class. 
 *      It is derived from the SpaceHouse class.
 * 
 ******************************************************************************/
#ifndef SPACE_ITEM_HPP
#define SPACE_ITEM_HPP

#include "SpaceHouse.hpp"

class SpaceItem : public Space
{
	public:
		SpaceItem();
		SpaceItem(std::string, int, int, std::string);
		~SpaceItem();

		// Virtual
		void interact(Player*, const std::vector<std::vector<Space*>> &);

	private:
		std::string itemName;
};

#endif // SPACE_STORE_HPP

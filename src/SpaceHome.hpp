/*******************************************************************************
 * 
 * File:	SpaceHome.hpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the specification file for the SpaceHome class. 
 *      It is derived from the Space class.
 * 
 ******************************************************************************/
#ifndef SPACE_HOME_HPP
#define SPACE_HOME_HPP

#include "Space.hpp"

class SpaceHome : public Space
{
	public:
		SpaceHome();
		SpaceHome(std::string, int, int, std::string);
		~SpaceHome();

		// Virtual
		void interact(Player*, const std::vector<std::vector<Space*>> &);

	private:
		std::string itemName;
};

#endif // SPACE_HOME_HPP

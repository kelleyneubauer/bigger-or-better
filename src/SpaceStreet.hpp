/*******************************************************************************
 * 
 * File:	SpaceStreet.hpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the specification file for the SpaceStreet class. 
 *      It is derived from the Space class.
 * 
 ******************************************************************************/
#ifndef SPACE_STREET_HPP
#define SPACE_STREET_HPP

#include "Space.hpp"

class SpaceStreet : public Space
{
    
	public:
		// Default constructor prototype
		SpaceStreet();
		SpaceStreet(std::string, int, int);
		~SpaceStreet();

		// Virtual
		void interact(Player*, const std::vector<std::vector<Space*>> &);

	private:
};

#endif // SPACE_STREET_HPP

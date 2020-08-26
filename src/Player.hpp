/*******************************************************************************
 * 
 * File:	Player.hpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the specification file for the Player class. 
 * 
 ******************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>

class Player 
{
    public:
        Player();
        ~Player();

		void addItem(std::string);
		void removeItem();
		void removeItem(std::string);
		bool hasItem(std::string);
		void printItems();

		void setLocation (int, int);
		int getXCoord();
		int getYCoord();

    protected:

    private:
		int xCoord;
		int yCoord;
		std::vector<std::string> items;
		int itemsCapacity; 
};

#endif // PLAYER_HPP

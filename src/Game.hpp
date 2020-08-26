/*******************************************************************************
 * 
 * File:	Game.hpp
 * Author:	Kelley Neubauer
 * Date:	11/13/2019
 * 
 * Description: 
 *      This is the specification file for the Game class. 
 * 
 ******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "Space.hpp"

class Game 
{
    public:
        Game();
        ~Game();

        void start();
        void play();
        
    private:

        void setTimes(std::vector<std::string>&);
        void linkSpaces(const std::vector<std::vector<Space*>>&);
        bool moveValid(Space*);
};

#endif // GAME_HPP

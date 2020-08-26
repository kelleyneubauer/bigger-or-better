/*******************************************************************************
 * 
 * File:	Game.cpp
 * Author:	Kelley Neubauer
 * Date:	12/5/2019
 * 
 * Description: 
 *      This is the implementation file for the Game class. 
 *      This file contains code that runs the Bigger or Better game. 
 *      Objective: trade up your item until you have a bike. Get home for dinner
 *      by 6:00 PM. 
 * 
 * -----------------------------------------------------------------------------
 *  Elements of this code & graphic design have been adapted from:
 * 
 *  -   Title: ASCII Art Archive - Houses
 *      Author: Unknown
 *      Date: Unknown
 *      Availability: https://www.asciiart.eu/buildings-and-places/houses
 * 
 *  -   Title: ASCII Art Dictionary - Trashcan
 *      Author: ptr
 *      Date: Unknown
 *      Availability: http://www.ascii-art.de/ascii/t/trashcan.txt
 * 
 *  -   Title: Text to ASCII Art Generator
 *      Author: Unknown
 *      Date: Unknown
 *      Availability: http://patorjk.com/software/taag/
 *      Additional Info:
 *          Small by Glenn Chappell 4/93 -- based on Standard
 *          Includes ISO Latin-1
 *          figlet release 2.1 -- 12 Aug 1994
 *          Permission is hereby given to modify this font, as long as the
 *          modifier's name is placed on a comment line.
 *
 *          Modified by Paul Burton <solution@earthlink.net> 
 *          12/96 to include new parameter supported by FIGlet and FIGWin.  
 *          May also be slightly modified for better use of new full-width/kern
 *          /smush alternatives, but default output is NOT changed.
 * 
 * -----------------------------------------------------------------------------
 * 
 * Any use of copyrighted material is done so under the fair use act.
 * 
 ******************************************************************************/
#include <iostream>
#include <ios>

#include "Game.hpp"
#include "Menu.hpp"
#include "utilityFunctions.hpp"
#include "Graphics.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include "SpaceHome.hpp"
#include "SpaceHouse.hpp"
#include "SpaceItem.hpp"
#include "SpaceStreet.hpp"

/**
 * 
 * Game::Game()
 * 
 * Summary: 
 * 		This is the default constructor for the Game class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This default constructor sets sets seed time for rand()
 * 
 **/
Game::Game()
{
    // Seed for random number generator
    srand(time(0));
}


/**
 * 
 * Game::~Game()
 * 
 * Summary: 
 * 		This is the destructor for the Game class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		The destructor frees dynamically allocate memory used for the Game
 * 
 **/
Game::~Game()
{
  
}


/**
 * 
 * void Game::start()
 * 
 * Summary: 
 * 		This function starts the game
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Prints game title graphics and gives user option to start game
 * 
 **/
void Game::start()
{
    Menu startMenu(std::vector<std::string>{"Play","Exit"});

    Graphics titleGraphics("graphicsTitle.txt");
    titleGraphics.print();

    if(startMenu.getChoice("\n",">") != 2)
    {
        play();
    }
}

/**
 * 
 * void Game::play()
 * 
 * Summary: 
 * 		This function begins gameplay
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This dictates game activity
 * 
 **/
void Game::play()
{
   // Move menu
    Menu gameMoveMenu(std::vector<std::string>{
        "Move up","Move down", "Move left", "Move right", 
        "Interact", "Print item list", "Quit"});

    int choice = 0;

    // Set step limit
    std::vector<std::string> time;
    setTimes(time);
    int moveLimit = time.size();
    int moveCount = 0;

    // Set game status
    bool gameWon = false;

    // Create player object and set starting parameters
    Player player1;
    player1.setLocation(2,2);
    player1.addItem("Paperclip");

    // Create game map and link Space pointers
    std::vector<std::vector<Space*>> gameMap{
        {new SpaceHouse("Bungalow",0,0,"TV","Card Collection"), 
            new SpaceHouse("Estate",0,1,"Book","Paperclip"), 
            new SpaceHouse("Shack",0,2,"Toy","Penny")},
        {new SpaceStreet("Street",1,0), 
            new SpaceItem("Street",1,1,"Penny"), 
            new SpaceStreet("Street",1,2)},
        {new SpaceHouse("Cottage",2,0,"Bike","TV"), 
            new SpaceHouse("Neighbor",2,1,"Card Collection","Book"), 
            new SpaceHome("Home",2,2,"Bike")}
    };

    linkSpaces(gameMap);

    // Create map graphics object
    Graphics mapGraphics("graphicsMap.txt");

    // Game objective
    lineBreak('-',80);
    std::cout << "Bigger or better:" << std::endl
        << "- Your objective is to go door to door and trade for an item" 
        << std::endl
        << " that is bigger or better than what you currently have."<< std::endl
        << "- Start with a paperclip and" << std::endl
        << " continue trading until you have a bike." << std::endl
        << "- Be sure to get home for dinner by 6:00 PM!" << std::endl;
    lineBreak('-',80);
    lineBreak();
    pressEnterToContinue("Press enter to begin...");

    

    while (moveCount < moveLimit && gameWon != true && choice != 7)
    {
        bool valid = false;

        while (!valid && choice !=7)
        {
            // Print map, current location, and time
            lineBreak('-',80);
            mapGraphics.print(player1.getXCoord(), player1.getYCoord());
            lineBreak('-',80);
            std::cout << "Location: " 
                << gameMap[player1.getXCoord()][player1.getYCoord()]->getName(); 
            std::cout.width(50); std::cout << std::right 
                << "Time: " << time[moveCount] << std::endl;
            lineBreak('-',80);


            choice = gameMoveMenu.getChoice("What would you like to do?\n",">");
           
            switch (choice)
            {
                // Move up
                case 1:
                {
                    if (moveValid(gameMap[player1.getXCoord()]
                        [player1.getYCoord()]->getUp()))
                    {
                        player1.setLocation(player1.getXCoord() - 1,
                            player1.getYCoord());
                        valid = true;
                    }
                    else
                    {
                        pressEnterToContinue();
                    }
                    break;
                }
                // Move down
                case 2:
                {
                    if (moveValid(gameMap[player1.getXCoord()]
                        [player1.getYCoord()]->getDown()))
                    {
                        player1.setLocation(player1.getXCoord() + 1,
                            player1.getYCoord());
                        valid = true;
                    }
                    else
                    {
                        pressEnterToContinue();
                    }
                    break;
                }
                // Move left
                case 3:
                {
                    if (moveValid(gameMap[player1.getXCoord()]
                        [player1.getYCoord()]->getLeft()))
                    {
                        player1.setLocation(player1.getXCoord(),
                            player1.getYCoord() - 1);
                        valid = true;
                    }
                    else
                    {
                        pressEnterToContinue();
                    }
                    break;
                }
                // Move right
                case 4:
                {
                    if (moveValid(gameMap[player1.getXCoord()]
                        [player1.getYCoord()]->getRight()))
                    {
                        player1.setLocation(player1.getXCoord(),
                            player1.getYCoord() + 1);
                        valid = true;
                    }
                    else
                    {
                        pressEnterToContinue();
                    }
                    break;
                }
                // Interact
                case 5:
                {
                    gameMap[player1.getXCoord()][player1.getYCoord()]->
                        interact(&player1, gameMap);
                    if (gameMap[player1.getXCoord()][player1.getYCoord()]->
                        getName() == "Home" && player1.hasItem("Bike"))
                    {
                        gameWon = true;
                        valid = true;
                    }
                    pressEnterToContinue();
                    break;
                }
                // Print items
                case 6:
                {
                    player1.printItems();
                    pressEnterToContinue();
                    break;
                }
                // Quit
                case 7:
                {
                    break;
                }
                default:
                {
                    break;
                }
            }
        }    
        moveCount++;
    }

    if (gameWon == false && choice !=7)
    {
        std::cout << "You didn't make it home for dinner!" << std::endl;
        std::cout << "You lose :(" << std::endl;
        std::cout << std::endl;
        pressEnterToContinue("Press enter");
    }

    if (gameWon == true)
    {
        std::cout << "You win!" << std::endl;
        std::cout << std::endl;
        pressEnterToContinue("Press enter");
    }


    // Delete map, free dynamic memory
    for (unsigned int i=0; i<gameMap.size(); i++)
    {
        for (unsigned int j=0; j<gameMap[i].size(); j++)
        {
            delete gameMap[i][j];
        }
    }
    start();
}


/**
 * 
 * void Game::setTimes(std::vector<std::string> &vect)
 * 
 * Summary: 
 * 		This funciton fills a vector with clock times 
 * 
 * Parameters:	a reference to a vector of strings
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This function initializes a vector with clock times for every 15 min
 *      from 9:00 AM to 6:00 PM
 * 
 **/
void Game::setTimes(std::vector<std::string> &vect)
{
    vect = {
        "9:00 AM","9:15 AM","9:30 AM","9:45 AM",
        "10:00 AM","10:15 AM","10:30 AM","10:45 AM",
        "11:00 AM","11:15 AM","11:30 AM","11:45 AM",
        "12:00 PM","12:15 PM","12:30 PM","12:45 PM",
        "1:00 PM","1:15 PM","1:30 PM","1:45 PM",
        "2:00 PM","2:15 PM","2:30 PM","2:45 PM",
        "3:00 PM","3:15 PM","3:30 PM","3:45 PM",
        "4:00 PM","4:15 PM","4:30 PM","4:45 PM",
        "5:00 PM","5:15 PM","5:30 PM","5:45 PM",
        "6:00 PM"};
}


/**
 * 
 * void Game::linkSpaces(const std::vector<std::vector<Space*>>& gameMap)
 * 
 * Summary: 
 * 		This function links Space objects based on their position in a 
 *      2D vector grid.
 * 
 * Parameters:	a const 2D vector of pointers to Space objects
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This function links each of the up, down, left, and right Space 
 *      object pointers based on it's position in the 2D vector. The space
 *      object in position [0][0] will be assigned nullptr for up and left, 
 *      a pointer to [0][1] for right, and a pointer to [1][0] for down.
 * 
 **/
void Game::linkSpaces(const std::vector<std::vector<Space*>>& gameMap)
{
    // Link game map
    for(unsigned int i=0; i<gameMap.size(); i++)
    {
        // Set rights
        for(unsigned int j=0; j<(gameMap[i].size()-1); j++)
        {
            gameMap[i][j]->setRight(gameMap[i][j+1]);
        }
        // Set lefts
        for(unsigned int j=1; j<gameMap[i].size(); j++)
        {
            gameMap[i][j]->setLeft(gameMap[i][j-1]);
        }
        // Set ups
        if (i>0)
        {
            for(unsigned int j=0; j<gameMap[i].size(); j++)
            {
                gameMap[i][j]->setUp(gameMap[i-1][j]);
            }
        }
        // Set downs
        if (i<gameMap.size()-1)
        {
            for(unsigned int j=0; j<gameMap[i].size(); j++)
            {
                gameMap[i][j]->setDown(gameMap[i+1][j]);
            }
        }
    }
}


/**
 * 
 * bool Game::moveValid (Space *moveTo)
 * 
 * Summary: 
 * 		This function checks to see if there is a valid move
 * 
 * Parameters:	a pointer to a Space object
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		If there is a space object that can be moved to it returns true, if
 *      the desired move has nullptr, it returns false.
 * 
 **/
bool Game::moveValid (Space *moveTo)
{
    bool valid = false;

    if (moveTo != nullptr)
    {
        valid = true;
    }
    else
    {
        std::cout << "You can't move there" << std::endl;
    }
    return valid;
}
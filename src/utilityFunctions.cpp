/*******************************************************************************
 * 
 * File:	utilityFunctions.cpp
 * Author:	Kelley Neubauer
 * Date:	11/5/2019
 * 
 * Description: 
 *      This is the implementation file for my utilityFunctions file. It
 *      contains code that provides utility functions. 
 * 
 ******************************************************************************/

#include"utilityFunctions.hpp"

#include<iostream>
// #include<string>
// #include<cctype> // for isdigit()
// #include<limits>
// #include <ctime> // for rand seed
#include <cstdlib> // for rand number




/**
 * 
 * int randomNumber(int min, int max)
 * 
 * Summary: 
 * 		This function generates a random number between min and max values
 * 
 * Parameters:	an int for min number in range
 * 				an int for max number in range
 * 				
 * Returns:	    an int
 * 
 * Description:
 * 		Uses seeded rand to generate number
 * 
 **/
int randomNumber(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

/**
 * 
 * int dieRoll(int sides)
 * 
 * Summary: 
 * 		This function generates a random number between 1 and number of sides
 * 
 * Parameters:	an int for the number of sides
 * 				
 * Returns:	    an int
 * 
 * Description:
 * 		Uses seeded rand to generate number
 * 
 **/
int dieRoll(int sides)
{
	return (rand() % (sides - 1 + 1)) + 1;
}


/**
 * 
 * void pressEnterToContinue()
 * 
 * Summary: 
 * 		This function holds the screen until the user presses enter
 * 
 * Parameters:	none
 * 				
 * Returns:	    nothing
 * 
 * Description:
 * 		Press enter to continue
 * 
 **/
void pressEnterToContinue()
{
    std::cout << "Press enter to continue..." << std::endl;
    // std::cin.ignore();
    std::string temp;
    std::getline(std::cin, temp);
}


/**
 * 
 * void pressEnterToContinue(std::string phrase)
 * 
 * Summary: 
 * 		This function holds the screen until the user presses enter
 * 
 * Parameters:	none
 * 				
 * Returns:	    nothing
 * 
 * Description:
 * 		Press enter to continue
 * 
 **/
void pressEnterToContinue(std::string phrase)
{
    std::cout << phrase << std::endl;
    // std::cin.ignore();
    std::string temp;
    std::getline(std::cin, temp);
}



void lineBreak()
{
    std::cout << std::endl;
}

void lineBreak(int lines)
{
    for (int i=0; i<lines; i++)
    {
        std::cout << std::endl;
    }
}

void lineBreak(char thing)
{
    for (int i=0; i<30; i++)
    {
        std::cout << thing;
    }
    std::cout << std::endl;
}

void lineBreak(char thing1, char thing2)
{
    for (int i=0; i<30; i+=2)
    {
        std::cout << thing1 << thing2;
    }
    std::cout << std::endl;
}

void lineBreak(char thing, int num)
{
    for (int i=0; i<num; i++)
    {
        std::cout << thing;
    }
    std::cout << std::endl;
}

void lineBreak(char thing1, char thing2, int num)
{
    for (int i=0; i<num; i++)
    {
        std::cout << thing1;
        i+=1;

        if(i<num)
        {
            std::cout << thing2;
        }
    }
    std::cout << std::endl;
}



/*******************************************************************************
 * 
 * File:	utilityFunctions.hpp
 * Author:	Kelley Neubauer
 * Date:	11/5/2019
 * 
 * Description: 
 * 		This is the header file for my utilityFunctions.
 * 
 ******************************************************************************/

#ifndef UTILITY_FUNCTIONS_HPP
#define UTILITY_FUNCTIONS_HPP

// #include <ctime> // for rand seed
// #include <cstdlib> // for rand number
#include <string>

int randomNumber(int min, int max);
int dieRoll(int sides);

void pressEnterToContinue();
void pressEnterToContinue(std::string);

void lineBreak();
void lineBreak(int);
void lineBreak(char);
void lineBreak(char, char);
void lineBreak(char, int);
void lineBreak(char, char, int);


// void doubleArraySize(int*, int);


#endif
/*******************************************************************************
 * 
 * File:	Graphics.cpp
 * Author:	Kelley Neubauer
 * Date:	12/6/2019
 * 
 * Description: 
 *      This is the implementation file for the Graphics class. It contains code
 *      that reads a text file into a vector of char and has functions to read,
 *      clear, and print the 2D char vector.
 * 
 ******************************************************************************/
#include <iostream>
#include <fstream>

#include "Graphics.hpp"

/**
 * 
 * Graphics::Graphics()
 * 
 * Summary: 
 * 		This is the default constructor for the Graphics class
 * 
 * Parameters:	a string for a file name
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		This default constructor reads the file into the 2D vector of char
 * 
 **/
Graphics::Graphics(std::string fileName)
{
	read(fileName);
}

    
/**
 * 
 * Graphics::~Graphics()
 * 
 * Summary: 
 * 		This is the destructor for the Graphics class 
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		The destructor frees dynamically allocate memory used if applicable
 * 
 **/
Graphics::~Graphics()
{

}


/**
 * 
 * void Graphics::read(std::string fileName)
 * 
 * Summary: 
 * 		This function reads the contents of a text file into a 2D vector of char
 * 
 * Parameters:	a string for the name of the file
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Reads char into automatically sized 2D vector of char. Optimized for
 *      80 char length lines.
 * 
 **/
void Graphics::read(std::string fileName)
{
    std::string inputLine;
    std::ifstream ifText;
	
    ifText.open(fileName);

    while (ifText.peek() != EOF)
    {
        std::vector<char> row(80);

        std::getline(ifText, inputLine);

        for (unsigned int i=0; i<row.size(); i++)
        {
            if (i < inputLine.length())
            {
                row[i] = inputLine[i];
            }
            else
            {
                row[i] = ' ';
            }
        }
        graphicMatrix.push_back(row);
    }
    ifText.close();
}


/**
 * 
 * void Graphics::clear()
 * 
 * Summary: 
 * 		This function clears the contents of a 2D vector
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Clears contents of vector using vector member functions.
 * 
 **/
void Graphics::clear()
{
    for (unsigned int i=0; i<graphicMatrix.size(); i++)
    {
        graphicMatrix[i].clear();
    }
    graphicMatrix.clear();
}


/**
 * 
 * void Graphics::print()
 * 
 * Summary: 
 * 		This function prints the contents of a 2D vector
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Uses nested for loops and vector.size()
 * 
 **/
void Graphics::print()
{
	for (unsigned int i=0; i<graphicMatrix.size(); i++)
	{
		for (unsigned int j=0; j<graphicMatrix[i].size(); j++)
		{
			std::cout << graphicMatrix[i][j];
		}
		std::cout << std::endl;
	}
}


/**
 * 
 * void Graphics::print(int xCoord, int yCoord)
 * 
 * Summary: 
 * 		This function prints the contents of a 2D vector with the character
 *      graphics at the specificed location
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 		Uses nested for loops and vector.size()
 * 
 **/
void Graphics::print(int xCoord, int yCoord)
{
    convertToPrint(xCoord, yCoord);

    for (int i=0; i<static_cast<int>(graphicMatrix.size()); i++)
    {
        for (int j=0; j<static_cast<int>(graphicMatrix[i].size()); j++)
        {
            if (i==xCoord && j==yCoord)
            {
                std::cout << ' ' << ' ' << ' ';
                j+=2;
            }
            else if (i==xCoord+1 && j==yCoord)
            {
                std::cout << ' ' << 'o' << ' ';
                j+=2; 
            }
            else if (i==xCoord+2 && j==yCoord)
            {
                std::cout << '/' << '|' << '\\';
                j+=2; 
            }
            else if (i==xCoord+3 && j==yCoord)
            {
                std::cout << '/' << ' ' << '\\';
                j+=2; 
            }
            else
            {
                std::cout << graphicMatrix[i][j];
            }
        }
        std::cout << std::endl;
    }
}


/**
 * 
 * void Graphics::convertToPrint(int &xCoord, int &yCoord)
 * 
 * Summary: 
 * 		This function converts the vector map coordinates to the coordinates
 *      in the graphics where the person graphic will be displayed
 * 
 * Parameters:	none
 * 
 * Returns:	    nothing
 * 
 * Description:
 * 
 **/
void Graphics::convertToPrint(int &xCoord, int &yCoord)
{
    if (xCoord == 0 && yCoord == 0)
    {
        xCoord = 6;
        yCoord = 8;
    }
    else if (xCoord == 0 && yCoord == 1)
    {
        xCoord = 6;
        yCoord = 48;
    }
    else if (xCoord == 0 && yCoord == 2)
    {
        xCoord = 6;
        yCoord = 69;
    }
    else if (xCoord == 1 && yCoord == 0)
    {
        xCoord = 8;
        yCoord = 14;
    }
    else if (xCoord == 1 && yCoord == 1)
    {
        xCoord = 8;
        yCoord = 39;
    }
    else if (xCoord == 1 && yCoord == 2)
    {
        xCoord = 8;
        yCoord = 63;
    }
    else if (xCoord == 2 && yCoord == 0)
    {
        xCoord = 10;
        yCoord = 2;
    }
    else if (xCoord == 2 && yCoord == 1)
    {
        xCoord = 10;
        yCoord = 33;
    }
    else if (xCoord == 2 && yCoord == 2)
    {
        xCoord = 10;
        yCoord = 66;
    }
    else
    {
    }
}
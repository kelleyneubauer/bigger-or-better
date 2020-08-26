/*******************************************************************************
 * 
 * File:	Graphics.hpp
 * Author:	Kelley Neubauer
 * Date:	10/9/2019
 * 
 * Description: 
 *      This is the specification file for the Graphics class.
 * 
 ******************************************************************************/
#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <string>
#include <vector>

class Graphics
{
    public:
		Graphics(std::string);
		~Graphics();

		void read(std::string);
		void clear();

		void print();
		void print(int, int);
		// void convertToPrint(int&, int&);

	private:
		std::vector<std::vector<char>> graphicMatrix;
		
		void convertToPrint(int&, int&);
};

#endif // GRAPHICS_HPP
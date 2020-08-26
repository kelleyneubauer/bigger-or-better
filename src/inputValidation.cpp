/*******************************************************************************
 * 
 * File:	inputValidation.cpp
 * Author:	Kelley Neubauer
 * Date:	10/1/2019
 * 
 * Description: 
 *      This is the implementation file for my inputValidation function. It
 *      contains code that will validate user input for various types. 
 * 
 ******************************************************************************/

#include"inputValidation.hpp"
#include<iostream>
#include<string>
#include<cctype> // for isdigit()
#include<limits>


bool willConvertInt(std::string input);
bool hasUnsignedLeadingZero (std::string input);
bool hasSignedLeadingZero (std::string input);
bool allIsUnsignedDigit (std::string input);
bool allIsSignedDigit (std::string input);
bool hasDigit (std::string input);
bool hasAlpha (std::string input);
bool hasWhiteSpace (std::string input);


/**
 * 
 * int getInt()
 * 
 * Summary: 
 * 		This function validates user input for integers. It loops until a valid
 *      integer is entered by the user.
 * 
 * Parameters:	none
 * 
 * Returns:	    an integer
 * 
 * Description:
 * 		This function collects user input as a string and checks each character
 *      against rules for integers. If all rules are passed it will convert
 *      the string to an integer and return that value.
 * 
 **/

int getInt()
{
    int status = 0;
    std::string userInput;
    int conversion = 0;

    do {
        std::getline(std::cin, userInput);

        if (!(allIsSignedDigit(userInput)))
        {
            status = 0;
        }
        else if (hasUnsignedLeadingZero(userInput))
        {
            status = 0;
        }
        else if (hasSignedLeadingZero(userInput))
        {
            status = 0;
        }
        else if (!(willConvertInt(userInput)))
        {
            status = 0;
        }
        else
        {
            status = 1;
        }

        // If any tests fail display error message
        if (status == 0)
        {
            std::cout << "Please enter a valid integer: ";
        }

    } while (status == 0);

    conversion = std::stoi(userInput);

    // Extra break for formatting
    std::cout << std::endl;

    return conversion;

}


/**
 * 
 * int getInt(int min, int max)
 * 
 * Summary: 
 * 		This function validates user input for integers within a specified
 *      range. It loops until a valid integer is entered by the user.
 * 
 * Parameters:	an integer for the minimum value allowed
 *              and an integer for the maximum value allowed
 * 
 * Returns:	    an integer
 * 
 * Description:
 * 		This function collects user input as a string and checks each character
 *      against rules for integers. If all rules are passed it will convert
 *      the string to an integer and return that value. It uses nested do while
 *      loop to validate that input is an integer and then check that the
 *      integer is within the specified range.
 * 
 **/

int getInt(int min, int max)
{
    int status = 0;
    std::string userInput;
    int conversion = 0;

    do{
        do {
            std::getline(std::cin, userInput);

            if (!(allIsSignedDigit(userInput)))
            {
                status = 0;
            }
            else if (hasUnsignedLeadingZero(userInput))
            {
                status = 0;
            }
            else if (hasSignedLeadingZero(userInput))
            {
                status = 0;
            }
            else if (!(willConvertInt(userInput)))
            {
                status = 0;
            }
            else
            {
                status = 1;
            }

            // If any tests fail display error message
            if (status == 0)
            {
                std::cout << "Please enter a valid integer: ";
            }

        } while (status == 0);

        conversion = std::stoi(userInput);

        if (conversion < min || conversion > max)
        {
            std::cout << "You must select a number between "
                << min << " and " << max << ": ";
        }

    } while (conversion < min || conversion > max);

    // Extra break for formatting
    std::cout << std::endl;

    return conversion;

}


/**
 * 
 * int getIntMin(int min)
 * 
 * Summary: 
 * 		This function validates user input for integers within a specified
 *      range. It loops until a valid integer is entered by the user.
 * 
 * Parameters:	an integer for the minimum value allowed
 * 
 * Returns:	    an integer
 * 
 * Description:
 * 		This function collects user input as a string and checks each character
 *      against rules for integers. If all rules are passed it will convert
 *      the string to an integer and return that value. It uses nested do while
 *      loop to validate that input is an integer and then check that the
 *      integer is within the specified range.
 * 
 **/

int getIntMin(int min)
{
    int status = 0;
    std::string userInput;
    int conversion = 0;

    do{
        do {
            std::getline(std::cin, userInput);

            if (!(allIsSignedDigit(userInput)))
            {
                status = 0;
            }
            else if (hasUnsignedLeadingZero(userInput))
            {
                status = 0;
            }
            else if (hasSignedLeadingZero(userInput))
            {
                status = 0;
            }
            else if (!(willConvertInt(userInput)))
            {
                status = 0;
            }
            else
            {
                status = 1;
            }

            // If any tests fail display error message
            if (status == 0)
            {
                std::cout << "Please enter a valid integer: ";
            }

        } while (status == 0);

        conversion = std::stoi(userInput);

        if (conversion < min)
        {
            std::cout << "You must select a number greater than or equal to "
                << min << ": ";
        }

    } while (conversion < min);

    // Extra break for formatting
    std::cout << std::endl;

    return conversion;

}


/**
 * 
 * int getIntMin(int min)
 * 
 * Summary: 
 * 		This function validates user input for integers within a specified
 *      range. It loops until a valid integer is entered by the user.
 * 
 * Parameters:	an integer for the maximum value allowed
 * 
 * Returns:	    an integer
 * 
 * Description:
 * 		This function collects user input as a string and checks each character
 *      against rules for integers. If all rules are passed it will convert
 *      the string to an integer and return that value. It uses nested do while
 *      loop to validate that input is an integer and then check that the
 *      integer is within the specified range.
 * 
 **/

int getIntMax(int max)
{
    int status = 0;
    std::string userInput;
    int conversion = 0;

    do{
        do {
            std::getline(std::cin, userInput);

            if (!(allIsSignedDigit(userInput)))
            {
                status = 0;
            }
            else if (hasUnsignedLeadingZero(userInput))
            {
                status = 0;
            }
            else if (hasSignedLeadingZero(userInput))
            {
                status = 0;
            }
            else if (!(willConvertInt(userInput)))
            {
                status = 0;
            }
            else
            {
                status = 1;
            }

            // If any tests fail display error message
            if (status == 0)
            {
                std::cout << "Please enter a valid integer: ";
            }

        } while (status == 0);

        conversion = std::stoi(userInput);

        if (conversion < max)
        {
            std::cout << "You must select a number less than or equal to "
                << max << ": ";
        }

    } while (conversion < max);

    // Extra break for formatting
    std::cout << std::endl;

    return conversion;

}












/**
 * 
 * bool willConvertInt(std::string input, int conversionType)
 * 
 * Summary: 
 * 		This function checks to see if an error will occur when using the
 *      stoi function to convert a string to an integer.
 * 
 * Parameters:	a string
 * 
 * Returns:	    a bool. True if it will successfully convert and False if not.
 * 
 * Description:
 * 		This function utilizes a try-block to check if the stoi conversion will 
 *      be successful. If the conversion will not be successful it will catch
 *      and return false.
 * 
 **/

bool willConvertInt(std::string input)
{
    bool result = true;
    /**
     * The following code is adapted from from:
     *      Title: Stack Overflow Website
     *      Author: User davmac
     *      Date: 10/13/2016
     *      Availability: https://stackoverflow.com/questions/40031543/
     **/
    try {
    std::stoi(input);
    }
    catch (...) {
        result = false;
        /*
        std::cout << "Your integer must be between " 
            << std::numeric_limits<int>::min()
            << " and " << std::numeric_limits<int>::max() << std::endl;
        */
    }
    /**
     * end of adapted code
     **/

    return result;

}


// Checks for leading 0. If there is a leading 0 returns true
bool hasUnsignedLeadingZero (std::string input)
{
    bool result = false;
    int inputLength = input.length();

    if (inputLength>1 && input[0] == '0')
    {
        result = true;
    }

    return result;
}

// Checks for signed leading 0. If there is a leading 0 returns true
bool hasSignedLeadingZero (std::string input)
{
    bool result = false;
    int inputLength = input.length();

    if (inputLength>1 && input[0] == '-' && input[1] == '0')
    {
        result = true;
    }

    return result;
}

// Checks that all characters in the string are digits
bool allIsUnsignedDigit (std::string input)
{
    bool result = true;
    int inputLength = input.length();

    for (int i=0; i<inputLength; i++)
    {   
        if(!isdigit(input[i]))
        {
                result = false;
        }
    }

    return result;

}

// Checks that all characters in the string are digits not including the sign
bool allIsSignedDigit (std::string input)
{
    bool result = true;
    int inputLength = input.length();

    for (int i=0; i<inputLength; i++)
    {   
        if(!isdigit(input[i]))
        {
            result = false;

            if (i==0 && input[i] == '-' && input.length()>1)
            {
                result = true;
            }

        }
    }

    return result;

}

// Checks to see if there is a digit anywhere in the string
bool hasDigit (std::string input)
{
    bool result = false;
    int inputLength = input.length();

    for (int i=0; i<inputLength; i++)
    {   
        if(isdigit(input[i]))
        {
            result = true;
        }
    }

    return result;

}

// Checks to see if there is an alpha character anywhere in the string
bool hasAlpha (std::string input)
{
    bool result = false;
    int inputLength = input.length();

    for (int i=0; i<inputLength; i++)
    {   
        if(isalpha(input[i]))
        {
            result = true;
        }
    }

    return result;

}

// Checks to see if there is a white-space character anywhere in the string
bool hasWhiteSpace (std::string input)
{
    bool result = false;
    int inputLength = input.length();

    for (int i=0; i<inputLength; i++)
    {   
        if(isspace(input[i]))
        {
            result = true;
        }
    }

    return result;

}










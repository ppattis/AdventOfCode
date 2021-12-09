/******************************************************************************
*******************************************************************************
**                                                                           **
**   Copyright 2021 PaTcHeS tHe DiPsTiCk <patrick.pattison@gmail.com         **
**                                                                           **
**   Permission is hereby granted, free of charge, to any person obtaining   **
**   a copy of this software and associated documentation files (the         **
**   "Software"), to deal in the Software without restriction, including     **
**   without limitation the rights to use, copy, modify, merge, publish,     **
**   distribute, sublicense, and/or sell copies of the Software, and to      **
**   permit persons to whom the Software is furnished to do so, subject to   **
**   the following conditions:                                               **
**                                                                           **
**   The above copyright notice and this permission notice shall be included **
**   in all copies or substantial portions of the Software.                  **
**                                                                           **
**   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS **
**   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF              **
**   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  **
**   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY    **
**   CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,    **
**   TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE       **
**   SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                  **
**                                                                           **
*******************************************************************************
*******************************************************************************
**                                                                           **
**                                                                           **
**                           Revision History                                **
**                                                                           **
**   03 Dec  2020     PaTcHeS tHe DiPsTiCk     Initial Coding...             **
**   18 Mar  2021     PaTcHeS tHe DiPsTiCk     Added namespaces...           **
**                                                                           **
**                                                                           **
*******************************************************************************
******************************************************************************/

#ifndef __PtD__UTILS_H__
#define __PtD__UTILS_H__

//  System includes...

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//  Third Party includes...



//  Project includes...



namespace ptd
{
		
    //  Type definitions...
	typedef int int16;
	typedef unsigned int uint16;
	typedef long int int32;
    typedef unsigned long int uint32;
	typedef long long int int64;
	typedef unsigned long long int uint64;
	
	typedef std::vector<std::string> strvect;
	typedef std::vector<int32> intvect;
	    
	namespace utils
	{
	    
        ptd::strvect getInput(std::string file_name)
        {
        
            ptd::strvect return_value;
            std::string input_line;
            std::ifstream input_file(file_name);
        
            std::cout << "Opening input file " << file_name << "..." << std::endl;
        	if (input_file.is_open())
        	{
        		std::cout << "Reading input file " << file_name << "..." << std::endl;
        
        		while ( getline (input_file, input_line) )
        		{
        			return_value.push_back(input_line);
        		}  //  while ( getline (input_file, input_line) )
        
        		std::cout << "Closing input file " << file_name << "..." << std::endl;
        		input_file.close();
        
        		return (return_value);
        	}  //  if (input_file.is_open())
        
        	else
        	{
        		std::cout << "Unable to open " << file_name << "!" << std::endl;
        	}  //  else
        	return (return_value);
        }  //  std::vector<std::string> getInput(std::string input_file_name)
        
        ptd::int32 min(ptd::int32 number_1, ptd::int32 number_2)
        {
            ptd::int32 return_value = number_1;
            if (number_2 < return_value)
            {
        
                return_value = number_2;
        
            }
            return (return_value);
        }
        
        ptd::int32 max(ptd::int32 number_1, ptd::int32 number_2)
        {
        	ptd::int32 return_value = number_1;
        	if (number_2 > return_value)
        	{
        		return_value = number_2;
        	}
        	return(return_value);
        }
        
        bool isNumber(std::string test_string)
        {
        	bool return_value = true;
        	for (ptd::int32 a = 0; a < test_string.length() && return_value; a++)
        	{
        		if (!isdigit(test_string[a]))
        		{
        			return_value = false;
        		}
        	}
        	return (return_value);
        }
        
        ptd::strvect parseLine(std::string input, std::string deliminator = " ")
        {
			
        	ptd::strvect return_value;
			int          pos;
        	while (pos = input.find(deliminator) != std::string::npos)
        	{
				std::string token = input.substr(0, pos);
				if (token != " ")
				{
					return_value.push_back(token);
				}
        		input.erase(0, pos + deliminator.size());
        	}
        	if (input[input.size() - 1] == '\r')
        	{
        		input.erase(input.size() - 1);
        	}
        	return_value.push_back(input);
        	return (return_value);
        }
		
		int stringToInt(std::string input)
		{
			int ret;
			std::stringstream(input) >> ret;
			return ( ret );
		}

		unsigned long int stringToULInt(std::string input)
		{
			unsigned long int ret;
			std::stringstream(input) >> ret;
			return ( ret );
		}
	}  //  namespace utils
    
}  //  namespace ptd

#endif // __PtD__UTILS_H__
    
//
//  Advent of Code 2015
//  Day 01
//
//  By PatchesTheDipstick
//


//  System includes...

#include <iostream>
#include <fstream>
#include <string>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int main(int argc, char** argv)
{
	
	std::string input_file_name = "input.txt";
	std::string input_line;
	std::ifstream input_file (input_file_name);
	
	int total_characters = 0;
	int actual_characters = 0;
	int reencode_characters = 0;
	std::string reencoding;
	
	std::cout << "Opening input file " << input_file_name << "..." << std::endl;
	
	if (input_file.is_open())
	{
		std::cout << "Reading input file " << input_file_name << "..." << std::endl;
		
		while ( getline (input_file, input_line) )
		{
			reencode_characters += 2;
			for (int a = 0; a < input_line.length(); a++)
			{
				if (input_line[a] == '\"')
				{
					total_characters++;
					reencode_characters += 2;
				}
				else if (input_line[a] == '\\')
				{
					total_characters++;
					reencode_characters += 2;
					if ( (input_line[a + 1] == '\\') ||
					     (input_line[a + 1] == '\"') )
					{
						total_characters++;
						actual_characters++;
						a++;
						reencode_characters += 2;
					}
					else if (input_line[a + 1] == 'x')
					{
						total_characters += 3;
						actual_characters++;
						a += 3;
						reencode_characters += 3;
					}
				}
				else
				{
					total_characters++;
					actual_characters++;
					reencode_characters++;
				}
			}
			
		}
		std::cout << "Reencode: " << reencode_characters << " Actual: " << actual_characters << std::endl;
		std::cout << "Closing input file " << input_file_name << "..." << std::endl;
		input_file.close();
		
		int answer_1 = total_characters - actual_characters;
		int answer_2 = reencode_characters - total_characters;
		
		std::cout << "Advent of Code 2015 Day 08 answers:" << std::endl;
		std::cout << "    Part 1 : " << answer_1 << std::endl;
		std::cout << "    Part 2 : " << answer_2 << std::endl;
		
	}
	
	else
	{
		std::cout << "Unable to open " << input_file_name << "!" << std::endl;
	}

}

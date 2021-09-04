//
//  Advent of Code 2015
//  Day 25
//
//  By PatchesTheDipstick
//


//  System includes...

#include <regex>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"


int main(int argc, char** argv)
{
	std::vector<std::string> input = ptd::utils::getInput("input.txt");
	
	std::regex pattern (".*row ([0-9]*), column ([0-9]*).");
	std::smatch token;
	std::regex_match(input[0], token, pattern);
	long long int row = std::stoi(token[1]);
	long long int col = std::stoi(token[2]);
	long long int last_row = row + col - 1;
	long long int index = 0;
	for (long long int a = 1; a <= last_row - 1; a++)
		index += a;
	index += col;
	long long int value = 20151125;
	for (long long int a = 2; a <= index; a++)
	{
		value = (value * 252533) % 33554393;
		
	}

	
	std::cout << "Advent of Code 2015 Day  answers:" << std::endl;
	std::cout << "    Part 1 : " << value << std::endl;
	std::cout << "    Part 2 : " << "Free Star" << std::endl;

	return (0);

}

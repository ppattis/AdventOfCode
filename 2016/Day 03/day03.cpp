//
//  Advent of Code 2016
//  Day 01
//
//  By PatchesTheDipstick
//


//  System includes...

#include <sstream>
#include <utility>
#include <vector>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

ptd::strvect parseInput(std::string input)
{
	ptd::strvect ret;
	std::string word;
	std::stringstream ss(input);
	
	while (ss >> word)
	{
		ret.push_back(word);
	}
	return ret;
}

int countTrianglesOne(std::vector<int> input)
{
	int ret = 0;
	
	for (int a = 0; a < input.size(); a = a + 3)
	{
		int one = input[a];
		int two = input[a + 1];
		int thr = input[a + 2];
		if ( (one + two > thr) && (two + thr > one) && (thr + one > two) )
		{
			ret++;
		}
	}
	return ret;
}

int countTrianglesTwo(std::vector<int> input)
{
	int ret = 0;
	
	for (int a = 0; a < input.size() - 6; a = a + 3)
	{
		int one = input[a];
		int two = input[a + 3];
		int thr = input[a + 6];
		if ( (one + two > thr) && (two + thr > one) && (thr + one > two) )
		{
			ret++;
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	ptd::strvect input = ptd::utils::getInput("input.txt");
	std::vector<int> part_one_input;
	std::vector<int> part_two_input;
	for (int a = 0; a < input.size(); a++)
	{
		ptd::strvect line = parseInput(input[a]);
		for (int b = 0; b < line.size(); b++)
		{
			part_one_input.push_back(ptd::utils::stringToInt(line[b]));
		}
		line.clear();
	}
	for (int a = 0; a < input.size() - 1; a = a + 3)
	{
		ptd::strvect one = parseInput(input[a]);
		ptd::strvect two = parseInput(input[a + 1]);
		ptd::strvect thr = parseInput(input[a + 2]);
		for (int b = 0; b < one.size(); b++)
		{
			part_two_input.push_back(ptd::utils::stringToInt(one[b]));
			part_two_input.push_back(ptd::utils::stringToInt(two[b]));
			part_two_input.push_back(ptd::utils::stringToInt(thr[b]));
		}
	}

	std::cout << "Advent of Code 2016 Day 3 answers:" << std::endl;
	std::cout << "    Part one : " << countTrianglesOne(part_one_input) << "\n";
	std::cout << "    Part two : " << countTrianglesOne(part_two_input) << "\n";
	return (0);

}

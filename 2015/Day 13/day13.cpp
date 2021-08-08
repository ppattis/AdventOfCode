//
//  Advent of Code 2015
//  Day 01
//
//  By PatchesTheDipstick
//


//  System includes...

#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int getBest(std::vector<std::string> guests, std::map<std::pair<std::string, std::string>, int> happiness_guide)
{
	int return_value = 0;
	std::vector<int> values;
	
	std::sort(guests.begin(), guests.end());
	
	do
	{
		int temp = 0;
		temp += happiness_guide[{guests[0], guests[guests.size() - 1]}];
		temp += happiness_guide[{guests[guests.size() - 1], guests[0]}];
		for (int a = 0; a < guests.size() - 1; a++)
		{
			temp += happiness_guide[{guests[a], guests[a + 1]}];
			temp += happiness_guide[{guests[a + 1], guests[a]}];
		}
		values.push_back(temp);
	} while (std::next_permutation(guests.begin(), guests.end()));
	return_value = values[0];
	for (int a = 1; a < values.size(); a++)
	{
		if (return_value < values[a])
		{
			return_value = values[a];
		}
	}
	return return_value;
}


int main(int argc, char** argv)
{
	
	std::vector<std::string> input = ptd::utils::getInput("input.txt");
	std::vector<std::string> guests;
	std::map<std::pair<std::string, std::string>, int> happiness_guide;
	std::vector<int> deltas;
	
	int answer_one = 0;
	int answer_two = 0;
	
	for (int a = 1; a < input.size(); a++)
	{
		std::vector<std::string> line = ptd::utils::parseLine(input[a], " ");
		bool negative_gain = false;
		if (line[2] == "lose")
		{
			negative_gain = true;
		}
		if (line[10][line[10].size() - 1] == '.')
		{
			line[10].erase(line[10].size() - 1);
		}
		happiness_guide[{line[0], line[10]}] = std::stoi(line[3]);
		if (negative_gain)
		{
			happiness_guide[{line[0], line[10]}] = happiness_guide[{line[0], line[10]}] * -1;
		}
		bool one = false;
		bool two = false;
		for (int a = 0; a < guests.size(); a++)
		{
			if (guests[a] == line[0])
			{
				one = true;
			}
			if (guests[a] == line[10])
			{
				two = true;
			}
		}
		if (!one)
		{
			guests.push_back(line[0]);
		}
		if (!two)
		{
			guests.push_back(line[10]);
		}
	}
	std::cout << "Input parsed..." << std::endl;
	answer_one = getBest(guests, happiness_guide);
	for (int a = 0; a < guests.size(); a++)
	{
		happiness_guide[{guests[a], "Patches"}] = 0;
		happiness_guide[{"Patches", guests[a]}] = 0;
	}
	guests.push_back("Patches");
	answer_two = getBest(guests, happiness_guide);
	
	std::cout << "Advent of Code 2015 Day 1 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_one << std::endl;
	std::cout << "    Part 2 : " << answer_two << std::endl;

	return (0);

}

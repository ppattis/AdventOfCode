//
//  Advent of Code 2015
//  Day 17
//
//  By PatchesTheDipstick
//


//  System includes...

#include <vector>
#include <string>
#include <algorithm>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int main(int argc, char** argv)
{
	
	std::vector<std::string> input = ptd::utils::getInput("input.txt");
	std::vector<int> containers;
	
	for (int a = 0; a < input.size(); a++)
	{
		containers.push_back(std::stoi(input[a]));
	}
	int number = 0;
	std::sort(containers.begin(), containers.end());
	int index = 0;
	do
	{
		index++;
		int volume = 150;
		int a = 0;
		while (volume > 0)
		{
			volume -= containers[a];
			a++;
		}
		if (volume == 0)
		{
			number++;
		}
	}
	while (std::next_permutation(containers.begin(), containers.end()));
		
	int answer_1 = number;
	int answer_2 = 0;
	
	std::cout << "Advent of Code 2015 Day 1 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}

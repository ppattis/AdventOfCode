//
//  Advent of Code 2015
//  Day 16
//
//  By PatchesTheDipstick
//


//  System includes...
#include <vector>
#include <string>
#include <iostream>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"


struct AuntSue
{
	bool part_one = true;
	bool part_two = true;
	int index = -1;
	int children = -1;
	int cats = -1;
	int samoyeds = -1;
	int pomeranians = -1;
	int akitas = -1;
	int vizslas = -1;
	int goldfish = -1;
	int trees = -1;
	int cars = -1;
	int perfumes = -1;
};


int main(int argc, char** argv)
{
	
	std::vector<std::string> raw_input = getInput("input.txt");
	std::vector<AuntSue> input;
	
	for (int a = 1; a < raw_input.size(); a++)
	{
		std::vector<std::string> line = parseLine(raw_input[a], " ");
		AuntSue new_aunt;
		//std::cout << line.size()<< std::endl;
		//std::cout << line[0] << std::endl;
		for (int b = 0; b < line.size(); b++)
		{
			if (line[b].find(':') != std::string::npos)
			{
				std::string temp = line[b].substr(0, line[b].find(':'));
				line[b].clear();
				line[b] = temp;
			}
			else if (line[b].find(',') != std::string::npos)
			{
				std::string temp = line[b].substr(0, line[b].find(','));
				line[b].clear();
				line[b] = temp;
			}
		}
		//std::cout << line[1] << std::endl;
		new_aunt.index = std::stoi(line[1]);
		for (int b = 2; b < line.size(); b += 2)
		{
			if (line[b] == "children")
			{
				//std::cout << line[b + 1] << std::endl;
				new_aunt.children = std::stoi(line[b + 1]);
			}else if (line[b] == "cats")
			{
				//std::cout << line[b + 1] << std::endl;
				new_aunt.cats = std::stoi(line[b + 1]);
			}else if (line[b] == "samoyeds")
			{
				//std::cout << line[b + 1] << std::endl;
				new_aunt.samoyeds = std::stoi(line[b + 1]);
			}else if (line[b] == "pomeranians")
			{
				//std::cout << line[b + 1] << std::endl;
				new_aunt.pomeranians = std::stoi(line[b + 1]);
			}else if (line[b] == "akitas")
			{
				//std::cout << line[b + 1] << std::endl;
				new_aunt.akitas = std::stoi(line[b + 1]);
			}else if (line[b] == "vizslas")
			{
				//std::cout << line[b + 1] << std::endl;
				new_aunt.vizslas = std::stoi(line[b + 1]);
			}else if (line[b] == "goldfish")
			{
				//std::cout << line[b + 1] << std::endl;
				new_aunt.goldfish = std::stoi(line[b + 1]);
			}else if (line[b] == "trees")
			{
				//std::cout << line[b + 1] << std::endl;
				new_aunt.trees = std::stoi(line[b + 1]);
			}else if (line[b] == "cars")
			{
				//std::cout << line[b + 1] << std::endl;
				new_aunt.cars = std::stoi(line[b + 1]);
			}else if (line[b] == "perfumes")
			{
				//std::cout << line[b + 1] << std::endl;
				new_aunt.perfumes = std::stoi(line[b + 1]);
			}
		}
		input.push_back(new_aunt);
	}
	
	for (int a = 0; a < input.size(); a++)
	{
		if ((input[a].children != -1) && (input[a].children != 3))
		{
			input[a].part_one = false;
			input[a].part_two = false;
		}
		if ((input[a].cats != -1) && (input[a].cats != 7))
		{
			input[a].part_one = false;
		}
		if ((input[a].cats != -1) && (input[a].cats <= 7))
		{
			input[a].part_two = false;
		}
		if ((input[a].samoyeds != -1) && (input[a].samoyeds != 2))
		{
			input[a].part_one = false;
			input[a].part_two = false;
		}
		if ((input[a].pomeranians != -1) && (input[a].pomeranians != 3))
		{
			input[a].part_one = false;
		}
		if ((input[a].pomeranians != -1) && (input[a].pomeranians >= 3))
		{
			input[a].part_two = false;
		}
		if ((input[a].akitas != -1) && (input[a].akitas != 0))
		{
			input[a].part_one = false;
			input[a].part_two = false;
		}
		if ((input[a].vizslas != -1) && (input[a].vizslas != 0))
		{
			input[a].part_one = false;
			input[a].part_two = false;
		}
		if ((input[a].goldfish != -1) && (input[a].goldfish != 5))
		{
			input[a].part_one = false;
		}
		if ((input[a].goldfish != -1) && (input[a].goldfish >= 5))
		{
			input[a].part_two = false;
		}
		if ((input[a].trees != -1) && (input[a].trees != 3))
		{
			input[a].part_one = false;
		}
		if ((input[a].trees != -1) && (input[a].trees <= 3))
		{
			input[a].part_two = false;
		}
		if ((input[a].cars != -1) && (input[a].cars != 2))
		{
			input[a].part_one = false;
			input[a].part_two = false;
		}
		if ((input[a].perfumes != -1) && (input[a].perfumes != 1))
		{
			input[a].part_one = false;
			input[a].part_two = false;
		}
	}
	
	int answer_1 = 0;
	int answer_2 = 0;
	
	for (int a = 0; a < input.size(); a++)
	{
		if (input[a].part_one)
		{
			answer_1 = input[a].index;
		}
		if (input[a].part_two)
		{
			answer_2 = input[a].index;
		}
	}
	std::cout << "Advent of Code 2015 Day 16 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}

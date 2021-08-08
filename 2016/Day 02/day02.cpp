//
//  Advent of Code 2016
//  Day 01
//
//  By PatchesTheDipstick
//


//  System includes...

#include <vector>
#include <map>
#include <utility>
#include <string>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int newButton(int current_button, std::string direction)
{
	int return_value = current_button;
	
	if (direction == "U")
	{
		if (return_value > 3)
		{
			return_value -= 3;
		}
	}
	else if (direction == "L")
	{
		if ((return_value != 1) && (return_value != 4) && (return_value != 7))
		{
			return_value--;
		}
	}
	else if (direction == "D")
	{
		if (return_value < 7)
		{
			return_value += 3;
		}
	}
	else if (direction == "R")
	{
		if ((return_value != 3) && (return_value != 6) && (return_value != 9))
		{
			return_value++;
		}
	}
	//std::cout << return_value << std::endl;
	return return_value;
}

int newButtonTwo(int current_button, std::string direction)
{
	int return_value = current_button;
	if (direction == "U")
	{
		if (return_value == 3)
		{
			return_value = 1;
		}
		else if ((return_value >= 6) && (return_value <= 8))
		{
			return_value -= 4;
		}
		else if ((return_value >= 10) && (return_value <= 12))
		{
			return_value -= 4;
		}
		else if (return_value == 13)
		{
			return_value -=2;
		}
	}
	else if (direction == "L")
	{
		if ((return_value >= 3) && (return_value <= 4))
		{
			return_value -=1;
		}
		else if ((return_value >= 6) && (return_value <= 9))
		{
			return_value -=1;
		}
		else if ((return_value >= 11) && (return_value <= 12))
		{
			return_value -= 1;
		}
	}
	else if (direction == "D")
	{
		if (return_value == 1)
		{
			return_value = 3;
		}
		else if ((return_value >= 2) && (return_value <= 4))
		{
			return_value += 4;
		}
		else if ((return_value >= 6) && (return_value <= 8))
		{
			return_value += 4;
		}
		else if (return_value == 11)
		{
			return_value = 13;
		}
	}
	else if (direction == "R")
	{
		if ((return_value >= 2) && (return_value <= 3))
		{
			return_value +=1;
		}
		else if ((return_value >= 5) && (return_value <= 8))
		{
			return_value +=1;
		}
		else if ((return_value >= 10) && (return_value <= 11))
		{
			return_value += 1;
		}
	}
	return return_value;
}

int main(int argc, char** argv)
{
	std::vector<std::string> input = ptd::utils::getInput("input.txt");
	std::vector<int> bathroom_code;
	std::vector<int> part_two_code;
	int current_button = 5;
	int part_two_button = 5;
	for (int a = 1; a < input.size(); a++)
	{
		for (int b = 0; b < input[a].size(); b++)
		{
			current_button = newButton(current_button, input[a].substr(b, 1));
			part_two_button = newButtonTwo(part_two_button, input[a].substr(b, 1));
		}
		bathroom_code.push_back(current_button);
		part_two_code.push_back(part_two_button);
	}
	
	
	std::cout << "Advent of Code Day 02:" << std::endl;
	std::cout << "    Part 1 : ";
	for (int a = 0; a < bathroom_code.size(); a++)
	{
		std::cout << bathroom_code[a];
	}
	std::cout << std::endl;
	std::cout << "    Part 2 : ";
	for (int a = 0; a < part_two_code.size(); a++)
	{
		std::cout <<  std::hex << part_two_code[a];
	}
	std::cout << std::endl;

	return (0);

}

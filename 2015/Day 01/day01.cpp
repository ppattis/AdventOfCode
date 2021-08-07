//
//  Advent of Code 2015
//  Day 01
//
//  By PatchesTheDipstick
//


//  System includes...


//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int main(int argc, char** argv)
{
	
	std::vector<std::string> input = getInput("input.txt");
	
	int current_floor = 0;
	int first_enter_basement = -1;
	int instruction_counter = 0;
	
	for (int a = 0; a < input.size(); a++)
	{
	
		for (int b = 0; b < input[a].length(); b++)
		{
			if (input[a][b] == '(')
			{
				current_floor++;
				instruction_counter++;
			}
			else
			{
				current_floor--;
				instruction_counter++;
				if ((current_floor < 0) && (first_enter_basement == -1))
				{
					first_enter_basement = instruction_counter;
				}
			}
		}
	}

		
	int answer_1 = current_floor;
	int answer_2 = first_enter_basement;
	
	std::cout << "AoC 2015 Day 1 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}

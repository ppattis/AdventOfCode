//
//  Advent of Code 2015
//  Day 12
//
//  By PatchesTheDipstick
//


//  System includes...


//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int main(int argc, char** argv)
{
	
	std::vector<std::string> input = ptd::utils::getInput("input.txt");
	
	std::vector<std::string> number_strings;
	std::string new_number_string;
	std::vector<std::string> red_number_strings;
	
	for (int a = 0; a < input.size(); a++)
	{
		bool on_number = false;
		int in_object = 0;
		int in_red_object = 0;
		for (int b = 0; b < input[a].length(); b++)
		{
			if (input[a][b] == '{')
			{
				in_object++;
			}
			if ((in_object) && (input[a][b] == 'r'))
			{
				if ((input[a][b + 1] == 'e') && (input[a][b + 2] == 'd'))
				{
					std::cout << "In Red Object" << std::endl;
					in_red_object = in_object;
				}
			}
			if (input[a][b] == '}')
			{
				if (in_red_object == in_object)
				{
					in_red_object = 0;
				}
				in_object--;
			}
			if ((input[a][b] <= '9') && (input[a][b] >= '0'))
			{
				if (!on_number)
				{
					new_number_string.clear();
					on_number = true;
					if (input[a][b - 1] == '-')
					{
						new_number_string += "-";
					}
				}
				new_number_string += input[a][b];
			}
			else if (on_number)
			{
				number_strings.push_back(new_number_string);
				on_number = false;
				if (in_red_object != 0)
				{
					red_number_strings.push_back(new_number_string);
				}
				std::cout << new_number_string << std::endl;
			}
		}
	}
	if (number_strings[number_strings.size() - 1] != new_number_string)
	{
		number_strings.push_back(new_number_string);
	}
		
	int answer_1 = 0;
	int answer_2 = 0;
	
	for (int a = 0; a < number_strings.size(); a++)
	{
		answer_1 += std::stoi(number_strings[a]);
	}
	answer_2 = answer_1;
	for (int a = 0; a < red_number_strings.size(); a++)
	{
		answer_2 -= std::stoi(red_number_strings[a]);
	}
	
	std::cout << "Advent of Code 2015 Day 12 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}

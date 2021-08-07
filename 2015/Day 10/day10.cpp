//
//  Advent of Code 2015
//  Day 10
//
//  By PatchesTheDipstick
//


//  System includes...


//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

std::string lookAndSay(std::string look)
{
	std::string say = "";
	
	if (look.length() == 0)
	{
		return ("");
	}
	else if (look.length() == 1)
	{
		say = "1" + look;
	}
	else
	{
		for (int a = 0; a < look.length(); a++)
		{
			int digit_count = 0;
			for (int b = a + 1; b < look.length(); b++)
			{
				if (look[b] == look[a])
				{
					digit_count++;
				}
				else 
				{
					break;
				}
			}
			say = say + std::to_string(digit_count + 1) + look[a];
			a += digit_count;

		}
	}
	return (say);
}

int main(int argc, char** argv)
{
	
	std::string input = "1113222113";
	
	long int answer_1 = 0;

	std::cout << "Advent of Code 2015 Day 10 answers:" << std::endl;
	
	for (int a = 0; a < 50; a++)
	{
		input = lookAndSay(input);
		if (a == 39)
		{
			answer_1 = input.size();
			std::cout << "    Part 1 : " << answer_1 << std::endl;
		}
	}

	long int answer_2 = input.size();
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}

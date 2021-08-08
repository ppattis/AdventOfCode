//
//  Advent of Code 2015
//  Day 20
//
//  By PatchesTheDipstick
//


//  System includes...
#include <vector>
#include <map>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

std::map<int, int> part_two_limits;

std::vector<int> getFactors(int number)
{
	std::vector<int> return_value;
	
	for (int a = 1; a <= number; a++)
	{
		if (number % a == 0)
		{
			return_value.push_back(a);
		}
	}
	return (return_value);
}

int calculatePresents(std::vector<int> factors, bool part_two)
{
	
	int return_value = 0;
	
	for (int a = 0; a < factors.size(); a++)
	{
		if (part_two)
		{
			//std::cout << part_two_limits[factors[a]] << std::endl;
			if (part_two_limits[factors[a]] < 50)
			{
				if (part_two_limits[factors[a]] == 0)
				{
					part_two_limits[factors[a]] = 1;
				}
				else 
				{
					part_two_limits[factors[a]] = part_two_limits[factors[a]] + 1;
				}
				return_value = return_value + ( factors[a] * 11);
				
			}
		}
		else
		{
			return_value = return_value + ( factors[a] * 10 );
		}
	}
	
	return (return_value);
	
}


int main(int argc, char** argv)
{
	int input = 33100000;
	
	int answer_one = 1;
	int answer_two = 1;
	bool part_one_answered = false;
	bool part_two_answered = false;
	
	while ((!part_one_answered)  && (!part_two_answered))
	{
		int temp = calculatePresents(getFactors(answer_one), false);
		int temp2 = calculatePresents(getFactors(answer_two), true);
		if (temp >= input)
		{
			part_one_answered = true;
		}
		else
		{
			answer_one++;
		}
		if (temp2 >= input)
		{
			part_two_answered = true;
		}
		else
		{
			answer_two++;
		}
	}
	
	std::cout << "Advent of Code 2015 Day 20 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_one << std::endl;
	std::cout << "    Part 2 : " << answer_two << std::endl;

	return (0);

}

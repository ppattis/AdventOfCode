//
//  Advent of Code 2015
//  Day 03
//
//  By PatchesTheDipstick
//


//  System includes...

#include <map>
#include <utility>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int main(int argc, char** argv)
{
	
	std::vector<std::string> input = getInput("input.txt");

	typedef std::map<std::pair<int, int>, int > houseMap;
	houseMap houses_year_one, houses_year_two;
	int year_one_X = 0, year_one_Y = 0;
	int santa_X = 0, santa_Y = 0;
	int robo_santa_X = 0, robo_santa_Y = 0;
	int instruction_counter = 1;
	
	houses_year_one[std::make_pair(year_one_X, year_one_Y)]++;
	houses_year_two[std::make_pair(santa_X, santa_Y)]++;
	houses_year_two[std::make_pair(robo_santa_X, robo_santa_Y)]++;
	
	for (int a = 0; a < input.size(); a++)
	{
		for (int index = 0; index < input[a].length(); index++)
		{
			if (input[a][index] == '^')
			{
				if (instruction_counter % 2 != 0)
				{
					santa_Y++;
					houses_year_two[std::make_pair(santa_X, santa_Y)]++;
					instruction_counter++;
				}
				else
				{
					robo_santa_Y++;
					houses_year_two[std::make_pair(robo_santa_X, robo_santa_Y)]++;
					instruction_counter++;
				}
				year_one_Y++;
				houses_year_one[std::make_pair(year_one_X, year_one_Y)]++;
			}
			else if (input[a][index] == 'v')
			{
				if (instruction_counter % 2 != 0)
				{
					santa_Y--;
					houses_year_two[std::make_pair(santa_X, santa_Y)]++;
					instruction_counter++;
				}
				else
				{
					robo_santa_Y--;
					houses_year_two[std::make_pair(robo_santa_X, robo_santa_Y)]++;
					instruction_counter++;
				}
				year_one_Y--;
				houses_year_one[std::make_pair(year_one_X, year_one_Y)]++;
			}
			else if (input[a][index] == '<')
			{
				if (instruction_counter % 2 != 0)
				{
					santa_X--;
					houses_year_two[std::make_pair(santa_X, santa_Y)]++;
					instruction_counter++;
				}
				else
				{
					robo_santa_X--;
					houses_year_two[std::make_pair(robo_santa_X, robo_santa_Y)]++;
					instruction_counter++;
				}
				year_one_X--;
				houses_year_one[std::make_pair(year_one_X, year_one_Y)]++;
			}
			else if (input[a][index] == '>')
			{
				if (instruction_counter % 2 != 0)
				{
					santa_X++;
					houses_year_two[std::make_pair(santa_X, santa_Y)]++;
					instruction_counter++;
				}
				else
				{
					robo_santa_X++;
					houses_year_two[std::make_pair(robo_santa_X, robo_santa_Y)]++;
					instruction_counter++;
				}
				year_one_X++;
				houses_year_one[std::make_pair(year_one_X, year_one_Y)]++;
			}
		}
	}
			
	int answer_1 = houses_year_one.size();
	int answer_2 = houses_year_two.size();
	
	std::cout << "Advent of Code 2015 Day 3 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;
	
}

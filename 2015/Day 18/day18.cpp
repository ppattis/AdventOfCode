//
//  Advent of Code 2015
//  Day 18
//
//  By PatchesTheDipstick
//


//  System includes...

#include <iostream>
#include <string>
#include <vector>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

void printGrid(std::vector<std::vector<char>> grid)
{
	for (int a = 0; a < grid.size(); a++)
	{
		for (int b = 0; b < grid[a].size(); b++)
		{
			std::cout << grid[a][b];
		}
		std::cout << "\n";
	}
}

void update(std::vector<std::vector<char>> &grid, bool part_two)
{
	
	std::vector<std::vector<char>> original = grid;
	for (int a = 0; a < original.size(); a++)
	{
		for (int b = 0; b < original[a].size(); b++)
		{
			int num_on = 0;
			for (int c = a - 1; c <= a + 1; c++)
			{
				for (int d = b - 1; d <= b + 1; d++)
				{
					if ( (c >= 0) && (c < original.size()) &&
					     (d >= 0) && (d < original[c].size()) && 
						 (original[c][d] == '#') )
						 num_on++;
				}
			}
			if (original[a][b] == '#')
			{
				if ((num_on == 3) || (num_on == 4))
					grid[a][b] = '#';
				else
					grid[a][b] = '.';
			}
			else
			{
				if (num_on == 3)
				{
					grid[a][b] = '#';
				}
			}
		}
	}
	if (part_two)
	{
		int h = grid.size() - 1;
		int w = grid[h].size() - 1;
		grid[0][0] = '#';
		grid[0][w] = '#';
		grid[h][0] = '#';
		grid[h][w] = '#';
	}
}

int count(std::vector<std::vector<char>> grid)
{
	int ret = 0;
	for (auto row : grid)
	{
		for (auto light : row)
		{
			if (light == '#')
			{
				ret++;
			}
		}
	}
	return ret;
}

int main(int argc, char** argv)
{
	std::vector<std::string> input = ptd::utils::getInput("input.txt");
	std::vector<std::vector<char>> grid;
		
	for (int a = 0; a < input.size(); a++)
	{
		std::vector<char> row;
		for (int b = 0; b < input[a].size(); b++)
		{
			row.push_back(input[a][b]);
		}
		grid.push_back(row);
	}
	std::vector<std::vector<char>> part_one = grid;
	std::vector<std::vector<char>> part_two = grid;
	int h = grid.size() - 1;
	int w = grid[h].size() - 1;
	part_two[0][0] = '#';
	part_two[0][w] = '#';
	part_two[h][0] = '#';
	part_two[h][w] = '#';
	
	for (int a = 0; a < 100; a++)
	{
		update(part_one, false);
		update(part_two, true);
	}
	
	
	std::cout << "Advent of Code 2015 Day 18 answers:" << std::endl;
	std::cout << "    Part 1 : " << count(part_one) << std::endl;
	std::cout << "    Part 2 : " << count(part_two)  << std::endl;

	return (0);

}

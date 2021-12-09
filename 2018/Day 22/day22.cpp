//
//  Advent of Code 2018
//  Day 22
//
//  By PatchesTheDipstick
//


//  System includes...

#include <string>
#include <vector>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int calculateAnswerOne(std::vector<std::vector<int>> risk)
{
	int ret = 0;
	for (std::vector<int> row : risk)
	{
		for (int a : row)
		{
			ret += a;
		}
	}
	return (ret);
}


int main(int argc, char** argv)
{
	
	int depth  = 5913;
	int targ_x = 8;
	int targ_y = 701;
	
	std::vector<std::vector<int>> geo_index;
	std::vector<std::vector<int>> erosion_level;
	std::vector<std::vector<int>> risk_level;
	
	//  resize the vectors to the correct size...
	geo_index.resize(targ_y + 1, std::vector<int>(targ_x + 1));
	erosion_level.resize(targ_y + 1, std::vector<int>(targ_x + 1));
	risk_level.resize(targ_y + 1, std::vector<int>(targ_x + 1));
	geo_index[0][0] = 0;
	for (int y = 0; y <= targ_y; y++)
	{
		for (int x = 0; x <= targ_x; x++)
		{
			if (y == 0)
			{
				geo_index[y][x] = x * 16807;
			}
			else if (x == 0)
			{
				geo_index[y][x] = y * 48271;
			}
			else if ((x == targ_x) && (y == targ_y))
			{
				geo_index[y][x] = 0;
			}
			else 
			{
				geo_index[y][x] = erosion_level[y][x - 1] * erosion_level[y - 1][x];
			}
			erosion_level[y][x] = ((geo_index[y][x] + depth) % 20183);
			risk_level[y][x] = (erosion_level[y][x] % 3);
		}
	}
	
	std::cout << "Advent of Code 2018 Day 22:" << std::endl;
	std::cout << "    Part 1 : " << calculateAnswerOne(risk_level) << std::endl;
	std::cout << "    Part 2 : " << 0 << std::endl;

	return (0);

}

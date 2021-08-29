//
//  Advent of Code 2016
//  Day 01
//
//  By PatchesTheDipstick
//


//  System includes...

#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

typedef std::pair<int, int> coord;

struct Direction
{
	char turn;
	int walk;
};

void turn(char dir, coord &move)
{
	//  Traveling north...
	if (move == std::make_pair(0, -1))
	{
		if (dir == 'R')
			move = std::make_pair(1, 0);
		else
			move = std::make_pair(-1, 0);
	}
	//  Traveling east...
	else if (move == std::make_pair(1, 0))
	{
		if (dir == 'R')
			move = std::make_pair(0, 1);
		else
			move = std::make_pair(0, -1);
	}
	//  Traveling south...
	else if (move == std::make_pair(0, 1))
	{
		if (dir == 'R')
			move = std::make_pair(-1, 0);
		else
			move = std::make_pair(1, 0);
	}
	//  Traveling west...
	else if (move == std::make_pair(-1, 0))
	{
		if (dir == 'R')
			move = std::make_pair(0, -1);
		else
			move = std::make_pair(0, 1);
	}
}

std::vector<std::string> parse(std::string input)
{
	std::stringstream ss (input);
	std::string token;
	std::vector<std::string> ret;
	while (ss >> token)
	{
		if (token.find(',') != std::string::npos)
		{
			token.erase(token.begin() + token.size() - 1);
		}
		ret.push_back(token);
	}
	return ret;
}

void walk(coord pos, coord dir)
{
	pos.first += dir.first;
	pos.second += dir.second;
}

int main(int argc, char** argv)
{
	std::vector<std::string> input = ptd::utils::getInput("input.txt");
	std:: vector<Direction> directions;
	std::map<coord, int> intersections;
	
	for (int a = 0; a < input.size(); a++)
	{
		std::vector<std::string> line = parse(input[a]);
		for (int b = 0; b < line.size(); b++)
		{
			Direction new_direction;
			new_direction.turn = line[b][0];
			line[b].erase(0, 1);
			new_direction.walk = std::stoi(line[b]);
			directions.push_back(new_direction);
		}
	}
	coord location = std::make_pair(0, 0);
	coord change = std::make_pair(-1, 0);
	intersections[{0, 0}]++;
	bool part2_done = false;
	coord part_two;
	
	for (int a = 0; a < directions.size(); a++)
	{
		turn(directions[a].turn, change);
		for (int steps = 0; steps < directions[a].walk; steps++)
		{
			location.first += change.first;
			location.second += change.second;
			intersections[location]++;
			if ((!part2_done) && (intersections[location] > 1))
			{
				part_two = location;
				part2_done = true;
			}
		}
	}
	
	int answer_1 = std::abs(location.first) + std::abs(location.second);
	int answer_2 = std::abs(part_two.first) + std::abs(part_two.second);
	
	std::cout << "Advent of Code 2016 Day 1 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}

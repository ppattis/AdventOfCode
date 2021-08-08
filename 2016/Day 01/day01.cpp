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

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

struct Direction
{
	char turn;
	int walk;
};


int main(int argc, char** argv)
{
	std::vector<std::string> input = ptd::utils::getInput("input.txt");
	std:: vector<Direction> directions;
	std::map<std::pair<int, int>, int> intersections;
	for (int a = 1; a < input.size(); a++)
	{
		std::vector<std::string> line = ptd::utils::parseLine(input[a], ", ");
		for (int b = 0; b < line.size(); b++)
		{
			Direction new_direction;
			new_direction.turn = line[b][0];
			line[b].erase(0, 1);
			new_direction.walk = std::stoi(line[b]);
			directions.push_back(new_direction);
		}
	}
	
	int my_x = 0;
	int my_y = 0;
	int my_dx = 0;
	int my_dy = 1;
	intersections[{0, 0}]++;
	bool part2_done = false;
	int part_2_x = 0;
	int part_2_y = 0;
	for (int a = 0; a < directions.size(); a++)
	{
		if (directions[a].turn == 'L')
		{
			if ((my_dx == 0) && (my_dy == 1))
			{
				my_dx = -1;
				my_dy = 0;
			}
			else if ((my_dx == -1) && (my_dy == 0))
			{
				my_dx = 0;
				my_dy = -1;
			}
			else if ((my_dx == 0) && (my_dy == -1))
			{
				my_dx = 1;
				my_dy = 0;
			}
			else
			{
				my_dx = 0;
				my_dy = 1;
			}
		}
		else
		{
			if ((my_dx == 0) && (my_dy == 1))
			{
				my_dx = 1;
				my_dy = 0;
			}
			else if ((my_dx == 1) && (my_dy == 0))
			{
				my_dx = 0;
				my_dy = -1;
			}
			else if ((my_dx == 0) && (my_dy == -1))
			{
				my_dx = -1;
				my_dy = 0;
			}
			else
			{
				my_dx = 0;
				my_dy = 1;
			}
		}
		my_x += my_dx * directions[a].walk;
		my_y += my_dy * directions[a].walk;
		intersections[{my_x, my_y}]++;
		if ((intersections[{my_x, my_y}] > 1) && (!part2_done))
			{
				part_2_x = my_x;
				part_2_y = my_y;
				part2_done = true;
			}
	}
	int x_away = my_x;
	int y_away = my_y;
	if (x_away < 0)
	{
		x_away = x_away * -1;
	}
	if (y_away < 0)
	{
		y_away = y_away * -1;
	}
	if (part_2_x < 0)
	{
		part_2_x = part_2_x * -1;
	}
	if (part_2_y < 0)
	{
		part_2_y = part_2_y * -1;
	}
	
	int answer_1 = x_away + y_away;
	int answer_2 = part_2_x + part_2_y;;
	
	std::cout << "Advent of Code 2016 Day 1 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}

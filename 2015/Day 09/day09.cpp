//
//  Advent of Code 2015
//  Day 09
//
//  By PatchesTheDipstick
//


//  System includes...

#include <map>
#include <algorithm>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int main(int argc, char** argv)
{
	
	std::vector<std::string> input = getInput("input.txt");
	std::map<std::pair<std::string, std::string>, int> distances;
	std::vector<std::string> locations;
	//std::cout << input.size() << std::endl;
	for (int a = 1; a < input.size(); a++)
	{
		std::vector<std::string> line = parseLine(input[a], " ");
		//std::cout << input[a] << std::endl;
		distances[{line[0], line[2]}] = std::stoi(line[4]);
		distances[{line[2], line[0]}] = std::stoi(line[4]);
		//std::cout << "Here 1" << std::endl;
		bool found_left = false, found_right = false;
		for (int b = 0; b < locations.size(); b++)
		{
		//std::cout << "Here 2" << std::endl;
			if (locations[b] == line[0])
			    found_left = true;
			if (locations[b] == line[2])
			    found_right = true;
		}
		if (!found_left)
		    locations.push_back(line[0]);
		if (!found_right)
		    locations.push_back(line[2]);
	}
	
	std::vector<int> trips;
	std::cout << "Input processed..." << std::endl;
	std::sort(locations.begin(), locations.end());
	std::cout << "Locations sorted..." << std::endl;
	do 
	{
		int new_distance = 0;
		for (int a = 1; a < locations.size(); a++)
		{
			//std::cout << "Distance from " << locations[a-1] << " to " << locations[a] << " is " << distances[{locations[a-1], locations[a]}] << std::endl;
			new_distance += distances[{locations[a - 1], locations[a]}];
		}
		trips.push_back(new_distance);
	} while (std::next_permutation(locations.begin(), locations.end()));
	
	int answer_1 = trips[0];
	int answer_2 = trips[0];
	
	for (int a = 1; a < trips.size(); a++)
	{
		if (trips[a] < answer_1)
		    answer_1 = trips[a];
		if (trips[a] > answer_2)
		    answer_2 = trips[a];
	}
	
	std::cout << "Advent of Code 2015 Day 9 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;
	
}

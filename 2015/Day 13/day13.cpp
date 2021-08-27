//
//  Advent of Code 2015
//  Day 01
//
//  By PatchesTheDipstick
//


//  System includes...

#include <iostream>
#include <limits>
#include <map>
#include <regex>
#include <string>
#include <vector>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int recBest(std::string name, std::string first, std::vector<std::string> guests, std::map<std::string, std::map<std::string, int>> happiness)
{
	if (guests.size() == 1)
	{
		return -happiness[name][guests[0]] + (-happiness[guests[0]][first]);
	}
	else
	{
		int happy = std::numeric_limits<int>::max();
		int happy_index = -1;
		for (int a = 0; a < guests.size(); a++)
		{
			if (happiness[name][guests[a]] < happy)
			{
				happy = happiness[name][guests[a]];
				happy_index = a;
			}
		}
		std::string new_name = guests[happy_index];
		guests.erase(guests.begin() + happy_index);
		return (-happy) + recBest(new_name, first, guests, happiness);
	}
	return -1;
}

int getBest(std::vector<std::string> guests, std::map<std::string, std::map<std::string, int>> happiness)
{
	std::vector<int> dists;
	dists.resize(guests.size(), std::numeric_limits<int>::max());
	std::vector<int> predecessor;
	predecessor.resize(guests.size(), -1);
	dists[0] = 0;
	for (int a = 0; a < guests.size() - 1; a++)
	{
		for (int b = a + 1; b < guests.size(); b++)
		{
			if (dists[a] + happiness[guests[a]][guests[b]] < dists[b])
			{
				dists[b] = dists[a] + happiness[guests[a]][guests[b]];
				predecessor[b] = a;
			}
		}
	}
	int total = 0;
	for (int a = 0; a < dists.size(); a++)
	{
		total += dists[a];
	}
	return -total;
}

void addOnce(std::vector<std::string> &guests, std::string name)
{
	for (int a = 0; a < guests.size(); a++)
	{
		if (guests[a] == name)
		{
			return;
		}
	}
	guests.push_back(name);
}
	
int main(int argc, char** argv)
{
	
	std::vector<std::string> input = ptd::utils::getInput("input.txt");
	std::vector<std::string> guests;
	std::map<std::string, std::map<std::string, int>> happiness;
	
	std::regex filter("([a-zA-Z]+) would (lose|gain) ([0-9]+) happiness units by sitting next to ([a-zA-Z]+).");
	for (std::string line : input)
	{
		std::smatch token;
		std::regex_match(line, token, filter);
		int happy = ptd::utils::stringToInt(token.str(3));
		//  Using shortest path, so taking the inverse of the happiness...
		if (token.str(2) == "gain")
		{
			happy = -happy;
		}
		happiness[token.str(1)][token.str(4)] += happy;
		happiness[token.str(4)][token.str(1)] += happy;
		addOnce(guests, token.str(1));
		addOnce(guests, token.str(4));
	}
	std::cout << "Input parsed..." << std::endl;
	std::vector<std::string> guests_one = guests;
	std::string name = guests_one[0];
	guests_one.erase(guests_one.begin());
	
	int answer_one = recBest(name, name, guests_one, happiness);
	
	std::cout << "Advent of Code 2015 Day 1 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_one << std::endl;
	
	std::vector<std::string> guests_two;
	for (std::string name : guests)
	{
		guests_two.push_back(name);
		happiness["Patches"][name] = 0;
		happiness[name]["Patches"] = 0;
	}
	name = guests_two[0];
	guests_two.erase(guests_two.begin());
	int answer_two = recBest(name, name, guests_two, happiness);
	
	std::cout << "    Part 2 : " << answer_two << std::endl;

	return (0);

}

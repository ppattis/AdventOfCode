//
//  Advent of Code 2015
//  Day 14
//
//  By PatchesTheDipstick
//


//  System includes...

#include <iostream>
#include <regex>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

class Reindeer
{
	private:
	
	std::string name;
	int speed;
	int can_fly;
	int rest_required;
	bool currently_resting;
	int time_in_state;
	int distance_traveled;
	int points;
	
	public:
	
	Reindeer()
	{
		currently_resting = false;
		time_in_state = 0;
		distance_traveled = 0;
		points = 0;
	}
	
	void setName(std::string new_name)
	{
		name = new_name;
	}
	
	void setSpeed(int new_speed)
	{
		speed = new_speed;
	}
	
	void setRun(int new_run)
	{
		can_fly = new_run;
	}
	
	void setRest(int new_rest)
	{
		rest_required = new_rest;
	}
	
	int getDistance()
	{
		return distance_traveled;
	}
	
	void awardPoint()
	{
		points++;
	}
	
	std::string getName()
	{
		return name;
	}
	
	int getPoints()
	{
		return points;
	}
	
	void update()
	{
		if (currently_resting)
		{
			if (time_in_state >= rest_required)
			{
				currently_resting = false;
				time_in_state = 1;
				distance_traveled += speed;
			}
			else
			{
				time_in_state++;
			}
		}
		else
		{
			if (time_in_state >= can_fly)
			{
				currently_resting = true;
				time_in_state = 1;
			}
			else
			{
				distance_traveled += speed;
				time_in_state++;
			}
		}
	}
	
	void printDeer()
	{
		std::string state = (currently_resting ? "resting" : "resting");
		std::cout << name << " flies " << speed << " km/s for " << can_fly;
		std::cout << " seconds, and then must rest for " << rest_required;
		std::cout << " seconds.  Is currently " << state << " and has flown ";
		std::cout << distance_traveled << "\n";
	}
};


int main(int argc, char** argv)
{
	
	std::regex filter ("^(.*) can fly (.*) km.* for (.*) sec.* for (.*) sec.*?");
	std::vector<std::string> input = ptd::utils::getInput("input.txt");
	std::vector<Reindeer> lineup;
	
	int race_time = 2503;
	for (int a = 0; a < input.size(); a++)
	{
		std::smatch token;
		std::regex_search(input[a], token, filter);
		Reindeer new_deer;
		new_deer.setName(token.str(1));
		new_deer.setSpeed(stoi(token.str(2)));
		new_deer.setRun(stoi(token.str(3)));
		new_deer.setRest(stoi(token.str(4)));
		lineup.push_back(new_deer);
	}
	for (int a = 1; a < race_time; a++)
	{
		for (int b = 0; b < lineup.size(); b++)
		{
			lineup[b].update();
		}
		
		int furthest_distance = lineup[0].getDistance();
		for (int a = 1; a < lineup.size(); a++)
		{
			if (lineup[a].getDistance() > furthest_distance)
			{
				furthest_distance = lineup[a].getDistance();
			}
		}
		for (int a = 0; a < lineup.size(); a++)
		{
			if (lineup[a].getDistance() == furthest_distance)
			{
				lineup[a].awardPoint();
			}
		}
	}
	
	int answer_1 = lineup[0].getDistance();
	int answer_2 = lineup[0].getPoints();
	std::cout << " Race complete..." << std::endl;
	for (int a = 0; a < lineup.size(); a++)
	{
		if (lineup[a].getDistance() > answer_1)
		{
			answer_1 = lineup[a].getDistance();
		}
		if (lineup[a].getPoints() > answer_2)
		{
			answer_2 = lineup[a].getPoints();
		}
	}
	
	std::cout << "Advent of Code 2015 Day 14 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}

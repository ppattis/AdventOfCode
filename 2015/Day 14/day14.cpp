//
//  Advent of Code 2015
//  Day 14
//
//  By PatchesTheDipstick
//


//  System includes...

#include <iostream>

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
		std::cout << name << std::endl;
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
			if (time_in_state == rest_required)
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
			if (time_in_state == can_fly)
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
};


int main(int argc, char** argv)
{
	
	std::vector<std::string> input = getInput("input.txt");
	std::vector<Reindeer> lineup;
	
	int race_time = 2503;
	for (int a = 1; a < input.size(); a++)
	{
		std::vector<std::string> line = parseLine(input[a], " ");
		Reindeer new_deer;
		std::cout << input[a] << std::endl;
		std::cout << line[0] << " " << line[3] << " " << line[6] << " " << line[13] << std::endl;
		new_deer.setName(line[0]);
		new_deer.setSpeed(stoi(line[3]));
		new_deer.setRun(stoi(line[6]));
		new_deer.setRest(stoi(line[13]));
		lineup.push_back(new_deer);
	}
	//std::cout << "Input processed.  " << lineup.size() << " deer." << std::endl;
	for (int a = 1; a < race_time; a++)
	{
		std::cout << "Race time : " << a + 1 << std::endl;
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
				std::cout << lineup[a].getName() << " gets a point." << std::endl;
				lineup[a].awardPoint();
			}
		}
			//std::cout << "Update deer " << b << " for second " << a << std::endl;
		
	}

	int answer_1 = lineup[0].getDistance();
	int answer_2 = lineup[0].getPoints();
	std::cout << " Race complete..." << std::endl;
	for (int a = 0; a < lineup.size(); a++)
	{
		std::cout << lineup[a].getName() << " " << lineup[a].getDistance() << " " << lineup[a].getPoints() << std::endl;
		if (lineup[a].getDistance() > answer_1)
		{
			answer_1 = lineup[a].getDistance();
		}
		if (lineup[a].getPoints() > answer_2)
		{
			answer_2 = lineup[a].getPoints();
		}
	}
	
	std::cout << "Advent of Code 2015 Day 1 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}

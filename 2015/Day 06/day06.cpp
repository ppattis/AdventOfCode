//
//  Advent of Code 2015
//  Day 06
//
//  By PatchesTheDipstick
//


//  System includes...

#include <iostream>
#include <fstream>
#include <string>

//  Third Party includes...



//  Project includes...

#include "../utils.hpp"


#define LIGHTS_PER_SIDE 1000

void initializeLightGridOne( bool input_grid[LIGHTS_PER_SIDE][LIGHTS_PER_SIDE] )
{
	for (int x = 0; x < LIGHTS_PER_SIDE; x++)
	{
		for (int y = 0; y < LIGHTS_PER_SIDE; y++)
		{
			input_grid[x][y] = false;
		}
	}
}

void initializeLightGridTwo( int input_grid[LIGHTS_PER_SIDE][LIGHTS_PER_SIDE] )
{
	for (int x = 0; x < LIGHTS_PER_SIDE; x++)
	{
		for (int y = 0; y < LIGHTS_PER_SIDE; y++)
		{
			input_grid[x][y] = 0;
		}
	}
}

void adjustLightsOne( bool input_grid[LIGHTS_PER_SIDE][LIGHTS_PER_SIDE], int start_x, int start_y, int end_x, int end_y, std::string command)
{
	for (int y = start_y; y <= end_y; y++)
	{
		for (int x = start_x; x <= end_x; x++)
		{
			if (command == "on")
			{
				input_grid[x][y] = true;
			}
			else if (command == "off")
			{
				input_grid[x][y] = false;
			}
			else if (command == "toggle")
			{
				input_grid[x][y] = !input_grid[x][y];
			}
		}
	}
}

void adjustLightsTwo( int input_grid[LIGHTS_PER_SIDE][LIGHTS_PER_SIDE], int start_x, int start_y, int end_x, int end_y, std::string command)
{
	//std::cout << command << "(" << start_x << "," << start_y << ") to (" << end_x << "," << end_y << "0" << std::endl;
	for (int y = start_y; y <= end_y; y++)
	{
		for (int x = start_x; x <= end_x; x++)
		{
			if (command == "on")
			{
				input_grid[x][y]++;
			}
			else if (command == "off")
			{
				input_grid[x][y]--;
				if (input_grid[x][y] < 0)
				{
					input_grid[x][y] = 0;
				}
			}
			else if (command == "toggle")
			{
				input_grid[x][y] += 2;
			}
		}
	}
}

int countLitLightsOne(bool input_grid[LIGHTS_PER_SIDE][LIGHTS_PER_SIDE])
{
	int return_value = 0;
	
	for (int x = 0; x < LIGHTS_PER_SIDE; x++)
	{
		for (int y = 0; y < LIGHTS_PER_SIDE; y++)
		{
			if (input_grid[x][y])
			{
				return_value++;
			}
		}
	}
	
	return ( return_value );
}

int countLitLightsTwo(int input_grid[LIGHTS_PER_SIDE][LIGHTS_PER_SIDE])
{
	int return_value = 0;
	
	for (int x = 0; x < LIGHTS_PER_SIDE; x++)
	{
		for (int y = 0; y < LIGHTS_PER_SIDE; y++)
		{
			return_value += input_grid[x][y];
		}
	}
	
	return ( return_value );
}

int main(int argc, char** argv)
{
	
	std::string input_file_name = "input.txt";
	std::string input_line;
	std::ifstream input_file (input_file_name);
	
	std::cout << "Declaring light grid one..." << std::endl;
	auto light_grid_1 = new bool[LIGHTS_PER_SIDE][LIGHTS_PER_SIDE];
	std::cout << "Declaring light grid two..." << std::endl;
	auto light_grid_2 = new int[LIGHTS_PER_SIDE][LIGHTS_PER_SIDE];
	initializeLightGridOne(light_grid_1);
	initializeLightGridTwo(light_grid_2);
	
	std::cout << "Opening input file " << input_file_name << "..." << std::endl;
	
	if (input_file.is_open())
	{
		std::cout << "Reading input file " << input_file_name << "..." << std::endl;
		
		while ( getline (input_file, input_line) )
		{
			
			std::string command = input_line.substr(0, input_line.find(' '));
			if (command == "turn")
			{
				input_line.erase(0, input_line.find(' ') + 1);
				command = input_line.substr(0, input_line.find(' '));
			}
			input_line.erase(0, input_line.find(' ') + 1);
			int start_x = std::stoi(input_line.substr(0, input_line.find(',')));
			input_line.erase(0, input_line.find(',') + 1);
			int start_y = std::stoi(input_line.substr(0, input_line.find(' ')));
			input_line.erase(0, input_line.find("h ") + 2);
			int end_x = std::stoi(input_line.substr(0, input_line.find(',')));
			input_line.erase(0, input_line.find(',') + 1);
			int end_y = std::stoi(input_line);
			
			adjustLightsOne(light_grid_1, start_x, start_y, end_x, end_y, command);
			adjustLightsTwo(light_grid_2, start_x, start_y, end_x, end_y, command);
		}
		
		std::cout << "Closing input file " << input_file_name << "..." << std::endl;
		input_file.close();
		
		int answer_1 = countLitLightsOne(light_grid_1);
		int answer_2 = countLitLightsTwo(light_grid_2);
		
		std::cout << "Advent of Code 2015 Day 6 answers:" << std::endl;
		std::cout << "    Part 1 : " << answer_1 << std::endl;
		std::cout << "    Part 2 : " << answer_2 << std::endl;
		
	}
	
	else
	{
		std::cout << "Unable to open " << input_file_name << "!" << std::endl;
	}
	delete [] light_grid_1;
	delete [] light_grid_2;
}

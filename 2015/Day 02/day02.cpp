//
//  Advent of Code 2015
//  Day 02
//
//  By PatchesTheDipstick
//


//  System includes...


//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

struct box
{
	int height;
	int width;
	int length;
};

int wrappingPaperRequired(const struct box present)
{
	int return_value = 0;
	
	int side[3];
	side[0] = present.width * present.height;
	side[1] = present.width * present.length;
	side[2] = present.height * present.length;
	
	int smallest = whichIsSmaller(whichIsSmaller(side[0], side[1]), side[2]);
	return_value = 2 * side[0];
	
	
	for (int a = 1; a < 3; a++)
	{
		return_value = return_value + (2 * side[a]);
		if (side[a] < smallest)
		{
			smallest = side[a];
		}  //  if (side[a] < smallest)
	}  //  for (int a = 1; a < 3; a++)
	return_value = return_value + smallest;
	return(return_value);
}  //  int wrappingPaperRequired(const struct box present)

int ribbonRequired(const struct box present)
{
	int return_value = whichIsSmaller(whichIsSmaller(((2 * present.length) + (2 * present.width)), ((2 * present.width) + (2 * present.height))), ((2 * present.height) + (2 * present.length)));
	int volume = present.length * present.width * present.height;
	return_value = return_value + volume;
	
	return (return_value);	
}  //  int ribbonRequired(const struct box present)

int main(int argc, char** argv)
{
	
	std::vector<std::string> input = getInput("input.txt");
	
	std::vector<struct box> boxes;
	struct box new_box;
	int answer_1 = 0, answer_2 = 0;
	
	for (int a = 1; a < input.size(); a++)
	{
		new_box.length = stoi(input[a].substr(0, input[a].find('x')));
		input[a].erase(0, input[a].find('x') + 1);
		new_box.width = stoi(input[a].substr(0, input[a].find('x')));
		input[a].erase(0, input[a].find('x') + 1);
		new_box.height = stoi(input[a]);
		boxes.push_back(new_box);
	}  //  for (int a = 0; a < input.size(); a++)

	for (int a = 0; a < boxes.size(); a++)
	{
		answer_1 = answer_1 + wrappingPaperRequired(boxes[a]);
		answer_2 = answer_2 + ribbonRequired(boxes[a]);
	}  //  for (int a = 0; a < boxes.size(); a++)
	
	std::cout << "Aoc 2015 Day 2 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;

}  //  int main(int argc, char** argv)

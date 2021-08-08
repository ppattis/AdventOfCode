//
//  Advent of Code 2015
//  Day 01
//
//  By PatchesTheDipstick
//


//  System includes...


//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

struct Ingredient
{
	std::string name;
	int capacity;
	int durability;
	int flavor;
	int texture;
	int calories;
};

int calculate(std::vector<Ingredient> stock, int a, int b, int c, int d)
{
	int return_value = 0;
	int cap = stock[0].capacity * a;
	cap += stock[1].capacity * b;
	cap += stock[2].capacity * c;
	cap += stock[3].capacity * d;
	//std::cout << "cap " << cap << std::endl;
	if (cap < 0)
	{
		cap = 0;
	}
	int dur = stock[0].durability * a;
	dur += stock[1].durability * b;
	dur += stock[2].durability * c;
	dur += stock[3].durability * d;
	//std::cout << "dur " << dur << std::endl;
	if (dur < 0)
	{
		dur = 0;
	}
	int fla = stock[0].flavor * a;
	fla += stock[1].flavor * b;
	fla += stock[2].flavor * c;
	fla += stock[3].flavor * d;
	//std::cout << "fla " << fla << std::endl;
	if (fla < 0)
	{
		fla = 0;
	}
	int tex = stock[0].texture * a;
	tex += stock[1].texture * b;
	tex += stock[2].texture * c;
	tex += stock[3].texture * d;
	//std::cout << "tex " << tex << std::endl;
	if (tex < 0)
	{
		tex = 0;
	}
	
	return_value = cap * dur * fla * tex;
	return return_value;
}

int countCalories(std::vector<Ingredient> stock, int a, int b, int c, int d)
{
	int return_value = 0;
	int cal = stock[0].calories * a;
	cal += stock[1].calories * b;
	cal += stock[2].calories * c;
	cal += stock[3].calories * d;
	return_value = cal;
	return return_value;
}

int main(int argc, char** argv)
{
	
	std::vector<Ingredient> cupboard = {{"Frosting", 4, -2, 0, 0, 5},
										{"Candy", 0, 5, -1, 0, 8},
										{"Butterscotch", -1, 0, 5, 0, 6},
										{"Sugar", 0, 0, -2, 2, 1}};
	

	std::vector<int> results;
	std::vector<int> results2;
	for (int a = 0; a <= 100; a++)
	{
		for (int b = 0; b <= 100; b++)
		{
			for (int c = 0; c <= 100; c++)
			{
				for (int d = 0; d <= 100; d++)
				{
					if (a + b + c + d == 100)
					{
						int temp = calculate(cupboard, a, b, c, d);
						if (temp > 0)
						{
							results.push_back(temp);
							if (countCalories(cupboard, a, b, c, d) == 500)
							{
								results2.push_back(temp);
							}
						}
					}
				}
			}
		}
	}
	int answer_1 = 0;
	
	for (int a = 0; a < results.size(); a++)
	{
		if (results[a] > answer_1)
		{
			answer_1 = results[a];
		}
	}
	std::cout << "Advent of Code 2015 Day 1 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	
	int answer_2 = 0;
	std::cout << results2.size() << std::endl;
	for (int a = 0; a < results2.size(); a++)
	{
		if (results2[a] > answer_2)
		{
			answer_2 = results2[a];
		}
	}
	
	std::cout << "    Part 2 : " << answer_2 << std::endl;

	return (0);

}

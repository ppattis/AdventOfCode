//
//  Advent of Code 2015
//  Day 05
//
//  By PatchesTheDipstick
//


//  System includes...


//  Third Party includes...



//  Project includes...

#include "../utils.hpp"

int main(int argc, char** argv)
{
	
	std::vector<std::string> input = getInput("input.txt");
    int part_1 = 0, part_2 = 0;
    std::vector<std::string> forbiden_list = { "ab", "cd", "pq", "xy" };

	for (int a = 0; a < input.size(); a++)
	{ 
		//  local variable declarations...
		int part_1_vowel_count = 0;
		bool part_1_has_double = false;
		bool part_1_contains_forbiden = false;
		bool part_2_has_pair_of_pair = false;
		bool part_2_has_pair_with_one_between = false;
		
		//  Test Part 1 Test 1
		//   Contains at least three vowels (aeiou)...
		std::cout << "Part 1 Test 1..." << std::endl;
		for (int b = 0; b < input[a].size(); b++)
		{
			if ( 
				(input[a][b] == 'a') ||
				(input[a][b] == 'e') ||
				(input[a][b] == 'i') ||
				(input[a][b] == 'o') ||
				(input[a][b] == 'u') )
			{
				part_1_vowel_count++;
			}
			
		}
		
		//  Test Part 1 Test 2
		//    Contains at least on letter that appears twice in a row...
		std::cout << "Part 1 Test 2..." << std::endl;
		for (int b = 1; b < input[a].size() - 2; b++)
		{
			std::cout << input[a].length() << std::endl;
			if (input[a][b] == input[a][b + 1])
			    part_1_has_double = true;
		}
		
		//  Test Part 1 Test 3
		//    Does not contain any forbidden strings...
		std::cout << "Part 1 Test 3..." << std::endl;
		for (int b = 0; b < forbiden_list.size(); b++)
		{
			if (input[a].find(forbiden_list[b]) != std::string::npos)
			{
				part_1_contains_forbiden = true;
			}
		}
		
		//  Test Part 2 Test 1
		std::cout << "Part 2 Test 1..." << std::endl;
		for (int b = 0; b < input[a].size() - 2; b++)
		{
			for (int c = b + 2; c < input[a].size() - 1; c++)
			{
				if (input[a].substr(b, 2) == input[a].substr(c, 2))
				{
					part_2_has_pair_of_pair = true;
				}				
			}
		}
		
		//  Test Part 2 Test 2
		std::cout << "Part 2 Test 2..." << std::endl;
		for (int b = 0; b < input[a].size() - 2; b++)
		{
			if (input[a][b] == input[a][b + 2])
			{
				part_2_has_pair_with_one_between = true;
			}
		}
		
		//  Now determine if Part one or Part two is fulfilled...
		if ( (part_1_vowel_count >= 3) && (part_1_has_double) && (!part_1_contains_forbiden) )
			part_1++;
		if ( (part_2_has_pair_of_pair) && (part_2_has_pair_with_one_between) )
			part_2++;
	}
	
	std::cout << "Advent of Code 2015 Day 5 answers:" << std::endl;
	std::cout << "    Part 1 : " << part_1 << std::endl;
	std::cout << "    Part 2 : " << part_2 << std::endl;
	
}


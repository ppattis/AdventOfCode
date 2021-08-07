//
//  Advent of Code 2015
//  Day 04
//
//  By PatchesTheDipstick
//


//  System includes...


//  Third Party includes...



//  Project includes...

#include "../utils.hpp"
#include "../../third_party/md5/md5.h"

ulint findMD5Key(const std::string secret, int num_zeros)
{
	ulint return_value = 0;
	std::string temp;
	bool found = false;
	std::string result;
	
	while (!found)
	{
		temp = secret + std::to_string(return_value);
		result = md5(temp);
		std::vector<std::string> compare = {"", "0", "00", "000", "0000", "00000", "000000"};

		if (result.substr(0, num_zeros) == compare[num_zeros])
		{
			found = true;
			break;
		}
		return_value++;
	}
	return (return_value - 1);
}

int main(int argc, char** argv)
{
	
	std::string test_input_1 = "abcdef";
	std::string test_input_2 = "pqrstuv";
	std::string input = "yzbqklnj";
		
	
	std::cout << "Advent of Code 2015 Day 4 answers:" << std::endl;
	std::cout << "    Test 1 answer is : " << findMD5Key(test_input_1, 5) << std::endl;
	std::cout << "    Test 2 answer is : " << findMD5Key(test_input_2, 5) << std::endl;
	std::cout << "    Part 1           : " << findMD5Key(input, 5) << std::endl;
	std::cout << "    Part 2           : " << findMD5Key(input, 6) << std::endl;
		

}

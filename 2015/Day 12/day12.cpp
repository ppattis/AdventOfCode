//
//  Advent of Code 2015
//  Day 12
//
//  By PatchesTheDipstick
//


//  System includes...


//  Third Party includes...
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

namespace pt = boost::property_tree;


//  Project includes...

#include "../utils.hpp"

int main(int argc, char** argv)
{
	
	pt::ptree root;
	pt::read_json("input.txt", root);
	
	
	/*
	std::cout << "Advent of Code 2015 Day 12 answers:" << std::endl;
	std::cout << "    Part 1 : " << answer_1 << std::endl;
	std::cout << "    Part 2 : " << answer_2 << std::endl;
	*/
	return (0);

}

#
#  Advent of Code 2015
#  Day 09
#
#  By PatchesTheDipstick
#

from itertools import permutations

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

if __name__ == '__main__':
	
	input = getInput("input.txt")
	all_cities = []
	distances = {}
	possibles = []
	for line in input:
		token = line.split()
		city_one = token[0]
		city_two = token[2]
		dist = int(token[4])
		if city_one not in distances.keys():
			distances[city_one] = {}
		if city_two not in distances.keys():
			distances[city_two] = {}
		distances[city_one][city_two] = dist
		distances[city_two][city_one] = dist
		all_cities.append(city_one)
		all_cities.append(city_two)
	cities = set(all_cities)
	options = permutations(cities)
	shortest = -1
	for opt in options:
		temp = 0
		for a in range(len(opt) - 1):
			temp += distances[opt[a]][opt[a + 1]]
		possibles.append(temp)
	
	
	
	part_one = min(possibles)
	part_two = max(possibles)
	print("Advent of Code 2015 Day 09")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
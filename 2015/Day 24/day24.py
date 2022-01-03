#
#  Advent of Code 2015
#  Day 24
#
#  By PatchesTheDipstick
#

from itertools import combinations

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def find_answer(weights, compartments):
	targ = sum(weights) // compartments
	entagles = []
	for i in range(1, len(weights)):
		for option in combinations(weights, i):
			if sum(option) == targ:
				entagle = 1
				for x in option:
					entagle *= x
				entagles.append(entagle)
	return min(entagles)

if __name__ == '__main__':
	
	input = getInput("input.txt")
	packages = [int(a) for a in input]

	print("Advent of Code 2015 Day 24")
	print("  Part one:", find_answer(packages, 3))
	print("  Part two:", find_answer(packages, 4))	
	
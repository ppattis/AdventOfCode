#
#  Advent of Code 2015
#  Day 
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
	packages = [int(a) for a in input]
	total_weight = sum(packages)
	third_weight = total_weight / 3
	options = permutations(packages)
	
	entaglements = {}
	for choice in options:
		left = third_weight
		new_set = []
		for a in choice:
			if a < left:
				new_set.append(a)
			elif a == left:
				new_set.append(a)
				ent = 1
				if new_set not in entaglements.keys():
					for b in new_set:
						ent *= b
					entaglements[new_set] = ent
				break
			else:
				break
	print(entaglements)
	
	part_one = 0
	part_two = 0
	print("Advent of Code 2015 Day 03")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
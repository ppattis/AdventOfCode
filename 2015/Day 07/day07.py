#
#  Advent of Code 2015
#  Day 07
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

if __name__ == '__main__':
	
	input = getInput("input.txt")
	gates = {}
	for line in input:
		tokens = line.split()
		gate = []
		if tokens[0] == "NOT":
			
	
	part_one = 0
	part_two = 0
	
	
	
	print("Advent of Code 2015 Day 07")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
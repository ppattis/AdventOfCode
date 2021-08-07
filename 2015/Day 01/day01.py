#
#  Advent of Code 2015
#  Day 01
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read.splitlines()
	return input

if __name__ == '__main__':
	
	input = getInput("input.txt")
	floor = 0
	first_basement = -1
	for index, char in enumerate(input[0]):
		if char == "(":
			floor += 1
		else:
			floor -= 1
		if (floor < 0) and (first_basement == -1):
			first_basement = index
			
	print("Advent of Code 2015 Day 01")
	print("  Part one:", floor)
	print("  Part two:", first_basement)
#
#  Advent of Code 2015
#  Day 
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
	
	
	part_one = 0
	part_two = 0
	print("Advent of Code 2015 Day 03")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
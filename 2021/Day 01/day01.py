#
#  Advent of Code 2021
#  Day 01
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def part_one(depths):
	answer = 0
	last = depths[0]
	for d in depths:
		if d > last:
			answer += 1
		last = d
	return answer

def part_two(depths):
	answer = 0
	last = depths[0] + depths[1] + depths[2]
	for i in range(len(depths) - 2):
		curr = depths[i] + depths[i + 1] + depths[i + 2]
		if curr > last:
			answer += 1
		last = curr
	return answer

if __name__ == '__main__':
		
	depths = [int(i) for i in getInput("input.txt")]

	print("Advent of Code 2021 Day 01")
	print("  Part one:", part_one(depths))
	print("  Part two:", part_two(depths))	
	
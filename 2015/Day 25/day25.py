#
#  Advent of Code 2015
#  Day 
#
#  By PatchesTheDipstick
#
import re

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

if __name__ == '__main__':
	
	input = getInput("input.txt")
	
	pattern = re.compile('.*row (\d*), column (\d*).')
	token = pattern.search(input[0])
	row = int(token.group(1))
	col = int(token.group(2))
	
	last_row = row + col - 1
	index = 0
	for a in range(1, last_row):
		index += a
	index += col
	print(index)
	grid = []
	value = 20151125
	for a in range(2, index + 1):
		print(a)
		value *= 252533
		value %= 33554393
	
	
	
	part_one = value
	part_two = 0
	print("Advent of Code 2015 Day 03")
	print("  Part one:", part_one)
	print("  Part two: Free Star")
	
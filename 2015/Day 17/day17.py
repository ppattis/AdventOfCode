#
#  Advent of Code 2015
#  Day 
#
#  By PatchesTheDipstick
#
import itertools
from time import time

start_time = time()

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def part_one(containers):
	amt = 0
	min_i = 9999
	for i in range(len(containers) - 1):
		for c in itertools.combinations(containers, i):
			if sum(c) == 150:
				if i < min_i:
					min_i = i
				amt += 1
	return amt, min_i

def part_two(containers, min_containers):
	ans = 0
	for c in itertools.combinations(containers, min_containers):
		if sum(c) == 150:
			ans += 1
	return ans

if __name__ == '__main__':
	
	input = getInput("input.txt")
	containers = [int(a) for a in input]

	answer_one, min_containers = part_one(containers)
	print(min_containers)
	print("Advent of Code 2015 Day 03")
	print("  Part one:", answer_one, 'run time:', time() - start_time)
	print("  Part two:", part_two(containers, min_containers), 'run time:', time() - start_time)	
	
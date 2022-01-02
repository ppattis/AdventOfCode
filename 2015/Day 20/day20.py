#
#  Advent of Code 2015
#  Day 20
#
#  By PatchesTheDipstick
#

from collections import defaultdict

def def_house():
	return 0

def part_one(input):
	houses = defaultdict(def_house)
	for i in range(1, input // 10):
		elf = i
		while elf <= input // 10:
			houses[elf] += 10 * i
			elf += i
		if houses[i] >= input:
			return i

def part_two(input):
	houses = defaultdict(def_house)
	for i in range(1, input // 11):
		elf = i
		house = 1
		while house <= 50:
			houses[elf] += 11 * i
			elf += i
			house += 1
		if houses[i] >= input:
			return i

if __name__ == '__main__':
	
	input = 33100000
	
	print("Advent of Code 2015 Day 20")
	print("  Part one:", part_one(input))
	print("  Part two:", part_two(input))	
	
#
#  Advent of Code 2015
#  Day 05
#
#  By PatchesTheDipstick
#

import re

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def countVowels(line):
	count = 0
	for char in line:
		if char in "aeiou":
			count += 1
	return count
	
def hasDoubleLetter(line):
	for a in range(len(line) - 1):
		if line[a] == line[a + 1]:
			return True
	return False
	
def noForbiden(line):
	forbiden = [ "ab", "cd", "pq", "xy" ]
	for a in range(len(line) - 1):
		s = line[a] + line[a + 1]
		if s in forbiden:
			return False
	return True
	
def containsTwoPairs(line):
	if len(re.findall(r"([a-z]{2}).*\1", line)) > 0:
		return True
	return False

def containsTrio(line):
	if len(re.findall(r"([a-z]).\1", line)) > 0:
		return True
	return False

if __name__ == '__main__':
	
	input = getInput("input.txt")
	part_one = 0
	part_two = 0
	for line in input:
		if (countVowels(line) >= 3):
			if (hasDoubleLetter(line)):
				if (noForbiden(line)):
					part_one += 1
		if containsTwoPairs(line):
			if containsTrio(line):
				part_two += 1
	
	
	print("Advent of Code 2015 Day 05")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
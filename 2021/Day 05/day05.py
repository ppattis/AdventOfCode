#
#  Advent of Code 2021
#  Day 05
#
#  By PatchesTheDipstick
#
from collections import defaultdict

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def empty_sea():
	return 0

def build_point(s):
	first, last = s.split(",")
	return (int(first), int(last))

def build_line(f, l):
	points = []
	if f[0] == l[0]:
		for y in range(min(f[1], l[1]), max(f[1], l[1]) + 1):
			points.append((f[0], y))
	elif f[1] == l[1]:
		for x in range(min(f[0], l[0]), max(f[0], l[0]) + 1):
			points.append((x, f[1]))
	else:
		# possible diagonal lines:
		#  first_x is lower than last_x and first_y is less than last_y
		if f[0] < l[0] and f[1] < l[1]:
			for x, y in zip(range(f[0], l[0] + 1), range(f[1], l[1] + 1)):
				points.append((x, y))
		#  first_x is lower than last_x, but first_y is higher than last_y
		elif f[0] < l[0] and f[1] > l[1]:
			for x, y in zip(range(f[0], l[0] + 1), range(f[1], l[1] - 1, -1)):
				points.append((x, y))
		#  first_x is higher than last_x, but first_y is lower than last_y
		elif f[0] > l[0] and f[1] < l[1]:
			for x, y in zip(range(f[0], l[0] - 1, -1), range(f[1], l[1] + 1)):
				points.append((x, y))
		#  first_x is higher than last_x and first_y is higher than last_y
		else:
			for x, y in zip(range(f[0], l[0] - 1, -1), range(f[1], l[1] - 1, -1)):
				points.append((x, y))
	
	return points

def count_overlap(ocean):
	answer = 0
	for val in ocean.keys():
		if ocean[val] > 1:
			answer += 1
	
	return answer

def print_ocean(ocean):
	min_x = min([x[0] for x in ocean.keys()])
	min_y = min([x[1] for x in ocean.keys()])
	max_x = max([x[0] for x in ocean.keys()])
	max_y = max([x[1] for x in ocean.keys()])
	for y in range(min_y, max_y + 1):
		for x in range(min_x, max_y + 1):
			if ocean[(x, y)] == 0:
				print(".", end="")
			else:
				print(ocean[(x, y)], end="")
		print()

if __name__ == '__main__':
	
	input = getInput("input.txt")
	
	lines = []
	ocean_one = defaultdict(empty_sea)
	ocean_two = defaultdict(empty_sea)
	min_x = 99999999999
	min_y = 99999999999
	max_x = -99999999999
	max_y = -99999999999

	for line in input:
		first, last = line.split(" ->")
		first = build_point(first)
		last = build_point(last)
		min_x = min([min_x, first[0], last[0]])
		min_y = min([min_y, first[1], last[1]])
		max_x = max([max_x, first[0], last[0]])
		max_y = max([max_y, first[1], last[1]])
		#print(first, "to", last)
		if first[0] == last[0] or first[1] == last[1]:
			for point in build_line(first, last):
				ocean_one[point] += 1
				ocean_two[point] += 1
		else:
			for point in build_line(first, last):
				ocean_two[point] += 1
	print("Advent of Code 2021 Day 05")
	print("  Part one:", count_overlap(ocean_one))
	print("  Part two:", count_overlap(ocean_two))	
	
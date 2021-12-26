#
#  Advent of Code 2015
#  Day 
#
#  By PatchesTheDipstick
#

from copy import deepcopy

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def print_lights(lights):
	for row in lights:
		for col in row:
			print(col, end='')
		print()
	print()

def within_lights(r, c, lights):
	if r < 0:
		return False
	if r >= len(lights):
		return False
	if c < 0:
		return False
	if c >= len(lights[r]):
		return False
	return True

def run(lights):
	new_lights = deepcopy(lights)
	for r, row in enumerate(lights):
		for c, col in enumerate(row):
			count = 0
			for rr in range(r - 1, r + 2):
				for cc in range(c - 1, c + 2):
					if within_lights(rr, cc, lights):
						#print(f'({rr}, {cc}) is ({lights[rr][cc]})')
						if rr != r or cc != c:
							if lights[rr][cc] == '#':
								#print(rr, cc, 'is on', end='; ')
								count += 1
			#print()
			#print('r:', r, 'c:', c, 'light:', lights[r][c], 'count:', count)
			if col == '#':
				if count == 2 or count == 3:
					new_lights[r][c] = '#'
				else:
					new_lights[r][c] = '.'
			else:
				if count == 3:
					new_lights[r][c] = '#'
				else:
					new_lights[r][c] = '.'
	return new_lights

def part_one(lights):
	for i in range(100):
		lights = run(lights)
	ans = 0
	for row in lights:
		ans += row.count('#')
	return ans

def part_two(lights):
	lights[0][0] = '#'
	lights[0][len(lights[0]) - 1] = '#'
	lights[len(lights) - 1][0] = '#'
	lights[len(lights) - 1][len(lights[0]) - 1] = '#'
	for i in range(100):
		lights = run(lights)
		lights[0][0] = '#'
		lights[0][len(lights[0]) - 1] = '#'
		lights[len(lights) - 1][0] = '#'
		lights[len(lights) - 1][len(lights[0]) - 1] = '#'
	ans = 0
	for row in lights:
		ans += row.count('#')
	return ans

if __name__ == '__main__':
	
	input = getInput("input.txt")
	lights = [[a for a in line] for line in input]
	#print_lights(deepcopy(lights))
	
	print("Advent of Code 2015 Day 03")
	print("  Part one:", part_one(deepcopy(lights)))
	print("  Part two:", part_two(deepcopy(lights)))	
	
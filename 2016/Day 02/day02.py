#
#  Advent of Code 2016
#  Day 02
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def part_one(directions):
	keypad = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
	code = ""
	x = y = 1
	for dir in directions:
		for d in dir:
			if d == 'U':
				if y > 0:
					y -=1
			elif d == 'D':
				if y < 2:
					y += 1
			elif d == 'L':
				if x > 0:
					x -= 1
			elif d == 'R':
				if x < 2:
					x += 1
		code += str(keypad[y][x])
	return code

def part_two(directions):
	keypad = []
	keypad.append(['N', 'N', '1', 'N', 'N'])
	keypad.append(['N', '2', '3', '4', 'N'])
	keypad.append(['5', '6', '7', '8', '9'])
	keypad.append(['N', 'A', 'B', 'C', 'N'])
	keypad.append(['N', 'N', 'D', 'N', 'N'])
	r = 2
	c = 0
	code = ""
	for dir in directions:
		for d in dir:
			if d =='U':
				if c in [1, 3] and r > 1:
					r -=1
				elif c == 2 and r > 0:
					r -= 1
			elif d == 'D':
				if c in [1, 3] and r < 3:
					r +=1
				elif c == 2 and r < 4:
					r += 1
			elif d =='L':
				if r in [1, 3] and c > 1:
					c -=1
				elif r == 2 and c > 0:
					c -= 1
			elif d == 'R':
				if r in [1, 3] and c < 3:
					c +=1
				elif r == 2 and c < 4:
					c += 1
		code += keypad[r][c]
	return code


if __name__ == '__main__':
	
	input = getInput("input.txt")
	
	print("Advent of Code 2016 Day 02")
	print("  Part one:", part_one(input))
	print("  Part two:", part_two(input))	
	
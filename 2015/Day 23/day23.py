#
#  Advent of Code 2015
#  Day 23
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def run(program, initial_a):
	pc = 0
	a = initial_a
	b = 0
	while (pc >= 0) and (pc < len(program)):
		op = program[pc][:3]
		param = program[pc][4:]
		param = param.split(', ')
		if op == 'hlf':
			if param[0] == 'a':
				a = a // 2
			elif param[0] == 'b':
				b = b // 2
			pc += 1
		elif op == 'tpl':
			if param[0] == 'a':
				a = a * 3
			elif param[0] == 'b':
				b = b * 3
			pc += 1
		elif op == 'inc':
			if param[0] == 'a':
				a += 1
			elif param[0] == 'b':
				b += 1
			pc += 1
		elif op == 'jmp':
			pc += int(param[0])
		elif op == 'jie':
			if param[0] == 'a':
				if a % 2 == 0:
					pc += int(param[1])
				else:
					pc += 1
			elif param[0] == 'b':
				if b % 2 == 0:
					pc += int(param[1])
				else:
					pc += 1
		elif op == 'jio':
			if param[0] == 'a':
				if a == 1:
					pc += int(param[1])
				else:
					pc += 1
			elif param[0] == 'b':
				if b == 1:
					pc += int(param[1])
				else:
					pc += 1
	return b



if __name__ == '__main__':
	
	input = getInput("input.txt")
	

	print("Advent of Code 2015 Day 23")
	print("  Part one:", run(input, 0))
	print("  Part two:", run(input, 1))	
	
#
#  Advent of Code 2015
#  Day 03
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
	houses_one = {}
	houses_two = {}
	x_one = 0
	y_one = 0
	x_santa = 0
	y_santa = 0
	x_robo = 0
	y_robo = 0
	houses_one[(x_one, y_one)] = 1
	houses_two[(x_one, y_one)] = 2
	santas_turn = True
	for line in input:
		for char in line:
			if char == '<':
				x_one -= 1
				if santas_turn:
					x_santa -= 1
				else:
					x_robo -= 1
			elif char == '^':
				y_one -= 1
				if santas_turn:
					y_santa -= 1
				else:
					y_robo -= 1
			elif char == '>':
				x_one += 1
				if santas_turn:
					x_santa += 1
				else:
					x_robo += 1
			elif char == 'v':
				y_one += 1
				if santas_turn:
					y_santa += 1
				else:
					y_robo += 1
			if (x_one, y_one) in houses_one.keys():
				houses_one[(x_one, y_one)] += 1
			else:
				houses_one[(x_one, y_one)] = 1
			if santas_turn:
				santas_turn = False
				if (x_santa, y_santa) in houses_two.keys():
					houses_two[(x_santa, y_santa)] += 1
				else:
					houses_two[(x_santa, y_santa)] = 1
			else:
				santas_turn = True
				if (x_robo, y_robo) in houses_two.keys():
					houses_two[(x_robo, y_robo)] += 1
				else:
					houses_two[(x_robo, y_robo)] = 1
				
	part_one = len(houses_one)
	part_two = len(houses_two)
	print("Advent of Code 2015 Day 03")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	

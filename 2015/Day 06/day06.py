#
#  Advent of Code 2015
#  Day 06
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.readlines()
	return input

if __name__ == '__main__':
	
	input = getInput("input.txt")
	lights_one = []
	lights_two = []
	for y in range(0, 1000):
		row_one = []
		row_two = []
		for x in range(0, 1000):
			row_one.append(False)
			row_two.append(0)
		lights_one.append(row_one)
		lights_two.append(row_two)
	for line in input:
		tokens = line.split()
		if tokens[0] == "turn":
			if tokens[1] == "on":
				coord_one = tokens[2].split(',')
				coord_two = tokens[4].split(',')
				for x in range(int(coord_one[0]), int(coord_two[0]) + 1):
					for y in range(int(coord_one[1]), int(coord_two[1]) + 1):
						lights_one[x][y] = True
						lights_two[x][y] += 1
			else:
				coord_one = tokens[2].split(',')
				coord_two = tokens[4].split(',')
				for x in range(int(coord_one[0]), int(coord_two[0]) + 1):
					for y in range(int(coord_one[1]), int(coord_two[1]) + 1):
						lights_one[x][y] = False
						lights_two[x][y] -= 1
						if lights_two[x][y] < 0:
							lights_two[x][y] = 0
		else:
			coord_one = tokens[1].split(',')
			coord_two = tokens[3].split(',')
			for x in range(int(coord_one[0]), int(coord_two[0]) + 1):
				for y in range(int(coord_one[1]), int(coord_two[1]) + 1):
					if lights_one[x][y] == True:
						lights_one[x][y] = False
					else:
						lights_one[x][y] = True
					lights_two[x][y] += 2
	part_one = 0
	part_two = 0
	for x in range(0, 1000):
		for y in range(0, 1000):
			if lights_one[x][y] == True:
				part_one += 1
			part_two += lights_two[x][y]
	
	print("Advent of Code 2015 Day 06")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
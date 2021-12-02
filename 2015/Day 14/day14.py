#
#  Advent of Code 2015
#  Day 14
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def race(deer):
	racers = dict(deer)

	for i in range(2503):
		for r in racers.keys():
			racers[r][4] += 1
			if racers[r][3]:
				racers[r][5] += racers[r][0]
				if racers[r][1] == racers[r][4]:
					racers[r][3] = False
					racers[r][4] = 0
			else:
				if racers[r][2] == racers[r][4]:
					racers[r][3] = True
					racers[r][4] = 0
		lead = 0
		for r in racers.keys():
			if racers[r][5] > lead:
				lead = racers[r][5]
		for r in racers.keys():
			if racers[r][5] == lead:
				racers[r][6] += 1
	furthest = 0
	most_points = 0
	for r in racers.keys():
		if racers[r][5] > furthest:
			furthest = racers[r][5]
		if racers[r][6] > most_points:
			most_points = racers[r][6]
	return furthest, most_points

if __name__ == '__main__':
	
	input = getInput("input.txt")
	deer = {}
	for line in input:
		token = line.split()
		#         deer = [fly_speed, fly_time, rest_time, flying, seconds_in_state, distance, points]
		deer[token[0]] = [int(token[3]), int(token[6]), int(token[13]), True, 0, 0, 0]

	part_one, part_two = race(deer)
	print("Advent of Code 2015 Day 14")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
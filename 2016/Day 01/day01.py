#
#  Advent of Code 2016
#  Day 01
#
#  By PatchesTheDipstick
#
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

def part_one(directions):
	x = 0
	y = 0
	f = 0
	for dir in directions:
		if dir[0] == 'L':
			f -= 1
			if f < 0:
				f = 3
		else:
			f += 1
			if f > 3:
				f = 0
		x += dir[1] * dx[f]
		y += dir[1] * dy[f]
	return abs(x) + abs(y)

def part_two(directions):
	locations = {}
	x = 0
	y = 0
	f = 0
	locations[(x, y)] = 1
	for dir in directions:
		if dir[0] == 'L':
			f -= 1
		else:
			f += 1
		f %= 4
		for i in range(dir[1]):
			x += dx[f]
			y += dy[f]
			if (x, y) not in locations.keys():
				locations[(x, y)] = 0
			locations[(x, y)] += 1
			if locations[(x, y)] == 2:
				return abs(x) + abs(y)

if __name__ == '__main__':

	with open('input.txt', 'r') as fin:
		data = fin.read()
	data = data.strip('\n').split(', ')
	directions = []
	for dir in data:
		d = dir[:1]
		l = int(dir[1:])
		directions.append((d, l))


	print("Advent of Code 2016 Day 01")
	print("  Part one:", part_one(directions))
	print("  Part two:", part_two(directions))	
	
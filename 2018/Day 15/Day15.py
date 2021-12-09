#
#  Advent of Code 2018
#  Day 
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	data = []
	with open(file_name) as input_file:
		data = input_file.read().splitlines()
	return data

def dist(s, e):
	r = abs(s[0] - e[0])
	c = abs(s[1] - e[1])
	return (r * r) + (c * c)

def bookOrder(l):
	ll = sorted(l, key=lambda tup: (tup[1],tup[0]))
	return ll[0]

class Node(object):
	def __init__(self, r, c, g = 0, h = 0, f = 0, p = None):
		self.r = r
		self.c = c
		self.p = p
		self.g = 0
		self.h = 0
		self.f = 0

	def __lt__(self, other):
		return self.f < other.f

	def __eq__(self, other):
		return self.r == other.r and self.c == other.c


class Npc(object):
	def __init__(self, r, c, t):
		self.r = r
		self.c = c
		self.t = t

	def enemiesAdjacent(self, grid):
		adj = []
		for c in [(1, 0), (-1, 0), (0, -1), (0, 1)]:
			if grid[self.r + c[0]][self.c + c[1]] not in [".", "#", self.t]:
				adj.append((self.r + c[0], self.c + c[1]))
		return adj

	def getMove(self, grid, s, e):
		# node = (r, c, g, h, f, parent)
		q = []
		d = []
		p = []
		q.append(Node(s[0], s[1]))
		while len(q) > 0:
			cc = q.pop(0)
			if (cc.r, cc.c) == e:
				while cc.p is not None:
					p.append(cc)
					cc = cc.p
					break
			for c in [(1, 0), (-1, 0), (0, -1), (0, 1)]:
				if grid[cc[0] + c[0]][cc[1] + c[1]] == ".":
					nn = Node(cc[0] + c[0], cc[1] + c[1])
					nn.g = cc.g + 1
					nn.h = dist((cc.r, cc.c), e)
					nn.f = nn.g + nn.h
					update = False
					for dd in d:
						if dd == nn and dd > nn:
							dd = nn
							update = True
					if not update:
						q.append(nn)
		return (p[1], len(p))

	def move(self, grid):
		reachable = []
		for c in [(1, 0), (-1, 0), (0, -1), (0, 1)]:
			if grid[self.r + c[0]][self.c + c[1]] == ".":
				q.append((self.r + c[0], self.c + c[1]))
		while len(q) > 0:
			cc = q.pop(0)
			for c in [(1, 0), (-1, 0), (0, -1), (0, 1)]:
				if grid[cc[0] + c[0]][cc[1] + c[1]] == ".":
					q.append((cc[0] + c[0], cc[1] + c[1]))
			reachable.append(cc)
		spots = []
		enemies = []
		for r, row in grid:
			for c, col in row:
				if col not in [".", "#", self.t]:
					enemies.append((r, c))
		for e in enemies:
			for c in [(1, 0), (-1, 0), (0, -1), (0, 1)]:
				if grid[e.r + c[0]][e.c + c[1]] == ".":
					spots.append((cc[0] + c[0], cc[1] + c[1]))
		spots = [s for s in spots if s in reachable]
		moves = []
		if len(spots) > 0:
			for spot in spots:
				move = getMove(grid, (self.r, self.c), spot)
				if move[1] > 0:
					moves.append(move)
		if len(moves) == 0:
			return False
		else:
			small = min(moves)[1]
			moves = [m[0] for m in moves if m[1] == small]
			move = bookOrder(moves)
			self.r = move[0]
			self.c = move[1]
			return True
		return False

def fightOver(npcs):
	t = [a.t for a in npcs]
	if len(set(t)) == 1:
		return True
	else:
		return False

if __name__ == '__main__':
	
	data = getInput("input.txt")
	
	grid = []
	npcs = []
	for r, row in enumerate(data):
		new_row = []
		for c, col in enumerate(row):
			new_row.append(col)
			if col in ["E", "G"]:
				npcs.append(Npc(r, c, col))
		grid.append(new_row)

	while not fightOver(npcs):
		dead = []
		for npc in npcs:
			if npc.hp > 0:
				if len(npc.enemiesAdjacent(grid)) == 0:
					npc.move(grid)
				if len(npc.enemiesAdjacent(grid)) > 0:
					npc.attack(grid)
					dead = [a for a in npcs if a.hp <= 0]
					
		dead = [a for a in npcs if a.hp <= 0]
		for d in dead:
			grid

	
	part_one = 0
	part_two = 0
	print("Advent of Code 2018 Day ")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
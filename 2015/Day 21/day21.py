#
#  Advent of Code 2015
#  Day 21
#
#  By PatchesTheDipstick


def fight(attack, defense):
	boss_hp = 103
	boss_att = 9
	boss_def = 2
	npc_hp = 100
	npc_att = attack
	npc_def = defense
	while True:
		boss_hp -= max([1, npc_att - boss_def])
		if boss_hp <= 0:
			return True
		npc_hp -= max([1, boss_att - npc_def])
		if npc_hp <= 0:
			return False

if __name__ == '__main__':
	
	'''
	Weapons:    Cost  Damage  Armor
	Dagger        8     4       0
	Shortsword   10     5       0
	Warhammer    25     6       0
	Longsword    40     7       0
	Greataxe     74     8       0

	Armor:      Cost  Damage  Armor
	Leather      13     0       1
	Chainmail    31     0       2
	Splintmail   53     0       3
	Bandedmail   75     0       4
	Platemail   102     0       5

	Rings:      Cost  Damage  Armor
	Damage +1    25     1       0
	Damage +2    50     2       0
	Damage +3   100     3       0
	Defense +1   20     0       1
	Defense +2   40     0       2
	Defense +3   80     0       3
	'''
	weapons = [(8, 4, 0), (10, 5, 0), (25, 6, 0), (40, 7, 0), (74, 8, 0)]
	armor = [(0, 0, 0), (13, 0, 1), (31, 0, 2), (53, 0, 3), (75, 0, 4), (102, 0, 5)]
	rings = [(0, 0, 0), (25, 1, 0), (50, 2, 0), (100, 3, 0), (20, 0, 1), (40, 0, 2), (80, 0, 3)]

	wins = []
	loses = []
	for w in range(len(weapons)):
		for a in range(len(armor)):
			for r1 in range(len(rings)):
				for r2 in range(len(rings)):
					if r1 != r2:
						attack = weapons[w][1] + rings[r1][1] + rings[r2][1]
						defense = armor[a][2] + rings[r1][2] + rings[r2][2]
						if fight(attack, defense):
							wins.append(weapons[w][0] + armor[a][0] + rings[r1][0] + rings[r2][0])
						else:
							loses.append(weapons[w][0] + armor[a][0] + rings[r1][0] + rings[r2][0])
	part_one = min(wins)
	part_two = max(loses)
	print("Advent of Code 2015 Day 21")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
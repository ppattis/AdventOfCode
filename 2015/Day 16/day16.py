#
#  Advent of Code 2015
#  Day 
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def part_two(sues):
	aunt = {}
	for i in range(1, 501):
		aunt[i] = True
	s = sues[0]
	for aspect in s.keys():
		val = s[aspect]
		for i, sue in enumerate(sues):
			if i != 0:
				if aspect in sue.keys():
					if aspect in ['cats', 'trees']:
						if sue[aspect] <= val:
							aunt[i] = False
					elif aspect in ['pomeranians', 'goldfish']:
						if sue[aspect] >= val:
							aunt[i] = False
					else:
						if sue[aspect] != val:
							aunt[i] = False
	for key in aunt.keys():
		if aunt[key] == True:
			return key


def part_one(sues):
	aunt = {}
	for i in range(1, 501):
		aunt[i] = True
	s = sues[0]
	for aspect in s.keys():
		val = s[aspect]
		for i, sue in enumerate(sues):
			if i != 0:
				if aspect in sue.keys():
					if sue[aspect] != val:
						aunt[i] = False
	for key in aunt.keys():
		if aunt[key] == True:
			return key

if __name__ == '__main__':
	
	input = getInput("input.txt")
	gift_giver = "children: 3, cats: 7, samoyeds: 2, pomeranians: 3, akitas: 0, vizslas: 0, goldfish: 5, trees: 3, cars: 2, perfumes: 1"
	gift_giver = gift_giver.split(', ')
	entry = {}
	for aspect in gift_giver:
		name, qty = aspect.split(': ')
		entry[name] = int(qty)
	sues = [entry]
	#print(entry)
	for line in input:
		index = line.index(':')
		line = line[index + 2:]
		aspects = line.split(', ')
		entry = {}
		for aspect in aspects:
			aspect = aspect.split(': ')
			#print(aspect)
			entry[aspect[0]] = int(aspect[1])
		sues.append(entry)

	print("Advent of Code 2015 Day 03")
	print("  Part one:", part_one(sues))
	print("  Part two:", part_two(sues))	
	
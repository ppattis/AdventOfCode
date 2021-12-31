#
#  Advent of Code 2015
#  Day 19
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		swaps, mol = input_file.read().split('\n\n')
	return swaps, mol

def toString(mole):
	ret = ""
	for atom in mole:
		ret += atom
	return ret

class Node:
	def __init__(self, atom, parent):
		self.atom = atom
		self.parent = parent
		self.kids = []


def part_one(molecule, swaps):
	ans = 0
	results = []
	for i, atom in enumerate(molecule):
		if atom in swaps.keys():
			for sub in swaps[atom]:
				mole = molecule[:i] + sub + molecule[i + 1:]
				#mole_string = toString(mole)
				if mole not in results:
					#print(mole)
					results.append(mole)
	return len(results)

def get_longest_key(swaps):
	key = ""
	length = 0
	for k in swaps.keys():
		if len(k) > length:
			length = len(k)
			key = k
	return key

def part_two(molecule, swaps):
	ans = 0
	orig_swaps = dict(swaps)
	while len(molecule) > 1:
		key = get_longest_key(swaps)
		#print(molecule, key)
		ans += molecule.count(key)
		molecule = molecule.replace(key, swaps[key])
		del swaps[key]
		if len(swaps.keys()) == 0:
			swaps = dict(orig_swaps)
	return ans


if __name__ == '__main__':
	
	swaps, mole = getInput("input.txt")
	swaps = swaps.split('\n')
	mole = mole.strip('/n').strip()
	molecule = []
	mole_two = mole
	for i in range(len(mole)):
		if i < len(mole) - 1 and mole[i + 1].islower():
			molecule.append(mole[i] + mole[i + 1])
		elif mole[i].isupper():
			molecule.append(mole[i])
	replacements = {}
	swaps_two = {}
	for swap in swaps:
		token = swap.split(' => ')
		swaps_two[token[1]] = token[0]
		if token[0] not in replacements.keys():
			replacements[token[0]] = []
		base = []
		for i in range(len(token[1])):
			if i < len(token[1]) - 1 and token[1][i + 1].islower():
				base.append(token[1][i] + token[1][i + 1])
			elif token[1][i].isupper():
				base.append(token[1][i])
		replacements[token[0]].append(base)

	#print(f'[{molecule}]')
	
	print("Advent of Code 2015 Day 19")
	print("  Part one:", part_one(molecule, replacements))
	print("  Part two:", part_two(mole_two, swaps_two))	
	
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

def min(one, two):
	if one < two:
		return one
	else:
		return two

if __name__ == '__main__':
	
	input = getInput("input.txt")
	wrapping_paper = 0
	ribbon = 0
	
	for line in input:
		l_s,w_s,h_s = line.split('x')
		l = int(l_s)
		w = int(w_s)
		h = int(h_s)
		side_one = l * w
		side_two = w * h
		side_three = l * h
		extra = min(min(side_one, side_two), side_three)
		wrapping_paper += (2 * side_one) + (2 * side_two) + (2 * side_three) + extra
		side_one = l + l + w + w
		side_two = w + w + h + h
		side_three = l + l + h + h
		extra = l * w * h
		ribbon += min(min(side_one, side_two), side_three) + extra
	
	print("Advent of Code 2015 Day 02")
	print("  Part one:", wrapping_paper)
	print("  Part two:", ribbon)	
	
	
	
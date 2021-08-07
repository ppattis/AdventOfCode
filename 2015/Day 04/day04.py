#
#  Advent of Code 2015
#  Day 04
#
#  By PatchesTheDipstick
#

import hashlib

if __name__ == '__main__':
	
	input = "yzbqklnj"
	
	index = 0
	part_one = 0
	part_two = 0
	part_one_done = False
	part_two_done = False
	complete = False
	while complete == False:
		
		key = bytes(input + str(index), encoding="utf-8")
		hash = hashlib.md5(key).hexdigest()
		if (hash[:5] == "00000" and part_one == 0):
			part_one = index
			part_one_done = True
		if (hash[:6] == "000000" and part_two == 0):
			part_two = index
			part_two_done = True
		index += 1
		if part_one_done and part_two_done:
			complete = True
		#print(index, hash[:5])
	
	print("Advent of Code 2015 Day 04")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	

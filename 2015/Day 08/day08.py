#
#  Advent of Code 2015
#  Day 08
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
	
	literal_chars = 0
	actual_chars = 0
	new_encode = []
	for line in input:
		in_escape = False
		in_hex = False
		new_line = [ '\"' ]
		for index in range(len(line)):
			if line[index] != ' ':
				literal_chars += 1
				if ((line[index] == '\\') and (in_escape == False)):
					in_escape = True
					new_line.append('\\')
					new_line.append('\\')
				elif ((in_escape == True) and (line[index] == 'x')):
					in_hex = True
					hex_count = 0
					new_line.append(line[index])
				elif ((in_escape == True) and (in_hex == True)):
					hex_count += 1
					new_line.append(line[index])
					if hex_count == 2:
						actual_chars += 1
						in_hex = False
						in_escape = False
				elif in_escape == True:
					in_escape = False
					actual_chars += 1
					new_line.append('\\')
					new_line.append(line[index])
				elif ((in_escape == False) and (line[index] == '\"')):
					new_line.append('\\')
					new_line.append('\"')
				else:
					actual_chars += 1
					new_line.append(line[index])
		new_line.append('\"')
		new_encode.append(new_line)
	part_two = 0
	for line in new_encode:
		part_two += len(line)
	part_two -= literal_chars
	
	part_one = literal_chars - actual_chars
	print("Advent of Code 2015 Day 08")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
#
#  Advent of Code 2018
#  Day 
#
#  By PatchesTheDipstick
#

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def get_co2(input):
	values= list(input)
	co2_value = ""
	for index in range(len(input[0])):
		ones = 0
		zeros = 0
		for value in values:
			if value[index] == "1":
				ones += 1
			else:
				zeros += 1
		if ones >= zeros:
			co2_value += "0"
		else:
			co2_value += "1"
		values = [a for a in values if a.startswith(co2_value)]
		#print(values)
		if len(values) == 1:
			co2_value = values[0]
			break
	return int(co2_value, 2)

def get_o2(input):
	values= list(input)
	o2_value = ""
	for index in range(len(input[0])):
		ones = 0
		zeros = 0
		for value in values:
			if value[index] == "1":
				ones += 1
			else:
				zeros += 1
		if ones < zeros:
			o2_value += "0"
		else:
			o2_value += "1"
		values = [a for a in values if a.startswith(o2_value)]
		if len(values) == 1:
			o2_value = values[0]
			break
	return int(o2_value, 2)



def part_one(input):
	
	gamma = ""
	epsilon = ""

	for i in range(len(input[0])):
		ones = 0
		zeros = 0
		for num in input:
			if num[i] == "0":
				zeros += 1
			else:
				ones += 1
		if ones > zeros:
			gamma += "1"
			epsilon += "0"
		else:
			gamma += "0"
			epsilon += "1"

	value = int(gamma, 2) * int(epsilon, 2)
	return value


	return answer

def part_two():
	answer = 0



	return answer

if __name__ == '__main__':
	
	input = getInput("input.txt")
	
	

	print("Advent of Code 2021 Day 03")
	print("  Part one:", part_one(input))
	print("  Part two:", get_o2(input) * get_co2(input))	
	
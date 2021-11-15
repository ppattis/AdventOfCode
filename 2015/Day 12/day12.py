#
#  Advent of Code 2015
#  Day 
#
#  By PatchesTheDipstick
#

import json

def sum_numbers(jo):
	ret = 0
	if isinstance(jo, dict):
		for k in jo.keys():
			if isinstance(jo[k], int):
				ret += jo[k]
			elif isinstance(jo[k], list):
				ret += sum_numbers(jo[k])
			elif isinstance(jo[k], dict):
				ret += sum_numbers(jo[k])
	elif isinstance(jo, list):
		for val in jo:
			if isinstance(val, int):
				ret += val
			elif isinstance(val, list):
				ret += sum_numbers(val)
			elif isinstance(val, dict):
				ret += sum_numbers(val)
	elif isinstance(jo, int):
		ret += jo
	return ret

def sum_non_red(jo):
	ret = 0
	if isinstance(jo, dict):
		for k in jo.keys():
			if isinstance(jo[k], int):
				ret += jo[k]
			elif isinstance(jo[k], list):
				ret += sum_non_red(jo[k])
			elif isinstance(jo[k], dict):
				ret += sum_non_red(jo[k])
			elif isinstance(jo[k], str) and jo[k] == "red":
				return 0
	elif isinstance(jo, list):
		for val in jo:
			if isinstance(val, int):
				ret += val
			elif isinstance(val, list):
				ret += sum_non_red(val)
			elif isinstance(val, dict):
				ret += sum_non_red(val)
	elif isinstance(jo, int):
		ret += jo
	return ret

if __name__ == '__main__':
	
	with open("input.txt", "r") as f:
		json_object = json.load(f)
	

	part_one = sum_numbers(json_object)
	part_two = sum_non_red(json_object)
	print("Advent of Code 2015 Day 12")
	print("  Part one:", part_one)
	print("  Part two:", part_two)	
	
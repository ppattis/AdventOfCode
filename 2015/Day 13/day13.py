#
#  Advent of Code 2015
#  Day 
#
#  By PatchesTheDipstick
#
from itertools import permutations
import time

start_time = time.time()

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def calculate_delta(guests, deltas):
	happiness = 0
	for i in range(len(guests) - 1):
		g1 = guests[i]
		g2 = guests[i + 1]
		happiness += deltas[g1][g2]
		happiness += deltas[g2][g1]
	happiness += deltas[guests[0]][guests[-1]]
	happiness += deltas[guests[-1]][guests[0]]
	return happiness


def get_best(deltas):
	guests = list(deltas.keys())
	guest_list = list(permutations(guests))
	answer = calculate_delta(guest_list[0], deltas)

	for opt in guest_list:
		a = calculate_delta(opt, deltas)
		if a > answer:
			answer = a

	return answer


if __name__ == '__main__':
	
	input = [l.strip(".") for l in getInput("input.txt")]
	deltas = {}
	for line in input:
		token = line.split()
		if token[0] not in deltas.keys():
			deltas[token[0]] = {}
		if token[10] not in deltas.keys():
			deltas[token[10]] = {}
		delta = int(token[3])
		if token[2] == "lose":
			delta *= -1
		deltas[token[0]][token[10]] = delta

		deltas_one = dict(deltas)
		deltas_two = dict(deltas)
		deltas_two["me"] = {}
		for person in deltas_one.keys():
			deltas_two[person]["me"] = 0
			deltas_two["me"][person] = 0

	
	
	print("Advent of Code 2015 Day 13")
	print("  Part one:", get_best(deltas_one))
	print("    Runtime:", time.time() - start_time)
	print("  Part two:", get_best(deltas_two))
	print("    Runtime:", time.time() - start_time)	
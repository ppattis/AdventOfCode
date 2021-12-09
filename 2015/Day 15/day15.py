#
#  Advent of Code 2015
#  Day 
#
#  By PatchesTheDipstick
#
import re

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def get_score(recipe, ingredient):

	score = 1
	for j in range(4):
		sub = 0
		for i, k in enumerate(recipe):
			sub += ingredient[i][j] * k
		if sub < 0:
			sub = 0
		score *= sub
	return score

def generate_recipes():
	recipes = []
	for a in range(101):
		for b in range(101):
			for c in range(101):
				for d in range(101):
					if a + b + c + d == 100:
						recipes.append((a, b, c, d))
	return recipes

def get_calories(ingredient, recipe):
	c = 0
	for i in range(4):
		c += ingredient[i][4] * recipe[i]
	return c

def part_one(ingredient, recipes):
	score = 0
	for recipe in recipes:
		s = get_score(recipe, ingredient)
		if s > score:
			score = s
	return score

def part_two(ingredient, recipes):
	score = 0
	for recipe in recipes:
		if get_calories(ingredient, recipe) == 500:
			s = get_score(recipe, ingredient)
			if s > score:
				score = s
	return score

if __name__ == '__main__':
	
	ingredient = {}
	input = getInput("input.txt")
	rule = "^(.+): capacity (.+), durability (.+), flavor (.+), texture (.+), calories (.+)$"
	for i, line in enumerate(input):
		token = re.search(rule, line)
		ingredient[i] = (int(token.group(2)), int(token.group(3)), int(token.group(4)), int(token.group(5)), int(token.group(6)), token.group(1))
	recipes = generate_recipes()

	print("Advent of Code 2015 Day 03")
	print("  Part one:", part_one(ingredient, recipes))
	print("  Part two:", part_two(ingredient, recipes))	
	
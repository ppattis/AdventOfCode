#
#  Advent of Code 2018
#  Day 
#
#  By PatchesTheDipstick
#
from copy import deepcopy

def getInput(file_name):
	input = []
	with open(file_name) as input_file:
		input = input_file.read().splitlines()
	return input

def has_won(board):
	for a in range(5):
		row_has = 0
		col_has = 0
		for b in range(5):
			if board[a][b][0] == "(":
				col_has += 1
			if board[b][a][0] == "(":
				row_has += 1
		if row_has == 5 or col_has == 5:
			return True
	return False

def score_board(board):
	answer = 0
	for row in board:
		for col in row:
			if col[0] != "(":
				answer += int(col)
	return answer

def part_one(board_data, drawing):
	answer = 0
	boards = deepcopy(board_data)
	for num in drawing:
		for board in boards:
			for r in range(5):
				for c in range(5):
					if board[r][c] == num:
						board[r][c] = "(" + num + ")"
		for board in boards:
			if has_won(board):
				return score_board(board) * int(num)
	
	return "Opps"

def part_two(board_data, drawing):
	boards = deepcopy(board_data)
	
	for num in drawing:
		for board in boards:
			for r in range(5):
				for c in range(5):
					if board[r][c] == num:
						board[r][c] = "(" + num + ")"
		winners = []
		for i, board in enumerate(boards):
			if has_won(board):
				winners.append(i)
		for i in winners[::-1]:
			if len(boards) == 1:
				return score_board(boards[0]) * int(num)
			del boards[i]

	return "Opps"


	return answer

if __name__ == '__main__':
	
	input = getInput("input.txt")
	
	drawing = [a for a in input[0].split(",")]
	input = input[2:]
	board_data = []
	board = []
	for line in input:
		if len(line) > 0:
			board.append([a for a in line.split()])
		else:
			board_data.append(board)
			board = []
	
	print(drawing)


	print("Advent of Code 2021 Day 03")
	print("  Part one:", part_one(board_data, drawing))
	print("  Part two:", part_two(board_data, drawing))	
	
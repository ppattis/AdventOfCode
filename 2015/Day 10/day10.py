#
#  Advent of Code 2015
#  Day 
#
#  By PatchesTheDipstick
#

def say_series(series):
	new_series = []
	cur_digit = 0
	count = 0
	for digit in series:
		if digit != cur_digit:
			if cur_digit != 0:
				new_series.append(count)
				new_series.append(cur_digit)
				cur_digit = digit
				count = 1
			if cur_digit == 0:
				cur_digit = digit
				count += 1
		else:
			count += 1
	new_series.append(count)
	new_series.append(cur_digit)
	return new_series

if __name__ == '__main__':
	
	input = "1113222113"
	series = []
	for ch in input:
		series.append(int(ch))

	print("Advent of Code 2015 Day 10")

	for index in range(40):
		series = say_series(series)
	
	print("  Part one:", len(series))

	for index in range(10):
		series = say_series(series)

	print("  Part two:", len(series))	
	
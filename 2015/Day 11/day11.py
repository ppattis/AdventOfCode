#
#  Advent of Code 2015
#  Day 
#
#  By PatchesTheDipstick
#

def increment_char(ch):
	if ch == "z":
		return "a"
	else:
		return chr(ord(ch) + 1)

def to_list(password):
	out_list = []
	for ch in password:
		out_list.append(ch)
	return out_list

def to_string(password):
	out_string = ""
	for ch in password:
		out_string += ch
	return out_string

def increment_password(password):
	carry = True
	index = len(password) - 1
	series = to_list(password)
	while carry:
		if password[index] != "z":
			series[index] = increment_char(series[index])
			carry = False
		else:
			series[index] = increment_char(series[index])
			index -= 1
	return to_string(series)

def is_valid(password):
	series = to_list(password)
	#  test first rule
	max_run_len = 0
	run_len = 0
	for i in range(len(series) - 1):
		if ord(series[i]) + 1 == ord(series[i + 1]):
			run_len += 1
		else:
			if run_len > max_run_len:
				max_run_len = run_len
			run_len = 1
	if max_run_len < 3:
		return False
	# test second rule
	if "i" in series or "o" in series or "l" in series:
		return False
	# test third rule
	doubles = []
	for i in range(len(password) - 1):
		if password[i] == password[i + 1]:
			doubles.append((i, i + 1))
	if len(doubles) < 2:
		return False
	else:
		new_doubles = []
		for i in range(len(doubles) - 1):
			if doubles[i][1] == doubles[i + 1][0]:
				doubles[i + 1] = (-1, -1)
	while (-1, -1) in doubles:
		doubles.remove((-1, -1))
	if len(doubles) < 2:
		return False
	return True



if __name__ == '__main__':
	
	input = "hepxcrrq"

	print("Advent of Code 2015 Day 03")
	
	current_password = input
	while not is_valid(current_password):
		current_password = increment_password(current_password)

	print("  Part one:", current_password)

	current_password = increment_password(current_password)
	while not is_valid(current_password):
		current_password = increment_password(current_password)

	print("  Part two:", current_password)	
	
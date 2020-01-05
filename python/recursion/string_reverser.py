def reverser(input_string):
	if len(input_string)==1:
		return input_string[0]
	else:
		return reverser(input_string[1:])+input_string[0]

print (reverser("sri priya"))

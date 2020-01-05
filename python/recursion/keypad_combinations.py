def get_characters(num):
    if num == 2:
        return "abc"
    elif num == 3:
        return "def"
    elif num == 4:
        return "ghi"
    elif num == 5:
        return "jkl"
    elif num == 6:
        return "mno"
    elif num == 7:
        return "pqrs"
    elif num == 8:
        return "tuv"
    elif num == 9:
        return "wxyz"
    else:
        return ""
def strings_from_num(num):
	strings_list=[get_characters(int(i)) for i in str(num)]
	return keypad(strings_list)
def keypad(strings_list):
	if len(strings_list)==1:
		return [i for i in strings_list[0]]
	elif len(strings_list)==2:
		return [i+j for i in strings_list[0] for j in strings_list[1]]
	else:
		element=strings_list[0]
		output=[]
		prev_combinations=keypad(strings_list[1:])
		for char in element:
			for item in prev_combinations:
				output.append(char+item)
		return output
print(strings_from_num(354))
	

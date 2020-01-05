def string_permutations(input_string):
	if len(input_string)<=1:
		return [input_list]
	elif len(input_string)==2:
		return [input_string,input_string[::-1]]
	else :
		output=[]
		element=input_string[0]
		permuted_list=string_permutations(input_string[1:])
		for item in permuted_list:
			for i in range(len(item)+1):
				temp_string=item[:i]+element+item[i:]
				output.append(temp_string)
		return output

print(string_permutations("123"))
				

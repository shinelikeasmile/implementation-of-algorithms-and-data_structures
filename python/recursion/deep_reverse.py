def deep_reverse(input_list):
	reversed_list=[]
	if type(input_list) is not list:
		return input_list
	else:
		for i in input_list[::-1]:
			reversed_list.append(deep_reverse(i))
	return reversed_list

print(deep_reverse([1,2,3,234,"fre"]))
			

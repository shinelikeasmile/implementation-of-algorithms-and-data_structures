def last_index(input_list,target):
	if len(input_list)==1:
		if input_list[0]==target:
			return 0
		else:
			return -1
	else:
		prev_val=last_index(input_list[1:],target)
		if prev_val==-1 and  input_list[0]!=target:
			return -1
		else:
			return prev_val+1

print(last_index([1,2,5,5,6],5))

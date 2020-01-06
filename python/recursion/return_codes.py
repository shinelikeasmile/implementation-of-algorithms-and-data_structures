def return_codes(num):
	str_num=str(num)
	list_of_numbers_list=[]
	for digit in str_num:
		if list_of_numbers_list==[]:
			list_of_numbers_list.append([int(digit)])
		else:
			updated_list_of_numbers_list=[]
			for number_list in list_of_numbers_list:
				updated_list_of_numbers_list.append(number_list+[int(digit)])
				if number_list[-1]<3 and int(digit)<7:
					number_list[-1]=number_list[-1]*10+int(digit)
					updated_list_of_numbers_list.append(number_list)
			list_of_numbers_list=updated_list_of_numbers_list
	for index in range(len(list_of_numbers_list)):
		list_of_numbers_list[index]="".join([chr(i+96) for i in list_of_numbers_list[index]])
	print (list_of_numbers_list)
return_codes(4545)
					
			
		

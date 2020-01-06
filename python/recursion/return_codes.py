""" In an encryption system where ASCII lower case letters represent numbers in the pattern a=1, b=2, c=3...so on,
find out all the codes that are possible for a given input number.

Example 1

    number = 123
    codes_possible = ["aw", "abc", "lc"]

Explanation: The codes are for the following number:

    1 . 23 = "aw"
    1 . 2 . 3 = "abc"
    12 . 3 = "lc"
"""

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
					
			
		

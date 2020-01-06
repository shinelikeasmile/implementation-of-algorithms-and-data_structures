"""
Given an integer array, find and return all the subsets of the array.
The order of subsets in the output array is not important. 
However the order of elements in a particular subset should remain the same as in the input array.
Note: An empty set will be represented by an empty list

Example 1

arr = [9]

output = [[]
          [9]]

Example 2

arr = [9, 12, 15]

output =  [[],
           [15],
           [12],
           [12, 15],
           [9],
           [9, 15],
           [9, 12],
           [9, 12, 15]]
"""
def return_subsets(input_list):
	list_of_subsets=[]
	for number in input_list:
		if list_of_subsets==[]:
			list_of_subsets.append([])
			list_of_subsets.append([number])
		else:
			length=len(list_of_subsets)
			for i in range(length):
					list_of_subsets.append(list_of_subsets[i]+[number])
	print (list_of_subsets)

return_subsets([9,12,15])

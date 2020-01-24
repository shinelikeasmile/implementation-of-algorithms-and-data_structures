def longest_consecutive_subsequence(input_list):
	input_list=sorted(input_list)
	temp_start=-1
	temp_end=-1
	temp_count=1
	start=-1
	end=-1
	count=1
	for i in range(len(input_list)-1):
		if temp_start==-1:
			if input_list[i]-input_list[i+1] == -1 :
				temp_start=i
				temp_end=i+1
				temp_count=temp_count+1
		else:
			if input_list[i]-input_list[i+1] == -1 :
				temp_end=i+1
				temp_count=temp_count+1
			else:
				if temp_count>count:
					count=temp_count
					start=temp_start
					end=temp_end
				temp_count=1
				temp_start=-1
				temp_end=-1	
	if start==-1 and end==-1:
		start=temp_start
		end=temp_end
	return input_list[start:end+1]
def test_function(test_case):
    output = longest_consecutive_subsequence(test_case[0])
    if output == test_case[1]:
        print("Pass")
    else:
        print("Fail")
test_case_1 = [[5, 4, 7, 10, 1, 3, 55, 2], [1, 2, 3, 4, 5]]
test_function(test_case_1)
test_case_2 = [[2, 12, 9, 16, 10, 5, 3, 20, 25, 11, 1, 8, 6 ], [8, 9, 10, 11, 12]]
test_function(test_case_2)
test_case_3 = [[0, 1, 2, 3, 4], [0, 1, 2, 3, 4]]
test_function(test_case_3)
			

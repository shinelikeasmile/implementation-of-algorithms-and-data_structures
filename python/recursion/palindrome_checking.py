def is_palindrome(input_string):
	if len(input_string)<=1:
		return True
	elif len(input_string)==2:
		return input_string[0]==input_string[1]
	else:
		return (input_string[0]==input_string[-1]) & (is_palindrome(input_string[1:len(input_string)-1]))

s="sri priya"
print (is_palindrome(s))
s="madam"
print(is_palindrome(s))
s="a"
print(is_palindrome(s))
s="sis"
print(is_palindrome(s))

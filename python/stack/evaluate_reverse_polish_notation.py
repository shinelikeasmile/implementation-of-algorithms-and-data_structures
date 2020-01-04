#python3
import math
class stack:
	def __init__(self):
		self.container=[]
	def push(self,value):
		self.container.append(value)
	def pop(self):
		return self.container.pop()
	def top(self):
		return self.container[-1]
	def size(self):
		return len(self.container)
	def is_empty(self):
		return not(len(self.container))

def eval_postfix(input_list):
	s=stack()
	for item in input_list:
		if item in ['*','+','-','/']:
			op1=s.pop()
			op2=s.pop()
			s.push(str(math.ceil(eval(op2+item+op1))))
		else:
			s.push(item)
	return s.pop()
print (eval_postfix(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]))


		

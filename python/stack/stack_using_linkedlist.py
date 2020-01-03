class Node:
	def __init__(self,value):
		self.value=value
		self.next=None
class LinkedList:
	def __init__(self,head):
		self.head=head
	#append adds elements at front of the linked list
	def append(self,value):
		if self.head==None:
			self.head=Node(value)
		else:
			node=Node(value)
			node.next=self.head
			self.head=node
class Stack:
	def __init__(self):
		self.LL=LinkedList(None)
		self.count=0
	def push(self,value):
		if self.LL.head==None:
			self.LL.head=Node(value)
		else:
			self.LL.append(value)
		self.count+=1
	def pop(self):
		if self.LL.head==None:
			print "no elements to pop"
		else:
			node=self.LL.head
			self.LL.head=node.next
			self.count-=1
			return node.value
	def top(self):
		if self.LL.head is not None:
			return self.LL.head.value
		else:
			print "no elements in the stack"
	def size(self):
		return self.count
	def is_empty(self):
		return self.LL.head is None

stack = Stack()
stack.push(10)
stack.push(20)
stack.push(30)
stack.push(40)
stack.push(50)

# Test size
print ("Pass" if (stack.size() == 5) else "Fail")

# Test pop
print ("Pass" if (stack.pop() == 50) else "Fail")

# Test push
stack.push(60)
print ("Pass" if (stack.pop() == 60) else "Fail")
print ("Pass" if (stack.pop() == 40) else "Fail")
print ("Pass" if (stack.pop() == 30) else "Fail")
stack.push(50)
print ("Pass" if (stack.size() == 3) else "Fail")


		
			
		
	
	

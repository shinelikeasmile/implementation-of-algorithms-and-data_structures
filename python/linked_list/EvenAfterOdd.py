#given a linked list , arrange the elements in such a manner that even elements come after all the odd elements without using any other data structure or new space.
#the relative order must remain same.
class Node:
	def __init__(self,value):
		self.value=value
		self.next=None

class LinkedList:
	def __init__(self,head):
		self.head=head
		while head.next is not None:
			head=head.next
		self.tail=head
	def append(self,value):
		if self.head==None:
			self.head=Node(value)
			self.tail=self.head
		else:
			self.tail.next=Node(value)
			self.tail=self.tail.next
	def traverse(self):
		node=self.head
		while node is not None:
			print node.value
			node=node.next
	def EvenOdd(self):
		parent=self.head
		current=self.head
		count =0
		node=self.head
		while node is not None:
			node=node.next
			count+=1
		while current is not None and count!=0:
			if current.value % 2 == 0:
				parent.next=current.next
				self.tail.next=current
				current=current.next
				self.tail=self.tail.next
				self.tail.next=None
				if self.tail==self.head:
					parent=current 
					self.head=current 
			else:
				parent=current
				current=current.next
			count=count-1

LL=LinkedList(Node(1))
for i in range(2,10+1):
	LL.append(i)
print "Linked_List :"
LL.traverse()
LL.EvenOdd()
print "EvenOdd Linked_List: "
LL.traverse()

			
			

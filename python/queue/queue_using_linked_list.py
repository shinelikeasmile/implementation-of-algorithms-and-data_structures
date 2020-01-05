class Node:
	def __init__(self,value):
		self.value=value
		self.next=None
class Queue:
	def __init__(self):
		self.head=None
		self.tail=None
		self.no_of_elements=0
	def enqueue(self,value):
		if self.tail==None:
			self.tail=Node(value)
			self.head=self.tail
			self.no_of_elements=1
		else:
			node=self.head
			while node.next!=None :
				node=node.next
			node.next=Node(value)
			self.tail=node.next
			self.no_of_elements+=1
	def size(self):
		return self.no_of_elements
	def is_empty(self):
		return self.no_of_elements==0
	def dequeue(self):
		if self.is_empty():
			return None
		else :
			temp=self.head
			self.head=self.head.next
			self.no_of_elements-=1
			return temp.value
	def peak(self):
		if self.is_empty():
			return None
		return self.head.value
	def reverse(self):
		if self.size()>1:
			tail=self._reverse(self.head,self.head.next)
			self.head=self.tail
			self.tail=tail
			self.tail.next=None
			print ("Queue reversed")
	def _reverse(self,parent,child):
			if child==None:
				return parent
			else :
				child=self._reverse(child,child.next)
				child.next=parent
				return parent
q=Queue()
print("peak : "+str(q.peak()))
print("size : "+str(q.size()))
for i in range(1,10+1):
	print("enqueue : "+str(i))
	q.enqueue(i)
print("peak : "+str(q.peak()))
q.reverse()
print("peak :"+str(q.peak()))
for i in range(10):
	print("dequeue :"+str(q.dequeue()))
print("peak :"+str(q.peak()))
print("size : "+str(q.size()))

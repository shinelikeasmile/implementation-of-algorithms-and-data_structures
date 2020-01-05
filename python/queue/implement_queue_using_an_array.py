class Queue:
	def __init__(self):
		self.array=[0 for i in range(10)]
		self.front=-1
		self.next=0
	def enqueue(self,value):
		if self.next >= len(self.array):
			self.handle_queue_capacity()
		self.array[self.next]=value
		self.next+=1
		if self.front == -1:
			self.front=0
	def handle_queue_capacity(self):
		self.newarray=[0 for i in range(len(self.array)*2)]
		for i,x in enumerate(self.array):
			self.newarray[i]=x
		self.array=self.newarray
	def dequeue(self):
		if self.front != -1 and self.next != 0:
			self.next-=1
			if self.next==0:
				self.front=-1
			return self.array.pop(0)
		else:
			return None
	def peak(self):
		if self.front!=-1:
			return self.array[0]
		else :
			return None
	def size(self):
		return self.next
q=Queue()
print ("peak is "+str(q.peak()))
for i in range(20):
	print ("enqueue "+str(i))
	q.enqueue(i)
for i in range(20):
	print ("dequeue"+str(q.dequeue()))
print ("peak is "+str(q.peak()))

			

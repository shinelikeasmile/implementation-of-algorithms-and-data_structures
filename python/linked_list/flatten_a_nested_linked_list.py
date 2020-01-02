#suppose you have a linked list where the value of each node is a sorted linked list (i.e nested list).
#our task is to flatten this nested list that is , to combine all nested lists into a single sorted linked list.
class Node:
	def __init__(self,value):
		self.value=value
		self.next=None
		
class LinkedList:
	def __init__(self,head):
		self.head=head
	def append(self,value):
		if self.head==None:
			self.head=Node(value)
		else :
			node=self.head
			while node.next is not None:
				node=node.next
			node.next=Node(value)

def merge(list1,list2):
	if list1 is None:
		return list2
	if list2 is None:
		return list1
	list1_el=list1.head
	list2_el=list2.head
	merged=LinkedList(None)
	while list1_el is not None or list2_el is not None:
		if list1_el is None:
			merged.append(list2_el.value)
			list2_el=list2_el.next
		elif list2_el is None:
			merged.append(list1_el.value)
			list1_el=list1_el.next
		elif list1_el.value<=list2_el.value:
			merged.append(list1_el.value)
			list1_el=list1_el.next
		else:
			merged.append(list2_el.value)
			list2_el=list2_el.next
	return merged
	
class NestedLinkedList(LinkedList):
	def flatten(self):
		return self._flatten(self.head)
	def _flatten(self,node):
		if node.next is None:
			return merge(node.value,None)
		else:
			return merge(node.value,self._flatten(node.next))

LL1=LinkedList(Node(1))
LL1.append(4)
LL1.append(1990)
LL1.append(12312414)
LL2=LinkedList(Node(3))
LL2.append(25)
LL2.append(50)
NestedLL= NestedLinkedList(Node(LL1))
NestedLL.append(LL2)
flat=NestedLL.flatten()
node=flat.head
while node is not None:
	print node.value
	node=node.next

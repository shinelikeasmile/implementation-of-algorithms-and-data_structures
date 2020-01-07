class Queue:
	def __init__(self):
		self.storage=[]
	def enqueue(self,value):
		self.storage.append(value)
	def dequeue(self):
		return self.storage.pop(0)
	def size(self):
		return len(self.storage)
	def __repr__(self):
		return str(self.storage)
	def peak(self):
		return self.storage[0]
	def is_empty(self):
		return self.size()==0
		
class Node:
	def __init__(self,value=None):
		self.value=value
		self.right=None
		self.left=None
	def getvalue(self):
		return self.value
	def setvalue(self,value):
		self.value=value
	def setleftchild(self,leftnode):
		self.left=leftnode
	def setrightchild(self,rightnode):
		self.right=rightnode
	def getleftchild(self):
		return self.left
	def getrightchild(self):
		return self.right
	def hasleftchild(self):
		return self.left!=None
	def hasrightchild(self):
		return self.right!=None
	def __repr__(self):
		return f"Node({self.getvalue()})"
	def __str__(self):
		return f"Node({self.getvalue()})"

class Tree:
	def __init__(self,value=None):
		if isinstance(value,Node):
			self.root=value
		else:
			self.root=Node(value)
	def getroot(self):
		return self.root
	def BSTinsertion(self,value):
		def insert(node,value):
			if node==None:
				return Node(value)
			elif node.value==value:
				return node
			elif node.value>value:
				node.left=insert(node.left,value)
				return node
			else:
				node.right=insert(node.right,value)
				return node
		insert(self.getroot(),value)	
	def BSTdeletion(self,value):
		def delete(node,value):
			parent=node
			while node is not None and node.value!=value:
				if node.value>value:
					parent=node
					node=node.left
				else:
					parent=node
					node=node.right
			if node==None:
				return None
			else:
				if node.right is not None:
					rightsuccessor=node.right
					parent=node.right
					while rightsuccessor.left is not None:
						parent=rightsuccessor
						rightsuccessor=rightsuccessor.left
					node.value=rightsuccessor.value
					parent.left=None
				else:
					if parent.left==node:
						parent.left=node.left
					else:
						parent.right=node.right
		delete(self.getroot(),value)
			
	def BFS(self):
		node=self.root
		Q=Queue()
		Q.enqueue(node)
		BFSlist=[]
		BFSlist.append(node.value)
		while not Q.is_empty() :
			node=Q.dequeue()
			if(node.hasleftchild()):
				BFSlist.append(node.left.value)
				Q.enqueue(node.left)
			else:
				BFSlist.append(None)
			if(node.hasrightchild()):
				BFSlist.append(node.right.value)
				Q.enqueue(node.right)
			else:
				BFSlist.append(None)
		power=0
		count=0
		for item in BFSlist:
			print(str(item),end=" ")
			count+=1
			if(count==2**power):
				count=0
				power+=1
				print("\n")
			
			
my_tree=Tree(5)
my_tree.BSTinsertion(2)
my_tree.BSTinsertion(7)
my_tree.BSTinsertion(1)
my_tree.BSTinsertion(0)
my_tree.BSTinsertion(9)
print("\nBFS :")
my_tree.BFS()
my_tree.BSTdeletion(2)
print("\n\nBFS after deletion of 2 :")
my_tree.BFS()




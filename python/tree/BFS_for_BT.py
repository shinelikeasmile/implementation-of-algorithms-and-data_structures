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
	def BFS(self):
		node=self.root
		Q=Queue()
		Q.enqueue(node)
		while not Q.is_empty() :
			node=Q.dequeue()
			print(node)
			if(node.hasleftchild()):
				Q.enqueue(node.left)
			if(node.hasrightchild()):
				Q.enqueue(node.right)
		
	
		
N1=Node(1)
N2=Node(2)
N4=Node(4)
N1.setleftchild(N2)
N2.setleftchild(N4)
my_tree=Tree(N1)
my_tree.BFS()




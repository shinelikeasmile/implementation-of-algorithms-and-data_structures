class Node:
	def __init__(self,key,value):
		self.key=key
		self.value=value
		self.next=None
		
class LinkedList:
	def __init__(self):
		self.head=None
	def append(self,key,value):
		if (self.head==None):
			self.head=Node(key,value)
		else:
			node=self.head
			while node.next is not None:
				node=node.next
			node.next=Node(key,value)
	def gethead(self):
		return self.head
		
class HashMap:
	def __init__(self,length=10):
		self.bucket_array=[None for _ in range(length)]
		self.no_of_elements=0
		self.prime=31	
		self.count=0
	def put(self,key,value):
		bucket_index=self.get_bucket_index(key)
		if self.bucket_array[bucket_index]==None:
			self.bucket_array[bucket_index]=LinkedList()
			self.bucket_array[bucket_index].append(key,value)
			self.count+=1
		else:
			node=self.bucket_array[bucket_index].gethead()
			while node is not None:
				if node.key==key:
					node.value=value
					return
				node=node.next
			self.bucket_array[bucket_index].append(key,value)
			self.count+=1
	def get(self,key):
		bucket_index=self.get_bucket_index(key)
		if self.bucket_array[bucket_index] is not None:
			node=self.bucket_array[bucket_index].gethead()
			while node is not None:
				if node.key==key:
					return node.value
				node=node.next
		return None
	def get_bucket_index(self,key):
		return self.get_hash_code(key)%len(self.bucket_array)
	def get_hash_code(self,key):
		expression_value=0
		for i in range(len(key)):
			expression_value+=ord(key[i])*(self.prime**(len(key)-1-i))
		return expression_value
	def size(self):
		return self.count

hash_map = HashMap()

hash_map.put("one", 1)
hash_map.put("two", 2)
hash_map.put("three", 3)
hash_map.put("neo", 11)

print("size: {}".format(hash_map.size()))


print("one: {}".format(hash_map.get("one")))
print("neo: {}".format(hash_map.get("neo")))
print("three: {}".format(hash_map.get("three")))
print("size: {}".format(hash_map.size()))

			
		
		
	

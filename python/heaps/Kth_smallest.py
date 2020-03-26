#heap_sort
def heapify(array,n,root):
	smallest=root
	left=2*root+1
	right=2*root+2
	if(left<n and array[left]<array[smallest]):
		smallest=left
	if(right<n and array[right]<array[smallest]):
		smallest=right
	if(smallest!=root):
		temp=array[smallest]
		array[smallest]=array[root]
		array[root]=temp
		heapify(array,n,smallest)
		
def K_smallest(array,N,K):
	for i in range(N//2-1,-1,-1):
		heapify(array,N,i)
	for i in range(1,K):
		temp=array[N-i]
		array[N-i]=array[0]
		array[0]=temp
		heapify(array,N-i,0)
	return array[0]
		
		
if __name__=="__main__":
	print("Enter size of the array : ")
	N=int(input())
	print("Enter elements of the array : ")
	L=list(map(int,input().split()))
	print("Enter K : ")
	K=int(input())
	print("{0} smallest element is : ".format(K),end=" ")
	print(K_smallest(L,N,K))
	

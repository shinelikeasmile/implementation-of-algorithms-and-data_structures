#heap_sort
def heapify(array,n,root):
	largest=root
	left=2*root+1
	right=2*root+2
	if(left<n and array[left]>array[largest]):
		largest=left
	if(right<n and array[right]>array[largest]):
		largest=right
	if(largest!=root):
		temp=array[largest]
		array[largest]=array[root]
		array[root]=temp
		heapify(array,n,largest)
		
def heap_sort(array,N):
	for i in range(N//2-1,-1,-1):
		heapify(array,N,i)
	for i in range(1,N):
		temp=array[N-i]
		array[N-i]=array[0]
		array[0]=temp
		heapify(array,N-i,0)
		
if __name__=="__main__":
	print("Enter size of the array : ")
	N=int(input())
	print("Enter elements of the array : ")
	L=list(map(int,input().split()))
	heap_sort(L,N)
	print("array after applying heap sort : ")
	print(*L)

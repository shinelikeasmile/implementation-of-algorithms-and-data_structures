def partition(arr,l,h):
	pivot=arr[h]
	i=l-1
	for j in range(l,h):
		if(arr[j]<=pivot):
			i=i+1
			arr[j],arr[i]=arr[i],arr[j]
	arr[h]=arr[i+1]
	arr[i+1]=pivot
	return i+1
def quick_sort(arr,l,h):
	if(l<h):
		p=partition(arr,l,h)
		quick_sort(arr,l,p-1)
		quick_sort(arr,p+1,h)
arr=list(map(int,input().split()))
quick_sort(arr,0,len(arr)-1)
print(arr)

			


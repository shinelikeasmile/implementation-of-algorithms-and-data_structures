import random
def partition (array,low,high):
	index=random.randrange(low,high+1,1)
	temp=array[index]
	array[index]=array[high]
	array[high]=temp
	pivot=array[high]
	i=low
	j=low
	while(j<high):
		if(array[j]>pivot):
			pass
		else:
			temp=array[j]
			array[j]=array[i]
			array[i]=temp
			i+=1
		j+=1
	temp=array[i]
	array[i]=pivot
	array[high]=temp
	return i
	
def quick_sort(array,low,high,K):
	if(low<high):
		pivot=partition(array,low,high)
		if(pivot==K):
			return array[K]
		if(pivot>K):
			result=quick_sort(array,low,pivot-1,K)
		if(pivot<K):
			result=quick_sort(array,pivot+1,high,K)
		return result
	return array[K]

if __name__=="__main__":
	print("Enter size of the array : ")
	N=int(input())
	print("Enter elements of the array : ")
	L=list(map(int,input().split()))
	print("Enter K : ")
	K=int(input())
	print(quick_sort(L,0,N-1,K-1))
	

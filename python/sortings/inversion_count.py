def merge(array,left,right):
	mid=(left+right)//2
	list1=[array[i] for i in range(left,mid+1)]
	list2=[array[i] for i in range(mid+1,right+1)]
	l1=0
	l2=0
	i=left
	inv_count=0
	while(l1<len(list1) and l2<len(list2)):
		if(list1[l1]<list2[l2]):
			array[i]=list1[l1]
			l1+=1
		else:
			array[i]=list2[l2]
			l2+=1
			inv_count+=len(list1)-l1
		i+=1
	while(l1<len(list1)):
		array[i]=list1[l1]
		l1+=1
		i+=1
	while(l2<len(list2)):
		array[i]=list2[l2]
		l2+=1
		i+=1
	return inv_count
def merge_sort(array,left,right):
	inv_count=0
	if(left<right):
		mid=(left+right)//2
		inv_count+=merge_sort(array,left,mid)
		inv_count+=merge_sort(array,mid+1,right)
		inv_count+=merge(array,left,right)
	return inv_count
if __name__=="__main__":
	print("size of the array : ",end="")
	N=int(input())
	print("enter elements of the array : ",end="")
	array=list(map(int,input().split()))
	print("inversion count : "+str(merge_sort(array,0,N-1)) )
	

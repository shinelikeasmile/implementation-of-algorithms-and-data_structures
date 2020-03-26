from sys import maxsize
print("enter size of the array : ")
N=int(input())
print("enter elements of the array : ")
L=list(map(int,input().split()))
max_ending_here=0
max_so_far=-maxsize-1
for i in L:
	max_ending_here+=i
	if(max_so_far<max_ending_here):
		max_so_far=max_ending_here
	if(max_ending_here<0):
		max_ending_here=0
print("maximum sum of contigous array : ")
print(max_so_far)

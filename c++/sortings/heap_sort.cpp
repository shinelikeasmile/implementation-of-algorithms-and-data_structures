#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>*array,int root,int size)
{
		int left=2*root+1;
		int right=2*root+2;
		int largest=root;
		if(left<size && (*array)[left]>(*array)[largest])
			largest=left;
		if(right<size && (*array)[right]>(*array)[largest])
			largest=right;
		if(largest!=root)
			{
				int temp=(*array)[largest];
				(*array)[largest]=(*array)[root];
				(*array)[root]=temp;
				heapify(array,largest,size);
			}
}
void heapsort(vector<int>*array,int size)
{
	for(int i=size/2-1;i>=0;i--)
		heapify(array,i,size);
	for(int i=size-1;i>0;i--)
	{
		int temp=(*array)[0];
		(*array)[0]=(*array)[i];
		(*array)[i]=temp;
		heapify(array,0,i);
	}
	
}
int main()
{
	int size;
	cout<<"enter no of elements :";
	cin>>size;
	cout<<"enter all the elements : ";
	vector<int> array(size);
	for(int i=0;i<size;i++)
		cin>>array[i];
	heapsort(&array,size);
	for(auto x:array)
		cout<<x<<" ";
}

#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> *temparray,int low,int mid,int high)
{
	int array1_size=mid-low+1;
	int array2_size=high-mid;
	vector<int>array1(array1_size);
	vector<int>array2(array2_size);
	int actual_index=low;
	for(int i=0;i<=array1_size;i++)
	{
		array1[i]=(*temparray)[actual_index];
		actual_index++;
	}
	actual_index=mid+1;
	for(int i=0;i<=array2_size;i++)
	{
		array2[i]=(*temparray)[actual_index];
		actual_index++;
	}
	int a1=0,a2=0;
	actual_index=low;
	while(a1<array1_size && a2<array2_size)
	{
		if(array1[a1]<array2[a2])
		{
			(*temparray)[actual_index]=array1[a1];
			a1++;
		}
		else
		{
			(*temparray)[actual_index]=array2[a2];
			a2++;
		}
		actual_index++;
	}
	while(a1<array1_size)
	{
		(*temparray)[actual_index]=array1[a1];
		a1++;
		actual_index++;
	}
	while(a2<array2_size)
	{
		(*temparray)[actual_index]=array2[a2];
		a2++;
		actual_index++;
	}
}
void mergesort(vector<int> *temparray,int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(temparray,low,mid);
		mergesort(temparray,mid+1,high);
		merge(temparray,low,mid,high);
	}
}

int main()
{
	vector <int> array;
	int size=0;
	cout<<"enter array size : ";
	cin>>size;
	cout<<"enter all elements : ";
	for(int i=0;i<size;i++)
	{
		int temp;
		cin>>temp;
		array.push_back(temp);
	}
	mergesort(&array,0,size-1);
	for(auto x:array)
	{
		cout<<x<<" ";
	}
	
	
}

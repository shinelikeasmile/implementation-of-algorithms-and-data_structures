#include <iostream>
#include <vector>
using namespace std;
void shellsort(vector<int>&array,int N)
{
	for(int gap=N/2;gap>0;gap=gap/2)
	{
		for(int i=0;i<N;i++)
		{
			int temp=array[i];
			int j=i-gap;
			while(j>=0)
			{
				if(temp<array[j])
				{
					array[j+gap]=array[j];
					j=j-gap;
				}
				else break;
			}
			array[j+gap]=temp;
		}
	}
}
int main()
{
	int N;
	cout<<"Enter no of elements in array : ";
	cin>>N;
	vector<int>array(N);
	cout<<"Enter the elements in array : ";
	for(int i=0;i<N;i++)
		cin>>array[i];
	cout<<"after performing shellsort : ";
	shellsort(array,N);
	for(auto i:array)
		cout<<i<<" ";
}

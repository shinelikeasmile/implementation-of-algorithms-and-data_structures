#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int GetParent(int x)
{
	int parent=~x;
	parent=parent+1;
	parent=parent&x;
	parent=x-parent;
	return parent;
}

int GetNext(int x)
{
	int next=~x;
	next=next+1;
	next=next&x;
	next=next+x;
	return next;
}

int GetSum(vector <int> &A,int start,int end)
{     
	  int sum=0;
      while(start<=end)
      {
		 sum+=A[start]; 
		 start++;
	  }
	  return sum;
}
void createFT(vector <int> &FT,vector <int> &A)
{
	unsigned int i=1;
	int parent;
	while(i<FT.size())
	{	
		parent=GetParent(i);
		FT[i]=GetSum(A,parent,i-1);
		i++;
	}	
}

int GetPrefix(vector <int> &FT,int i)
{
	int sum=0;
	i+=1;
	while(i!=0)
	{
		sum+=FT[i];
		i=GetParent(i);	
	}
	return sum;
}
void update(vector <int>&FT,unsigned int x,int u)
{
	while(x<FT.size())
	{
	FT[x]+=u;
	x=GetNext(x);
	}
}
using namespace std;
int main()
{
	vector <int> array;
	array.push_back(3);
	array.push_back(2);
	array.push_back(-1);
	array.push_back(6);
	array.push_back(5);
	array.push_back(4);
	array.push_back(-3);
	array.push_back(3);
	array.push_back(7);
	array.push_back(2);
	array.push_back(3);
	vector <int> FenwickTree(array.size()+1,0);
	createFT(FenwickTree,array);
	cout<<GetPrefix(FenwickTree,2);
}

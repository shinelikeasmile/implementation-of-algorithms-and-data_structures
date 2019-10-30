#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void createSegTree(vector <int> &ST,vector <int> &a,int low,int high,int pos)
{
	if(low==high)
	{
		ST[pos]=a[low];
		return;
	}
	int mid=(low+high)/2;
	createSegTree(ST,a,low,mid,2*pos+1);
	createSegTree(ST,a,mid+1,high,2*pos+2);
	ST[pos]=std::min(ST[2*pos+1],ST[2*pos+2]);	
}
int RangeMinQuery(vector <int> &ST,int low,int high,int ql,int qh,int pos)
{
	//no overlap
	if((high<ql) || (low>qh))
	{
		return INT8_MAX;
	}
	//total overlap
	if(ql<=low && qh>=high)
	{
		return ST[pos];
		
	}
	//partial overlap
	int mid = (low+high)/2;
	return std::min(RangeMinQuery(ST,low,mid,ql,qh,2*pos+1),RangeMinQuery(ST,mid+1,high,ql,qh,2*pos+2));
}
int main()
{
	vector <int> array;
	int i;
	do{
		cin>>i;
		array.push_back(i);
	}while(array.back()!=0);
	array.pop_back();
	int length=array.size();
	length=pow(ceil(log(length)/log(2))+1,2)-1;
	vector <int> segTree(length,INT8_MAX);
	createSegTree(segTree,array,0,array.size()-1,0);
	cout<<RangeMinQuery(segTree,0,array.size()-1,0,6,0);
}

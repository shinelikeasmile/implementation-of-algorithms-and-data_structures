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
int RangeMinQuery(vector <int> &ST,vector <int> &LT,int low,int high,int ql,int qh,int pos)
{
	if(LT[pos]!=0)
	{
		ST[pos]+=LT[pos];
		if(low!=high){
		LT[2*pos+1]=LT[pos];
		LT[2*pos+2]=LT[pos];}
		LT[pos]=0;
	}
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
	return std::min(RangeMinQuery(ST,LT,low,mid,ql,qh,2*pos+1),RangeMinQuery(ST,LT,mid+1,high,ql,qh,2*pos+2));
}
int LazyUpdation(vector <int> &ST,vector <int> &LT,int low,int high,int ql,int qh,int pos,int update)
{
	//check for updation
	if(LT[pos]!=0)
	{
		ST[pos]+=LT[pos];
		if(low!=high){
		LT[2*pos+1]=LT[pos];
		LT[2*pos+2]=LT[pos];}
		LT[pos]=0;
	}
	
	//no overlap
	if((high<ql) || (low>qh))
	{
		return ST[pos];
	}
	//total overlap
	if(ql<=low && qh>=high)
	{
		ST[pos]+=update;
		if(low!=high){
		LT[2*pos+1]+=update;
		LT[2*pos+2]+=update;}
		return ST[pos];
	}
	//partial overlap
	int mid = (low+high)/2;
	ST[pos]=std::min(LazyUpdation(ST,LT,low,mid,ql,qh,2*pos+1,update),LazyUpdation(ST,LT,mid+1,high,ql,qh,2*pos+2,update));
	return ST[pos];
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
	vector <int> lazyTree(length,0);
	createSegTree(segTree,array,0,array.size()-1,0);
	LazyUpdation(segTree,lazyTree,0,array.size(),0,3,0,3);
	LazyUpdation(segTree,lazyTree,0,array.size(),0,3,0,1);
	LazyUpdation(segTree,lazyTree,0,array.size(),0,0,0,2);
	cout<<"="<<RangeMinQuery(segTree,lazyTree,0,array.size()-1,3,5,0);
}
